#include "CmPhysXCommon.h"
#include "PsSync.h"

namespace PxUtil {
    physx::PxDefaultAllocator gUtilAllocator;
    struct UtilAllocator {
        void* allocate(size_t size, const char* file, physx::PxU32 line) { return gUtilAllocator.allocate(size, NULL, file, int(line)); }
        void deallocate(void* ptr) { gUtilAllocator.deallocate(ptr); }
    };

	struct Sync: public physx::Ps::SyncT<UtilAllocator> {};

	Sync* syncCreate() {
		return new(gUtilAllocator.allocate(sizeof(Sync), 0, 0, 0)) Sync();
	}

	void syncWait(Sync* sync) { sync->wait(); }

	void syncSet(Sync* sync) { sync->set(); }

	void syncReset(Sync* sync) { sync->reset(); }

	void syncRelease(Sync* sync) {
		sync->~Sync();
		gUtilAllocator.deallocate(sync);
	}
}

class BatchVehicleUpdateDesc {
    public:
        physx::PxFoundation* foundation = NULL;
        physx::PxScene* scene = NULL;
        physx::PxVehicleDrivableSurfaceToTireFrictionPairs* frictionPairs = NULL;
        physx::PxU32 maxNbVehicles = 256;
        physx::PxU32 maxNbWheelsPerVehicle = 4;
        physx::PxU32 maxNbHitPointsPerWheel = 1;
        physx::PxU32 numWorkers = 8;
        physx::PxU32 batchSize = 32;
		physx::PxBatchQueryPreFilterShader preFilterShader = NULL;
		physx::PxBatchQueryPostFilterShader postFilterShader = NULL;
};

class BatchVehicleQueryData {
    public:
        static BatchVehicleQueryData* allocate(BatchVehicleUpdateDesc& desc, physx::PxAllocatorCallback& allocator) {
            const physx::PxU32 qryDataSize = ((sizeof(BatchVehicleQueryData) + 15) & ~15);
            const physx::PxU32 maxNbWheels = desc.maxNbVehicles * desc.maxNbWheelsPerVehicle;
            const physx::PxU32 raycastResultSize = ((sizeof(physx::PxRaycastQueryResult) * maxNbWheels + 15) & ~15);
            const physx::PxU32 sweepResultSize = ((sizeof(physx::PxSweepQueryResult) * maxNbWheels + 15) & ~15);
            const physx::PxU32 maxNbHitPoints = maxNbWheels * desc.maxNbHitPointsPerWheel;
            const physx::PxU32 raycastHitSize = ((sizeof(physx::PxRaycastHit) * maxNbHitPoints + 15) & ~15);
            const physx::PxU32 sweepHitSize = ((sizeof(physx::PxSweepHit) * maxNbHitPoints + 15) & ~15);

            const physx::PxU32 size = qryDataSize + raycastResultSize + raycastHitSize + sweepResultSize + sweepHitSize;
            physx::PxU8* buffer = static_cast<physx::PxU8*>(allocator.allocate(size, NULL, NULL, 0));

            BatchVehicleQueryData* batchData = new(buffer) BatchVehicleQueryData();
            batchData->mMaxNbVehicles = desc.maxNbVehicles;
            batchData->mPreFilterShader = desc.preFilterShader;
            batchData->mPostFilterShader = desc.postFilterShader;
            batchData->mNbQueriesPerBatch = desc.batchSize * desc.maxNbWheelsPerVehicle;
            batchData->mNbHitResultsPerQuery = desc.maxNbHitPointsPerWheel;
            buffer += qryDataSize;

            batchData->mRaycastResults = reinterpret_cast<physx::PxRaycastQueryResult*>(buffer);
            buffer += raycastResultSize;
            batchData->mRaycastHitBuffer = reinterpret_cast<physx::PxRaycastHit*>(buffer);
            buffer += raycastHitSize;
            batchData->mSweepResults = reinterpret_cast<physx::PxSweepQueryResult*>(buffer);
            buffer += sweepResultSize;
            batchData->mSweepHitBuffer = reinterpret_cast<physx::PxSweepHit*>(buffer);
            buffer += sweepHitSize;

            for (physx::PxU32 i = 0; i < maxNbWheels; i++) {
                new(batchData->mRaycastResults + i) physx::PxRaycastQueryResult();
                new(batchData->mSweepResults + i) physx::PxSweepQueryResult();
            }
            for (physx::PxU32 i = 0; i < maxNbHitPoints; i++) {
                new(batchData->mRaycastHitBuffer + i) physx::PxRaycastHit();
                new(batchData->mSweepHitBuffer + i) physx::PxSweepHit();
            }

            for (physx::PxU32 i = 0; i < (desc.maxNbVehicles + desc.batchSize - 1) / desc.batchSize; i++) {
                batchData->batchQueries.push_back(batchData->setupBatchedSceneQuery(i, desc.scene));
            }

            return batchData;
        }

