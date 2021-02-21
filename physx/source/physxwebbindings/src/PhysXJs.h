#include "PxPhysicsAPI.h"
#include <vector>

// enums within namespaces are not supported by webidl binder, as a hack we can use typedefs
typedef physx::PxActorFlag::Enum PxActorFlagEnum;
typedef physx::PxActorType::Enum PxActorTypeEnum;
typedef physx::PxArticulationAxis::Enum PxArticulationAxisEnum;
typedef physx::PxArticulationCache::Enum PxArticulationCacheEnum;
typedef physx::PxArticulationDriveType::Enum PxArticulationDriveTypeEnum;
typedef physx::PxArticulationFlag::Enum PxArticulationFlagEnum;
typedef physx::PxArticulationJointDriveType::Enum PxArticulationJointDriveTypeEnum;
typedef physx::PxArticulationJointType::Enum PxArticulationJointTypeEnum;
typedef physx::PxArticulationMotion::Enum PxArticulationMotionEnum;
typedef physx::PxBaseFlag::Enum PxBaseFlagEnum;
typedef physx::PxConstraintFlag::Enum PxConstraintFlagEnum;
typedef physx::PxContactPairFlag::Enum PxContactPairFlagEnum;
typedef physx::PxContactPairHeaderFlag::Enum PxContactPairHeaderFlagEnum;
typedef physx::PxConvexFlag::Enum PxConvexFlagEnum;
typedef physx::PxConvexMeshCookingType::Enum PxConvexMeshCookingTypeEnum;
typedef physx::PxConvexMeshGeometryFlag::Enum PxConvexMeshGeometryFlagEnum;
typedef physx::PxD6Axis::Enum PxD6AxisEnum;
typedef physx::PxD6Drive::Enum PxD6DriveEnum;
typedef physx::PxD6Motion::Enum PxD6MotionEnum;
typedef physx::PxD6JointDriveFlag::Enum PxD6JointDriveFlagEnum;
typedef physx::PxDistanceJointFlag::Enum PxDistanceJointFlagEnum;
typedef physx::PxErrorCode::Enum PxErrorCodeEnum;
typedef physx::PxForceMode::Enum PxForceModeEnum;
typedef physx::PxHitFlag::Enum PxHitFlagEnum;
typedef physx::PxIDENTITY PxIDENTITYEnum;
typedef physx::PxJointActorIndex::Enum PxJointActorIndexEnum;
typedef physx::PxMeshCookingHint::Enum PxMeshCookingHintEnum;
typedef physx::PxMeshFlag::Enum PxMeshFlagEnum;
typedef physx::PxMeshGeometryFlag::Enum PxMeshGeometryFlagEnum;
typedef physx::PxMeshMidPhase::Enum PxMeshMidPhaseEnum;
typedef physx::PxMeshPreprocessingFlag::Enum PxMeshPreprocessingFlagEnum;
typedef physx::PxPairFlag::Enum PxPairFlagEnum;
typedef physx::PxPrismaticJointFlag::Enum PxPrismaticJointFlagEnum;
typedef physx::PxRigidBodyFlag::Enum PxRigidBodyFlagEnum;
typedef physx::PxRigidDynamicLockFlag::Enum PxRigidDynamicLockFlagEnum;
typedef physx::PxSceneFlag::Enum PxSceneFlagEnum;
typedef physx::PxShapeFlag::Enum PxShapeFlagEnum;
typedef physx::PxSphericalJointFlag::Enum PxSphericalJointFlagEnum;
typedef physx::PxRevoluteJointFlag::Enum PxRevoluteJointFlagEnum;
typedef physx::PxTriangleMeshFlag::Enum PxTriangleMeshFlagEnum;
typedef physx::PxTriggerPairFlag::Enum PxTriggerPairFlagEnum;
typedef physx::PxVehicleClutchAccuracyMode::Enum PxVehicleClutchAccuracyModeEnum;
typedef physx::PxVehicleDifferential4WData::Enum PxVehicleDifferential4WDataEnum;
typedef physx::PxVehicleDrive4WControl::Enum PxVehicleDrive4WControlEnum;
typedef physx::PxVehicleGearsData::Enum PxVehicleGearEnum;
typedef physx::PxVehicleUpdateMode::Enum PxVehicleUpdateModeEnum;
typedef physx::PxVehicleWheelsSimFlag::Enum PxVehicleWheelsSimFlagEnum;

