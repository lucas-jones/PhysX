#include "PxPhysicsAPI.h"
#include <vector>

physx::PxFilterFlags defaultFilterShader(  
  physx::PxFilterObjectAttributes attributes0, physx::PxFilterData , 
  physx::PxFilterObjectAttributes attributes1, physx::PxFilterData ,
  physx::PxPairFlags& pairFlags, const void* , physx::PxU32 )
{
  if(physx::PxFilterObjectIsTrigger(attributes0) || physx::PxFilterObjectIsTrigger(attributes1))
  {
    pairFlags = physx::PxPairFlag::eTRIGGER_DEFAULT | physx::PxPairFlag::eDETECT_CCD_CONTACT;
    return physx::PxFilterFlag::eDEFAULT;
  }
  pairFlags = physx::PxPairFlag::eCONTACT_DEFAULT | physx::PxPairFlag::eNOTIFY_TOUCH_FOUND | physx::PxPairFlag::eNOTIFY_TOUCH_LOST | physx::PxPairFlag::eNOTIFY_TOUCH_PERSISTS | physx::PxPairFlag::eDETECT_CCD_CONTACT;
  return physx::PxFilterFlag::eDEFAULT;
}

// top-level functions are not supported by webidl binder, we need to wrap them in a class
class PxTopLevelFunctions {
    public:
        static const int PHYSICS_VERSION = PX_PHYSICS_VERSION;

        static physx::PxSimulationFilterShader DefaultFilterShader() {
            return &defaultFilterShader;
        }

        static physx::PxFoundation* CreateFoundation(physx::PxU32 version, physx::PxDefaultAllocator& allocator, physx::PxDefaultErrorCallback& errorCallback) {
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
        
        static physx::PxRevoluteJoint* RevoluteJointCreate(physx::PxPhysics& physics, physx::PxRigidActor* actor0, physx::PxTransform& localFrame0, physx::PxRigidActor* actor1, physx::PxTransform& localFrame1) {
            return physx::PxRevoluteJointCreate(physics, actor0, localFrame0, actor1, localFrame1);
        }

        // helper function for array-like access on a raw PxU8-pointer
        static physx::PxU8 getU8At(void* pointer, int index) {
            return static_cast<physx::PxU8*>(pointer)[index];
        }

        // helper function for array-like access on a raw PxVec3-pointer
        static physx::PxVec3 getVec3At(void* pointer, int index) {
            return static_cast<physx::PxVec3*>(pointer)[index];
        }
};

// enums within namespaces are not supported by webidl binder, as a hack we can use typedefs
typedef physx::PxActorFlag::Enum physx_PxActorFlag;
typedef physx::PxActorType::Enum physx_PxActorType;
typedef physx::PxBaseFlag::Enum physx_PxBaseFlag;
typedef physx::PxConvexFlag::Enum physx_PxConvexFlag;
typedef physx::PxConvexMeshGeometryFlag::Enum physx_PxConvexMeshGeometryFlag;
typedef physx::PxForceMode::Enum physx_PxForceMode;
typedef physx::PxRigidBodyFlag::Enum physx_PxRigidBodyFlag;
typedef physx::PxSceneFlag::Enum physx_PxSceneFlag;
typedef physx::PxShapeFlag::Enum physx_PxShapeFlag;
typedef physx::PxRevoluteJointFlag::Enum physx_PxRevoluteJointFlag;

// template classes are not supported by webidl binder, as a hack we can use typedefs
typedef std::vector<physx::PxVec3> VectorPxVec3;