		BatchVehicleQueryData() { }
		~BatchVehicleQueryData() { }

        void free(physx::PxAllocatorCallback& allocator) {
            allocator.deallocate(this);
        }

        physx::PxU32 getNbVehicles() { return static_cast<physx::PxU32>(vehicles.size()); }

        bool addVehicle(physx::PxVehicleWheels* vehicle) {
            if (vehicles.size() < mMaxNbVehicles) {
                vehicles.push_back(vehicle);
                return true;
            }
            return false;
        }

        bool removeVehicle(physx::PxVehicleWheels* vehicle) {
            for (size_t i = 0; i < vehicles.size(); i++) {
                if (vehicles[i] == vehicle) {
                    vehicles.erase(vehicles.begin() + i);
                    return true;
                }
            }
            return false;
        }

        void removeAllVehicles() {
            vehicles.clear();
        }

        physx::PxI32 indexOf(physx::PxVehicleWheels* vehicle) {
            for (size_t i = 0; i < vehicles.size(); i++) {
                if (vehicles[i] == vehicle) {
                    return static_cast<physx::PxI32>(i);
                }
            }
            return -1;
        }

        physx::PxVehicleWheels* getVehicle(physx::PxU32 index) { return vehicles[index]; }

        physx::PxVehicleWheels** getVehicles(physx::PxU32 index) { return vehicles.data() + index; }

        physx::PxBatchQuery* getBatchQuery(physx::PxU32 batchId) { return batchQueries[batchId]; }

        physx::PxRaycastQueryResult* getRaycastQueryResultBuffer(const physx::PxU32 batchId) {
            return mRaycastResults + batchId * mNbQueriesPerBatch;
        }

        physx::PxSweepQueryResult* getSweepQueryResultBuffer(const physx::PxU32 batchId) {
            return mSweepResults + batchId * mNbQueriesPerBatch;
        }

        physx::PxU32 getQueryResultBufferSize() {
            return mNbQueriesPerBatch;
        }

	private:
        physx::PxBatchQuery* setupBatchedSceneQuery(const physx::PxU32 batchId, physx::PxScene* scene) {
            const physx::PxU32 maxNbHitResultsInBatch = mNbQueriesPerBatch * mNbHitResultsPerQuery;
            physx::PxBatchQueryDesc sqDesc(mNbQueriesPerBatch, mNbQueriesPerBatch, 0);

            sqDesc.queryMemory.userRaycastResultBuffer = mRaycastResults + batchId * mNbQueriesPerBatch;
            sqDesc.queryMemory.userRaycastTouchBuffer = mRaycastHitBuffer + batchId * maxNbHitResultsInBatch;
            sqDesc.queryMemory.raycastTouchBufferSize = maxNbHitResultsInBatch;

            sqDesc.queryMemory.userSweepResultBuffer = mSweepResults + batchId * mNbQueriesPerBatch;
            sqDesc.queryMemory.userSweepTouchBuffer = mSweepHitBuffer + batchId * maxNbHitResultsInBatch;
            sqDesc.queryMemory.sweepTouchBufferSize = maxNbHitResultsInBatch;

            sqDesc.preFilterShader = mPreFilterShader;
            sqDesc.postFilterShader = mPostFilterShader;

            return scene->createBatchQuery(sqDesc);
        }

		physx::PxU32 mMaxNbVehicles = 0;
		physx::PxBatchQueryPreFilterShader mPreFilterShader = NULL;
		physx::PxBatchQueryPostFilterShader mPostFilterShader = NULL;
		physx::PxU32 mNbQueriesPerBatch = 0;
		physx::PxU32 mNbHitResultsPerQuery = 0;
		physx::PxRaycastQueryResult* mRaycastResults = NULL;
		physx::PxSweepQueryResult* mSweepResults = NULL;
		physx::PxRaycastHit* mRaycastHitBuffer = NULL;
		physx::PxSweepHit* mSweepHitBuffer = NULL;

		std::vector<physx::PxVehicleWheels*> vehicles;
		std::vector<physx::PxBatchQuery*> batchQueries;
};