// typedefs for pointer types
typedef const physx::PxU8* PxU8Ptr;
typedef const physx::PxU16* PxU16Ptr;
typedef const physx::PxU32* PxU32Ptr;
typedef const physx::PxMaterial* PxMaterialPtr;
typedef physx::PxReal* PxRealPtr;
typedef physx::PxActor* PxActorPtr;
typedef physx::PxVehicleWheels* PxVehicleWheelsPtr;

// template classes are not supported by webidl binder, as a hack we can use typedefs
typedef physx::PxFixedSizeLookupTable<physx::PxVehicleEngineData::eMAX_NB_ENGINE_TORQUE_CURVE_ENTRIES> PxEngineTorqueLookupTable;
typedef physx::PxTypedStridedData<physx::PxU16> PxU16StridedData;

typedef std::vector<PxMaterialPtr> Vector_PxMaterial;
typedef std::vector<physx::PxRaycastHit> Vector_PxRaycastHit;
typedef std::vector<physx::PxRaycastQueryResult> Vector_PxRaycastQueryResult;
typedef std::vector<physx::PxSweepHit> Vector_PxSweepHit;
typedef std::vector<physx::PxSweepQueryResult> Vector_PxSweepQueryResult;
typedef std::vector<physx::PxVehicleDrivableSurfaceType> Vector_PxVehicleDrivableSurfaceType;
typedef std::vector<physx::PxWheelQueryResult> Vector_PxWheelQueryResult;
typedef std::vector<PxVehicleWheelsPtr> Vector_PxVehicleWheels;

typedef std::vector<physx::PxReal> Vector_PxReal;
typedef std::vector<physx::PxU16> Vector_PxU16;
typedef std::vector<physx::PxU32> Vector_PxU32;
typedef std::vector<physx::PxVec3> Vector_PxVec3;

// default scene filter / query shaders, implemented in C++ for performance reasons
physx::PxFilterFlags defaultFilterShader(physx::PxFilterObjectAttributes attributes0, physx::PxFilterData filterData0,
                                         physx::PxFilterObjectAttributes attributes1, physx::PxFilterData filterData1,
                                         physx::PxPairFlags& pairFlags, const void* constantBlock, physx::PxU32 constantBlockSize) {
    PX_UNUSED(constantBlock);
    PX_UNUSED(constantBlockSize);

    if ((0 == (filterData0.word0 & filterData1.word1)) && (0 == (filterData1.word0 & filterData0.word1))) {
        return physx::PxFilterFlag::eSUPPRESS;
    }

    if (physx::PxFilterObjectIsTrigger(attributes0) || physx::PxFilterObjectIsTrigger(attributes1)) {
        pairFlags = physx::PxPairFlag::eTRIGGER_DEFAULT;
    } else {
        pairFlags = physx::PxPairFlag::eCONTACT_DEFAULT | physx::PxPairFlag::eDETECT_CCD_CONTACT;
    }
    pairFlags |= physx::PxPairFlags(physx::PxU16(filterData0.word2 | filterData1.word2));

    return physx::PxFilterFlag::eDEFAULT;
}

enum VehicleSurfaceTypeMask {
	DRIVABLE_SURFACE = 0xffff0000,
	UNDRIVABLE_SURFACE = 0x0000ffff
};

physx::PxQueryHitType::Enum defaultWheelSceneQueryPreFilterBlocking(physx::PxFilterData filterData0, physx::PxFilterData filterData1,
                                                                    const void* constantBlock, physx::PxU32 constantBlockSize,
                                                                    physx::PxHitFlags& queryFlags) {
	//filterData0 is the vehicle suspension query.
	//filterData1 is the shape potentially hit by the query.
	PX_UNUSED(filterData0);
	PX_UNUSED(constantBlock);
	PX_UNUSED(constantBlockSize);
	PX_UNUSED(queryFlags);
	return ((0 == (filterData1.word3 & DRIVABLE_SURFACE)) ? physx::PxQueryHitType::eNONE : physx::PxQueryHitType::eBLOCK);
}

physx::PxQueryHitType::Enum defaultWheelSceneQueryPostFilterBlocking(physx::PxFilterData filterData0, physx::PxFilterData filterData1,
                                                                     const void* constantBlock, physx::PxU32 constantBlockSize,
                                                                     const physx::PxQueryHit& hit) {
	PX_UNUSED(filterData0);
	PX_UNUSED(filterData1);
	PX_UNUSED(constantBlock);
	PX_UNUSED(constantBlockSize);
	return ((static_cast<const physx::PxSweepHit&>(hit)).hadInitialOverlap() ? physx::PxQueryHitType::eNONE : physx::PxQueryHitType::eBLOCK);
}