class BatchWheelQueryResults {
	public:
		static BatchWheelQueryResults* allocate(BatchVehicleUpdateDesc& desc, physx::PxAllocatorCallback& allocator) {
			const physx::PxU32 byteSize = sizeof(BatchWheelQueryResults)
			            + sizeof(physx::PxVehicleWheelQueryResult) * desc.maxNbVehicles
			            + sizeof(physx::PxWheelQueryResult) * desc.maxNbWheelsPerVehicle * desc.maxNbVehicles
			            + sizeof(physx::PxVehicleConcurrentUpdateData) * desc.maxNbVehicles
			            + sizeof(physx::PxVehicleWheelConcurrentUpdateData) * desc.maxNbWheelsPerVehicle * desc.maxNbVehicles;

			physx::PxU8* buffer = static_cast<physx::PxU8*>(allocator.allocate(byteSize, NULL, NULL, 0));

			BatchWheelQueryResults* bwqr = reinterpret_cast<BatchWheelQueryResults*>(buffer);
			buffer += sizeof(BatchWheelQueryResults);
			bwqr->mVehicleWheelQueryResults = reinterpret_cast<physx::PxVehicleWheelQueryResult*>(buffer);
			buffer += sizeof(physx::PxVehicleWheelQueryResult) * desc.maxNbVehicles;

			for (physx::PxU32 i = 0; i < desc.maxNbVehicles; i++) {
				new(buffer) physx::PxWheelQueryResult();
				bwqr->mVehicleWheelQueryResults[i].wheelQueryResults = reinterpret_cast<physx::PxWheelQueryResult*>(buffer);
				bwqr->mVehicleWheelQueryResults[i].nbWheelQueryResults = desc.maxNbWheelsPerVehicle;
				buffer += sizeof(physx::PxWheelQueryResult) * desc.maxNbWheelsPerVehicle;
			}

			bwqr->mVehicleConcurrentUpdates = reinterpret_cast<physx::PxVehicleConcurrentUpdateData*>(buffer);
			buffer += sizeof(physx::PxVehicleConcurrentUpdateData) * desc.maxNbVehicles;

			for (physx::PxU32 i = 0; i < desc.maxNbVehicles; i++) {
				new(bwqr->mVehicleConcurrentUpdates + i) physx::PxVehicleConcurrentUpdateData();
				bwqr->mVehicleConcurrentUpdates[i].nbConcurrentWheelUpdates = desc.maxNbWheelsPerVehicle;
				bwqr->mVehicleConcurrentUpdates[i].concurrentWheelUpdates = reinterpret_cast<physx::PxVehicleWheelConcurrentUpdateData*>(buffer);
				buffer += sizeof(physx::PxVehicleWheelConcurrentUpdateData) * desc.maxNbWheelsPerVehicle;
				for (physx::PxU32 j = 0; j < desc.maxNbWheelsPerVehicle; j++) {
					new(bwqr->mVehicleConcurrentUpdates[i].concurrentWheelUpdates + j) physx::PxVehicleWheelConcurrentUpdateData();
				}
			}
			return bwqr;
		}

		BatchWheelQueryResults() { }
		~BatchWheelQueryResults() { }

		void free(physx::PxAllocatorCallback& allocator) {
			allocator.deallocate(this);
		}

		physx::PxVehicleWheelQueryResult* getVehicleWheelQueryResults(const physx::PxU32 id) {
			return mVehicleWheelQueryResults + id;
		}

		physx::PxVehicleConcurrentUpdateData* getVehicleConcurrentUpdate(const physx::PxU32 id) {
			return mVehicleConcurrentUpdates + id;
		}

		physx::PxVehicleConcurrentUpdateData* getVehicleConcurrentUpdateBuffer() {
			return mVehicleConcurrentUpdates;
		}

	private:
		physx::PxVehicleWheelQueryResult* mVehicleWheelQueryResults = NULL;
		physx::PxVehicleConcurrentUpdateData* mVehicleConcurrentUpdates = NULL;
};

/**
 * TaskBatchVehicleRaycasts allows vehicle suspension raycasts to be performed concurrently across multiple threads.
 */
class TaskBatchVehicleRaycasts : public physx::PxLightCpuTask {
    public:
        void setup(physx::PxU32 threadId, BatchVehicleUpdateDesc* batchDesc, BatchVehicleQueryData* batchData) {
            mThreadId = threadId;
            mBatchDesc = batchDesc;
            mBatchData = batchData;
        }

        virtual void run() {
            physx::PxU32 nbVehicles = mBatchData->getNbVehicles();
            physx::PxU32 batchId = mThreadId;
            physx::PxU32 vehicleId = batchId * mBatchDesc->batchSize;
            while (vehicleId < nbVehicles) {
                physx::PxU32 numToRaycast = physx::PxMin(nbVehicles - vehicleId, mBatchDesc->batchSize);

                physx::PxVehicleWheels** vehicles = mBatchData->getVehicles(vehicleId);
                physx::PxBatchQuery* batchQuery = mBatchData->getBatchQuery(batchId);
                physx::PxU32 raycastQueryResultsSize = mBatchData->getQueryResultBufferSize();
                physx::PxRaycastQueryResult* raycastQueryResults = mBatchData->getRaycastQueryResultBuffer(batchId);
                physx::PxVehicleSuspensionRaycasts(batchQuery, numToRaycast, vehicles, raycastQueryResultsSize, raycastQueryResults);

                batchId += mBatchDesc->numWorkers;
                vehicleId = batchId * mBatchDesc->batchSize;
            }
        }

        virtual const char* getName() const { return "TaskVehicleRaycasts"; }

    private:
        BatchVehicleUpdateDesc* mBatchDesc = NULL;
        BatchVehicleQueryData* mBatchData = NULL;
        physx::PxU32 mThreadId = 0xffffffff;
};

/**
 * TaskBatchVehicleUpdates allows vehicle updates to be performed concurrently across multiple threads.
 */
class TaskBatchVehicleUpdates : public physx::PxLightCpuTask {
    public:
        void setup(physx::PxU32 threadId, BatchVehicleUpdateDesc* batchDesc, BatchVehicleQueryData* batchData, BatchWheelQueryResults* wheelQryData, physx::PxF32 timestep) {
            mThreadId = threadId;
            mBatchDesc = batchDesc;
            mBatchData = batchData;
            mWheelQryData = wheelQryData;
            mTimestep = timestep;
        }

        virtual void run() {
            physx::PxU32 nbVehicles = mBatchData->getNbVehicles();
            physx::PxU32 batchId = mThreadId;
            physx::PxU32 vehicleId = batchId * mBatchDesc->batchSize;
            while (vehicleId < nbVehicles) {
                physx::PxU32 numToUpdate = physx::PxMin(nbVehicles - vehicleId, mBatchDesc->batchSize);

                physx::PxVehicleWheels** vehicles = mBatchData->getVehicles(vehicleId);
                physx::PxVehicleWheelQueryResult* vehicleWheelQueryResults = mWheelQryData->getVehicleWheelQueryResults(vehicleId);
                physx::PxVehicleConcurrentUpdateData* concurrentUpdates = mWheelQryData->getVehicleConcurrentUpdate(vehicleId);
                physx::PxVehicleUpdates(mTimestep, mBatchDesc->scene->getGravity(), *mBatchDesc->frictionPairs, numToUpdate, vehicles, vehicleWheelQueryResults, concurrentUpdates);

                batchId += mBatchDesc->numWorkers;
                vehicleId = batchId * mBatchDesc->batchSize;
            }
        }

        virtual const char* getName() const { return "TaskVehicleUpdates"; }

    private:
        BatchVehicleUpdateDesc* mBatchDesc = NULL;
        BatchVehicleQueryData* mBatchData = NULL;
        BatchWheelQueryResults* mWheelQryData = NULL;
        physx::PxF32 mTimestep = 0;
        physx::PxU32 mThreadId = 0xffffffff;
};

class TaskWait : public physx::PxLightCpuTask {
	public:
		TaskWait(PxUtil::Sync* syncHandle) : mSyncHandle(syncHandle) { }

		virtual void run() { }

		PX_INLINE void release() {
			PxLightCpuTask::release();
			PxUtil::syncSet(mSyncHandle);
		}

		virtual const char* getName() const { return "TaskWait"; }

	private:
		PxUtil::Sync* mSyncHandle;
};

class BatchVehicleUpdate {
    public:
        BatchVehicleUpdate(BatchVehicleUpdateDesc& desc) :
                allocator(desc.foundation->getAllocatorCallback()),
                desc(desc)
        {
            batchData = BatchVehicleQueryData::allocate(desc, allocator);
            wheelQryData = BatchWheelQueryResults::allocate(desc, allocator);
            taskManager = physx::PxTaskManager::createTaskManager(desc.foundation->getErrorCallback(), desc.scene->getCpuDispatcher());
        }

        ~BatchVehicleUpdate() {
            batchData->free(allocator);
            wheelQryData->free(allocator);
        }

        void batchUpdate(physx::PxF32 timestep) {
            concurrentVehicleRaycasts();
            concurrentVehicleUpdates(timestep);
        }

        void addVehicle(physx::PxVehicleWheels* vehicle) {
            if (!batchData->addVehicle(vehicle)) {
                desc.foundation->getErrorCallback().reportError(physx::PxErrorCode::Enum::eOUT_OF_MEMORY, "Maximum number of vehicles exceeded", __FILE__, __LINE__);
            }
        }