// Slightly simplified SimulationEventCallback which can be implemented in non-native code
class SimpleSimulationEventCallback : physx::PxSimulationEventCallback {
    public:
        virtual void onConstraintBreak(physx::PxConstraintInfo*, physx::PxU32) = 0;
        virtual void onWake(physx::PxActor**, physx::PxU32) = 0;
        virtual void onSleep(physx::PxActor**, physx::PxU32) = 0;
        virtual void onContact(const physx::PxContactPairHeader&, const physx::PxContactPair*, physx::PxU32 nbPairs) = 0;
        virtual void onTrigger(physx::PxTriggerPair*, physx::PxU32) = 0;

        // implement onAdvance with empty body so it does not have to be implemented
        // in non-native code (for the sake of performance)
        virtual void onAdvance(const physx::PxRigidBody *const *, const physx::PxTransform*, const physx::PxU32) { }
};

// top-level functions are not supported by webidl binder, we need to wrap them in a class
class PxTopLevelFunctions {
    public:
        static const physx::PxU32 PHYSICS_VERSION = PX_PHYSICS_VERSION;

        static physx::PxSimulationFilterShader DefaultFilterShader() {
            return &defaultFilterShader;
        }

        static physx::PxBatchQueryPreFilterShader DefaultWheelSceneQueryPreFilterBlocking() {
            return &defaultWheelSceneQueryPreFilterBlocking;
        }

        static physx::PxBatchQueryPostFilterShader DefaultWheelSceneQueryPostFilterBlocking() {
            return &defaultWheelSceneQueryPostFilterBlocking;
        }

        static physx::PxFoundation* CreateFoundation(physx::PxU32 version, physx::PxDefaultAllocator& allocator, physx::PxErrorCallback& errorCallback) {
            return PxCreateFoundation(version, allocator, errorCallback);
        }

        static physx::PxPhysics* CreatePhysics(physx::PxU32 version, physx::PxFoundation& foundation, const physx::PxTolerancesScale& scale) {
            return PxCreatePhysics(version, foundation, scale);
        }

        static physx::PxCooking* CreateCooking(physx::PxU32 version, physx::PxFoundation& foundation, const physx::PxCookingParams& params) {
            return PxCreateCooking(version, foundation, params);
        }

        static physx::PxDefaultCpuDispatcher* DefaultCpuDispatcherCreate(physx::PxU32 numThreads) {
            return physx::PxDefaultCpuDispatcherCreate(numThreads);
        }

        static bool InitExtensions(physx::PxPhysics& physics) {
            return PxInitExtensions(physics, NULL);
        }

        static physx::PxD6Joint* D6JointCreate(physx::PxPhysics& physics, physx::PxRigidActor* actor0, physx::PxTransform& localFrame0, physx::PxRigidActor* actor1, physx::PxTransform& localFrame1) {
            return physx::PxD6JointCreate(physics, actor0, localFrame0, actor1, localFrame1);
        }

        static physx::PxDistanceJoint* DistanceJointCreate(physx::PxPhysics& physics, physx::PxRigidActor* actor0, physx::PxTransform& localFrame0, physx::PxRigidActor* actor1, physx::PxTransform& localFrame1) {
            return physx::PxDistanceJointCreate(physics, actor0, localFrame0, actor1, localFrame1);
        }

        static physx::PxFixedJoint* FixedJointCreate(physx::PxPhysics& physics, physx::PxRigidActor* actor0, physx::PxTransform& localFrame0, physx::PxRigidActor* actor1, physx::PxTransform& localFrame1) {
            return physx::PxFixedJointCreate(physics, actor0, localFrame0, actor1, localFrame1);
        }

        static physx::PxPrismaticJoint* PrismaticJointCreate(physx::PxPhysics& physics, physx::PxRigidActor* actor0, physx::PxTransform& localFrame0, physx::PxRigidActor* actor1, physx::PxTransform& localFrame1) {
            return physx::PxPrismaticJointCreate(physics, actor0, localFrame0, actor1, localFrame1);
        }
        
        static physx::PxRevoluteJoint* RevoluteJointCreate(physx::PxPhysics& physics, physx::PxRigidActor* actor0, physx::PxTransform& localFrame0, physx::PxRigidActor* actor1, physx::PxTransform& localFrame1) {
            return physx::PxRevoluteJointCreate(physics, actor0, localFrame0, actor1, localFrame1);
        }