        void removeVehicle(physx::PxVehicleWheels* vehicle) {
            if (!batchData->removeVehicle(vehicle)) {
                desc.foundation->getErrorCallback().reportError(physx::PxErrorCode::Enum::eINVALID_PARAMETER , "Vehicle already removed", __FILE__, __LINE__);
            }
        }

        void removeAllVehicles() {
            batchData->removeAllVehicles();
        }

        physx::PxI32 indexOf(physx::PxVehicleWheels* vehicle) {
            return batchData->indexOf(vehicle);
        }

        physx::PxWheelQueryResult* getWheelQueryResult(physx::PxU32 vehicleId, physx::PxU32 wheelId) {
            if (vehicleId >= static_cast<physx::PxU32>(batchData->getNbVehicles())) {
                return NULL;
            }
            physx::PxVehicleWheelQueryResult* vehicleResult = wheelQryData->getVehicleWheelQueryResults(vehicleId);
            if (wheelId >= vehicleResult->nbWheelQueryResults) {
                return NULL;
            }
            return &vehicleResult->wheelQueryResults[wheelId];
        }

    private:
        void concurrentVehicleRaycasts() {
            PxUtil::Sync* vehicleRaycastsComplete = PxUtil::syncCreate();
            PxUtil::syncReset(vehicleRaycastsComplete);

            // Create tasks that will update the vehicles concurrently then wait until all vehicles
            // have completed their update.
            TaskWait taskWait(vehicleRaycastsComplete);
            std::vector<TaskBatchVehicleRaycasts> taskVehicleRaycasts(desc.numWorkers);
            for (physx::PxU32 i = 0; i < desc.numWorkers; i++) {
                taskVehicleRaycasts[i].setup(i, &desc, batchData);
            }

            // Start the task manager.
            taskManager->resetDependencies();
            taskManager->startSimulation();

            // Update the raycasts concurrently then wait until all vehicles have completed their raycasts.
            taskWait.setContinuation(*taskManager, NULL);
            for (physx::PxU32 i = 0; i < desc.numWorkers; i++) {
                taskVehicleRaycasts[i].setContinuation(&taskWait);
            }
            taskWait.removeReference();
            for (physx::PxU32 i = 0; i < desc.numWorkers; i++) {
                taskVehicleRaycasts[i].removeReference();
            }

            // Wait for the signal that the work has been completed.
            PxUtil::syncWait(vehicleRaycastsComplete);
            // Release the sync handle
            PxUtil::syncRelease(vehicleRaycastsComplete);
        }

        void concurrentVehicleUpdates(const physx::PxF32 timestep) {
            PxUtil::Sync* vehicleUpdatesComplete = PxUtil::syncCreate();
            PxUtil::syncReset(vehicleUpdatesComplete);

            // Create tasks that will update the vehicles concurrently then wait until all vehicles have completed their update.
            TaskWait taskWait(vehicleUpdatesComplete);
            std::vector<TaskBatchVehicleUpdates> taskVehicleUpdates(desc.numWorkers);
            for (physx::PxU32 i = 0; i < desc.numWorkers; i++) {
                taskVehicleUpdates[i].setup(i, &desc, batchData, wheelQryData, timestep);
            }

            // Start the task manager.
            taskManager->resetDependencies();
            taskManager->startSimulation();

            // Update the vehicles concurrently then wait until all vehicles have completed their update.
            taskWait.setContinuation(*taskManager, NULL);
            for (physx::PxU32 i = 0; i < desc.numWorkers; i++) {
                taskVehicleUpdates[i].setContinuation(&taskWait);
            }
            taskWait.removeReference();
            for (physx::PxU32 i = 0; i < desc.numWorkers; i++) {
                taskVehicleUpdates[i].removeReference();
            }

            // Wait for the signal that the work has been completed.
            PxUtil::syncWait(vehicleUpdatesComplete);
            // Release the sync handle
            PxUtil::syncRelease(vehicleUpdatesComplete);
            // When PxVehicleUpdates is executed concurrently a secondary step is required to complete the update of the vehicles.
            physx::PxVehiclePostUpdates(wheelQryData->getVehicleConcurrentUpdateBuffer(), batchData->getNbVehicles(), batchData->getVehicles(0));
        }

        physx::PxAllocatorCallback& allocator;
        physx::PxTaskManager* taskManager;

        BatchVehicleUpdateDesc desc;
        BatchVehicleQueryData* batchData;
        BatchWheelQueryResults* wheelQryData;
};