        static physx::PxSphericalJoint* SphericalJointCreate(physx::PxPhysics& physics, physx::PxRigidActor* actor0, physx::PxTransform& localFrame0, physx::PxRigidActor* actor1, physx::PxTransform& localFrame1) {
            return physx::PxSphericalJointCreate(physics, actor0, localFrame0, actor1, localFrame1);
        }
};

class PxVehicleTopLevelFunctions {
    public:
        static bool InitVehicleSDK(physx::PxPhysics& physics) {
            return PxInitVehicleSDK(physics, NULL);
        }

        static void PxVehicleComputeSprungMasses(physx::PxU32 nbSprungMasses, const physx::PxVec3* sprungMassCoordinates, const physx::PxVec3& centreOfMass, physx::PxReal totalMass, physx::PxU32 gravityDirection, physx::PxReal* sprungMasses) {
            physx::PxVehicleComputeSprungMasses(nbSprungMasses, sprungMassCoordinates, centreOfMass, totalMass, gravityDirection, sprungMasses);
        }
        
        static void PxVehicleSuspensionRaycasts(physx::PxBatchQuery* batchQuery, Vector_PxVehicleWheels& vehicles, physx::PxU32 nbSceneQueryResults, physx::PxRaycastQueryResult* sceneQueryResults) {
            physx::PxVehicleSuspensionRaycasts(batchQuery, physx::PxU32(vehicles.size()), vehicles.data(), nbSceneQueryResults, sceneQueryResults);
        }

        static void PxVehicleUpdates(const physx::PxReal timestep, const physx::PxVec3& gravity, const physx::PxVehicleDrivableSurfaceToTireFrictionPairs& vehicleDrivableSurfaceToTireFrictionPairs,
                                     Vector_PxVehicleWheels& vehicles, physx::PxVehicleWheelQueryResult* vehicleWheelQueryResults) {
            physx::PxVehicleUpdates(timestep, gravity, vehicleDrivableSurfaceToTireFrictionPairs, physx::PxU32(vehicles.size()), vehicles.data(), vehicleWheelQueryResults);
        }

        static void VehicleSetBasisVectors(const physx::PxVec3& up, const physx::PxVec3& forward) {
            physx::PxVehicleSetBasisVectors(up, forward);
        }

        static void VehicleSetUpdateMode(physx::PxVehicleUpdateMode::Enum vehicleUpdateMode) {
            physx::PxVehicleSetUpdateMode(vehicleUpdateMode);
        }

        static float PxVehicleTireData_getFrictionVsSlipGraph(physx::PxVehicleTireData* tireData, physx::PxU32 m, physx::PxU32 n) {
            return tireData->mFrictionVsSlipGraph[m][n];
        }

        static void PxVehicleTireData_setFrictionVsSlipGraph(physx::PxVehicleTireData* tireData, physx::PxU32 m, physx::PxU32 n, float value) {
            tireData->mFrictionVsSlipGraph[m][n] = value;
        }
};

// Various helper functions for pointer access and conversion
class TypeHelpers {
    public:
        static physx::PxU8 getU8At(const physx::PxU8* base, int index) {
            return base[index];
        }

        static physx::PxU16 getU16At(const physx::PxU16* base, int index) {
            return base[index];
        }

        static physx::PxU32 getU32At(const physx::PxU32* base, int index) {
            return base[index];
        }

        static physx::PxReal getRealAt(physx::PxReal* base, int index) {
            return base[index];
        }

        static physx::PxContactPair* getContactPairAt(physx::PxContactPair* base, int index) {
            return &base[index];
        }

        static physx::PxTriggerPair* getTriggerPairAt(physx::PxTriggerPair* base, int index) {
            return &base[index];
        }

        static physx::PxVec3* getVec3At(physx::PxVec3* base, int index) {
            return &base[index];
        }

        static PxU8Ptr voidToU8Ptr(void* voidPtr) {
            return (PxU8Ptr) voidPtr;
        }

        static PxU16Ptr voidToU16Ptr(void* voidPtr) {
            return (PxU16Ptr) voidPtr;
        }

        static PxU32Ptr voidToU32Ptr(void* voidPtr) {
            return (PxU32Ptr) voidPtr;
        }

        static PxRealPtr voidToRealPtr(void* voidPtr) {
            return (PxRealPtr) voidPtr;
        }
};
