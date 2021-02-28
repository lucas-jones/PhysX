/*
 * JNI glue code. You should not edit this file.
 * Generated from WebIDL model 'PhysXJs' by webidl-util.
 */
#include <jni.h>

static JavaVM * javaVm = NULL;

class JniThreadEnv {
    public:
        JniThreadEnv() : shouldDetach(false), env(NULL) { }
        JniThreadEnv(JNIEnv *env) : shouldDetach(false), env(env) { }
        ~JniThreadEnv() {
            if (shouldDetach) {
                javaVm->DetachCurrentThread();
            }
        }
        JNIEnv* getEnv() {
            if (env == NULL && javaVm != NULL) {
                javaVm->AttachCurrentThread((void**) &env, NULL);
                shouldDetach = true;
            }
            return env;
        }
        
    private:
        bool shouldDetach;
        JNIEnv *env;
};

static thread_local JniThreadEnv jniThreadEnv;

class JniThreadManager {
    public:
        static bool init(JNIEnv *env) {
            if (env->GetJavaVM(&javaVm) != 0) {
                return false;
            }
            jniThreadEnv = JniThreadEnv(env);
            return true;
        }
};

class JavaSimulationEventCallback : SimpleSimulationEventCallback {
    public:
        JavaSimulationEventCallback(JNIEnv* env, jobject javaLocalRef) {
            javaGlobalRef = env->NewGlobalRef(javaLocalRef);
            jclass javaClass = env->GetObjectClass(javaLocalRef);
            onConstraintBreakMethodId = env->GetMethodID(javaClass, "_onConstraintBreak", "(JI)V");
            onWakeMethodId = env->GetMethodID(javaClass, "_onWake", "(JI)V");
            onSleepMethodId = env->GetMethodID(javaClass, "_onSleep", "(JI)V");
            onContactMethodId = env->GetMethodID(javaClass, "_onContact", "(JJI)V");
            onTriggerMethodId = env->GetMethodID(javaClass, "_onTrigger", "(JI)V");
        }
        
        ~JavaSimulationEventCallback() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        virtual void onConstraintBreak(physx::PxConstraintInfo* constraints, unsigned int count) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, onConstraintBreakMethodId, (jlong) constraints, (jint) count);
        }

        virtual void onWake(PxActorPtr* actors, unsigned int count) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, onWakeMethodId, (jlong) actors, (jint) count);
        }

        virtual void onSleep(PxActorPtr* actors, unsigned int count) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, onSleepMethodId, (jlong) actors, (jint) count);
        }

        virtual void onContact(const physx::PxContactPairHeader& pairHeader, const physx::PxContactPair* pairs, unsigned int nbPairs) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, onContactMethodId, (jlong) &pairHeader, (jlong) pairs, (jint) nbPairs);
        }

        virtual void onTrigger(physx::PxTriggerPair* pairs, unsigned int count) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, onTriggerMethodId, (jlong) pairs, (jint) count);
        }

    private:
        jobject javaGlobalRef;
        jmethodID onConstraintBreakMethodId;
        jmethodID onWakeMethodId;
        jmethodID onSleepMethodId;
        jmethodID onContactMethodId;
        jmethodID onTriggerMethodId;
};

class JavaErrorCallback : physx::PxErrorCallback {
    public:
        JavaErrorCallback(JNIEnv* env, jobject javaLocalRef) {
            javaGlobalRef = env->NewGlobalRef(javaLocalRef);
            jclass javaClass = env->GetObjectClass(javaLocalRef);
            reportErrorMethodId = env->GetMethodID(javaClass, "_reportError", "(ILjava/lang/String;Ljava/lang/String;I)V");
        }
        
        ~JavaErrorCallback() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        virtual void reportError(PxErrorCodeEnum code, const char* message, const char* file, int line) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, reportErrorMethodId, (jint) code, _env->NewStringUTF(message), _env->NewStringUTF(file), (jint) line);
        }

    private:
        jobject javaGlobalRef;
        jmethodID reportErrorMethodId;
};

class JavaUserControllerHitReport : physx::PxUserControllerHitReport {
    public:
        JavaUserControllerHitReport(JNIEnv* env, jobject javaLocalRef) {
            javaGlobalRef = env->NewGlobalRef(javaLocalRef);
            jclass javaClass = env->GetObjectClass(javaLocalRef);
            onShapeHitMethodId = env->GetMethodID(javaClass, "_onShapeHit", "(J)V");
            onControllerHitMethodId = env->GetMethodID(javaClass, "_onControllerHit", "(J)V");
            onObstacleHitMethodId = env->GetMethodID(javaClass, "_onObstacleHit", "(J)V");
        }
        
        ~JavaUserControllerHitReport() {
            jniThreadEnv.getEnv()->DeleteGlobalRef(javaGlobalRef);
        }
        
        virtual void onShapeHit(const physx::PxControllerShapeHit& hit) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, onShapeHitMethodId, (jlong) &hit);
        }

        virtual void onControllerHit(const physx::PxControllersHit& hit) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, onControllerHitMethodId, (jlong) &hit);
        }

        virtual void onObstacleHit(const physx::PxControllerObstacleHit& hit) {
            JNIEnv* _env = jniThreadEnv.getEnv();
            _env->CallVoidMethod(javaGlobalRef, onObstacleHitMethodId, (jlong) &hit);
        }

    private:
        jobject javaGlobalRef;
        jmethodID onShapeHitMethodId;
        jmethodID onControllerHitMethodId;
        jmethodID onObstacleHitMethodId;
};

extern "C" {

// JniThreadManager
JNIEXPORT jboolean JNICALL Java_physx_JniThreadManager__1init(JNIEnv* env, jclass) {
    return (jboolean) JniThreadManager::init(env);
}
JNIEXPORT void JNICALL Java_physx_JniThreadManager__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (JniThreadManager*) address;
}

// PxTopLevelFunctions
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1DefaultFilterShader(JNIEnv*, jclass) {
    static thread_local physx::PxSimulationFilterShader _cache;
    _cache = PxTopLevelFunctions::DefaultFilterShader();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1DefaultWheelSceneQueryPreFilterBlocking(JNIEnv*, jclass) {
    static thread_local physx::PxBatchQueryPreFilterShader _cache;
    _cache = PxTopLevelFunctions::DefaultWheelSceneQueryPreFilterBlocking();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1DefaultWheelSceneQueryPostFilterBlocking(JNIEnv*, jclass) {
    static thread_local physx::PxBatchQueryPostFilterShader _cache;
    _cache = PxTopLevelFunctions::DefaultWheelSceneQueryPostFilterBlocking();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1CreateControllerManager__J(JNIEnv*, jclass, jlong scene) {
    return (jlong) PxTopLevelFunctions::CreateControllerManager(*((physx::PxScene*) scene));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1CreateControllerManager__JZ(JNIEnv*, jclass, jlong scene, jboolean lockingEnabled) {
    return (jlong) PxTopLevelFunctions::CreateControllerManager(*((physx::PxScene*) scene), lockingEnabled);
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1CreateCooking(JNIEnv*, jclass, jint version, jlong foundation, jlong scale) {
    return (jlong) PxTopLevelFunctions::CreateCooking(version, *((physx::PxFoundation*) foundation), *((physx::PxCookingParams*) scale));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1CreateFoundation(JNIEnv*, jclass, jint version, jlong allocator, jlong errorCallback) {
    return (jlong) PxTopLevelFunctions::CreateFoundation(version, *((physx::PxDefaultAllocator*) allocator), *((physx::PxErrorCallback*) errorCallback));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1CreatePhysics(JNIEnv*, jclass, jint version, jlong foundation, jlong params) {
    return (jlong) PxTopLevelFunctions::CreatePhysics(version, *((physx::PxFoundation*) foundation), *((physx::PxTolerancesScale*) params));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1DefaultCpuDispatcherCreate(JNIEnv*, jclass, jint numThreads) {
    return (jlong) PxTopLevelFunctions::DefaultCpuDispatcherCreate(numThreads);
}
JNIEXPORT jboolean JNICALL Java_physx_PxTopLevelFunctions__1InitExtensions(JNIEnv*, jclass, jlong physics) {
    return (jboolean) PxTopLevelFunctions::InitExtensions(*((physx::PxPhysics*) physics));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1D6JointCreate(JNIEnv*, jclass, jlong physics, jlong actor0, jlong localFrame0, jlong actor1, jlong localFrame1) {
    return (jlong) PxTopLevelFunctions::D6JointCreate(*((physx::PxPhysics*) physics), (physx::PxRigidActor*) actor0, *((physx::PxTransform*) localFrame0), (physx::PxRigidActor*) actor1, *((physx::PxTransform*) localFrame1));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1DistanceJointCreate(JNIEnv*, jclass, jlong physics, jlong actor0, jlong localFrame0, jlong actor1, jlong localFrame1) {
    return (jlong) PxTopLevelFunctions::DistanceJointCreate(*((physx::PxPhysics*) physics), (physx::PxRigidActor*) actor0, *((physx::PxTransform*) localFrame0), (physx::PxRigidActor*) actor1, *((physx::PxTransform*) localFrame1));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1FixedJointCreate(JNIEnv*, jclass, jlong physics, jlong actor0, jlong localFrame0, jlong actor1, jlong localFrame1) {
    return (jlong) PxTopLevelFunctions::FixedJointCreate(*((physx::PxPhysics*) physics), (physx::PxRigidActor*) actor0, *((physx::PxTransform*) localFrame0), (physx::PxRigidActor*) actor1, *((physx::PxTransform*) localFrame1));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1PrismaticJointCreate(JNIEnv*, jclass, jlong physics, jlong actor0, jlong localFrame0, jlong actor1, jlong localFrame1) {
    return (jlong) PxTopLevelFunctions::PrismaticJointCreate(*((physx::PxPhysics*) physics), (physx::PxRigidActor*) actor0, *((physx::PxTransform*) localFrame0), (physx::PxRigidActor*) actor1, *((physx::PxTransform*) localFrame1));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1RevoluteJointCreate(JNIEnv*, jclass, jlong physics, jlong actor0, jlong localFrame0, jlong actor1, jlong localFrame1) {
    return (jlong) PxTopLevelFunctions::RevoluteJointCreate(*((physx::PxPhysics*) physics), (physx::PxRigidActor*) actor0, *((physx::PxTransform*) localFrame0), (physx::PxRigidActor*) actor1, *((physx::PxTransform*) localFrame1));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1SphericalJointCreate(JNIEnv*, jclass, jlong physics, jlong actor0, jlong localFrame0, jlong actor1, jlong localFrame1) {
    return (jlong) PxTopLevelFunctions::SphericalJointCreate(*((physx::PxPhysics*) physics), (physx::PxRigidActor*) actor0, *((physx::PxTransform*) localFrame0), (physx::PxRigidActor*) actor1, *((physx::PxTransform*) localFrame1));
}
JNIEXPORT void JNICALL Java_physx_PxTopLevelFunctions__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxTopLevelFunctions*) _address;
}
JNIEXPORT jint JNICALL Java_physx_PxTopLevelFunctions__1getPHYSICS_1VERSION(JNIEnv*, jclass) {
    return (jint) PxTopLevelFunctions::PHYSICS_VERSION;
}

// PxBoxController
JNIEXPORT jfloat JNICALL Java_physx_character_PxBoxController__1getHalfHeight(JNIEnv*, jclass, jlong _address) {
    physx::PxBoxController* self = (physx::PxBoxController*) _address;
    return (jfloat) self->getHalfHeight();
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxBoxController__1getHalfSideExtent(JNIEnv*, jclass, jlong _address) {
    physx::PxBoxController* self = (physx::PxBoxController*) _address;
    return (jfloat) self->getHalfSideExtent();
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxBoxController__1getHalfForwardExtent(JNIEnv*, jclass, jlong _address) {
    physx::PxBoxController* self = (physx::PxBoxController*) _address;
    return (jfloat) self->getHalfForwardExtent();
}
JNIEXPORT void JNICALL Java_physx_character_PxBoxController__1setHalfHeight(JNIEnv*, jclass, jlong _address, jfloat halfHeight) {
    physx::PxBoxController* self = (physx::PxBoxController*) _address;
    self->setHalfHeight(halfHeight);
}
JNIEXPORT void JNICALL Java_physx_character_PxBoxController__1setHalfSideExtent(JNIEnv*, jclass, jlong _address, jfloat halfSideExtent) {
    physx::PxBoxController* self = (physx::PxBoxController*) _address;
    self->setHalfSideExtent(halfSideExtent);
}
JNIEXPORT void JNICALL Java_physx_character_PxBoxController__1setHalfForwardExtent(JNIEnv*, jclass, jlong _address, jfloat halfForwardExtent) {
    physx::PxBoxController* self = (physx::PxBoxController*) _address;
    self->setHalfForwardExtent(halfForwardExtent);
}

// PxBoxControllerDesc
JNIEXPORT jlong JNICALL Java_physx_character_PxBoxControllerDesc__1PxBoxControllerDesc(JNIEnv*, jclass) {
    return (jlong) new physx::PxBoxControllerDesc();
}
JNIEXPORT void JNICALL Java_physx_character_PxBoxControllerDesc__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::PxBoxControllerDesc* self = (physx::PxBoxControllerDesc*) _address;
    self->setToDefault();
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxBoxControllerDesc__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxBoxControllerDesc* self = (physx::PxBoxControllerDesc*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_character_PxBoxControllerDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBoxControllerDesc*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxBoxControllerDesc__1getHalfHeight(JNIEnv*, jclass, jlong _address) {
    physx::PxBoxControllerDesc* _self = (physx::PxBoxControllerDesc*) _address;
    return (jfloat) _self->halfHeight;
}
JNIEXPORT void JNICALL Java_physx_character_PxBoxControllerDesc__1setHalfHeight(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxBoxControllerDesc* _self = (physx::PxBoxControllerDesc*) _address;
    _self->halfHeight = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxBoxControllerDesc__1getHalfSideExtent(JNIEnv*, jclass, jlong _address) {
    physx::PxBoxControllerDesc* _self = (physx::PxBoxControllerDesc*) _address;
    return (jfloat) _self->halfSideExtent;
}
JNIEXPORT void JNICALL Java_physx_character_PxBoxControllerDesc__1setHalfSideExtent(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxBoxControllerDesc* _self = (physx::PxBoxControllerDesc*) _address;
    _self->halfSideExtent = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxBoxControllerDesc__1getHalfForwardExtent(JNIEnv*, jclass, jlong _address) {
    physx::PxBoxControllerDesc* _self = (physx::PxBoxControllerDesc*) _address;
    return (jfloat) _self->halfForwardExtent;
}
JNIEXPORT void JNICALL Java_physx_character_PxBoxControllerDesc__1setHalfForwardExtent(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxBoxControllerDesc* _self = (physx::PxBoxControllerDesc*) _address;
    _self->halfForwardExtent = value;
}

// PxBoxObstacle
JNIEXPORT jlong JNICALL Java_physx_character_PxBoxObstacle__1PxBoxObstacle(JNIEnv*, jclass) {
    return (jlong) new physx::PxBoxObstacle();
}
JNIEXPORT void JNICALL Java_physx_character_PxBoxObstacle__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBoxObstacle*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxBoxObstacle__1getMHalfExtents(JNIEnv*, jclass, jlong _address) {
    physx::PxBoxObstacle* _self = (physx::PxBoxObstacle*) _address;
    return (jlong) &_self->mHalfExtents;
}
JNIEXPORT void JNICALL Java_physx_character_PxBoxObstacle__1setMHalfExtents(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBoxObstacle* _self = (physx::PxBoxObstacle*) _address;
    _self->mHalfExtents = *((physx::PxVec3*) value);
}

// PxCapsuleController
JNIEXPORT jfloat JNICALL Java_physx_character_PxCapsuleController__1getRadius(JNIEnv*, jclass, jlong _address) {
    physx::PxCapsuleController* self = (physx::PxCapsuleController*) _address;
    return (jfloat) self->getRadius();
}
JNIEXPORT void JNICALL Java_physx_character_PxCapsuleController__1setRadius(JNIEnv*, jclass, jlong _address, jfloat radius) {
    physx::PxCapsuleController* self = (physx::PxCapsuleController*) _address;
    self->setRadius(radius);
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxCapsuleController__1getHeight(JNIEnv*, jclass, jlong _address) {
    physx::PxCapsuleController* self = (physx::PxCapsuleController*) _address;
    return (jfloat) self->getHeight();
}
JNIEXPORT void JNICALL Java_physx_character_PxCapsuleController__1setHeight(JNIEnv*, jclass, jlong _address, jfloat height) {
    physx::PxCapsuleController* self = (physx::PxCapsuleController*) _address;
    self->setHeight(height);
}
JNIEXPORT jint JNICALL Java_physx_character_PxCapsuleController__1getClimbingMode(JNIEnv*, jclass, jlong _address) {
    physx::PxCapsuleController* self = (physx::PxCapsuleController*) _address;
    return (jint) self->getClimbingMode();
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxCapsuleController__1setClimbingMode(JNIEnv*, jclass, jlong _address, jint mode) {
    physx::PxCapsuleController* self = (physx::PxCapsuleController*) _address;
    return (jboolean) self->setClimbingMode((PxCapsuleClimbingModeEnum) mode);
}

// PxCapsuleControllerDesc
JNIEXPORT jlong JNICALL Java_physx_character_PxCapsuleControllerDesc__1PxCapsuleControllerDesc(JNIEnv*, jclass) {
    return (jlong) new physx::PxCapsuleControllerDesc();
}
JNIEXPORT void JNICALL Java_physx_character_PxCapsuleControllerDesc__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::PxCapsuleControllerDesc* self = (physx::PxCapsuleControllerDesc*) _address;
    self->setToDefault();
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxCapsuleControllerDesc__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxCapsuleControllerDesc* self = (physx::PxCapsuleControllerDesc*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_character_PxCapsuleControllerDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxCapsuleControllerDesc*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxCapsuleControllerDesc__1getRadius(JNIEnv*, jclass, jlong _address) {
    physx::PxCapsuleControllerDesc* _self = (physx::PxCapsuleControllerDesc*) _address;
    return (jfloat) _self->radius;
}
JNIEXPORT void JNICALL Java_physx_character_PxCapsuleControllerDesc__1setRadius(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxCapsuleControllerDesc* _self = (physx::PxCapsuleControllerDesc*) _address;
    _self->radius = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxCapsuleControllerDesc__1getHeight(JNIEnv*, jclass, jlong _address) {
    physx::PxCapsuleControllerDesc* _self = (physx::PxCapsuleControllerDesc*) _address;
    return (jfloat) _self->height;
}
JNIEXPORT void JNICALL Java_physx_character_PxCapsuleControllerDesc__1setHeight(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxCapsuleControllerDesc* _self = (physx::PxCapsuleControllerDesc*) _address;
    _self->height = value;
}
JNIEXPORT jint JNICALL Java_physx_character_PxCapsuleControllerDesc__1getClimbingMode(JNIEnv*, jclass, jlong _address) {
    physx::PxCapsuleControllerDesc* _self = (physx::PxCapsuleControllerDesc*) _address;
    return (jint) _self->climbingMode;
}
JNIEXPORT void JNICALL Java_physx_character_PxCapsuleControllerDesc__1setClimbingMode(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxCapsuleControllerDesc* _self = (physx::PxCapsuleControllerDesc*) _address;
    _self->climbingMode = (PxCapsuleClimbingModeEnum) value;
}

// PxCapsuleObstacle
JNIEXPORT jlong JNICALL Java_physx_character_PxCapsuleObstacle__1PxCapsuleObstacle(JNIEnv*, jclass) {
    return (jlong) new physx::PxCapsuleObstacle();
}
JNIEXPORT void JNICALL Java_physx_character_PxCapsuleObstacle__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxCapsuleObstacle*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxCapsuleObstacle__1getMHalfHeight(JNIEnv*, jclass, jlong _address) {
    physx::PxCapsuleObstacle* _self = (physx::PxCapsuleObstacle*) _address;
    return (jfloat) _self->mHalfHeight;
}
JNIEXPORT void JNICALL Java_physx_character_PxCapsuleObstacle__1setMHalfHeight(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxCapsuleObstacle* _self = (physx::PxCapsuleObstacle*) _address;
    _self->mHalfHeight = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxCapsuleObstacle__1getMRadius(JNIEnv*, jclass, jlong _address) {
    physx::PxCapsuleObstacle* _self = (physx::PxCapsuleObstacle*) _address;
    return (jfloat) _self->mRadius;
}
JNIEXPORT void JNICALL Java_physx_character_PxCapsuleObstacle__1setMRadius(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxCapsuleObstacle* _self = (physx::PxCapsuleObstacle*) _address;
    _self->mRadius = value;
}

// PxController
JNIEXPORT jint JNICALL Java_physx_character_PxController__1getType(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jint) self->getType();
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    self->release();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxController__1move__JJFFJ(JNIEnv*, jclass, jlong _address, jlong disp, jfloat minDist, jfloat elapsedTime, jlong filters) {
    static thread_local physx::PxControllerCollisionFlags _cache;
    physx::PxController* self = (physx::PxController*) _address;
    _cache = self->move(*((physx::PxVec3*) disp), minDist, elapsedTime, *((physx::PxControllerFilters*) filters));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxController__1move__JJFFJJ(JNIEnv*, jclass, jlong _address, jlong disp, jfloat minDist, jfloat elapsedTime, jlong filters, jlong obstacles) {
    static thread_local physx::PxControllerCollisionFlags _cache;
    physx::PxController* self = (physx::PxController*) _address;
    _cache = self->move(*((physx::PxVec3*) disp), minDist, elapsedTime, *((physx::PxControllerFilters*) filters), (physx::PxObstacleContext*) obstacles);
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxController__1setPosition(JNIEnv*, jclass, jlong _address, jlong position) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jboolean) self->setPosition(*((physx::PxExtendedVec3*) position));
}
JNIEXPORT jlong JNICALL Java_physx_character_PxController__1getPosition(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jlong) &self->getPosition();
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxController__1setFootPosition(JNIEnv*, jclass, jlong _address, jlong position) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jboolean) self->setFootPosition(*((physx::PxExtendedVec3*) position));
}
JNIEXPORT jlong JNICALL Java_physx_character_PxController__1getFootPosition(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxExtendedVec3 _cache;
    physx::PxController* self = (physx::PxController*) _address;
    _cache = self->getFootPosition();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxController__1getActor(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jlong) self->getActor();
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1setStepOffset(JNIEnv*, jclass, jlong _address, jfloat offset) {
    physx::PxController* self = (physx::PxController*) _address;
    self->setStepOffset(offset);
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxController__1getStepOffset(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jfloat) self->getStepOffset();
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1setNonWalkableMode(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxController* self = (physx::PxController*) _address;
    self->setNonWalkableMode((PxControllerNonWalkableModeEnum) flag);
}
JNIEXPORT jint JNICALL Java_physx_character_PxController__1getNonWalkableMode(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jint) self->getNonWalkableMode();
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxController__1getContactOffset(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jfloat) self->getContactOffset();
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1setContactOffset(JNIEnv*, jclass, jlong _address, jfloat offset) {
    physx::PxController* self = (physx::PxController*) _address;
    self->setContactOffset(offset);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxController__1getUpDirection(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxVec3 _cache;
    physx::PxController* self = (physx::PxController*) _address;
    _cache = self->getUpDirection();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1setUpDirection(JNIEnv*, jclass, jlong _address, jlong up) {
    physx::PxController* self = (physx::PxController*) _address;
    self->setUpDirection(*((physx::PxVec3*) up));
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxController__1getSlopeLimit(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jfloat) self->getSlopeLimit();
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1setSlopeLimit(JNIEnv*, jclass, jlong _address, jfloat slopeLimit) {
    physx::PxController* self = (physx::PxController*) _address;
    self->setSlopeLimit(slopeLimit);
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1invalidateCache(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    self->invalidateCache();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxController__1getScene(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jlong) self->getScene();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxController__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxController* self = (physx::PxController*) _address;
    return (jlong) self->getUserData();
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1setUserData(JNIEnv*, jclass, jlong _address, jlong userData) {
    physx::PxController* self = (physx::PxController*) _address;
    self->setUserData((void*) userData);
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1getState(JNIEnv*, jclass, jlong _address, jlong state) {
    physx::PxController* self = (physx::PxController*) _address;
    self->getState(*((physx::PxControllerState*) state));
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1getStats(JNIEnv*, jclass, jlong _address, jlong stats) {
    physx::PxController* self = (physx::PxController*) _address;
    self->getStats(*((physx::PxControllerStats*) stats));
}
JNIEXPORT void JNICALL Java_physx_character_PxController__1resize(JNIEnv*, jclass, jlong _address, jfloat height) {
    physx::PxController* self = (physx::PxController*) _address;
    self->resize(height);
}

// PxControllerCollisionFlags
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerCollisionFlags__1PxControllerCollisionFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxControllerCollisionFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxControllerCollisionFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxControllerCollisionFlags* self = (physx::PxControllerCollisionFlags*) _address;
    return (jboolean) self->isSet((PxControllerCollisionFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerCollisionFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxControllerCollisionFlags* self = (physx::PxControllerCollisionFlags*) _address;
    self->set((PxControllerCollisionFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerCollisionFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxControllerCollisionFlags* self = (physx::PxControllerCollisionFlags*) _address;
    self->clear((PxControllerCollisionFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerCollisionFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxControllerCollisionFlags*) _address;
}

// PxControllerDesc
JNIEXPORT jboolean JNICALL Java_physx_character_PxControllerDesc__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* self = (physx::PxControllerDesc*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerDesc__1getType(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* self = (physx::PxControllerDesc*) _address;
    return (jint) self->getType();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerDesc__1getPosition(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jlong) &_self->position;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setPosition(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->position = *((physx::PxExtendedVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerDesc__1getUpDirection(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jlong) &_self->upDirection;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setUpDirection(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->upDirection = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxControllerDesc__1getSlopeLimit(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jfloat) _self->slopeLimit;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setSlopeLimit(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->slopeLimit = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxControllerDesc__1getInvisibleWallHeight(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jfloat) _self->invisibleWallHeight;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setInvisibleWallHeight(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->invisibleWallHeight = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxControllerDesc__1getMaxJumpHeight(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jfloat) _self->maxJumpHeight;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setMaxJumpHeight(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->maxJumpHeight = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxControllerDesc__1getContactOffset(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jfloat) _self->contactOffset;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setContactOffset(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->contactOffset = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxControllerDesc__1getStepOffset(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jfloat) _self->stepOffset;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setStepOffset(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->stepOffset = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxControllerDesc__1getDensity(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jfloat) _self->density;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setDensity(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->density = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxControllerDesc__1getScaleCoeff(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jfloat) _self->scaleCoeff;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setScaleCoeff(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->scaleCoeff = value;
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxControllerDesc__1getVolumeGrowth(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jfloat) _self->volumeGrowth;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setVolumeGrowth(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->volumeGrowth = value;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerDesc__1getReportCallback(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jlong) _self->reportCallback;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setReportCallback(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->reportCallback = (physx::PxUserControllerHitReport*) value;
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerDesc__1getNonWalkableMode(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jint) _self->nonWalkableMode;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setNonWalkableMode(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->nonWalkableMode = (PxControllerNonWalkableModeEnum) value;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerDesc__1getMaterial(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jlong) _self->material;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setMaterial(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->material = (physx::PxMaterial*) value;
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxControllerDesc__1getRegisterDeletionListener(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jboolean) _self->registerDeletionListener;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setRegisterDeletionListener(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->registerDeletionListener = value;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerDesc__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerDesc__1setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerDesc* _self = (physx::PxControllerDesc*) _address;
    _self->userData = (void*) value;
}

// PxControllerFilters
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerFilters__1PxControllerFilters(JNIEnv*, jclass, jlong filterData) {
    return (jlong) new physx::PxControllerFilters((physx::PxFilterData*) filterData);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerFilters__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxControllerFilters*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerFilters__1getMFilterData(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerFilters* _self = (physx::PxControllerFilters*) _address;
    return (jlong) _self->mFilterData;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerFilters__1setMFilterData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerFilters* _self = (physx::PxControllerFilters*) _address;
    _self->mFilterData = (physx::PxFilterData*) value;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerFilters__1getMFilterFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerFilters* _self = (physx::PxControllerFilters*) _address;
    return (jlong) &_self->mFilterFlags;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerFilters__1setMFilterFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerFilters* _self = (physx::PxControllerFilters*) _address;
    _self->mFilterFlags = *((physx::PxQueryFlags*) value);
}

// PxControllerHit
JNIEXPORT void JNICALL Java_physx_character_PxControllerHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxControllerHit*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerHit__1getController(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerHit* _self = (physx::PxControllerHit*) _address;
    return (jlong) _self->controller;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerHit__1setController(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerHit* _self = (physx::PxControllerHit*) _address;
    _self->controller = (physx::PxController*) value;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerHit__1getWorldPos(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerHit* _self = (physx::PxControllerHit*) _address;
    return (jlong) &_self->worldPos;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerHit__1setWorldPos(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerHit* _self = (physx::PxControllerHit*) _address;
    _self->worldPos = *((physx::PxExtendedVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerHit__1getWorldNormal(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerHit* _self = (physx::PxControllerHit*) _address;
    return (jlong) &_self->worldNormal;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerHit__1setWorldNormal(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerHit* _self = (physx::PxControllerHit*) _address;
    _self->worldNormal = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerHit__1getDir(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerHit* _self = (physx::PxControllerHit*) _address;
    return (jlong) &_self->dir;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerHit__1setDir(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerHit* _self = (physx::PxControllerHit*) _address;
    _self->dir = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_character_PxControllerHit__1getLength(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerHit* _self = (physx::PxControllerHit*) _address;
    return (jfloat) _self->length;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerHit__1setLength(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxControllerHit* _self = (physx::PxControllerHit*) _address;
    _self->length = value;
}

// PxControllerManager
JNIEXPORT void JNICALL Java_physx_character_PxControllerManager__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    self->release();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerManager__1getScene(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    return (jlong) &self->getScene();
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerManager__1getNbControllers(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    return (jint) self->getNbControllers();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerManager__1getController(JNIEnv*, jclass, jlong _address, jint index) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    return (jlong) self->getController(index);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerManager__1createController(JNIEnv*, jclass, jlong _address, jlong desc) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    return (jlong) self->createController(*((physx::PxControllerDesc*) desc));
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerManager__1purgeControllers(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    self->purgeControllers();
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerManager__1getNbObstacleContexts(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    return (jint) self->getNbObstacleContexts();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerManager__1getObstacleContext(JNIEnv*, jclass, jlong _address, jint index) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    return (jlong) self->getObstacleContext(index);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerManager__1createObstacleContext(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    return (jlong) self->createObstacleContext();
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerManager__1computeInteractions(JNIEnv*, jclass, jlong _address, jfloat elapsedTime) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    self->computeInteractions(elapsedTime);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerManager__1setTessellation(JNIEnv*, jclass, jlong _address, jboolean flag, jfloat maxEdgeLength) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    self->setTessellation(flag, maxEdgeLength);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerManager__1setOverlapRecoveryModule(JNIEnv*, jclass, jlong _address, jboolean flag) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    self->setOverlapRecoveryModule(flag);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerManager__1setPreciseSweeps(JNIEnv*, jclass, jlong _address, jboolean flags) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    self->setPreciseSweeps(flags);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerManager__1setPreventVerticalSlidingAgainstCeiling(JNIEnv*, jclass, jlong _address, jboolean flag) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    self->setPreventVerticalSlidingAgainstCeiling(flag);
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerManager__1shiftOrigin(JNIEnv*, jclass, jlong _address, jlong shift) {
    physx::PxControllerManager* self = (physx::PxControllerManager*) _address;
    self->shiftOrigin(*((physx::PxVec3*) shift));
}

// PxControllerObstacleHit
JNIEXPORT void JNICALL Java_physx_character_PxControllerObstacleHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxControllerObstacleHit*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerObstacleHit__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerObstacleHit* _self = (physx::PxControllerObstacleHit*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerObstacleHit__1setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerObstacleHit* _self = (physx::PxControllerObstacleHit*) _address;
    _self->userData = (void*) value;
}

// PxControllerShapeHit
JNIEXPORT void JNICALL Java_physx_character_PxControllerShapeHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxControllerShapeHit*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerShapeHit__1getShape(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerShapeHit* _self = (physx::PxControllerShapeHit*) _address;
    return (jlong) _self->shape;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerShapeHit__1setShape(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerShapeHit* _self = (physx::PxControllerShapeHit*) _address;
    _self->shape = (physx::PxShape*) value;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerShapeHit__1getActor(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerShapeHit* _self = (physx::PxControllerShapeHit*) _address;
    return (jlong) _self->actor;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerShapeHit__1setActor(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerShapeHit* _self = (physx::PxControllerShapeHit*) _address;
    _self->actor = (physx::PxRigidActor*) value;
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerShapeHit__1getTriangleIndex(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerShapeHit* _self = (physx::PxControllerShapeHit*) _address;
    return (jint) _self->triangleIndex;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerShapeHit__1setTriangleIndex(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxControllerShapeHit* _self = (physx::PxControllerShapeHit*) _address;
    _self->triangleIndex = value;
}

// PxControllersHit
JNIEXPORT void JNICALL Java_physx_character_PxControllersHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxControllersHit*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllersHit__1getOther(JNIEnv*, jclass, jlong _address) {
    physx::PxControllersHit* _self = (physx::PxControllersHit*) _address;
    return (jlong) _self->other;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllersHit__1setOther(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllersHit* _self = (physx::PxControllersHit*) _address;
    _self->other = (physx::PxController*) value;
}

// PxControllerState
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerState__1PxControllerState(JNIEnv*, jclass) {
    return (jlong) new physx::PxControllerState();
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerState__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxControllerState*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerState__1getDeltaXP(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    return (jlong) &_self->deltaXP;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerState__1setDeltaXP(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    _self->deltaXP = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerState__1getTouchedShape(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    return (jlong) _self->touchedShape;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerState__1setTouchedShape(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    _self->touchedShape = (physx::PxShape*) value;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxControllerState__1getTouchedActor(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    return (jlong) _self->touchedActor;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerState__1setTouchedActor(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    _self->touchedActor = (physx::PxRigidActor*) value;
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerState__1getTouchedObstacleHandle(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    return (jint) _self->touchedObstacleHandle;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerState__1setTouchedObstacleHandle(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    _self->touchedObstacleHandle = value;
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerState__1getCollisionFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    return (jint) _self->collisionFlags;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerState__1setCollisionFlags(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    _self->collisionFlags = value;
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxControllerState__1getStandOnAnotherCCT(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    return (jboolean) _self->standOnAnotherCCT;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerState__1setStandOnAnotherCCT(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    _self->standOnAnotherCCT = value;
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxControllerState__1getStandOnObstacle(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    return (jboolean) _self->standOnObstacle;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerState__1setStandOnObstacle(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    _self->standOnObstacle = value;
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxControllerState__1getIsMovingUp(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    return (jboolean) _self->isMovingUp;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerState__1setIsMovingUp(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxControllerState* _self = (physx::PxControllerState*) _address;
    _self->isMovingUp = value;
}

// PxControllerStats
JNIEXPORT void JNICALL Java_physx_character_PxControllerStats__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxControllerStats*) _address;
}
JNIEXPORT jshort JNICALL Java_physx_character_PxControllerStats__1getNbIterations(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerStats* _self = (physx::PxControllerStats*) _address;
    return (jshort) _self->nbIterations;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerStats__1setNbIterations(JNIEnv*, jclass, jlong _address, jshort value) {
    physx::PxControllerStats* _self = (physx::PxControllerStats*) _address;
    _self->nbIterations = value;
}
JNIEXPORT jshort JNICALL Java_physx_character_PxControllerStats__1getNbFullUpdates(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerStats* _self = (physx::PxControllerStats*) _address;
    return (jshort) _self->nbFullUpdates;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerStats__1setNbFullUpdates(JNIEnv*, jclass, jlong _address, jshort value) {
    physx::PxControllerStats* _self = (physx::PxControllerStats*) _address;
    _self->nbFullUpdates = value;
}
JNIEXPORT jshort JNICALL Java_physx_character_PxControllerStats__1getNbPartialUpdates(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerStats* _self = (physx::PxControllerStats*) _address;
    return (jshort) _self->nbPartialUpdates;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerStats__1setNbPartialUpdates(JNIEnv*, jclass, jlong _address, jshort value) {
    physx::PxControllerStats* _self = (physx::PxControllerStats*) _address;
    _self->nbPartialUpdates = value;
}
JNIEXPORT jshort JNICALL Java_physx_character_PxControllerStats__1getNbTessellation(JNIEnv*, jclass, jlong _address) {
    physx::PxControllerStats* _self = (physx::PxControllerStats*) _address;
    return (jshort) _self->nbTessellation;
}
JNIEXPORT void JNICALL Java_physx_character_PxControllerStats__1setNbTessellation(JNIEnv*, jclass, jlong _address, jshort value) {
    physx::PxControllerStats* _self = (physx::PxControllerStats*) _address;
    _self->nbTessellation = value;
}

// PxExtendedVec3
JNIEXPORT jlong JNICALL Java_physx_character_PxExtendedVec3__1PxExtendedVec3__(JNIEnv*, jclass) {
    return (jlong) new physx::PxExtendedVec3();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxExtendedVec3__1PxExtendedVec3__DDD(JNIEnv*, jclass, jdouble x, jdouble y, jdouble z) {
    return (jlong) new physx::PxExtendedVec3(x, y, z);
}
JNIEXPORT void JNICALL Java_physx_character_PxExtendedVec3__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxExtendedVec3*) _address;
}
JNIEXPORT jdouble JNICALL Java_physx_character_PxExtendedVec3__1getX(JNIEnv*, jclass, jlong _address) {
    physx::PxExtendedVec3* _self = (physx::PxExtendedVec3*) _address;
    return (jdouble) _self->x;
}
JNIEXPORT void JNICALL Java_physx_character_PxExtendedVec3__1setX(JNIEnv*, jclass, jlong _address, jdouble value) {
    physx::PxExtendedVec3* _self = (physx::PxExtendedVec3*) _address;
    _self->x = value;
}
JNIEXPORT jdouble JNICALL Java_physx_character_PxExtendedVec3__1getY(JNIEnv*, jclass, jlong _address) {
    physx::PxExtendedVec3* _self = (physx::PxExtendedVec3*) _address;
    return (jdouble) _self->y;
}
JNIEXPORT void JNICALL Java_physx_character_PxExtendedVec3__1setY(JNIEnv*, jclass, jlong _address, jdouble value) {
    physx::PxExtendedVec3* _self = (physx::PxExtendedVec3*) _address;
    _self->y = value;
}
JNIEXPORT jdouble JNICALL Java_physx_character_PxExtendedVec3__1getZ(JNIEnv*, jclass, jlong _address) {
    physx::PxExtendedVec3* _self = (physx::PxExtendedVec3*) _address;
    return (jdouble) _self->z;
}
JNIEXPORT void JNICALL Java_physx_character_PxExtendedVec3__1setZ(JNIEnv*, jclass, jlong _address, jdouble value) {
    physx::PxExtendedVec3* _self = (physx::PxExtendedVec3*) _address;
    _self->z = value;
}

// PxObstacle
JNIEXPORT jint JNICALL Java_physx_character_PxObstacle__1getType(JNIEnv*, jclass, jlong _address) {
    physx::PxObstacle* self = (physx::PxObstacle*) _address;
    return (jint) self->getType();
}
JNIEXPORT void JNICALL Java_physx_character_PxObstacle__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxObstacle*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxObstacle__1getMUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxObstacle* _self = (physx::PxObstacle*) _address;
    return (jlong) _self->mUserData;
}
JNIEXPORT void JNICALL Java_physx_character_PxObstacle__1setMUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxObstacle* _self = (physx::PxObstacle*) _address;
    _self->mUserData = (void*) value;
}
JNIEXPORT jlong JNICALL Java_physx_character_PxObstacle__1getMPos(JNIEnv*, jclass, jlong _address) {
    physx::PxObstacle* _self = (physx::PxObstacle*) _address;
    return (jlong) &_self->mPos;
}
JNIEXPORT void JNICALL Java_physx_character_PxObstacle__1setMPos(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxObstacle* _self = (physx::PxObstacle*) _address;
    _self->mPos = *((physx::PxExtendedVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxObstacle__1getMRot(JNIEnv*, jclass, jlong _address) {
    physx::PxObstacle* _self = (physx::PxObstacle*) _address;
    return (jlong) &_self->mRot;
}
JNIEXPORT void JNICALL Java_physx_character_PxObstacle__1setMRot(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxObstacle* _self = (physx::PxObstacle*) _address;
    _self->mRot = *((physx::PxQuat*) value);
}

// PxObstacleContext
JNIEXPORT void JNICALL Java_physx_character_PxObstacleContext__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxObstacleContext* self = (physx::PxObstacleContext*) _address;
    self->release();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxObstacleContext__1getControllerManager(JNIEnv*, jclass, jlong _address) {
    physx::PxObstacleContext* self = (physx::PxObstacleContext*) _address;
    return (jlong) &self->getControllerManager();
}
JNIEXPORT jint JNICALL Java_physx_character_PxObstacleContext__1addObstacle(JNIEnv*, jclass, jlong _address, jlong obstacle) {
    physx::PxObstacleContext* self = (physx::PxObstacleContext*) _address;
    return (jint) self->addObstacle(*((physx::PxObstacle*) obstacle));
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxObstacleContext__1removeObstacle(JNIEnv*, jclass, jlong _address, jint handle) {
    physx::PxObstacleContext* self = (physx::PxObstacleContext*) _address;
    return (jboolean) self->removeObstacle(handle);
}
JNIEXPORT jboolean JNICALL Java_physx_character_PxObstacleContext__1updateObstacle(JNIEnv*, jclass, jlong _address, jint handle, jlong obstacle) {
    physx::PxObstacleContext* self = (physx::PxObstacleContext*) _address;
    return (jboolean) self->updateObstacle(handle, *((physx::PxObstacle*) obstacle));
}
JNIEXPORT jint JNICALL Java_physx_character_PxObstacleContext__1getNbObstacles(JNIEnv*, jclass, jlong _address) {
    physx::PxObstacleContext* self = (physx::PxObstacleContext*) _address;
    return (jint) self->getNbObstacles();
}
JNIEXPORT jlong JNICALL Java_physx_character_PxObstacleContext__1getObstacle(JNIEnv*, jclass, jlong _address, jint i) {
    physx::PxObstacleContext* self = (physx::PxObstacleContext*) _address;
    return (jlong) self->getObstacle(i);
}
JNIEXPORT jlong JNICALL Java_physx_character_PxObstacleContext__1getObstacleByHandle(JNIEnv*, jclass, jlong _address, jint handle) {
    physx::PxObstacleContext* self = (physx::PxObstacleContext*) _address;
    return (jlong) self->getObstacleByHandle(handle);
}
JNIEXPORT void JNICALL Java_physx_character_PxObstacleContext__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxObstacleContext*) _address;
}

// PxUserControllerHitReport
JNIEXPORT void JNICALL Java_physx_character_PxUserControllerHitReport__1onShapeHit(JNIEnv*, jclass, jlong _address, jlong hit) {
    physx::PxUserControllerHitReport* self = (physx::PxUserControllerHitReport*) _address;
    self->onShapeHit(*((physx::PxControllerShapeHit*) hit));
}
JNIEXPORT void JNICALL Java_physx_character_PxUserControllerHitReport__1onControllerHit(JNIEnv*, jclass, jlong _address, jlong hit) {
    physx::PxUserControllerHitReport* self = (physx::PxUserControllerHitReport*) _address;
    self->onControllerHit(*((physx::PxControllersHit*) hit));
}
JNIEXPORT void JNICALL Java_physx_character_PxUserControllerHitReport__1onObstacleHit(JNIEnv*, jclass, jlong _address, jlong hit) {
    physx::PxUserControllerHitReport* self = (physx::PxUserControllerHitReport*) _address;
    self->onObstacleHit(*((physx::PxControllerObstacleHit*) hit));
}

// JavaUserControllerHitReport
JNIEXPORT jlong JNICALL Java_physx_character_JavaUserControllerHitReport__1JavaUserControllerHitReport(JNIEnv* env, jobject obj) {
    return (jlong) new JavaUserControllerHitReport(env, obj);
}
JNIEXPORT void JNICALL Java_physx_character_JavaUserControllerHitReport__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (JavaUserControllerHitReport*) address;
}

// PxCapsuleClimbingModeEnum
JNIEXPORT jint JNICALL Java_physx_character_PxCapsuleClimbingModeEnum__1geteEASY(JNIEnv*, jclass) {
    return PxCapsuleClimbingModeEnum::eEASY;
}
JNIEXPORT jint JNICALL Java_physx_character_PxCapsuleClimbingModeEnum__1geteCONSTRAINED(JNIEnv*, jclass) {
    return PxCapsuleClimbingModeEnum::eCONSTRAINED;
}

// PxControllerCollisionFlagEnum
JNIEXPORT jint JNICALL Java_physx_character_PxControllerCollisionFlagEnum__1geteCOLLISION_1SIDES(JNIEnv*, jclass) {
    return PxControllerCollisionFlagEnum::eCOLLISION_SIDES;
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerCollisionFlagEnum__1geteCOLLISION_1UP(JNIEnv*, jclass) {
    return PxControllerCollisionFlagEnum::eCOLLISION_UP;
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerCollisionFlagEnum__1geteCOLLISION_1DOWN(JNIEnv*, jclass) {
    return PxControllerCollisionFlagEnum::eCOLLISION_DOWN;
}

// PxControllerNonWalkableModeEnum
JNIEXPORT jint JNICALL Java_physx_character_PxControllerNonWalkableModeEnum__1getePREVENT_1CLIMBING(JNIEnv*, jclass) {
    return PxControllerNonWalkableModeEnum::ePREVENT_CLIMBING;
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerNonWalkableModeEnum__1getePREVENT_1CLIMBING_1AND_1FORCE_1SLIDING(JNIEnv*, jclass) {
    return PxControllerNonWalkableModeEnum::ePREVENT_CLIMBING_AND_FORCE_SLIDING;
}

// PxControllerShapeTypeEnum
JNIEXPORT jint JNICALL Java_physx_character_PxControllerShapeTypeEnum__1geteBOX(JNIEnv*, jclass) {
    return PxControllerShapeTypeEnum::eBOX;
}
JNIEXPORT jint JNICALL Java_physx_character_PxControllerShapeTypeEnum__1geteCAPSULE(JNIEnv*, jclass) {
    return PxControllerShapeTypeEnum::eCAPSULE;
}

// PxBase
JNIEXPORT void JNICALL Java_physx_common_PxBase__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxBase* self = (physx::PxBase*) _address;
    self->release();
}
JNIEXPORT jstring JNICALL Java_physx_common_PxBase__1getConcreteTypeName(JNIEnv* _env, jclass, jlong _address) {
    physx::PxBase* self = (physx::PxBase*) _address;
    return _env->NewStringUTF(self->getConcreteTypeName());
}
JNIEXPORT jint JNICALL Java_physx_common_PxBase__1getConcreteType(JNIEnv*, jclass, jlong _address) {
    physx::PxBase* self = (physx::PxBase*) _address;
    return (jint) self->getConcreteType();
}
JNIEXPORT void JNICALL Java_physx_common_PxBase__1setBaseFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxBase* self = (physx::PxBase*) _address;
    self->setBaseFlag((PxBaseFlagEnum) flag, value);
}
JNIEXPORT void JNICALL Java_physx_common_PxBase__1setBaseFlags(JNIEnv*, jclass, jlong _address, jlong inFlags) {
    physx::PxBase* self = (physx::PxBase*) _address;
    self->setBaseFlags(*((physx::PxBaseFlags*) inFlags));
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBase__1getBaseFlags(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxBaseFlags _cache;
    physx::PxBase* self = (physx::PxBase*) _address;
    _cache = self->getBaseFlags();
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBase__1isReleasable(JNIEnv*, jclass, jlong _address) {
    physx::PxBase* self = (physx::PxBase*) _address;
    return (jboolean) self->isReleasable();
}

// PxBaseFlags
JNIEXPORT jint JNICALL Java_physx_common_PxBaseFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxBaseFlags);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBaseFlags__1_1placement_1new_1PxBaseFlags(JNIEnv*, jclass, jlong _placement_address, jshort flags) {
    return (jlong) new((void*)_placement_address) physx::PxBaseFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBaseFlags__1PxBaseFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxBaseFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBaseFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxBaseFlags* self = (physx::PxBaseFlags*) _address;
    return (jboolean) self->isSet((PxBaseFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_common_PxBaseFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxBaseFlags* self = (physx::PxBaseFlags*) _address;
    self->set((PxBaseFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_common_PxBaseFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxBaseFlags* self = (physx::PxBaseFlags*) _address;
    self->clear((PxBaseFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_common_PxBaseFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBaseFlags*) _address;
}

// PxBaseTask
JNIEXPORT void JNICALL Java_physx_common_PxBaseTask__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBaseTask*) _address;
}

// PxBoundedData
JNIEXPORT jint JNICALL Java_physx_common_PxBoundedData__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxBoundedData);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBoundedData__1_1placement_1new_1PxBoundedData(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxBoundedData();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBoundedData__1PxBoundedData(JNIEnv*, jclass) {
    return (jlong) new physx::PxBoundedData();
}
JNIEXPORT void JNICALL Java_physx_common_PxBoundedData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBoundedData*) _address;
}
JNIEXPORT jint JNICALL Java_physx_common_PxBoundedData__1getCount(JNIEnv*, jclass, jlong _address) {
    physx::PxBoundedData* _self = (physx::PxBoundedData*) _address;
    return (jint) _self->count;
}
JNIEXPORT void JNICALL Java_physx_common_PxBoundedData__1setCount(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxBoundedData* _self = (physx::PxBoundedData*) _address;
    _self->count = value;
}
JNIEXPORT jint JNICALL Java_physx_common_PxBoundedData__1getStride(JNIEnv*, jclass, jlong _address) {
    physx::PxBoundedData* _self = (physx::PxBoundedData*) _address;
    return (jint) _self->stride;
}
JNIEXPORT void JNICALL Java_physx_common_PxBoundedData__1setStride(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxBoundedData* _self = (physx::PxBoundedData*) _address;
    _self->stride = value;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBoundedData__1getData(JNIEnv*, jclass, jlong _address) {
    physx::PxBoundedData* _self = (physx::PxBoundedData*) _address;
    return (jlong) _self->data;
}
JNIEXPORT void JNICALL Java_physx_common_PxBoundedData__1setData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBoundedData* _self = (physx::PxBoundedData*) _address;
    _self->data = (void*) value;
}

// PxBounds3
JNIEXPORT jint JNICALL Java_physx_common_PxBounds3__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxBounds3);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1_1placement_1new_1PxBounds3__J(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxBounds3();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1_1placement_1new_1PxBounds3__JJJ(JNIEnv*, jclass, jlong _placement_address, jlong minimum, jlong maximum) {
    return (jlong) new((void*)_placement_address) physx::PxBounds3(*((physx::PxVec3*) minimum), *((physx::PxVec3*) maximum));
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1PxBounds3__(JNIEnv*, jclass) {
    return (jlong) new physx::PxBounds3();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1PxBounds3__JJ(JNIEnv*, jclass, jlong minimum, jlong maximum) {
    return (jlong) new physx::PxBounds3(*((physx::PxVec3*) minimum), *((physx::PxVec3*) maximum));
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1setEmpty(JNIEnv*, jclass, jlong _address) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    self->setEmpty();
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1setMaximal(JNIEnv*, jclass, jlong _address) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    self->setMaximal();
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1include(JNIEnv*, jclass, jlong _address, jlong v) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    self->include(*((physx::PxVec3*) v));
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBounds3__1isEmpty(JNIEnv*, jclass, jlong _address) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    return (jboolean) self->isEmpty();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBounds3__1intersects(JNIEnv*, jclass, jlong _address, jlong b) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    return (jboolean) self->intersects(*((physx::PxBounds3*) b));
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBounds3__1intersects1D(JNIEnv*, jclass, jlong _address, jlong b, jint axis) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    return (jboolean) self->intersects1D(*((physx::PxBounds3*) b), axis);
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBounds3__1contains(JNIEnv*, jclass, jlong _address, jlong v) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    return (jboolean) self->contains(*((physx::PxVec3*) v));
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBounds3__1isInside(JNIEnv*, jclass, jlong _address, jlong box) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    return (jboolean) self->isInside(*((physx::PxBounds3*) box));
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1getCenter(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxVec3 _cache;
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    _cache = self->getCenter();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1getDimensions(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxVec3 _cache;
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    _cache = self->getDimensions();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1getExtents(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxVec3 _cache;
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    _cache = self->getExtents();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1scaleSafe(JNIEnv*, jclass, jlong _address, jfloat scale) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    self->scaleSafe(scale);
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1scaleFast(JNIEnv*, jclass, jlong _address, jfloat scale) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    self->scaleFast(scale);
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1fattenSafe(JNIEnv*, jclass, jlong _address, jfloat distance) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    self->fattenSafe(distance);
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1fattenFast(JNIEnv*, jclass, jlong _address, jfloat distance) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    self->fattenFast(distance);
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBounds3__1isFinite(JNIEnv*, jclass, jlong _address) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    return (jboolean) self->isFinite();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBounds3__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxBounds3* self = (physx::PxBounds3*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBounds3*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1getMinimum(JNIEnv*, jclass, jlong _address) {
    physx::PxBounds3* _self = (physx::PxBounds3*) _address;
    return (jlong) &_self->minimum;
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1setMinimum(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBounds3* _self = (physx::PxBounds3*) _address;
    _self->minimum = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1getMaximum(JNIEnv*, jclass, jlong _address) {
    physx::PxBounds3* _self = (physx::PxBounds3*) _address;
    return (jlong) &_self->maximum;
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1setMaximum(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBounds3* _self = (physx::PxBounds3*) _address;
    _self->maximum = *((physx::PxVec3*) value);
}

// PxCpuDispatcher
JNIEXPORT void JNICALL Java_physx_common_PxCpuDispatcher__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxCpuDispatcher*) _address;
}

// PxCudaContextManager

// PxDefaultErrorCallback
JNIEXPORT jlong JNICALL Java_physx_common_PxDefaultErrorCallback__1PxDefaultErrorCallback(JNIEnv*, jclass) {
    return (jlong) new physx::PxDefaultErrorCallback();
}
JNIEXPORT void JNICALL Java_physx_common_PxDefaultErrorCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxDefaultErrorCallback*) _address;
}

// PxErrorCallback
JNIEXPORT void JNICALL Java_physx_common_PxErrorCallback__1reportError(JNIEnv* _env, jclass, jlong _address, jint code, jstring message, jstring file, jint line) {
    physx::PxErrorCallback* self = (physx::PxErrorCallback*) _address;
    self->reportError((PxErrorCodeEnum) code, _env->GetStringUTFChars(message, 0), _env->GetStringUTFChars(file, 0), line);
}
JNIEXPORT void JNICALL Java_physx_common_PxErrorCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxErrorCallback*) _address;
}

// JavaErrorCallback
JNIEXPORT jlong JNICALL Java_physx_common_JavaErrorCallback__1JavaErrorCallback(JNIEnv* env, jobject obj) {
    return (jlong) new JavaErrorCallback(env, obj);
}
JNIEXPORT void JNICALL Java_physx_common_JavaErrorCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (JavaErrorCallback*) address;
}

// PxFoundation
JNIEXPORT void JNICALL Java_physx_common_PxFoundation__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxFoundation* self = (physx::PxFoundation*) _address;
    self->release();
}

// PxPhysicsInsertionCallback

// PxQuat
JNIEXPORT jint JNICALL Java_physx_common_PxQuat__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxQuat);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxQuat__1_1placement_1new_1PxQuat__J(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxQuat();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxQuat__1_1placement_1new_1PxQuat__JFFFF(JNIEnv*, jclass, jlong _placement_address, jfloat x, jfloat y, jfloat z, jfloat w) {
    return (jlong) new((void*)_placement_address) physx::PxQuat(x, y, z, w);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxQuat__1PxQuat__(JNIEnv*, jclass) {
    return (jlong) new physx::PxQuat();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxQuat__1PxQuat__FFFF(JNIEnv*, jclass, jfloat x, jfloat y, jfloat z, jfloat w) {
    return (jlong) new physx::PxQuat(x, y, z, w);
}
JNIEXPORT void JNICALL Java_physx_common_PxQuat__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxQuat*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxQuat__1getX(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* _self = (physx::PxQuat*) _address;
    return (jfloat) _self->x;
}
JNIEXPORT void JNICALL Java_physx_common_PxQuat__1setX(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxQuat* _self = (physx::PxQuat*) _address;
    _self->x = value;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxQuat__1getY(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* _self = (physx::PxQuat*) _address;
    return (jfloat) _self->y;
}
JNIEXPORT void JNICALL Java_physx_common_PxQuat__1setY(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxQuat* _self = (physx::PxQuat*) _address;
    _self->y = value;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxQuat__1getZ(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* _self = (physx::PxQuat*) _address;
    return (jfloat) _self->z;
}
JNIEXPORT void JNICALL Java_physx_common_PxQuat__1setZ(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxQuat* _self = (physx::PxQuat*) _address;
    _self->z = value;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxQuat__1getW(JNIEnv*, jclass, jlong _address) {
    physx::PxQuat* _self = (physx::PxQuat*) _address;
    return (jfloat) _self->w;
}
JNIEXPORT void JNICALL Java_physx_common_PxQuat__1setW(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxQuat* _self = (physx::PxQuat*) _address;
    _self->w = value;
}

// PxTolerancesScale
JNIEXPORT jlong JNICALL Java_physx_common_PxTolerancesScale__1PxTolerancesScale(JNIEnv*, jclass) {
    return (jlong) new physx::PxTolerancesScale();
}
JNIEXPORT void JNICALL Java_physx_common_PxTolerancesScale__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxTolerancesScale*) _address;
}

// PxTransform
JNIEXPORT jint JNICALL Java_physx_common_PxTransform__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxTransform);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxTransform__1_1placement_1new_1PxTransform__JI(JNIEnv*, jclass, jlong _placement_address, jint r) {
    return (jlong) new((void*)_placement_address) physx::PxTransform((PxIDENTITYEnum) r);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxTransform__1_1placement_1new_1PxTransform__JJJ(JNIEnv*, jclass, jlong _placement_address, jlong p0, jlong q0) {
    return (jlong) new((void*)_placement_address) physx::PxTransform(*((physx::PxVec3*) p0), *((physx::PxQuat*) q0));
}
JNIEXPORT jlong JNICALL Java_physx_common_PxTransform__1PxTransform__I(JNIEnv*, jclass, jint r) {
    return (jlong) new physx::PxTransform((PxIDENTITYEnum) r);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxTransform__1PxTransform__JJ(JNIEnv*, jclass, jlong p0, jlong q0) {
    return (jlong) new physx::PxTransform(*((physx::PxVec3*) p0), *((physx::PxQuat*) q0));
}
JNIEXPORT void JNICALL Java_physx_common_PxTransform__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxTransform*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxTransform__1getQ(JNIEnv*, jclass, jlong _address) {
    physx::PxTransform* _self = (physx::PxTransform*) _address;
    return (jlong) &_self->q;
}
JNIEXPORT void JNICALL Java_physx_common_PxTransform__1setQ(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxTransform* _self = (physx::PxTransform*) _address;
    _self->q = *((physx::PxQuat*) value);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxTransform__1getP(JNIEnv*, jclass, jlong _address) {
    physx::PxTransform* _self = (physx::PxTransform*) _address;
    return (jlong) &_self->p;
}
JNIEXPORT void JNICALL Java_physx_common_PxTransform__1setP(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxTransform* _self = (physx::PxTransform*) _address;
    _self->p = *((physx::PxVec3*) value);
}

// PxStridedData
JNIEXPORT void JNICALL Java_physx_common_PxStridedData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxStridedData*) _address;
}
JNIEXPORT jint JNICALL Java_physx_common_PxStridedData__1getStride(JNIEnv*, jclass, jlong _address) {
    physx::PxStridedData* _self = (physx::PxStridedData*) _address;
    return (jint) _self->stride;
}
JNIEXPORT void JNICALL Java_physx_common_PxStridedData__1setStride(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxStridedData* _self = (physx::PxStridedData*) _address;
    _self->stride = value;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxStridedData__1getData(JNIEnv*, jclass, jlong _address) {
    physx::PxStridedData* _self = (physx::PxStridedData*) _address;
    return (jlong) _self->data;
}
JNIEXPORT void JNICALL Java_physx_common_PxStridedData__1setData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxStridedData* _self = (physx::PxStridedData*) _address;
    _self->data = (void*) value;
}

// PxU16StridedData
JNIEXPORT void JNICALL Java_physx_common_PxU16StridedData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxU16StridedData*) _address;
}
JNIEXPORT jint JNICALL Java_physx_common_PxU16StridedData__1getStride(JNIEnv*, jclass, jlong _address) {
    PxU16StridedData* _self = (PxU16StridedData*) _address;
    return (jint) _self->stride;
}
JNIEXPORT void JNICALL Java_physx_common_PxU16StridedData__1setStride(JNIEnv*, jclass, jlong _address, jint value) {
    PxU16StridedData* _self = (PxU16StridedData*) _address;
    _self->stride = value;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxU16StridedData__1getData(JNIEnv*, jclass, jlong _address) {
    PxU16StridedData* _self = (PxU16StridedData*) _address;
    return (jlong) &_self->data;
}
JNIEXPORT void JNICALL Java_physx_common_PxU16StridedData__1setData(JNIEnv*, jclass, jlong _address, jlong value) {
    PxU16StridedData* _self = (PxU16StridedData*) _address;
    _self->data = *((PxU16ConstPtr*) value);
}

// PxVec3
JNIEXPORT jint JNICALL Java_physx_common_PxVec3__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxVec3);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxVec3__1_1placement_1new_1PxVec3__J(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxVec3();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxVec3__1_1placement_1new_1PxVec3__JFFF(JNIEnv*, jclass, jlong _placement_address, jfloat x, jfloat y, jfloat z) {
    return (jlong) new((void*)_placement_address) physx::PxVec3(x, y, z);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxVec3__1PxVec3__(JNIEnv*, jclass) {
    return (jlong) new physx::PxVec3();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxVec3__1PxVec3__FFF(JNIEnv*, jclass, jfloat x, jfloat y, jfloat z) {
    return (jlong) new physx::PxVec3(x, y, z);
}
JNIEXPORT void JNICALL Java_physx_common_PxVec3__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVec3*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxVec3__1getX(JNIEnv*, jclass, jlong _address) {
    physx::PxVec3* _self = (physx::PxVec3*) _address;
    return (jfloat) _self->x;
}
JNIEXPORT void JNICALL Java_physx_common_PxVec3__1setX(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVec3* _self = (physx::PxVec3*) _address;
    _self->x = value;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxVec3__1getY(JNIEnv*, jclass, jlong _address) {
    physx::PxVec3* _self = (physx::PxVec3*) _address;
    return (jfloat) _self->y;
}
JNIEXPORT void JNICALL Java_physx_common_PxVec3__1setY(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVec3* _self = (physx::PxVec3*) _address;
    _self->y = value;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxVec3__1getZ(JNIEnv*, jclass, jlong _address) {
    physx::PxVec3* _self = (physx::PxVec3*) _address;
    return (jfloat) _self->z;
}
JNIEXPORT void JNICALL Java_physx_common_PxVec3__1setZ(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVec3* _self = (physx::PxVec3*) _address;
    _self->z = value;
}

// PxBaseFlagEnum
JNIEXPORT jint JNICALL Java_physx_common_PxBaseFlagEnum__1geteOWNS_1MEMORY(JNIEnv*, jclass) {
    return PxBaseFlagEnum::eOWNS_MEMORY;
}
JNIEXPORT jint JNICALL Java_physx_common_PxBaseFlagEnum__1geteIS_1RELEASABLE(JNIEnv*, jclass) {
    return PxBaseFlagEnum::eIS_RELEASABLE;
}

// PxErrorCodeEnum
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCodeEnum__1geteNO_1ERROR(JNIEnv*, jclass) {
    return PxErrorCodeEnum::eNO_ERROR;
}
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCodeEnum__1geteDEBUG_1INFO(JNIEnv*, jclass) {
    return PxErrorCodeEnum::eDEBUG_INFO;
}
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCodeEnum__1geteDEBUG_1WARNING(JNIEnv*, jclass) {
    return PxErrorCodeEnum::eDEBUG_WARNING;
}
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCodeEnum__1geteINVALID_1PARAMETER(JNIEnv*, jclass) {
    return PxErrorCodeEnum::eINVALID_PARAMETER;
}
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCodeEnum__1geteINVALID_1OPERATION(JNIEnv*, jclass) {
    return PxErrorCodeEnum::eINVALID_OPERATION;
}
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCodeEnum__1geteOUT_1OF_1MEMORY(JNIEnv*, jclass) {
    return PxErrorCodeEnum::eOUT_OF_MEMORY;
}
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCodeEnum__1geteINTERNAL_1ERROR(JNIEnv*, jclass) {
    return PxErrorCodeEnum::eINTERNAL_ERROR;
}
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCodeEnum__1geteABORT(JNIEnv*, jclass) {
    return PxErrorCodeEnum::eABORT;
}
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCodeEnum__1getePERF_1WARNING(JNIEnv*, jclass) {
    return PxErrorCodeEnum::ePERF_WARNING;
}
JNIEXPORT jint JNICALL Java_physx_common_PxErrorCodeEnum__1geteMASK_1ALL(JNIEnv*, jclass) {
    return PxErrorCodeEnum::eMASK_ALL;
}

// PxIDENTITYEnum
JNIEXPORT jint JNICALL Java_physx_common_PxIDENTITYEnum__1getPxIdentity(JNIEnv*, jclass) {
    return PxIDENTITYEnum::PxIdentity;
}

// PxBVH33MidphaseDesc
JNIEXPORT void JNICALL Java_physx_cooking_PxBVH33MidphaseDesc__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::PxBVH33MidphaseDesc* self = (physx::PxBVH33MidphaseDesc*) _address;
    self->setToDefault();
}
JNIEXPORT jboolean JNICALL Java_physx_cooking_PxBVH33MidphaseDesc__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxBVH33MidphaseDesc* self = (physx::PxBVH33MidphaseDesc*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_cooking_PxBVH33MidphaseDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBVH33MidphaseDesc*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_cooking_PxBVH33MidphaseDesc__1getMeshSizePerformanceTradeOff(JNIEnv*, jclass, jlong _address) {
    physx::PxBVH33MidphaseDesc* _self = (physx::PxBVH33MidphaseDesc*) _address;
    return (jfloat) _self->meshSizePerformanceTradeOff;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxBVH33MidphaseDesc__1setMeshSizePerformanceTradeOff(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxBVH33MidphaseDesc* _self = (physx::PxBVH33MidphaseDesc*) _address;
    _self->meshSizePerformanceTradeOff = value;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxBVH33MidphaseDesc__1getMeshCookingHint(JNIEnv*, jclass, jlong _address) {
    physx::PxBVH33MidphaseDesc* _self = (physx::PxBVH33MidphaseDesc*) _address;
    return (jint) _self->meshCookingHint;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxBVH33MidphaseDesc__1setMeshCookingHint(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxBVH33MidphaseDesc* _self = (physx::PxBVH33MidphaseDesc*) _address;
    _self->meshCookingHint = (PxMeshCookingHintEnum) value;
}

// PxBVH34MidphaseDesc
JNIEXPORT void JNICALL Java_physx_cooking_PxBVH34MidphaseDesc__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::PxBVH34MidphaseDesc* self = (physx::PxBVH34MidphaseDesc*) _address;
    self->setToDefault();
}
JNIEXPORT jboolean JNICALL Java_physx_cooking_PxBVH34MidphaseDesc__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxBVH34MidphaseDesc* self = (physx::PxBVH34MidphaseDesc*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_cooking_PxBVH34MidphaseDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBVH34MidphaseDesc*) _address;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxBVH34MidphaseDesc__1getNumPrimsPerLeaf(JNIEnv*, jclass, jlong _address) {
    physx::PxBVH34MidphaseDesc* _self = (physx::PxBVH34MidphaseDesc*) _address;
    return (jint) _self->numPrimsPerLeaf;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxBVH34MidphaseDesc__1setNumPrimsPerLeaf(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxBVH34MidphaseDesc* _self = (physx::PxBVH34MidphaseDesc*) _address;
    _self->numPrimsPerLeaf = value;
}

// PxConvexFlags
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxConvexFlags);
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxConvexFlags__1_1placement_1new_1PxConvexFlags(JNIEnv*, jclass, jlong _placement_address, jshort flags) {
    return (jlong) new((void*)_placement_address) physx::PxConvexFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxConvexFlags__1PxConvexFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxConvexFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_cooking_PxConvexFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxConvexFlags* self = (physx::PxConvexFlags*) _address;
    return (jboolean) self->isSet((PxConvexFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_cooking_PxConvexFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxConvexFlags* self = (physx::PxConvexFlags*) _address;
    self->set((PxConvexFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_cooking_PxConvexFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxConvexFlags* self = (physx::PxConvexFlags*) _address;
    self->clear((PxConvexFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_cooking_PxConvexFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxConvexFlags*) _address;
}

// PxConvexMeshDesc
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexMeshDesc__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxConvexMeshDesc);
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxConvexMeshDesc__1_1placement_1new_1PxConvexMeshDesc(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxConvexMeshDesc();
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxConvexMeshDesc__1PxConvexMeshDesc(JNIEnv*, jclass) {
    return (jlong) new physx::PxConvexMeshDesc();
}
JNIEXPORT void JNICALL Java_physx_cooking_PxConvexMeshDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxConvexMeshDesc*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxConvexMeshDesc__1getPoints(JNIEnv*, jclass, jlong _address) {
    physx::PxConvexMeshDesc* _self = (physx::PxConvexMeshDesc*) _address;
    return (jlong) &_self->points;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxConvexMeshDesc__1setPoints(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxConvexMeshDesc* _self = (physx::PxConvexMeshDesc*) _address;
    _self->points = *((physx::PxBoundedData*) value);
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxConvexMeshDesc__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxConvexMeshDesc* _self = (physx::PxConvexMeshDesc*) _address;
    return (jlong) &_self->flags;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxConvexMeshDesc__1setFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxConvexMeshDesc* _self = (physx::PxConvexMeshDesc*) _address;
    _self->flags = *((physx::PxConvexFlags*) value);
}

// PxCooking
JNIEXPORT void JNICALL Java_physx_cooking_PxCooking__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxCooking* self = (physx::PxCooking*) _address;
    self->release();
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxCooking__1createConvexMesh(JNIEnv*, jclass, jlong _address, jlong desc, jlong insertionCallback) {
    physx::PxCooking* self = (physx::PxCooking*) _address;
    return (jlong) self->createConvexMesh(*((physx::PxConvexMeshDesc*) desc), *((physx::PxPhysicsInsertionCallback*) insertionCallback));
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxCooking__1createTriangleMesh(JNIEnv*, jclass, jlong _address, jlong desc, jlong insertionCallback) {
    physx::PxCooking* self = (physx::PxCooking*) _address;
    return (jlong) self->createTriangleMesh(*((physx::PxTriangleMeshDesc*) desc), *((physx::PxPhysicsInsertionCallback*) insertionCallback));
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxCooking__1createHeightField(JNIEnv*, jclass, jlong _address, jlong desc, jlong insertionCallback) {
    physx::PxCooking* self = (physx::PxCooking*) _address;
    return (jlong) self->createHeightField(*((physx::PxHeightFieldDesc*) desc), *((physx::PxPhysicsInsertionCallback*) insertionCallback));
}

// PxCookingParams
JNIEXPORT jlong JNICALL Java_physx_cooking_PxCookingParams__1PxCookingParams(JNIEnv*, jclass, jlong sc) {
    return (jlong) new physx::PxCookingParams(*((physx::PxTolerancesScale*) sc));
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxCookingParams*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_cooking_PxCookingParams__1getAreaTestEpsilon(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jfloat) _self->areaTestEpsilon;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setAreaTestEpsilon(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->areaTestEpsilon = value;
}
JNIEXPORT jfloat JNICALL Java_physx_cooking_PxCookingParams__1getPlaneTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jfloat) _self->planeTolerance;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setPlaneTolerance(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->planeTolerance = value;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxCookingParams__1getConvexMeshCookingType(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jint) _self->convexMeshCookingType;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setConvexMeshCookingType(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->convexMeshCookingType = (PxConvexMeshCookingTypeEnum) value;
}
JNIEXPORT jboolean JNICALL Java_physx_cooking_PxCookingParams__1getSuppressTriangleMeshRemapTable(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jboolean) _self->suppressTriangleMeshRemapTable;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setSuppressTriangleMeshRemapTable(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->suppressTriangleMeshRemapTable = value;
}
JNIEXPORT jboolean JNICALL Java_physx_cooking_PxCookingParams__1getBuildTriangleAdjacencies(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jboolean) _self->buildTriangleAdjacencies;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setBuildTriangleAdjacencies(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->buildTriangleAdjacencies = value;
}
JNIEXPORT jboolean JNICALL Java_physx_cooking_PxCookingParams__1getBuildGPUData(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jboolean) _self->buildGPUData;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setBuildGPUData(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->buildGPUData = value;
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxCookingParams__1getScale(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jlong) &_self->scale;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setScale(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->scale = *((physx::PxTolerancesScale*) value);
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxCookingParams__1getMeshPreprocessParams(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jlong) &_self->meshPreprocessParams;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setMeshPreprocessParams(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->meshPreprocessParams = *((physx::PxMeshPreprocessingFlags*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_cooking_PxCookingParams__1getMeshWeldTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jfloat) _self->meshWeldTolerance;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setMeshWeldTolerance(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->meshWeldTolerance = value;
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxCookingParams__1getMidphaseDesc(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jlong) &_self->midphaseDesc;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setMidphaseDesc(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->midphaseDesc = *((physx::PxMidphaseDesc*) value);
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxCookingParams__1getGaussMapLimit(JNIEnv*, jclass, jlong _address) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    return (jint) _self->gaussMapLimit;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1setGaussMapLimit(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxCookingParams* _self = (physx::PxCookingParams*) _address;
    _self->gaussMapLimit = value;
}

// PxMeshPreprocessingFlags
JNIEXPORT jlong JNICALL Java_physx_cooking_PxMeshPreprocessingFlags__1PxMeshPreprocessingFlags(JNIEnv*, jclass, jint flags) {
    return (jlong) new physx::PxMeshPreprocessingFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_cooking_PxMeshPreprocessingFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxMeshPreprocessingFlags* self = (physx::PxMeshPreprocessingFlags*) _address;
    return (jboolean) self->isSet((PxMeshPreprocessingFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_cooking_PxMeshPreprocessingFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxMeshPreprocessingFlags* self = (physx::PxMeshPreprocessingFlags*) _address;
    self->set((PxMeshPreprocessingFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_cooking_PxMeshPreprocessingFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxMeshPreprocessingFlags* self = (physx::PxMeshPreprocessingFlags*) _address;
    self->clear((PxMeshPreprocessingFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_cooking_PxMeshPreprocessingFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxMeshPreprocessingFlags*) _address;
}

// PxMidphaseDesc
JNIEXPORT jlong JNICALL Java_physx_cooking_PxMidphaseDesc__1PxMidphaseDesc(JNIEnv*, jclass) {
    return (jlong) new physx::PxMidphaseDesc();
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxMidphaseDesc__1getType(JNIEnv*, jclass, jlong _address) {
    physx::PxMidphaseDesc* self = (physx::PxMidphaseDesc*) _address;
    return (jint) self->getType();
}
JNIEXPORT void JNICALL Java_physx_cooking_PxMidphaseDesc__1setToDefault(JNIEnv*, jclass, jlong _address, jint type) {
    physx::PxMidphaseDesc* self = (physx::PxMidphaseDesc*) _address;
    self->setToDefault((PxMeshMidPhaseEnum) type);
}
JNIEXPORT jboolean JNICALL Java_physx_cooking_PxMidphaseDesc__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxMidphaseDesc* self = (physx::PxMidphaseDesc*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_cooking_PxMidphaseDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxMidphaseDesc*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxMidphaseDesc__1getMBVH33Desc(JNIEnv*, jclass, jlong _address) {
    physx::PxMidphaseDesc* _self = (physx::PxMidphaseDesc*) _address;
    return (jlong) &_self->mBVH33Desc;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxMidphaseDesc__1setMBVH33Desc(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxMidphaseDesc* _self = (physx::PxMidphaseDesc*) _address;
    _self->mBVH33Desc = *((physx::PxBVH33MidphaseDesc*) value);
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxMidphaseDesc__1getMBVH34Desc(JNIEnv*, jclass, jlong _address) {
    physx::PxMidphaseDesc* _self = (physx::PxMidphaseDesc*) _address;
    return (jlong) &_self->mBVH34Desc;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxMidphaseDesc__1setMBVH34Desc(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxMidphaseDesc* _self = (physx::PxMidphaseDesc*) _address;
    _self->mBVH34Desc = *((physx::PxBVH34MidphaseDesc*) value);
}

// PxTriangleMeshDesc
JNIEXPORT jint JNICALL Java_physx_cooking_PxTriangleMeshDesc__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxTriangleMeshDesc);
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxTriangleMeshDesc__1_1placement_1new_1PxTriangleMeshDesc(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxTriangleMeshDesc();
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxTriangleMeshDesc__1PxTriangleMeshDesc(JNIEnv*, jclass) {
    return (jlong) new physx::PxTriangleMeshDesc();
}
JNIEXPORT void JNICALL Java_physx_cooking_PxTriangleMeshDesc__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMeshDesc* self = (physx::PxTriangleMeshDesc*) _address;
    self->setToDefault();
}
JNIEXPORT jboolean JNICALL Java_physx_cooking_PxTriangleMeshDesc__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMeshDesc* self = (physx::PxTriangleMeshDesc*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_cooking_PxTriangleMeshDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxTriangleMeshDesc*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxTriangleMeshDesc__1getMaterialIndices(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMeshDesc* _self = (physx::PxTriangleMeshDesc*) _address;
    return (jlong) &_self->materialIndices;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxTriangleMeshDesc__1setMaterialIndices(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxTriangleMeshDesc* _self = (physx::PxTriangleMeshDesc*) _address;
    _self->materialIndices = *((PxU16StridedData*) value);
}

// PxConvexFlagEnum
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexFlagEnum__1gete16_1BIT_1INDICES(JNIEnv*, jclass) {
    return PxConvexFlagEnum::e16_BIT_INDICES;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexFlagEnum__1geteCOMPUTE_1CONVEX(JNIEnv*, jclass) {
    return PxConvexFlagEnum::eCOMPUTE_CONVEX;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexFlagEnum__1geteCHECK_1ZERO_1AREA_1TRIANGLES(JNIEnv*, jclass) {
    return PxConvexFlagEnum::eCHECK_ZERO_AREA_TRIANGLES;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexFlagEnum__1geteQUANTIZE_1INPUT(JNIEnv*, jclass) {
    return PxConvexFlagEnum::eQUANTIZE_INPUT;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexFlagEnum__1geteDISABLE_1MESH_1VALIDATION(JNIEnv*, jclass) {
    return PxConvexFlagEnum::eDISABLE_MESH_VALIDATION;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexFlagEnum__1getePLANE_1SHIFTING(JNIEnv*, jclass) {
    return PxConvexFlagEnum::ePLANE_SHIFTING;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexFlagEnum__1geteFAST_1INERTIA_1COMPUTATION(JNIEnv*, jclass) {
    return PxConvexFlagEnum::eFAST_INERTIA_COMPUTATION;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexFlagEnum__1geteGPU_1COMPATIBLE(JNIEnv*, jclass) {
    return PxConvexFlagEnum::eGPU_COMPATIBLE;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexFlagEnum__1geteSHIFT_1VERTICES(JNIEnv*, jclass) {
    return PxConvexFlagEnum::eSHIFT_VERTICES;
}

// PxConvexMeshCookingTypeEnum
JNIEXPORT jint JNICALL Java_physx_cooking_PxConvexMeshCookingTypeEnum__1geteQUICKHULL(JNIEnv*, jclass) {
    return PxConvexMeshCookingTypeEnum::eQUICKHULL;
}

// PxMeshCookingHintEnum
JNIEXPORT jint JNICALL Java_physx_cooking_PxMeshCookingHintEnum__1geteSIM_1PERFORMANCE(JNIEnv*, jclass) {
    return PxMeshCookingHintEnum::eSIM_PERFORMANCE;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxMeshCookingHintEnum__1geteCOOKING_1PERFORMANCE(JNIEnv*, jclass) {
    return PxMeshCookingHintEnum::eCOOKING_PERFORMANCE;
}

// PxMeshPreprocessingFlagEnum
JNIEXPORT jint JNICALL Java_physx_cooking_PxMeshPreprocessingFlagEnum__1geteWELD_1VERTICES(JNIEnv*, jclass) {
    return PxMeshPreprocessingFlagEnum::eWELD_VERTICES;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxMeshPreprocessingFlagEnum__1geteDISABLE_1CLEAN_1MESH(JNIEnv*, jclass) {
    return PxMeshPreprocessingFlagEnum::eDISABLE_CLEAN_MESH;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxMeshPreprocessingFlagEnum__1geteDISABLE_1ACTIVE_1EDGES_1PRECOMPUTE(JNIEnv*, jclass) {
    return PxMeshPreprocessingFlagEnum::eDISABLE_ACTIVE_EDGES_PRECOMPUTE;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxMeshPreprocessingFlagEnum__1geteFORCE_132BIT_1INDICES(JNIEnv*, jclass) {
    return PxMeshPreprocessingFlagEnum::eFORCE_32BIT_INDICES;
}

// PxMeshMidPhaseEnum
JNIEXPORT jint JNICALL Java_physx_cooking_PxMeshMidPhaseEnum__1geteBVH33(JNIEnv*, jclass) {
    return PxMeshMidPhaseEnum::eBVH33;
}
JNIEXPORT jint JNICALL Java_physx_cooking_PxMeshMidPhaseEnum__1geteBVH34(JNIEnv*, jclass) {
    return PxMeshMidPhaseEnum::eBVH34;
}

// PxD6Joint
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setMotion(JNIEnv*, jclass, jlong _address, jint axis, jint type) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setMotion((PxD6AxisEnum) axis, (PxD6MotionEnum) type);
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6Joint__1getMotion(JNIEnv*, jclass, jlong _address, jint axis) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    return (jint) self->getMotion((PxD6AxisEnum) axis);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxD6Joint__1getTwistAngle(JNIEnv*, jclass, jlong _address) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    return (jfloat) self->getTwistAngle();
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxD6Joint__1getSwingYAngle(JNIEnv*, jclass, jlong _address) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    return (jfloat) self->getSwingYAngle();
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxD6Joint__1getSwingZAngle(JNIEnv*, jclass, jlong _address) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    return (jfloat) self->getSwingZAngle();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setDistanceLimit(JNIEnv*, jclass, jlong _address, jlong limit) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setDistanceLimit(*((physx::PxJointLinearLimit*) limit));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setLinearLimit(JNIEnv*, jclass, jlong _address, jint axis, jlong limit) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setLinearLimit((PxD6AxisEnum) axis, *((physx::PxJointLinearLimitPair*) limit));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setTwistLimit(JNIEnv*, jclass, jlong _address, jlong limit) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setTwistLimit(*((physx::PxJointAngularLimitPair*) limit));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setSwingLimit(JNIEnv*, jclass, jlong _address, jlong limit) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setSwingLimit(*((physx::PxJointLimitCone*) limit));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setPyramidSwingLimit(JNIEnv*, jclass, jlong _address, jlong limit) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setPyramidSwingLimit(*((physx::PxJointLimitPyramid*) limit));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setDrive(JNIEnv*, jclass, jlong _address, jint index, jlong drive) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setDrive((PxD6DriveEnum) index, *((physx::PxD6JointDrive*) drive));
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxD6Joint__1getDrive(JNIEnv*, jclass, jlong _address, jint index) {
    static thread_local physx::PxD6JointDrive _cache;
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    _cache = self->getDrive((PxD6DriveEnum) index);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setDrivePosition__JJ(JNIEnv*, jclass, jlong _address, jlong pose) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setDrivePosition(*((physx::PxTransform*) pose));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setDrivePosition__JJZ(JNIEnv*, jclass, jlong _address, jlong pose, jboolean autowake) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setDrivePosition(*((physx::PxTransform*) pose), autowake);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxD6Joint__1getDrivePosition(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxTransform _cache;
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    _cache = self->getDrivePosition();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setDriveVelocity(JNIEnv*, jclass, jlong _address, jlong linear, jlong angular) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setDriveVelocity(*((physx::PxVec3*) linear), *((physx::PxVec3*) angular));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1getDriveVelocity(JNIEnv*, jclass, jlong _address, jlong linear, jlong angular) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->getDriveVelocity(*((physx::PxVec3*) linear), *((physx::PxVec3*) angular));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setProjectionLinearTolerance(JNIEnv*, jclass, jlong _address, jfloat tolerance) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setProjectionLinearTolerance(tolerance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxD6Joint__1getProjectionLinearTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    return (jfloat) self->getProjectionLinearTolerance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1setProjectionAngularTolerance(JNIEnv*, jclass, jlong _address, jfloat tolerance) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    self->setProjectionAngularTolerance(tolerance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxD6Joint__1getProjectionAngularTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxD6Joint* self = (physx::PxD6Joint*) _address;
    return (jfloat) self->getProjectionAngularTolerance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6Joint__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxD6Joint*) _address;
}

// PxD6JointDrive
JNIEXPORT jlong JNICALL Java_physx_extensions_PxD6JointDrive__1PxD6JointDrive__(JNIEnv*, jclass) {
    return (jlong) new physx::PxD6JointDrive();
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxD6JointDrive__1PxD6JointDrive__FFF(JNIEnv*, jclass, jfloat driveStiffness, jfloat driveDamping, jfloat driveForceLimit) {
    return (jlong) new physx::PxD6JointDrive(driveStiffness, driveDamping, driveForceLimit);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxD6JointDrive__1PxD6JointDrive__FFFZ(JNIEnv*, jclass, jfloat driveStiffness, jfloat driveDamping, jfloat driveForceLimit, jboolean isAcceleration) {
    return (jlong) new physx::PxD6JointDrive(driveStiffness, driveDamping, driveForceLimit, isAcceleration);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6JointDrive__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxD6JointDrive*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxD6JointDrive__1getForceLimit(JNIEnv*, jclass, jlong _address) {
    physx::PxD6JointDrive* _self = (physx::PxD6JointDrive*) _address;
    return (jfloat) _self->forceLimit;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6JointDrive__1setForceLimit(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxD6JointDrive* _self = (physx::PxD6JointDrive*) _address;
    _self->forceLimit = value;
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxD6JointDrive__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxD6JointDrive* _self = (physx::PxD6JointDrive*) _address;
    return (jlong) &_self->flags;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6JointDrive__1setFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxD6JointDrive* _self = (physx::PxD6JointDrive*) _address;
    _self->flags = *((physx::PxD6JointDriveFlags*) value);
}

// PxD6JointDriveFlags
JNIEXPORT jlong JNICALL Java_physx_extensions_PxD6JointDriveFlags__1PxD6JointDriveFlags(JNIEnv*, jclass, jint flags) {
    return (jlong) new physx::PxD6JointDriveFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxD6JointDriveFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxD6JointDriveFlags* self = (physx::PxD6JointDriveFlags*) _address;
    return (jboolean) self->isSet((PxD6JointDriveFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6JointDriveFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxD6JointDriveFlags* self = (physx::PxD6JointDriveFlags*) _address;
    self->set((PxD6JointDriveFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6JointDriveFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxD6JointDriveFlags* self = (physx::PxD6JointDriveFlags*) _address;
    self->clear((PxD6JointDriveFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxD6JointDriveFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxD6JointDriveFlags*) _address;
}

// PxDefaultAllocator
JNIEXPORT jlong JNICALL Java_physx_extensions_PxDefaultAllocator__1PxDefaultAllocator(JNIEnv*, jclass) {
    return (jlong) new physx::PxDefaultAllocator();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDefaultAllocator__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxDefaultAllocator*) _address;
}

// PxDefaultCpuDispatcher
JNIEXPORT void JNICALL Java_physx_extensions_PxDefaultCpuDispatcher__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxDefaultCpuDispatcher*) _address;
}

// PxDistanceJoint
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxDistanceJoint__1getDistance(JNIEnv*, jclass, jlong _address) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    return (jfloat) self->getDistance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJoint__1setMinDistance(JNIEnv*, jclass, jlong _address, jfloat distance) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    self->setMinDistance(distance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxDistanceJoint__1getMinDistance(JNIEnv*, jclass, jlong _address) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    return (jfloat) self->getMinDistance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJoint__1setMaxDistance(JNIEnv*, jclass, jlong _address, jfloat distance) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    self->setMaxDistance(distance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxDistanceJoint__1getMaxDistance(JNIEnv*, jclass, jlong _address) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    return (jfloat) self->getMaxDistance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJoint__1setTolerance(JNIEnv*, jclass, jlong _address, jfloat tolerance) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    self->setTolerance(tolerance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxDistanceJoint__1getTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    return (jfloat) self->getTolerance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJoint__1setStiffness(JNIEnv*, jclass, jlong _address, jfloat stiffness) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    self->setStiffness(stiffness);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxDistanceJoint__1getStiffness(JNIEnv*, jclass, jlong _address) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    return (jfloat) self->getStiffness();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJoint__1setDamping(JNIEnv*, jclass, jlong _address, jfloat damping) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    self->setDamping(damping);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxDistanceJoint__1getDamping(JNIEnv*, jclass, jlong _address) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    return (jfloat) self->getDamping();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJoint__1setDistanceJointFlags(JNIEnv*, jclass, jlong _address, jlong flags) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    self->setDistanceJointFlags(*((physx::PxDistanceJointFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJoint__1setDistanceJointFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    self->setDistanceJointFlag((PxDistanceJointFlagEnum) flag, value);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxDistanceJoint__1getDistanceJointFlags(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxDistanceJointFlags _cache;
    physx::PxDistanceJoint* self = (physx::PxDistanceJoint*) _address;
    _cache = self->getDistanceJointFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJoint__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxDistanceJoint*) _address;
}

// PxDistanceJointFlags
JNIEXPORT jlong JNICALL Java_physx_extensions_PxDistanceJointFlags__1PxDistanceJointFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxDistanceJointFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxDistanceJointFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxDistanceJointFlags* self = (physx::PxDistanceJointFlags*) _address;
    return (jboolean) self->isSet((PxDistanceJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJointFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxDistanceJointFlags* self = (physx::PxDistanceJointFlags*) _address;
    self->set((PxDistanceJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJointFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxDistanceJointFlags* self = (physx::PxDistanceJointFlags*) _address;
    self->clear((PxDistanceJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDistanceJointFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxDistanceJointFlags*) _address;
}

// PxFixedJoint
JNIEXPORT void JNICALL Java_physx_extensions_PxFixedJoint__1setProjectionLinearTolerance(JNIEnv*, jclass, jlong _address, jfloat tolerance) {
    physx::PxFixedJoint* self = (physx::PxFixedJoint*) _address;
    self->setProjectionLinearTolerance(tolerance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxFixedJoint__1getProjectionLinearTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxFixedJoint* self = (physx::PxFixedJoint*) _address;
    return (jfloat) self->getProjectionLinearTolerance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxFixedJoint__1setProjectionAngularTolerance(JNIEnv*, jclass, jlong _address, jfloat tolerance) {
    physx::PxFixedJoint* self = (physx::PxFixedJoint*) _address;
    self->setProjectionAngularTolerance(tolerance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxFixedJoint__1getProjectionAngularTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxFixedJoint* self = (physx::PxFixedJoint*) _address;
    return (jfloat) self->getProjectionAngularTolerance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxFixedJoint__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxFixedJoint*) _address;
}

// PxJoint
JNIEXPORT void JNICALL Java_physx_extensions_PxJoint__1setActors(JNIEnv*, jclass, jlong _address, jlong actor0, jlong actor1) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    self->setActors((physx::PxRigidActor*) actor0, (physx::PxRigidActor*) actor1);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJoint__1setLocalPose(JNIEnv*, jclass, jlong _address, jint actor, jlong localPose) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    self->setLocalPose((PxJointActorIndexEnum) actor, *((physx::PxTransform*) localPose));
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJoint__1getLocalPose(JNIEnv*, jclass, jlong _address, jint actor) {
    static thread_local physx::PxTransform _cache;
    physx::PxJoint* self = (physx::PxJoint*) _address;
    _cache = self->getLocalPose((PxJointActorIndexEnum) actor);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJoint__1getRelativeTransform(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxTransform _cache;
    physx::PxJoint* self = (physx::PxJoint*) _address;
    _cache = self->getRelativeTransform();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJoint__1getRelativeLinearVelocity(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxVec3 _cache;
    physx::PxJoint* self = (physx::PxJoint*) _address;
    _cache = self->getRelativeLinearVelocity();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJoint__1getRelativeAngularVelocity(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxVec3 _cache;
    physx::PxJoint* self = (physx::PxJoint*) _address;
    _cache = self->getRelativeAngularVelocity();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJoint__1setBreakForce(JNIEnv*, jclass, jlong _address, jfloat force, jfloat torque) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    self->setBreakForce(force, torque);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJoint__1setConstraintFlags(JNIEnv*, jclass, jlong _address, jlong flags) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    self->setConstraintFlags(*((physx::PxConstraintFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJoint__1setConstraintFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    self->setConstraintFlag((PxConstraintFlagEnum) flag, value);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJoint__1getConstraintFlags(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxConstraintFlags _cache;
    physx::PxJoint* self = (physx::PxJoint*) _address;
    _cache = self->getConstraintFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJoint__1setInvMassScale0(JNIEnv*, jclass, jlong _address, jfloat invMassScale) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    self->setInvMassScale0(invMassScale);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJoint__1getInvMassScale0(JNIEnv*, jclass, jlong _address) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    return (jfloat) self->getInvMassScale0();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJoint__1setInvMassScale1(JNIEnv*, jclass, jlong _address, jfloat invMassScale) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    self->setInvMassScale1(invMassScale);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJoint__1getInvMassScale1(JNIEnv*, jclass, jlong _address) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    return (jfloat) self->getInvMassScale1();
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJoint__1getConstraint(JNIEnv*, jclass, jlong _address) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    return (jlong) self->getConstraint();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJoint__1setName(JNIEnv* _env, jclass, jlong _address, jstring name) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    self->setName(_env->GetStringUTFChars(name, 0));
}
JNIEXPORT jstring JNICALL Java_physx_extensions_PxJoint__1getName(JNIEnv* _env, jclass, jlong _address) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    return _env->NewStringUTF(self->getName());
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJoint__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    self->release();
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJoint__1getScene(JNIEnv*, jclass, jlong _address) {
    physx::PxJoint* self = (physx::PxJoint*) _address;
    return (jlong) self->getScene();
}

// PxJointAngularLimitPair
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJointAngularLimitPair__1PxJointAngularLimitPair(JNIEnv*, jclass, jfloat lowerLimit, jfloat upperLimit, jlong spring) {
    return (jlong) new physx::PxJointAngularLimitPair(lowerLimit, upperLimit, *((physx::PxSpring*) spring));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointAngularLimitPair__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxJointAngularLimitPair*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointAngularLimitPair__1getUpper(JNIEnv*, jclass, jlong _address) {
    physx::PxJointAngularLimitPair* _self = (physx::PxJointAngularLimitPair*) _address;
    return (jfloat) _self->upper;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointAngularLimitPair__1setUpper(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointAngularLimitPair* _self = (physx::PxJointAngularLimitPair*) _address;
    _self->upper = value;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointAngularLimitPair__1getLower(JNIEnv*, jclass, jlong _address) {
    physx::PxJointAngularLimitPair* _self = (physx::PxJointAngularLimitPair*) _address;
    return (jfloat) _self->lower;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointAngularLimitPair__1setLower(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointAngularLimitPair* _self = (physx::PxJointAngularLimitPair*) _address;
    _self->lower = value;
}

// PxJointLimitCone
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJointLimitCone__1PxJointLimitCone(JNIEnv*, jclass, jfloat yLimitAngle, jfloat zLimitAngle, jlong spring) {
    return (jlong) new physx::PxJointLimitCone(yLimitAngle, zLimitAngle, *((physx::PxSpring*) spring));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitCone__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxJointLimitCone*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLimitCone__1getYAngle(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitCone* _self = (physx::PxJointLimitCone*) _address;
    return (jfloat) _self->yAngle;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitCone__1setYAngle(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLimitCone* _self = (physx::PxJointLimitCone*) _address;
    _self->yAngle = value;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLimitCone__1getZAngle(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitCone* _self = (physx::PxJointLimitCone*) _address;
    return (jfloat) _self->zAngle;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitCone__1setZAngle(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLimitCone* _self = (physx::PxJointLimitCone*) _address;
    _self->zAngle = value;
}

// PxJointLimitParameters
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxJointLimitParameters__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitParameters* self = (physx::PxJointLimitParameters*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxJointLimitParameters__1isSoft(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitParameters* self = (physx::PxJointLimitParameters*) _address;
    return (jboolean) self->isSoft();
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLimitParameters__1getRestitution(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitParameters* _self = (physx::PxJointLimitParameters*) _address;
    return (jfloat) _self->restitution;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitParameters__1setRestitution(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLimitParameters* _self = (physx::PxJointLimitParameters*) _address;
    _self->restitution = value;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLimitParameters__1getBounceThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitParameters* _self = (physx::PxJointLimitParameters*) _address;
    return (jfloat) _self->bounceThreshold;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitParameters__1setBounceThreshold(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLimitParameters* _self = (physx::PxJointLimitParameters*) _address;
    _self->bounceThreshold = value;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLimitParameters__1getStiffness(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitParameters* _self = (physx::PxJointLimitParameters*) _address;
    return (jfloat) _self->stiffness;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitParameters__1setStiffness(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLimitParameters* _self = (physx::PxJointLimitParameters*) _address;
    _self->stiffness = value;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLimitParameters__1getDamping(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitParameters* _self = (physx::PxJointLimitParameters*) _address;
    return (jfloat) _self->damping;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitParameters__1setDamping(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLimitParameters* _self = (physx::PxJointLimitParameters*) _address;
    _self->damping = value;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLimitParameters__1getContactDistance(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitParameters* _self = (physx::PxJointLimitParameters*) _address;
    return (jfloat) _self->contactDistance;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitParameters__1setContactDistance(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLimitParameters* _self = (physx::PxJointLimitParameters*) _address;
    _self->contactDistance = value;
}

// PxJointLimitPyramid
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJointLimitPyramid__1PxJointLimitPyramid(JNIEnv*, jclass, jfloat yLimitAngleMin, jfloat yLimitAngleMax, jfloat zLimitAngleMin, jfloat zLimitAngleMax, jlong spring) {
    return (jlong) new physx::PxJointLimitPyramid(yLimitAngleMin, yLimitAngleMax, zLimitAngleMin, zLimitAngleMax, *((physx::PxSpring*) spring));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitPyramid__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxJointLimitPyramid*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLimitPyramid__1getYAngleMin(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitPyramid* _self = (physx::PxJointLimitPyramid*) _address;
    return (jfloat) _self->yAngleMin;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitPyramid__1setYAngleMin(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLimitPyramid* _self = (physx::PxJointLimitPyramid*) _address;
    _self->yAngleMin = value;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLimitPyramid__1getYAngleMax(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitPyramid* _self = (physx::PxJointLimitPyramid*) _address;
    return (jfloat) _self->yAngleMax;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitPyramid__1setYAngleMax(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLimitPyramid* _self = (physx::PxJointLimitPyramid*) _address;
    _self->yAngleMax = value;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLimitPyramid__1getZAngleMin(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitPyramid* _self = (physx::PxJointLimitPyramid*) _address;
    return (jfloat) _self->zAngleMin;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitPyramid__1setZAngleMin(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLimitPyramid* _self = (physx::PxJointLimitPyramid*) _address;
    _self->zAngleMin = value;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLimitPyramid__1getZAngleMax(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLimitPyramid* _self = (physx::PxJointLimitPyramid*) _address;
    return (jfloat) _self->zAngleMax;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLimitPyramid__1setZAngleMax(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLimitPyramid* _self = (physx::PxJointLimitPyramid*) _address;
    _self->zAngleMax = value;
}

// PxJointLinearLimit
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJointLinearLimit__1PxJointLinearLimit(JNIEnv*, jclass, jfloat extent, jlong spring) {
    return (jlong) new physx::PxJointLinearLimit(extent, *((physx::PxSpring*) spring));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLinearLimit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxJointLinearLimit*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLinearLimit__1getValue(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLinearLimit* _self = (physx::PxJointLinearLimit*) _address;
    return (jfloat) _self->value;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLinearLimit__1setValue(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLinearLimit* _self = (physx::PxJointLinearLimit*) _address;
    _self->value = value;
}

// PxJointLinearLimitPair
JNIEXPORT jlong JNICALL Java_physx_extensions_PxJointLinearLimitPair__1PxJointLinearLimitPair(JNIEnv*, jclass, jfloat lowerLimit, jfloat upperLimit, jlong spring) {
    return (jlong) new physx::PxJointLinearLimitPair(lowerLimit, upperLimit, *((physx::PxSpring*) spring));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLinearLimitPair__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxJointLinearLimitPair*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLinearLimitPair__1getUpper(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLinearLimitPair* _self = (physx::PxJointLinearLimitPair*) _address;
    return (jfloat) _self->upper;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLinearLimitPair__1setUpper(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLinearLimitPair* _self = (physx::PxJointLinearLimitPair*) _address;
    _self->upper = value;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxJointLinearLimitPair__1getLower(JNIEnv*, jclass, jlong _address) {
    physx::PxJointLinearLimitPair* _self = (physx::PxJointLinearLimitPair*) _address;
    return (jfloat) _self->lower;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxJointLinearLimitPair__1setLower(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxJointLinearLimitPair* _self = (physx::PxJointLinearLimitPair*) _address;
    _self->lower = value;
}

// PxPrismaticJoint
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxPrismaticJoint__1getPosition(JNIEnv*, jclass, jlong _address) {
    physx::PxPrismaticJoint* self = (physx::PxPrismaticJoint*) _address;
    return (jfloat) self->getPosition();
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxPrismaticJoint__1getVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxPrismaticJoint* self = (physx::PxPrismaticJoint*) _address;
    return (jfloat) self->getVelocity();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxPrismaticJoint__1setLimit(JNIEnv*, jclass, jlong _address, jlong limit) {
    physx::PxPrismaticJoint* self = (physx::PxPrismaticJoint*) _address;
    self->setLimit(*((physx::PxJointLinearLimitPair*) limit));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxPrismaticJoint__1setPrismaticJointFlags(JNIEnv*, jclass, jlong _address, jlong flags) {
    physx::PxPrismaticJoint* self = (physx::PxPrismaticJoint*) _address;
    self->setPrismaticJointFlags(*((physx::PxPrismaticJointFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxPrismaticJoint__1setPrismaticJointFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxPrismaticJoint* self = (physx::PxPrismaticJoint*) _address;
    self->setPrismaticJointFlag((PxPrismaticJointFlagEnum) flag, value);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxPrismaticJoint__1getPrismaticJointFlags(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxPrismaticJointFlags _cache;
    physx::PxPrismaticJoint* self = (physx::PxPrismaticJoint*) _address;
    _cache = self->getPrismaticJointFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxPrismaticJoint__1setProjectionLinearTolerance(JNIEnv*, jclass, jlong _address, jfloat tolerance) {
    physx::PxPrismaticJoint* self = (physx::PxPrismaticJoint*) _address;
    self->setProjectionLinearTolerance(tolerance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxPrismaticJoint__1getProjectionLinearTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxPrismaticJoint* self = (physx::PxPrismaticJoint*) _address;
    return (jfloat) self->getProjectionLinearTolerance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxPrismaticJoint__1setProjectionAngularTolerance(JNIEnv*, jclass, jlong _address, jfloat tolerance) {
    physx::PxPrismaticJoint* self = (physx::PxPrismaticJoint*) _address;
    self->setProjectionAngularTolerance(tolerance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxPrismaticJoint__1getProjectionAngularTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxPrismaticJoint* self = (physx::PxPrismaticJoint*) _address;
    return (jfloat) self->getProjectionAngularTolerance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxPrismaticJoint__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxPrismaticJoint*) _address;
}

// PxPrismaticJointFlags
JNIEXPORT jlong JNICALL Java_physx_extensions_PxPrismaticJointFlags__1PxPrismaticJointFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxPrismaticJointFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxPrismaticJointFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxPrismaticJointFlags* self = (physx::PxPrismaticJointFlags*) _address;
    return (jboolean) self->isSet((PxPrismaticJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxPrismaticJointFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxPrismaticJointFlags* self = (physx::PxPrismaticJointFlags*) _address;
    self->set((PxPrismaticJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxPrismaticJointFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxPrismaticJointFlags* self = (physx::PxPrismaticJointFlags*) _address;
    self->clear((PxPrismaticJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxPrismaticJointFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxPrismaticJointFlags*) _address;
}

// PxRigidActorExt
JNIEXPORT jlong JNICALL Java_physx_extensions_PxRigidActorExt__1createExclusiveShape__JJJ(JNIEnv*, jclass, jlong actor, jlong geometry, jlong material) {
    return (jlong) physx::PxRigidActorExt::createExclusiveShape(*((physx::PxRigidActor*) actor), *((physx::PxGeometry*) geometry), *((physx::PxMaterial*) material));
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxRigidActorExt__1createExclusiveShape__JJJJ(JNIEnv*, jclass, jlong actor, jlong geometry, jlong material, jlong flags) {
    return (jlong) physx::PxRigidActorExt::createExclusiveShape(*((physx::PxRigidActor*) actor), *((physx::PxGeometry*) geometry), *((physx::PxMaterial*) material), *((physx::PxShapeFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidActorExt__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxRigidActorExt*) _address;
}

// PxRigidBodyExt
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxRigidBodyExt__1updateMassAndInertia__JF(JNIEnv*, jclass, jlong body, jfloat density) {
    return (jboolean) physx::PxRigidBodyExt::updateMassAndInertia(*((physx::PxRigidBody*) body), density);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxRigidBodyExt__1updateMassAndInertia__JFJ(JNIEnv*, jclass, jlong body, jfloat density, jlong massLocalPose) {
    return (jboolean) physx::PxRigidBodyExt::updateMassAndInertia(*((physx::PxRigidBody*) body), density, (physx::PxVec3*) massLocalPose);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxRigidBodyExt__1updateMassAndInertia__JFJZ(JNIEnv*, jclass, jlong body, jfloat density, jlong massLocalPose, jboolean includeNonSimShapes) {
    return (jboolean) physx::PxRigidBodyExt::updateMassAndInertia(*((physx::PxRigidBody*) body), density, (physx::PxVec3*) massLocalPose, includeNonSimShapes);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxRigidBodyExt__1setMassAndUpdateInertia__JF(JNIEnv*, jclass, jlong body, jfloat mass) {
    return (jboolean) physx::PxRigidBodyExt::setMassAndUpdateInertia(*((physx::PxRigidBody*) body), mass);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxRigidBodyExt__1setMassAndUpdateInertia__JFJ(JNIEnv*, jclass, jlong body, jfloat mass, jlong massLocalPose) {
    return (jboolean) physx::PxRigidBodyExt::setMassAndUpdateInertia(*((physx::PxRigidBody*) body), mass, (physx::PxVec3*) massLocalPose);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxRigidBodyExt__1setMassAndUpdateInertia__JFJZ(JNIEnv*, jclass, jlong body, jfloat mass, jlong massLocalPose, jboolean includeNonSimShapes) {
    return (jboolean) physx::PxRigidBodyExt::setMassAndUpdateInertia(*((physx::PxRigidBody*) body), mass, (physx::PxVec3*) massLocalPose, includeNonSimShapes);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addForceAtPos__JJJ(JNIEnv*, jclass, jlong body, jlong force, jlong pos) {
    physx::PxRigidBodyExt::addForceAtPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addForceAtPos__JJJI(JNIEnv*, jclass, jlong body, jlong force, jlong pos, jint mode) {
    physx::PxRigidBodyExt::addForceAtPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos), (PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addForceAtPos__JJJIZ(JNIEnv*, jclass, jlong body, jlong force, jlong pos, jint mode, jboolean wakeup) {
    physx::PxRigidBodyExt::addForceAtPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos), (PxForceModeEnum) mode, wakeup);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addForceAtLocalPos__JJJ(JNIEnv*, jclass, jlong body, jlong force, jlong pos) {
    physx::PxRigidBodyExt::addForceAtLocalPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addForceAtLocalPos__JJJI(JNIEnv*, jclass, jlong body, jlong force, jlong pos, jint mode) {
    physx::PxRigidBodyExt::addForceAtLocalPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos), (PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addForceAtLocalPos__JJJIZ(JNIEnv*, jclass, jlong body, jlong force, jlong pos, jint mode, jboolean wakeup) {
    physx::PxRigidBodyExt::addForceAtLocalPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos), (PxForceModeEnum) mode, wakeup);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addLocalForceAtPos__JJJ(JNIEnv*, jclass, jlong body, jlong force, jlong pos) {
    physx::PxRigidBodyExt::addLocalForceAtPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addLocalForceAtPos__JJJI(JNIEnv*, jclass, jlong body, jlong force, jlong pos, jint mode) {
    physx::PxRigidBodyExt::addLocalForceAtPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos), (PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addLocalForceAtPos__JJJIZ(JNIEnv*, jclass, jlong body, jlong force, jlong pos, jint mode, jboolean wakeup) {
    physx::PxRigidBodyExt::addLocalForceAtPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos), (PxForceModeEnum) mode, wakeup);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addLocalForceAtLocalPos__JJJ(JNIEnv*, jclass, jlong body, jlong force, jlong pos) {
    physx::PxRigidBodyExt::addLocalForceAtLocalPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addLocalForceAtLocalPos__JJJI(JNIEnv*, jclass, jlong body, jlong force, jlong pos, jint mode) {
    physx::PxRigidBodyExt::addLocalForceAtLocalPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos), (PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1addLocalForceAtLocalPos__JJJIZ(JNIEnv*, jclass, jlong body, jlong force, jlong pos, jint mode, jboolean wakeup) {
    physx::PxRigidBodyExt::addLocalForceAtLocalPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) force), *((physx::PxVec3*) pos), (PxForceModeEnum) mode, wakeup);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxRigidBodyExt__1getVelocityAtPos(JNIEnv*, jclass, jlong body, jlong pos) {
    static thread_local physx::PxVec3 _cache;
    _cache = physx::PxRigidBodyExt::getVelocityAtPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) pos));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxRigidBodyExt__1getLocalVelocityAtLocalPos(JNIEnv*, jclass, jlong body, jlong pos) {
    static thread_local physx::PxVec3 _cache;
    _cache = physx::PxRigidBodyExt::getLocalVelocityAtLocalPos(*((physx::PxRigidBody*) body), *((physx::PxVec3*) pos));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxRigidBodyExt__1getVelocityAtOffset(JNIEnv*, jclass, jlong body, jlong pos) {
    static thread_local physx::PxVec3 _cache;
    _cache = physx::PxRigidBodyExt::getVelocityAtOffset(*((physx::PxRigidBody*) body), *((physx::PxVec3*) pos));
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1computeVelocityDeltaFromImpulse__JJJJJ(JNIEnv*, jclass, jlong body, jlong impulsiveForce, jlong impulsiveTorque, jlong deltaLinearVelocity, jlong deltaAngularVelocity) {
    physx::PxRigidBodyExt::computeVelocityDeltaFromImpulse(*((physx::PxRigidBody*) body), *((physx::PxVec3*) impulsiveForce), *((physx::PxVec3*) impulsiveTorque), *((physx::PxVec3*) deltaLinearVelocity), *((physx::PxVec3*) deltaAngularVelocity));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1computeVelocityDeltaFromImpulse__JJJJFFJJ(JNIEnv*, jclass, jlong body, jlong globalPose, jlong point, jlong impulse, jfloat invMassScale, jfloat invInertiaScale, jlong deltaLinearVelocity, jlong deltaAngularVelocity) {
    physx::PxRigidBodyExt::computeVelocityDeltaFromImpulse(*((physx::PxRigidBody*) body), *((physx::PxTransform*) globalPose), *((physx::PxVec3*) point), *((physx::PxVec3*) impulse), invMassScale, invInertiaScale, *((physx::PxVec3*) deltaLinearVelocity), *((physx::PxVec3*) deltaAngularVelocity));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1computeLinearAngularImpulse(JNIEnv*, jclass, jlong body, jlong globalPose, jlong point, jlong impulse, jfloat invMassScale, jfloat invInertiaScale, jlong linearImpulse, jlong angularImpulse) {
    physx::PxRigidBodyExt::computeLinearAngularImpulse(*((physx::PxRigidBody*) body), *((physx::PxTransform*) globalPose), *((physx::PxVec3*) point), *((physx::PxVec3*) impulse), invMassScale, invInertiaScale, *((physx::PxVec3*) linearImpulse), *((physx::PxVec3*) angularImpulse));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRigidBodyExt__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxRigidBodyExt*) _address;
}

// PxRevoluteJoint
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxRevoluteJoint__1getAngle(JNIEnv*, jclass, jlong _address) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    return (jfloat) self->getAngle();
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxRevoluteJoint__1getVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    return (jfloat) self->getVelocity();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setLimit(JNIEnv*, jclass, jlong _address, jlong limits) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    self->setLimit(*((physx::PxJointAngularLimitPair*) limits));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setDriveVelocity__JF(JNIEnv*, jclass, jlong _address, jfloat velocity) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    self->setDriveVelocity(velocity);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setDriveVelocity__JFZ(JNIEnv*, jclass, jlong _address, jfloat velocity, jboolean autowake) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    self->setDriveVelocity(velocity, autowake);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxRevoluteJoint__1getDriveVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    return (jfloat) self->getDriveVelocity();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setDriveForceLimit(JNIEnv*, jclass, jlong _address, jfloat limit) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    self->setDriveForceLimit(limit);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxRevoluteJoint__1getDriveForceLimit(JNIEnv*, jclass, jlong _address) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    return (jfloat) self->getDriveForceLimit();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setDriveGearRatio(JNIEnv*, jclass, jlong _address, jfloat ratio) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    self->setDriveGearRatio(ratio);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxRevoluteJoint__1getDriveGearRatio(JNIEnv*, jclass, jlong _address) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    return (jfloat) self->getDriveGearRatio();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setRevoluteJointFlags(JNIEnv*, jclass, jlong _address, jlong flags) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    self->setRevoluteJointFlags(*((physx::PxRevoluteJointFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setRevoluteJointFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    self->setRevoluteJointFlag((PxRevoluteJointFlagEnum) flag, value);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxRevoluteJoint__1getRevoluteJointFlags(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxRevoluteJointFlags _cache;
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    _cache = self->getRevoluteJointFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setProjectionLinearTolerance(JNIEnv*, jclass, jlong _address, jfloat tolerance) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    self->setProjectionLinearTolerance(tolerance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxRevoluteJoint__1getProjectionLinearTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    return (jfloat) self->getProjectionLinearTolerance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setProjectionAngularTolerance(JNIEnv*, jclass, jlong _address, jfloat tolerance) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    self->setProjectionAngularTolerance(tolerance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxRevoluteJoint__1getProjectionAngularTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) _address;
    return (jfloat) self->getProjectionAngularTolerance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxRevoluteJoint*) _address;
}

// PxRevoluteJointFlags
JNIEXPORT jint JNICALL Java_physx_extensions_PxRevoluteJointFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxRevoluteJointFlags);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxRevoluteJointFlags__1_1placement_1new_1PxRevoluteJointFlags(JNIEnv*, jclass, jlong _placement_address, jshort flags) {
    return (jlong) new((void*)_placement_address) physx::PxRevoluteJointFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxRevoluteJointFlags__1PxRevoluteJointFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxRevoluteJointFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxRevoluteJointFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxRevoluteJointFlags* self = (physx::PxRevoluteJointFlags*) _address;
    return (jboolean) self->isSet((PxRevoluteJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJointFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxRevoluteJointFlags* self = (physx::PxRevoluteJointFlags*) _address;
    self->set((PxRevoluteJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJointFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxRevoluteJointFlags* self = (physx::PxRevoluteJointFlags*) _address;
    self->clear((PxRevoluteJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJointFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxRevoluteJointFlags*) _address;
}

// PxSphericalJoint
JNIEXPORT void JNICALL Java_physx_extensions_PxSphericalJoint__1setLimitCone(JNIEnv*, jclass, jlong _address, jlong limitCone) {
    physx::PxSphericalJoint* self = (physx::PxSphericalJoint*) _address;
    self->setLimitCone(*((physx::PxJointLimitCone*) limitCone));
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxSphericalJoint__1getSwingYAngle(JNIEnv*, jclass, jlong _address) {
    physx::PxSphericalJoint* self = (physx::PxSphericalJoint*) _address;
    return (jfloat) self->getSwingYAngle();
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxSphericalJoint__1getSwingZAngle(JNIEnv*, jclass, jlong _address) {
    physx::PxSphericalJoint* self = (physx::PxSphericalJoint*) _address;
    return (jfloat) self->getSwingZAngle();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSphericalJoint__1setSphericalJointFlags(JNIEnv*, jclass, jlong _address, jlong flags) {
    physx::PxSphericalJoint* self = (physx::PxSphericalJoint*) _address;
    self->setSphericalJointFlags(*((physx::PxSphericalJointFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSphericalJoint__1setSphericalJointFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxSphericalJoint* self = (physx::PxSphericalJoint*) _address;
    self->setSphericalJointFlag((PxSphericalJointFlagEnum) flag, value);
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxSphericalJoint__1getSphericalJointFlags(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxSphericalJointFlags _cache;
    physx::PxSphericalJoint* self = (physx::PxSphericalJoint*) _address;
    _cache = self->getSphericalJointFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSphericalJoint__1setProjectionLinearTolerance(JNIEnv*, jclass, jlong _address, jfloat tolerance) {
    physx::PxSphericalJoint* self = (physx::PxSphericalJoint*) _address;
    self->setProjectionLinearTolerance(tolerance);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxSphericalJoint__1getProjectionLinearTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxSphericalJoint* self = (physx::PxSphericalJoint*) _address;
    return (jfloat) self->getProjectionLinearTolerance();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSphericalJoint__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSphericalJoint*) _address;
}

// PxSphericalJointFlags
JNIEXPORT jlong JNICALL Java_physx_extensions_PxSphericalJointFlags__1PxSphericalJointFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxSphericalJointFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxSphericalJointFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxSphericalJointFlags* self = (physx::PxSphericalJointFlags*) _address;
    return (jboolean) self->isSet((PxSphericalJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSphericalJointFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxSphericalJointFlags* self = (physx::PxSphericalJointFlags*) _address;
    self->set((PxSphericalJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSphericalJointFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxSphericalJointFlags* self = (physx::PxSphericalJointFlags*) _address;
    self->clear((PxSphericalJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSphericalJointFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSphericalJointFlags*) _address;
}

// PxSpring
JNIEXPORT jlong JNICALL Java_physx_extensions_PxSpring__1PxSpring(JNIEnv*, jclass, jfloat stiffness, jfloat damping) {
    return (jlong) new physx::PxSpring(stiffness, damping);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSpring__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSpring*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxSpring__1getStiffness(JNIEnv*, jclass, jlong _address) {
    physx::PxSpring* _self = (physx::PxSpring*) _address;
    return (jfloat) _self->stiffness;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSpring__1setStiffness(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxSpring* _self = (physx::PxSpring*) _address;
    _self->stiffness = value;
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxSpring__1getDamping(JNIEnv*, jclass, jlong _address) {
    physx::PxSpring* _self = (physx::PxSpring*) _address;
    return (jfloat) _self->damping;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxSpring__1setDamping(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxSpring* _self = (physx::PxSpring*) _address;
    _self->damping = value;
}

// PxD6AxisEnum
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6AxisEnum__1geteX(JNIEnv*, jclass) {
    return PxD6AxisEnum::eX;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6AxisEnum__1geteY(JNIEnv*, jclass) {
    return PxD6AxisEnum::eY;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6AxisEnum__1geteZ(JNIEnv*, jclass) {
    return PxD6AxisEnum::eZ;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6AxisEnum__1geteTWIST(JNIEnv*, jclass) {
    return PxD6AxisEnum::eTWIST;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6AxisEnum__1geteSWING1(JNIEnv*, jclass) {
    return PxD6AxisEnum::eSWING1;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6AxisEnum__1geteSWING2(JNIEnv*, jclass) {
    return PxD6AxisEnum::eSWING2;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6AxisEnum__1geteCOUNT(JNIEnv*, jclass) {
    return PxD6AxisEnum::eCOUNT;
}

// PxD6DriveEnum
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6DriveEnum__1geteX(JNIEnv*, jclass) {
    return PxD6DriveEnum::eX;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6DriveEnum__1geteY(JNIEnv*, jclass) {
    return PxD6DriveEnum::eY;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6DriveEnum__1geteZ(JNIEnv*, jclass) {
    return PxD6DriveEnum::eZ;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6DriveEnum__1geteSWING(JNIEnv*, jclass) {
    return PxD6DriveEnum::eSWING;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6DriveEnum__1geteTWIST(JNIEnv*, jclass) {
    return PxD6DriveEnum::eTWIST;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6DriveEnum__1geteSLERP(JNIEnv*, jclass) {
    return PxD6DriveEnum::eSLERP;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6DriveEnum__1geteCOUNT(JNIEnv*, jclass) {
    return PxD6DriveEnum::eCOUNT;
}

// PxD6JointDriveFlagEnum
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6JointDriveFlagEnum__1geteACCELERATION(JNIEnv*, jclass) {
    return PxD6JointDriveFlagEnum::eACCELERATION;
}

// PxD6MotionEnum
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6MotionEnum__1geteLOCKED(JNIEnv*, jclass) {
    return PxD6MotionEnum::eLOCKED;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6MotionEnum__1geteLIMITED(JNIEnv*, jclass) {
    return PxD6MotionEnum::eLIMITED;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxD6MotionEnum__1geteFREE(JNIEnv*, jclass) {
    return PxD6MotionEnum::eFREE;
}

// PxDistanceJointFlagEnum
JNIEXPORT jint JNICALL Java_physx_extensions_PxDistanceJointFlagEnum__1geteMAX_1DISTANCE_1ENABLED(JNIEnv*, jclass) {
    return PxDistanceJointFlagEnum::eMAX_DISTANCE_ENABLED;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxDistanceJointFlagEnum__1geteMIN_1DISTANCE_1ENABLED(JNIEnv*, jclass) {
    return PxDistanceJointFlagEnum::eMIN_DISTANCE_ENABLED;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxDistanceJointFlagEnum__1geteSPRING_1ENABLED(JNIEnv*, jclass) {
    return PxDistanceJointFlagEnum::eSPRING_ENABLED;
}

// PxJointActorIndexEnum
JNIEXPORT jint JNICALL Java_physx_extensions_PxJointActorIndexEnum__1geteACTOR0(JNIEnv*, jclass) {
    return PxJointActorIndexEnum::eACTOR0;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxJointActorIndexEnum__1geteACTOR1(JNIEnv*, jclass) {
    return PxJointActorIndexEnum::eACTOR1;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxJointActorIndexEnum__1getCOUNT(JNIEnv*, jclass) {
    return PxJointActorIndexEnum::COUNT;
}

// PxPrismaticJointFlagEnum
JNIEXPORT jint JNICALL Java_physx_extensions_PxPrismaticJointFlagEnum__1geteLIMIT_1ENABLED(JNIEnv*, jclass) {
    return PxPrismaticJointFlagEnum::eLIMIT_ENABLED;
}

// PxRevoluteJointFlagEnum
JNIEXPORT jint JNICALL Java_physx_extensions_PxRevoluteJointFlagEnum__1geteLIMIT_1ENABLED(JNIEnv*, jclass) {
    return PxRevoluteJointFlagEnum::eLIMIT_ENABLED;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxRevoluteJointFlagEnum__1geteDRIVE_1ENABLED(JNIEnv*, jclass) {
    return PxRevoluteJointFlagEnum::eDRIVE_ENABLED;
}
JNIEXPORT jint JNICALL Java_physx_extensions_PxRevoluteJointFlagEnum__1geteDRIVE_1FREESPIN(JNIEnv*, jclass) {
    return PxRevoluteJointFlagEnum::eDRIVE_FREESPIN;
}

// PxSphericalJointFlagEnum
JNIEXPORT jint JNICALL Java_physx_extensions_PxSphericalJointFlagEnum__1geteLIMIT_1ENABLED(JNIEnv*, jclass) {
    return PxSphericalJointFlagEnum::eLIMIT_ENABLED;
}

// PxBoxGeometry
JNIEXPORT jint JNICALL Java_physx_geomutils_PxBoxGeometry__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxBoxGeometry);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxBoxGeometry__1_1placement_1new_1PxBoxGeometry(JNIEnv*, jclass, jlong _placement_address, jfloat hx, jfloat hy, jfloat hz) {
    return (jlong) new((void*)_placement_address) physx::PxBoxGeometry(hx, hy, hz);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxBoxGeometry__1PxBoxGeometry(JNIEnv*, jclass, jfloat hx, jfloat hy, jfloat hz) {
    return (jlong) new physx::PxBoxGeometry(hx, hy, hz);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxBoxGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBoxGeometry*) _address;
}

// PxBVHStructure

// PxCapsuleGeometry
JNIEXPORT jint JNICALL Java_physx_geomutils_PxCapsuleGeometry__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxCapsuleGeometry);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxCapsuleGeometry__1_1placement_1new_1PxCapsuleGeometry(JNIEnv*, jclass, jlong _placement_address, jfloat radius, jfloat halfHeight) {
    return (jlong) new((void*)_placement_address) physx::PxCapsuleGeometry(radius, halfHeight);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxCapsuleGeometry__1PxCapsuleGeometry(JNIEnv*, jclass, jfloat radius, jfloat halfHeight) {
    return (jlong) new physx::PxCapsuleGeometry(radius, halfHeight);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxCapsuleGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxCapsuleGeometry*) _address;
}

// PxConvexMesh
JNIEXPORT jint JNICALL Java_physx_geomutils_PxConvexMesh__1getNbVertices(JNIEnv*, jclass, jlong _address) {
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) _address;
    return (jint) self->getNbVertices();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxConvexMesh__1getVertices(JNIEnv*, jclass, jlong _address) {
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) _address;
    return (jlong) self->getVertices();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxConvexMesh__1getIndexBuffer(JNIEnv*, jclass, jlong _address) {
    static thread_local PxU8ConstPtr _cache;
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) _address;
    _cache = self->getIndexBuffer();
    return (jlong) &_cache;
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxConvexMesh__1getNbPolygons(JNIEnv*, jclass, jlong _address) {
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) _address;
    return (jint) self->getNbPolygons();
}
JNIEXPORT jboolean JNICALL Java_physx_geomutils_PxConvexMesh__1getPolygonData(JNIEnv*, jclass, jlong _address, jint index, jlong data) {
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) _address;
    return (jboolean) self->getPolygonData(index, *((physx::PxHullPolygon*) data));
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxConvexMesh__1getReferenceCount(JNIEnv*, jclass, jlong _address) {
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) _address;
    return (jint) self->getReferenceCount();
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxConvexMesh__1acquireReference(JNIEnv*, jclass, jlong _address) {
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) _address;
    self->acquireReference();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxConvexMesh__1getLocalBounds(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxBounds3 _cache;
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) _address;
    _cache = self->getLocalBounds();
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_geomutils_PxConvexMesh__1isGpuCompatible(JNIEnv*, jclass, jlong _address) {
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) _address;
    return (jboolean) self->isGpuCompatible();
}

// PxConvexMeshGeometry
JNIEXPORT jint JNICALL Java_physx_geomutils_PxConvexMeshGeometry__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxConvexMeshGeometry);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxConvexMeshGeometry__1_1placement_1new_1PxConvexMeshGeometry__JJ(JNIEnv*, jclass, jlong _placement_address, jlong mesh) {
    return (jlong) new((void*)_placement_address) physx::PxConvexMeshGeometry((physx::PxConvexMesh*) mesh);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxConvexMeshGeometry__1_1placement_1new_1PxConvexMeshGeometry__JJJ(JNIEnv*, jclass, jlong _placement_address, jlong mesh, jlong scaling) {
    return (jlong) new((void*)_placement_address) physx::PxConvexMeshGeometry((physx::PxConvexMesh*) mesh, *((physx::PxMeshScale*) scaling));
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxConvexMeshGeometry__1_1placement_1new_1PxConvexMeshGeometry__JJJJ(JNIEnv*, jclass, jlong _placement_address, jlong mesh, jlong scaling, jlong flags) {
    return (jlong) new((void*)_placement_address) physx::PxConvexMeshGeometry((physx::PxConvexMesh*) mesh, *((physx::PxMeshScale*) scaling), *((physx::PxConvexMeshGeometryFlags*) flags));
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxConvexMeshGeometry__1PxConvexMeshGeometry__J(JNIEnv*, jclass, jlong mesh) {
    return (jlong) new physx::PxConvexMeshGeometry((physx::PxConvexMesh*) mesh);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxConvexMeshGeometry__1PxConvexMeshGeometry__JJ(JNIEnv*, jclass, jlong mesh, jlong scaling) {
    return (jlong) new physx::PxConvexMeshGeometry((physx::PxConvexMesh*) mesh, *((physx::PxMeshScale*) scaling));
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxConvexMeshGeometry__1PxConvexMeshGeometry__JJJ(JNIEnv*, jclass, jlong mesh, jlong scaling, jlong flags) {
    return (jlong) new physx::PxConvexMeshGeometry((physx::PxConvexMesh*) mesh, *((physx::PxMeshScale*) scaling), *((physx::PxConvexMeshGeometryFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxConvexMeshGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxConvexMeshGeometry*) _address;
}

// PxConvexMeshGeometryFlags
JNIEXPORT jint JNICALL Java_physx_geomutils_PxConvexMeshGeometryFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxConvexMeshGeometryFlags);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxConvexMeshGeometryFlags__1_1placement_1new_1PxConvexMeshGeometryFlags(JNIEnv*, jclass, jlong _placement_address, jbyte flags) {
    return (jlong) new((void*)_placement_address) physx::PxConvexMeshGeometryFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxConvexMeshGeometryFlags__1PxConvexMeshGeometryFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxConvexMeshGeometryFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_geomutils_PxConvexMeshGeometryFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxConvexMeshGeometryFlags* self = (physx::PxConvexMeshGeometryFlags*) _address;
    return (jboolean) self->isSet((PxConvexMeshGeometryFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxConvexMeshGeometryFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxConvexMeshGeometryFlags* self = (physx::PxConvexMeshGeometryFlags*) _address;
    self->set((PxConvexMeshGeometryFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxConvexMeshGeometryFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxConvexMeshGeometryFlags* self = (physx::PxConvexMeshGeometryFlags*) _address;
    self->clear((PxConvexMeshGeometryFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxConvexMeshGeometryFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxConvexMeshGeometryFlags*) _address;
}

// PxGeometry
JNIEXPORT jint JNICALL Java_physx_geomutils_PxGeometry__1getType(JNIEnv*, jclass, jlong _address) {
    physx::PxGeometry* self = (physx::PxGeometry*) _address;
    return (jint) self->getType();
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxGeometry*) _address;
}

// PxGeometryHolder
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxGeometryHolder__1PxGeometryHolder__(JNIEnv*, jclass) {
    return (jlong) new physx::PxGeometryHolder();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxGeometryHolder__1PxGeometryHolder__J(JNIEnv*, jclass, jlong geometry) {
    return (jlong) new physx::PxGeometryHolder(*((physx::PxGeometry*) geometry));
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxGeometryHolder__1getType(JNIEnv*, jclass, jlong _address) {
    physx::PxGeometryHolder* self = (physx::PxGeometryHolder*) _address;
    return (jint) self->getType();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxGeometryHolder__1sphere(JNIEnv*, jclass, jlong _address) {
    physx::PxGeometryHolder* self = (physx::PxGeometryHolder*) _address;
    return (jlong) &self->sphere();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxGeometryHolder__1plane(JNIEnv*, jclass, jlong _address) {
    physx::PxGeometryHolder* self = (physx::PxGeometryHolder*) _address;
    return (jlong) &self->plane();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxGeometryHolder__1capsule(JNIEnv*, jclass, jlong _address) {
    physx::PxGeometryHolder* self = (physx::PxGeometryHolder*) _address;
    return (jlong) &self->capsule();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxGeometryHolder__1box(JNIEnv*, jclass, jlong _address) {
    physx::PxGeometryHolder* self = (physx::PxGeometryHolder*) _address;
    return (jlong) &self->box();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxGeometryHolder__1convexMesh(JNIEnv*, jclass, jlong _address) {
    physx::PxGeometryHolder* self = (physx::PxGeometryHolder*) _address;
    return (jlong) &self->convexMesh();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxGeometryHolder__1triangleMesh(JNIEnv*, jclass, jlong _address) {
    physx::PxGeometryHolder* self = (physx::PxGeometryHolder*) _address;
    return (jlong) &self->triangleMesh();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxGeometryHolder__1heightField(JNIEnv*, jclass, jlong _address) {
    physx::PxGeometryHolder* self = (physx::PxGeometryHolder*) _address;
    return (jlong) &self->heightField();
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxGeometryHolder__1storeAny(JNIEnv*, jclass, jlong _address, jlong geometry) {
    physx::PxGeometryHolder* self = (physx::PxGeometryHolder*) _address;
    self->storeAny(*((physx::PxGeometry*) geometry));
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxGeometryHolder__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxGeometryHolder*) _address;
}

// PxGeometryQuery
JNIEXPORT jboolean JNICALL Java_physx_geomutils_PxGeometryQuery__1sweep__JFJJJJJ(JNIEnv*, jclass, jlong unitDir, jfloat maxDist, jlong geom0, jlong pose0, jlong geom1, jlong pose1, jlong sweepHit) {
    return (jboolean) physx::PxGeometryQuery::sweep(*((physx::PxVec3*) unitDir), maxDist, *((physx::PxGeometry*) geom0), *((physx::PxTransform*) pose0), *((physx::PxGeometry*) geom1), *((physx::PxTransform*) pose1), *((physx::PxSweepHit*) sweepHit));
}
JNIEXPORT jboolean JNICALL Java_physx_geomutils_PxGeometryQuery__1sweep__JFJJJJJJ(JNIEnv*, jclass, jlong unitDir, jfloat maxDist, jlong geom0, jlong pose0, jlong geom1, jlong pose1, jlong sweepHit, jlong hitFlags) {
    return (jboolean) physx::PxGeometryQuery::sweep(*((physx::PxVec3*) unitDir), maxDist, *((physx::PxGeometry*) geom0), *((physx::PxTransform*) pose0), *((physx::PxGeometry*) geom1), *((physx::PxTransform*) pose1), *((physx::PxSweepHit*) sweepHit), *((physx::PxHitFlags*) hitFlags));
}
JNIEXPORT jboolean JNICALL Java_physx_geomutils_PxGeometryQuery__1sweep__JFJJJJJJF(JNIEnv*, jclass, jlong unitDir, jfloat maxDist, jlong geom0, jlong pose0, jlong geom1, jlong pose1, jlong sweepHit, jlong hitFlags, jfloat inflation) {
    return (jboolean) physx::PxGeometryQuery::sweep(*((physx::PxVec3*) unitDir), maxDist, *((physx::PxGeometry*) geom0), *((physx::PxTransform*) pose0), *((physx::PxGeometry*) geom1), *((physx::PxTransform*) pose1), *((physx::PxSweepHit*) sweepHit), *((physx::PxHitFlags*) hitFlags), inflation);
}
JNIEXPORT jboolean JNICALL Java_physx_geomutils_PxGeometryQuery__1overlap(JNIEnv*, jclass, jlong geom0, jlong pose0, jlong geom1, jlong pose1) {
    return (jboolean) physx::PxGeometryQuery::overlap(*((physx::PxGeometry*) geom0), *((physx::PxTransform*) pose0), *((physx::PxGeometry*) geom1), *((physx::PxTransform*) pose1));
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxGeometryQuery__1raycast(JNIEnv*, jclass, jlong origin, jlong unitDir, jlong geom, jlong pose, jfloat maxDist, jlong hitFlags, jint maxHits, jlong rayHits) {
    return (jint) physx::PxGeometryQuery::raycast(*((physx::PxVec3*) origin), *((physx::PxVec3*) unitDir), *((physx::PxGeometry*) geom), *((physx::PxTransform*) pose), maxDist, *((physx::PxHitFlags*) hitFlags), maxHits, (physx::PxRaycastHit*) rayHits);
}
JNIEXPORT jfloat JNICALL Java_physx_geomutils_PxGeometryQuery__1pointDistance__JJJ(JNIEnv*, jclass, jlong point, jlong geom, jlong pose) {
    return (jfloat) physx::PxGeometryQuery::pointDistance(*((physx::PxVec3*) point), *((physx::PxGeometry*) geom), *((physx::PxTransform*) pose));
}
JNIEXPORT jfloat JNICALL Java_physx_geomutils_PxGeometryQuery__1pointDistance__JJJJ(JNIEnv*, jclass, jlong point, jlong geom, jlong pose, jlong closestPoint) {
    return (jfloat) physx::PxGeometryQuery::pointDistance(*((physx::PxVec3*) point), *((physx::PxGeometry*) geom), *((physx::PxTransform*) pose), (physx::PxVec3*) closestPoint);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxGeometryQuery__1getWorldBounds__JJ(JNIEnv*, jclass, jlong geom, jlong pose) {
    static thread_local physx::PxBounds3 _cache;
    _cache = physx::PxGeometryQuery::getWorldBounds(*((physx::PxGeometry*) geom), *((physx::PxTransform*) pose));
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxGeometryQuery__1getWorldBounds__JJF(JNIEnv*, jclass, jlong geom, jlong pose, jfloat inflation) {
    static thread_local physx::PxBounds3 _cache;
    _cache = physx::PxGeometryQuery::getWorldBounds(*((physx::PxGeometry*) geom), *((physx::PxTransform*) pose), inflation);
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_geomutils_PxGeometryQuery__1isValid(JNIEnv*, jclass, jlong geom) {
    return (jboolean) physx::PxGeometryQuery::isValid(*((physx::PxGeometry*) geom));
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxGeometryQuery__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxGeometryQuery*) _address;
}

// PxHeightField
JNIEXPORT jint JNICALL Java_physx_geomutils_PxHeightField__1saveCells(JNIEnv*, jclass, jlong _address, jlong destBuffer, jint destBufferSize) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jint) self->saveCells((void*) destBuffer, destBufferSize);
}
JNIEXPORT jboolean JNICALL Java_physx_geomutils_PxHeightField__1modifySamples__JIIJ(JNIEnv*, jclass, jlong _address, jint startCol, jint startRow, jlong subfieldDesc) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jboolean) self->modifySamples(startCol, startRow, *((physx::PxHeightFieldDesc*) subfieldDesc));
}
JNIEXPORT jboolean JNICALL Java_physx_geomutils_PxHeightField__1modifySamples__JIIJZ(JNIEnv*, jclass, jlong _address, jint startCol, jint startRow, jlong subfieldDesc, jboolean shrinkBounds) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jboolean) self->modifySamples(startCol, startRow, *((physx::PxHeightFieldDesc*) subfieldDesc), shrinkBounds);
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxHeightField__1getNbRows(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jint) self->getNbRows();
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxHeightField__1getNbColumns(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jint) self->getNbColumns();
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxHeightField__1getFormat(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jint) self->getFormat();
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxHeightField__1getSampleStride(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jint) self->getSampleStride();
}
JNIEXPORT jfloat JNICALL Java_physx_geomutils_PxHeightField__1getConvexEdgeThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jfloat) self->getConvexEdgeThreshold();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxHeightField__1getFlags(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxHeightFieldFlags _cache;
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    _cache = self->getFlags();
    return (jlong) &_cache;
}
JNIEXPORT jfloat JNICALL Java_physx_geomutils_PxHeightField__1getHeight(JNIEnv*, jclass, jlong _address, jfloat x, jfloat z) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jfloat) self->getHeight(x, z);
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxHeightField__1getReferenceCount(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jint) self->getReferenceCount();
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightField__1acquireReference(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    self->acquireReference();
}
JNIEXPORT jshort JNICALL Java_physx_geomutils_PxHeightField__1getTriangleMaterialIndex(JNIEnv*, jclass, jlong _address, jint triangleIndex) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jshort) self->getTriangleMaterialIndex(triangleIndex);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxHeightField__1getTriangleNormal(JNIEnv*, jclass, jlong _address, jint triangleIndex) {
    static thread_local physx::PxVec3 _cache;
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    _cache = self->getTriangleNormal(triangleIndex);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxHeightField__1getSample(JNIEnv*, jclass, jlong _address, jint row, jint column) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jlong) &self->getSample(row, column);
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxHeightField__1getTimestamp(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightField* self = (physx::PxHeightField*) _address;
    return (jint) self->getTimestamp();
}

// PxHeightFieldDesc
JNIEXPORT jint JNICALL Java_physx_geomutils_PxHeightFieldDesc__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxHeightFieldDesc);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxHeightFieldDesc__1_1placement_1new_1PxHeightFieldDesc(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxHeightFieldDesc();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxHeightFieldDesc__1PxHeightFieldDesc(JNIEnv*, jclass) {
    return (jlong) new physx::PxHeightFieldDesc();
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightFieldDesc__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldDesc* self = (physx::PxHeightFieldDesc*) _address;
    self->setToDefault();
}
JNIEXPORT jboolean JNICALL Java_physx_geomutils_PxHeightFieldDesc__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldDesc* self = (physx::PxHeightFieldDesc*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightFieldDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxHeightFieldDesc*) _address;
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxHeightFieldDesc__1getNbRows(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    return (jint) _self->nbRows;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightFieldDesc__1setNbRows(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    _self->nbRows = value;
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxHeightFieldDesc__1getNbColumns(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    return (jint) _self->nbColumns;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightFieldDesc__1setNbColumns(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    _self->nbColumns = value;
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxHeightFieldDesc__1getFormat(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    return (jint) _self->format;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightFieldDesc__1setFormat(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    _self->format = (PxHeightFieldFormatEnum) value;
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxHeightFieldDesc__1getSamples(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    return (jlong) &_self->samples;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightFieldDesc__1setSamples(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    _self->samples = *((physx::PxStridedData*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_geomutils_PxHeightFieldDesc__1getConvexEdgeThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    return (jfloat) _self->convexEdgeThreshold;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightFieldDesc__1setConvexEdgeThreshold(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    _self->convexEdgeThreshold = value;
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxHeightFieldDesc__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    return (jlong) &_self->flags;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightFieldDesc__1setFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxHeightFieldDesc* _self = (physx::PxHeightFieldDesc*) _address;
    _self->flags = *((physx::PxHeightFieldFlags*) value);
}

// PxHeightFieldFlags
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxHeightFieldFlags__1PxHeightFieldFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxHeightFieldFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_geomutils_PxHeightFieldFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxHeightFieldFlags* self = (physx::PxHeightFieldFlags*) _address;
    return (jboolean) self->isSet((PxHeightFieldFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightFieldFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxHeightFieldFlags* self = (physx::PxHeightFieldFlags*) _address;
    self->set((PxHeightFieldFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightFieldFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxHeightFieldFlags* self = (physx::PxHeightFieldFlags*) _address;
    self->clear((PxHeightFieldFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightFieldFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxHeightFieldFlags*) _address;
}

// PxHeightFieldGeometry
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxHeightFieldGeometry__1PxHeightFieldGeometry__(JNIEnv*, jclass) {
    return (jlong) new physx::PxHeightFieldGeometry();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxHeightFieldGeometry__1PxHeightFieldGeometry__JJFFF(JNIEnv*, jclass, jlong hf, jlong flags, jfloat heightScale, jfloat rowScale, jfloat columnScale) {
    return (jlong) new physx::PxHeightFieldGeometry((physx::PxHeightField*) hf, *((physx::PxMeshGeometryFlags*) flags), heightScale, rowScale, columnScale);
}
JNIEXPORT jboolean JNICALL Java_physx_geomutils_PxHeightFieldGeometry__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldGeometry* self = (physx::PxHeightFieldGeometry*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightFieldGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxHeightFieldGeometry*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxHeightFieldGeometry__1getHeightField(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldGeometry* _self = (physx::PxHeightFieldGeometry*) _address;
    return (jlong) _self->heightField;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightFieldGeometry__1setHeightField(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxHeightFieldGeometry* _self = (physx::PxHeightFieldGeometry*) _address;
    _self->heightField = (physx::PxHeightField*) value;
}
JNIEXPORT jfloat JNICALL Java_physx_geomutils_PxHeightFieldGeometry__1getHeightScale(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldGeometry* _self = (physx::PxHeightFieldGeometry*) _address;
    return (jfloat) _self->heightScale;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightFieldGeometry__1setHeightScale(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxHeightFieldGeometry* _self = (physx::PxHeightFieldGeometry*) _address;
    _self->heightScale = value;
}
JNIEXPORT jfloat JNICALL Java_physx_geomutils_PxHeightFieldGeometry__1getRowScale(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldGeometry* _self = (physx::PxHeightFieldGeometry*) _address;
    return (jfloat) _self->rowScale;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightFieldGeometry__1setRowScale(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxHeightFieldGeometry* _self = (physx::PxHeightFieldGeometry*) _address;
    _self->rowScale = value;
}
JNIEXPORT jfloat JNICALL Java_physx_geomutils_PxHeightFieldGeometry__1getColumnScale(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldGeometry* _self = (physx::PxHeightFieldGeometry*) _address;
    return (jfloat) _self->columnScale;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightFieldGeometry__1setColumnScale(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxHeightFieldGeometry* _self = (physx::PxHeightFieldGeometry*) _address;
    _self->columnScale = value;
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxHeightFieldGeometry__1getHeightFieldFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldGeometry* _self = (physx::PxHeightFieldGeometry*) _address;
    return (jlong) &_self->heightFieldFlags;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightFieldGeometry__1setHeightFieldFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxHeightFieldGeometry* _self = (physx::PxHeightFieldGeometry*) _address;
    _self->heightFieldFlags = *((physx::PxMeshGeometryFlags*) value);
}

// PxHeightFieldSample
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightFieldSample__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxHeightFieldSample*) _address;
}
JNIEXPORT jshort JNICALL Java_physx_geomutils_PxHeightFieldSample__1getHeight(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldSample* _self = (physx::PxHeightFieldSample*) _address;
    return (jshort) _self->height;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightFieldSample__1setHeight(JNIEnv*, jclass, jlong _address, jshort value) {
    physx::PxHeightFieldSample* _self = (physx::PxHeightFieldSample*) _address;
    _self->height = value;
}
JNIEXPORT jbyte JNICALL Java_physx_geomutils_PxHeightFieldSample__1getMaterialIndex0(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldSample* _self = (physx::PxHeightFieldSample*) _address;
    return (jbyte) _self->materialIndex0;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightFieldSample__1setMaterialIndex0(JNIEnv*, jclass, jlong _address, jbyte value) {
    physx::PxHeightFieldSample* _self = (physx::PxHeightFieldSample*) _address;
    _self->materialIndex0 = value;
}
JNIEXPORT jbyte JNICALL Java_physx_geomutils_PxHeightFieldSample__1getMaterialIndex1(JNIEnv*, jclass, jlong _address) {
    physx::PxHeightFieldSample* _self = (physx::PxHeightFieldSample*) _address;
    return (jbyte) _self->materialIndex1;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHeightFieldSample__1setMaterialIndex1(JNIEnv*, jclass, jlong _address, jbyte value) {
    physx::PxHeightFieldSample* _self = (physx::PxHeightFieldSample*) _address;
    _self->materialIndex1 = value;
}

// PxHullPolygon
JNIEXPORT jint JNICALL Java_physx_geomutils_PxHullPolygon__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxHullPolygon);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxHullPolygon__1_1placement_1new_1PxHullPolygon(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxHullPolygon();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxHullPolygon__1PxHullPolygon(JNIEnv*, jclass) {
    return (jlong) new physx::PxHullPolygon();
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHullPolygon__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxHullPolygon*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_geomutils_PxHullPolygon__1getMPlane(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::PxHullPolygon* _self = (physx::PxHullPolygon*) _address;
    return (jfloat) _self->mPlane[_index];
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHullPolygon__1setMPlane(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::PxHullPolygon* _self = (physx::PxHullPolygon*) _address;
    _self->mPlane[_index] = value;
}
JNIEXPORT jshort JNICALL Java_physx_geomutils_PxHullPolygon__1getMNbVerts(JNIEnv*, jclass, jlong _address) {
    physx::PxHullPolygon* _self = (physx::PxHullPolygon*) _address;
    return (jshort) _self->mNbVerts;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHullPolygon__1setMNbVerts(JNIEnv*, jclass, jlong _address, jshort value) {
    physx::PxHullPolygon* _self = (physx::PxHullPolygon*) _address;
    _self->mNbVerts = value;
}
JNIEXPORT jshort JNICALL Java_physx_geomutils_PxHullPolygon__1getMIndexBase(JNIEnv*, jclass, jlong _address) {
    physx::PxHullPolygon* _self = (physx::PxHullPolygon*) _address;
    return (jshort) _self->mIndexBase;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHullPolygon__1setMIndexBase(JNIEnv*, jclass, jlong _address, jshort value) {
    physx::PxHullPolygon* _self = (physx::PxHullPolygon*) _address;
    _self->mIndexBase = value;
}

// PxMeshFlags
JNIEXPORT jint JNICALL Java_physx_geomutils_PxMeshFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxMeshFlags);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxMeshFlags__1_1placement_1new_1PxMeshFlags(JNIEnv*, jclass, jlong _placement_address, jbyte flags) {
    return (jlong) new((void*)_placement_address) physx::PxMeshFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxMeshFlags__1PxMeshFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxMeshFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_geomutils_PxMeshFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxMeshFlags* self = (physx::PxMeshFlags*) _address;
    return (jboolean) self->isSet((PxMeshFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxMeshFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxMeshFlags* self = (physx::PxMeshFlags*) _address;
    self->set((PxMeshFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxMeshFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxMeshFlags* self = (physx::PxMeshFlags*) _address;
    self->clear((PxMeshFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxMeshFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxMeshFlags*) _address;
}

// PxMeshGeometryFlags
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxMeshGeometryFlags__1PxMeshGeometryFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxMeshGeometryFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_geomutils_PxMeshGeometryFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxMeshGeometryFlags* self = (physx::PxMeshGeometryFlags*) _address;
    return (jboolean) self->isSet((PxMeshGeometryFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxMeshGeometryFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxMeshGeometryFlags* self = (physx::PxMeshGeometryFlags*) _address;
    self->set((PxMeshGeometryFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxMeshGeometryFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxMeshGeometryFlags* self = (physx::PxMeshGeometryFlags*) _address;
    self->clear((PxMeshGeometryFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxMeshGeometryFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxMeshGeometryFlags*) _address;
}

// PxMeshScale
JNIEXPORT jint JNICALL Java_physx_geomutils_PxMeshScale__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxMeshScale);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxMeshScale__1_1placement_1new_1PxMeshScale__J(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxMeshScale();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxMeshScale__1_1placement_1new_1PxMeshScale__JF(JNIEnv*, jclass, jlong _placement_address, jfloat r) {
    return (jlong) new((void*)_placement_address) physx::PxMeshScale(r);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxMeshScale__1_1placement_1new_1PxMeshScale__JJJ(JNIEnv*, jclass, jlong _placement_address, jlong s, jlong r) {
    return (jlong) new((void*)_placement_address) physx::PxMeshScale(*((physx::PxVec3*) s), *((physx::PxQuat*) r));
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxMeshScale__1PxMeshScale__(JNIEnv*, jclass) {
    return (jlong) new physx::PxMeshScale();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxMeshScale__1PxMeshScale__F(JNIEnv*, jclass, jfloat r) {
    return (jlong) new physx::PxMeshScale(r);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxMeshScale__1PxMeshScale__JJ(JNIEnv*, jclass, jlong s, jlong r) {
    return (jlong) new physx::PxMeshScale(*((physx::PxVec3*) s), *((physx::PxQuat*) r));
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxMeshScale__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxMeshScale*) _address;
}

// PxPlaneGeometry
JNIEXPORT jint JNICALL Java_physx_geomutils_PxPlaneGeometry__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxPlaneGeometry);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxPlaneGeometry__1_1placement_1new_1PxPlaneGeometry(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxPlaneGeometry();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxPlaneGeometry__1PxPlaneGeometry(JNIEnv*, jclass) {
    return (jlong) new physx::PxPlaneGeometry();
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxPlaneGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxPlaneGeometry*) _address;
}

// PxSimpleTriangleMesh
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxSimpleTriangleMesh__1PxSimpleTriangleMesh(JNIEnv*, jclass) {
    return (jlong) new physx::PxSimpleTriangleMesh();
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxSimpleTriangleMesh__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::PxSimpleTriangleMesh* self = (physx::PxSimpleTriangleMesh*) _address;
    self->setToDefault();
}
JNIEXPORT jboolean JNICALL Java_physx_geomutils_PxSimpleTriangleMesh__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxSimpleTriangleMesh* self = (physx::PxSimpleTriangleMesh*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxSimpleTriangleMesh__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSimpleTriangleMesh*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxSimpleTriangleMesh__1getPoints(JNIEnv*, jclass, jlong _address) {
    physx::PxSimpleTriangleMesh* _self = (physx::PxSimpleTriangleMesh*) _address;
    return (jlong) &_self->points;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxSimpleTriangleMesh__1setPoints(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSimpleTriangleMesh* _self = (physx::PxSimpleTriangleMesh*) _address;
    _self->points = *((physx::PxBoundedData*) value);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxSimpleTriangleMesh__1getTriangles(JNIEnv*, jclass, jlong _address) {
    physx::PxSimpleTriangleMesh* _self = (physx::PxSimpleTriangleMesh*) _address;
    return (jlong) &_self->triangles;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxSimpleTriangleMesh__1setTriangles(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSimpleTriangleMesh* _self = (physx::PxSimpleTriangleMesh*) _address;
    _self->triangles = *((physx::PxBoundedData*) value);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxSimpleTriangleMesh__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxSimpleTriangleMesh* _self = (physx::PxSimpleTriangleMesh*) _address;
    return (jlong) &_self->flags;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxSimpleTriangleMesh__1setFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSimpleTriangleMesh* _self = (physx::PxSimpleTriangleMesh*) _address;
    _self->flags = *((physx::PxMeshFlags*) value);
}

// PxSphereGeometry
JNIEXPORT jint JNICALL Java_physx_geomutils_PxSphereGeometry__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSphereGeometry);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxSphereGeometry__1_1placement_1new_1PxSphereGeometry(JNIEnv*, jclass, jlong _placement_address, jfloat ir) {
    return (jlong) new((void*)_placement_address) physx::PxSphereGeometry(ir);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxSphereGeometry__1PxSphereGeometry(JNIEnv*, jclass, jfloat ir) {
    return (jlong) new physx::PxSphereGeometry(ir);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxSphereGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSphereGeometry*) _address;
}

// PxTriangle
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxTriangle__1PxTriangle__(JNIEnv*, jclass) {
    return (jlong) new physx::PxTriangle();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxTriangle__1PxTriangle__JJJ(JNIEnv*, jclass, jlong p0, jlong p1, jlong p2) {
    return (jlong) new physx::PxTriangle(*((physx::PxVec3*) p0), *((physx::PxVec3*) p1), *((physx::PxVec3*) p2));
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxTriangle__1normal(JNIEnv*, jclass, jlong _address, jlong normal) {
    physx::PxTriangle* self = (physx::PxTriangle*) _address;
    self->normal(*((physx::PxVec3*) normal));
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxTriangle__1denormalizedNormal(JNIEnv*, jclass, jlong _address, jlong normal) {
    physx::PxTriangle* self = (physx::PxTriangle*) _address;
    self->denormalizedNormal(*((physx::PxVec3*) normal));
}
JNIEXPORT jfloat JNICALL Java_physx_geomutils_PxTriangle__1area(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangle* self = (physx::PxTriangle*) _address;
    return (jfloat) self->area();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxTriangle__1pointFromUV(JNIEnv*, jclass, jlong _address, jfloat u, jfloat v) {
    static thread_local physx::PxVec3 _cache;
    physx::PxTriangle* self = (physx::PxTriangle*) _address;
    _cache = self->pointFromUV(u, v);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxTriangle__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxTriangle*) _address;
}

// PxTriangleMesh
JNIEXPORT jint JNICALL Java_physx_geomutils_PxTriangleMesh__1getNbVertices(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    return (jint) self->getNbVertices();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxTriangleMesh__1getVertices(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    return (jlong) self->getVertices();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxTriangleMesh__1getVerticesForModification(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    return (jlong) self->getVerticesForModification();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxTriangleMesh__1refitBVH(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxBounds3 _cache;
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    _cache = self->refitBVH();
    return (jlong) &_cache;
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxTriangleMesh__1getNbTriangles(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    return (jint) self->getNbTriangles();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxTriangleMesh__1getTriangles(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    return (jlong) self->getTriangles();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxTriangleMesh__1getTriangleMeshFlags(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxTriangleMeshFlags _cache;
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    _cache = self->getTriangleMeshFlags();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxTriangleMesh__1getTrianglesRemap(JNIEnv*, jclass, jlong _address) {
    static thread_local PxU32ConstPtr _cache;
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    _cache = self->getTrianglesRemap();
    return (jlong) &_cache;
}
JNIEXPORT jshort JNICALL Java_physx_geomutils_PxTriangleMesh__1getTriangleMaterialIndex(JNIEnv*, jclass, jlong _address, jint triangleIndex) {
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    return (jshort) self->getTriangleMaterialIndex(triangleIndex);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxTriangleMesh__1getLocalBounds(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxBounds3 _cache;
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    _cache = self->getLocalBounds();
    return (jlong) &_cache;
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxTriangleMesh__1getReferenceCount(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    return (jint) self->getReferenceCount();
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxTriangleMesh__1acquireReference(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMesh* self = (physx::PxTriangleMesh*) _address;
    self->acquireReference();
}

// PxTriangleMeshFlags
JNIEXPORT jint JNICALL Java_physx_geomutils_PxTriangleMeshFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxTriangleMeshFlags);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxTriangleMeshFlags__1_1placement_1new_1PxTriangleMeshFlags(JNIEnv*, jclass, jlong _placement_address, jbyte flags) {
    return (jlong) new((void*)_placement_address) physx::PxTriangleMeshFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxTriangleMeshFlags__1PxTriangleMeshFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxTriangleMeshFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_geomutils_PxTriangleMeshFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxTriangleMeshFlags* self = (physx::PxTriangleMeshFlags*) _address;
    return (jboolean) self->isSet((PxTriangleMeshFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxTriangleMeshFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxTriangleMeshFlags* self = (physx::PxTriangleMeshFlags*) _address;
    self->set((PxTriangleMeshFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxTriangleMeshFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxTriangleMeshFlags* self = (physx::PxTriangleMeshFlags*) _address;
    self->clear((PxTriangleMeshFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxTriangleMeshFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxTriangleMeshFlags*) _address;
}

// PxTriangleMeshGeometry
JNIEXPORT jint JNICALL Java_physx_geomutils_PxTriangleMeshGeometry__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxTriangleMeshGeometry);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxTriangleMeshGeometry__1_1placement_1new_1PxTriangleMeshGeometry__JJ(JNIEnv*, jclass, jlong _placement_address, jlong mesh) {
    return (jlong) new((void*)_placement_address) physx::PxTriangleMeshGeometry((physx::PxTriangleMesh*) mesh);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxTriangleMeshGeometry__1_1placement_1new_1PxTriangleMeshGeometry__JJJ(JNIEnv*, jclass, jlong _placement_address, jlong mesh, jlong scaling) {
    return (jlong) new((void*)_placement_address) physx::PxTriangleMeshGeometry((physx::PxTriangleMesh*) mesh, *((physx::PxMeshScale*) scaling));
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxTriangleMeshGeometry__1_1placement_1new_1PxTriangleMeshGeometry__JJJJ(JNIEnv*, jclass, jlong _placement_address, jlong mesh, jlong scaling, jlong flags) {
    return (jlong) new((void*)_placement_address) physx::PxTriangleMeshGeometry((physx::PxTriangleMesh*) mesh, *((physx::PxMeshScale*) scaling), *((physx::PxMeshGeometryFlags*) flags));
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxTriangleMeshGeometry__1PxTriangleMeshGeometry__J(JNIEnv*, jclass, jlong mesh) {
    return (jlong) new physx::PxTriangleMeshGeometry((physx::PxTriangleMesh*) mesh);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxTriangleMeshGeometry__1PxTriangleMeshGeometry__JJ(JNIEnv*, jclass, jlong mesh, jlong scaling) {
    return (jlong) new physx::PxTriangleMeshGeometry((physx::PxTriangleMesh*) mesh, *((physx::PxMeshScale*) scaling));
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxTriangleMeshGeometry__1PxTriangleMeshGeometry__JJJ(JNIEnv*, jclass, jlong mesh, jlong scaling, jlong flags) {
    return (jlong) new physx::PxTriangleMeshGeometry((physx::PxTriangleMesh*) mesh, *((physx::PxMeshScale*) scaling), *((physx::PxMeshGeometryFlags*) flags));
}
JNIEXPORT jboolean JNICALL Java_physx_geomutils_PxTriangleMeshGeometry__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxTriangleMeshGeometry* self = (physx::PxTriangleMeshGeometry*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxTriangleMeshGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxTriangleMeshGeometry*) _address;
}

// PxConvexMeshGeometryFlagEnum
JNIEXPORT jint JNICALL Java_physx_geomutils_PxConvexMeshGeometryFlagEnum__1geteTIGHT_1BOUNDS(JNIEnv*, jclass) {
    return PxConvexMeshGeometryFlagEnum::eTIGHT_BOUNDS;
}

// PxGeometryTypeEnum
JNIEXPORT jint JNICALL Java_physx_geomutils_PxGeometryTypeEnum__1geteSPHERE(JNIEnv*, jclass) {
    return PxGeometryTypeEnum::eSPHERE;
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxGeometryTypeEnum__1getePLANE(JNIEnv*, jclass) {
    return PxGeometryTypeEnum::ePLANE;
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxGeometryTypeEnum__1geteCAPSULE(JNIEnv*, jclass) {
    return PxGeometryTypeEnum::eCAPSULE;
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxGeometryTypeEnum__1geteBOX(JNIEnv*, jclass) {
    return PxGeometryTypeEnum::eBOX;
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxGeometryTypeEnum__1geteCONVEXMESH(JNIEnv*, jclass) {
    return PxGeometryTypeEnum::eCONVEXMESH;
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxGeometryTypeEnum__1geteTRIANGLEMESH(JNIEnv*, jclass) {
    return PxGeometryTypeEnum::eTRIANGLEMESH;
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxGeometryTypeEnum__1geteHEIGHTFIELD(JNIEnv*, jclass) {
    return PxGeometryTypeEnum::eHEIGHTFIELD;
}

// PxHeightFieldFlagEnum
JNIEXPORT jint JNICALL Java_physx_geomutils_PxHeightFieldFlagEnum__1geteNO_1BOUNDARY_1EDGES(JNIEnv*, jclass) {
    return PxHeightFieldFlagEnum::eNO_BOUNDARY_EDGES;
}

// PxHeightFieldFormatEnum
JNIEXPORT jint JNICALL Java_physx_geomutils_PxHeightFieldFormatEnum__1geteS16_1TM(JNIEnv*, jclass) {
    return PxHeightFieldFormatEnum::eS16_TM;
}

// PxMeshFlagEnum
JNIEXPORT jint JNICALL Java_physx_geomutils_PxMeshFlagEnum__1geteFLIPNORMALS(JNIEnv*, jclass) {
    return PxMeshFlagEnum::eFLIPNORMALS;
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxMeshFlagEnum__1gete16_1BIT_1INDICES(JNIEnv*, jclass) {
    return PxMeshFlagEnum::e16_BIT_INDICES;
}

// PxMeshGeometryFlagEnum
JNIEXPORT jint JNICALL Java_physx_geomutils_PxMeshGeometryFlagEnum__1geteDOUBLE_1SIDED(JNIEnv*, jclass) {
    return PxMeshGeometryFlagEnum::eDOUBLE_SIDED;
}

// PxTriangleMeshFlagEnum
JNIEXPORT jint JNICALL Java_physx_geomutils_PxTriangleMeshFlagEnum__1gete16_1BIT_1INDICES(JNIEnv*, jclass) {
    return PxTriangleMeshFlagEnum::e16_BIT_INDICES;
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxTriangleMeshFlagEnum__1geteADJACENCY_1INFO(JNIEnv*, jclass) {
    return PxTriangleMeshFlagEnum::eADJACENCY_INFO;
}

// PxActor
JNIEXPORT jint JNICALL Java_physx_physics_PxActor__1getType(JNIEnv*, jclass, jlong _address) {
    physx::PxActor* self = (physx::PxActor*) _address;
    return (jint) self->getType();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActor__1getScene(JNIEnv*, jclass, jlong _address) {
    physx::PxActor* self = (physx::PxActor*) _address;
    return (jlong) self->getScene();
}
JNIEXPORT void JNICALL Java_physx_physics_PxActor__1setName(JNIEnv* _env, jclass, jlong _address, jstring name) {
    physx::PxActor* self = (physx::PxActor*) _address;
    self->setName(_env->GetStringUTFChars(name, 0));
}
JNIEXPORT jstring JNICALL Java_physx_physics_PxActor__1getName(JNIEnv* _env, jclass, jlong _address) {
    physx::PxActor* self = (physx::PxActor*) _address;
    return _env->NewStringUTF(self->getName());
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActor__1getWorldBounds__J(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxBounds3 _cache;
    physx::PxActor* self = (physx::PxActor*) _address;
    _cache = self->getWorldBounds();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActor__1getWorldBounds__JF(JNIEnv*, jclass, jlong _address, jfloat inflation) {
    static thread_local physx::PxBounds3 _cache;
    physx::PxActor* self = (physx::PxActor*) _address;
    _cache = self->getWorldBounds(inflation);
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxActor__1setActorFlags(JNIEnv*, jclass, jlong _address, jlong flags) {
    physx::PxActor* self = (physx::PxActor*) _address;
    self->setActorFlags(*((physx::PxActorFlags*) flags));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActor__1getActorFlags(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxActorFlags _cache;
    physx::PxActor* self = (physx::PxActor*) _address;
    _cache = self->getActorFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxActor__1setDominanceGroup(JNIEnv*, jclass, jlong _address, jbyte dominanceGroup) {
    physx::PxActor* self = (physx::PxActor*) _address;
    self->setDominanceGroup(dominanceGroup);
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxActor__1getDominanceGroup(JNIEnv*, jclass, jlong _address) {
    physx::PxActor* self = (physx::PxActor*) _address;
    return (jbyte) self->getDominanceGroup();
}
JNIEXPORT void JNICALL Java_physx_physics_PxActor__1setOwnerClient(JNIEnv*, jclass, jlong _address, jbyte inClient) {
    physx::PxActor* self = (physx::PxActor*) _address;
    self->setOwnerClient(inClient);
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxActor__1getOwnerClient(JNIEnv*, jclass, jlong _address) {
    physx::PxActor* self = (physx::PxActor*) _address;
    return (jbyte) self->getOwnerClient();
}

// PxActorFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxActorFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxActorFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActorFlags__1_1placement_1new_1PxActorFlags(JNIEnv*, jclass, jlong _placement_address, jbyte flags) {
    return (jlong) new((void*)_placement_address) physx::PxActorFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActorFlags__1PxActorFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxActorFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxActorFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxActorFlags* self = (physx::PxActorFlags*) _address;
    return (jboolean) self->isSet((PxActorFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxActorFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxActorFlags* self = (physx::PxActorFlags*) _address;
    self->set((PxActorFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxActorFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxActorFlags* self = (physx::PxActorFlags*) _address;
    self->clear((PxActorFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxActorFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxActorFlags*) _address;
}

// PxActorShape
JNIEXPORT void JNICALL Java_physx_physics_PxActorShape__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxActorShape*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActorShape__1getActor(JNIEnv*, jclass, jlong _address) {
    physx::PxActorShape* _self = (physx::PxActorShape*) _address;
    return (jlong) _self->actor;
}
JNIEXPORT void JNICALL Java_physx_physics_PxActorShape__1setActor(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxActorShape* _self = (physx::PxActorShape*) _address;
    _self->actor = (physx::PxRigidActor*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActorShape__1getShape(JNIEnv*, jclass, jlong _address) {
    physx::PxActorShape* _self = (physx::PxActorShape*) _address;
    return (jlong) _self->shape;
}
JNIEXPORT void JNICALL Java_physx_physics_PxActorShape__1setShape(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxActorShape* _self = (physx::PxActorShape*) _address;
    _self->shape = (physx::PxShape*) value;
}

// PxActorTypeFlags
JNIEXPORT jlong JNICALL Java_physx_physics_PxActorTypeFlags__1PxActorTypeFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxActorTypeFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxActorTypeFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxActorTypeFlags* self = (physx::PxActorTypeFlags*) _address;
    return (jboolean) self->isSet((PxActorTypeFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxActorTypeFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxActorTypeFlags* self = (physx::PxActorTypeFlags*) _address;
    self->set((PxActorTypeFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxActorTypeFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxActorTypeFlags* self = (physx::PxActorTypeFlags*) _address;
    self->clear((PxActorTypeFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxActorTypeFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxActorTypeFlags*) _address;
}

// PxAggregate
JNIEXPORT jboolean JNICALL Java_physx_physics_PxAggregate__1addActor__JJ(JNIEnv*, jclass, jlong _address, jlong actor) {
    physx::PxAggregate* self = (physx::PxAggregate*) _address;
    return (jboolean) self->addActor(*((physx::PxActor*) actor));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxAggregate__1addActor__JJJ(JNIEnv*, jclass, jlong _address, jlong actor, jlong bvhStructure) {
    physx::PxAggregate* self = (physx::PxAggregate*) _address;
    return (jboolean) self->addActor(*((physx::PxActor*) actor), (physx::PxBVHStructure*) bvhStructure);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxAggregate__1removeActor(JNIEnv*, jclass, jlong _address, jlong actor) {
    physx::PxAggregate* self = (physx::PxAggregate*) _address;
    return (jboolean) self->removeActor(*((physx::PxActor*) actor));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxAggregate__1addArticulation(JNIEnv*, jclass, jlong _address, jlong articulation) {
    physx::PxAggregate* self = (physx::PxAggregate*) _address;
    return (jboolean) self->addArticulation(*((physx::PxArticulationBase*) articulation));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxAggregate__1removeArticulation(JNIEnv*, jclass, jlong _address, jlong articulation) {
    physx::PxAggregate* self = (physx::PxAggregate*) _address;
    return (jboolean) self->removeArticulation(*((physx::PxArticulationBase*) articulation));
}
JNIEXPORT jint JNICALL Java_physx_physics_PxAggregate__1getNbActors(JNIEnv*, jclass, jlong _address) {
    physx::PxAggregate* self = (physx::PxAggregate*) _address;
    return (jint) self->getNbActors();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxAggregate__1getMaxNbActors(JNIEnv*, jclass, jlong _address) {
    physx::PxAggregate* self = (physx::PxAggregate*) _address;
    return (jint) self->getMaxNbActors();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxAggregate__1getScene(JNIEnv*, jclass, jlong _address) {
    physx::PxAggregate* self = (physx::PxAggregate*) _address;
    return (jlong) self->getScene();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxAggregate__1getSelfCollision(JNIEnv*, jclass, jlong _address) {
    physx::PxAggregate* self = (physx::PxAggregate*) _address;
    return (jboolean) self->getSelfCollision();
}

// PxArticulation
JNIEXPORT void JNICALL Java_physx_physics_PxArticulation__1setMaxProjectionIterations(JNIEnv*, jclass, jlong _address, jint iterations) {
    physx::PxArticulation* self = (physx::PxArticulation*) _address;
    self->setMaxProjectionIterations(iterations);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulation__1getMaxProjectionIterations(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulation* self = (physx::PxArticulation*) _address;
    return (jint) self->getMaxProjectionIterations();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulation__1setSeparationTolerance(JNIEnv*, jclass, jlong _address, jfloat tolerance) {
    physx::PxArticulation* self = (physx::PxArticulation*) _address;
    self->setSeparationTolerance(tolerance);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulation__1getSeparationTolerance(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulation* self = (physx::PxArticulation*) _address;
    return (jfloat) self->getSeparationTolerance();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulation__1setInternalDriveIterations(JNIEnv*, jclass, jlong _address, jint iterations) {
    physx::PxArticulation* self = (physx::PxArticulation*) _address;
    self->setInternalDriveIterations(iterations);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulation__1getInternalDriveIterations(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulation* self = (physx::PxArticulation*) _address;
    return (jint) self->getInternalDriveIterations();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulation__1setExternalDriveIterations(JNIEnv*, jclass, jlong _address, jint iterations) {
    physx::PxArticulation* self = (physx::PxArticulation*) _address;
    self->setExternalDriveIterations(iterations);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulation__1getExternalDriveIterations(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulation* self = (physx::PxArticulation*) _address;
    return (jint) self->getExternalDriveIterations();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulation__1createDriveCache(JNIEnv*, jclass, jlong _address, jfloat compliance, jint driveIterations) {
    physx::PxArticulation* self = (physx::PxArticulation*) _address;
    return (jlong) self->createDriveCache(compliance, driveIterations);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulation__1updateDriveCache(JNIEnv*, jclass, jlong _address, jlong driveCache, jfloat compliance, jint driveIterations) {
    physx::PxArticulation* self = (physx::PxArticulation*) _address;
    self->updateDriveCache(*((physx::PxArticulationDriveCache*) driveCache), compliance, driveIterations);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulation__1releaseDriveCache(JNIEnv*, jclass, jlong _address, jlong driveCache) {
    physx::PxArticulation* self = (physx::PxArticulation*) _address;
    self->releaseDriveCache(*((physx::PxArticulationDriveCache*) driveCache));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulation__1applyImpulse(JNIEnv*, jclass, jlong _address, jlong link, jlong driveCache, jlong linearImpulse, jlong angularImpulse) {
    physx::PxArticulation* self = (physx::PxArticulation*) _address;
    self->applyImpulse((physx::PxArticulationLink*) link, *((physx::PxArticulationDriveCache*) driveCache), *((physx::PxVec3*) linearImpulse), *((physx::PxVec3*) angularImpulse));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulation__1computeImpulseResponse(JNIEnv*, jclass, jlong _address, jlong link, jlong linearResponse, jlong angularResponse, jlong driveCache, jlong linearImpulse, jlong angularImpulse) {
    physx::PxArticulation* self = (physx::PxArticulation*) _address;
    self->computeImpulseResponse((physx::PxArticulationLink*) link, *((physx::PxVec3*) linearResponse), *((physx::PxVec3*) angularResponse), *((physx::PxArticulationDriveCache*) driveCache), *((physx::PxVec3*) linearImpulse), *((physx::PxVec3*) angularImpulse));
}

// PxArticulationBase
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationBase__1getScene(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationBase* self = (physx::PxArticulationBase*) _address;
    return (jlong) self->getScene();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationBase__1setSolverIterationCounts(JNIEnv*, jclass, jlong _address, jint minPositionIters, jint minVelocityIters) {
    physx::PxArticulationBase* self = (physx::PxArticulationBase*) _address;
    self->setSolverIterationCounts(minPositionIters, minVelocityIters);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxArticulationBase__1isSleeping(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationBase* self = (physx::PxArticulationBase*) _address;
    return (jboolean) self->isSleeping();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationBase__1setSleepThreshold(JNIEnv*, jclass, jlong _address, jfloat threshold) {
    physx::PxArticulationBase* self = (physx::PxArticulationBase*) _address;
    self->setSleepThreshold(threshold);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationBase__1getSleepThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationBase* self = (physx::PxArticulationBase*) _address;
    return (jfloat) self->getSleepThreshold();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationBase__1setStabilizationThreshold(JNIEnv*, jclass, jlong _address, jfloat threshold) {
    physx::PxArticulationBase* self = (physx::PxArticulationBase*) _address;
    self->setStabilizationThreshold(threshold);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationBase__1getStabilizationThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationBase* self = (physx::PxArticulationBase*) _address;
    return (jfloat) self->getStabilizationThreshold();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationBase__1setWakeCounter(JNIEnv*, jclass, jlong _address, jfloat wakeCounterValue) {
    physx::PxArticulationBase* self = (physx::PxArticulationBase*) _address;
    self->setWakeCounter(wakeCounterValue);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationBase__1getWakeCounter(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationBase* self = (physx::PxArticulationBase*) _address;
    return (jfloat) self->getWakeCounter();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationBase__1wakeUp(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationBase* self = (physx::PxArticulationBase*) _address;
    self->wakeUp();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationBase__1putToSleep(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationBase* self = (physx::PxArticulationBase*) _address;
    self->putToSleep();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationBase__1createLink(JNIEnv*, jclass, jlong _address, jlong parent, jlong pose) {
    physx::PxArticulationBase* self = (physx::PxArticulationBase*) _address;
    return (jlong) self->createLink((physx::PxArticulationLink*) parent, *((physx::PxTransform*) pose));
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationBase__1getNbLinks(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationBase* self = (physx::PxArticulationBase*) _address;
    return (jint) self->getNbLinks();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationBase__1setName(JNIEnv* _env, jclass, jlong _address, jstring name) {
    physx::PxArticulationBase* self = (physx::PxArticulationBase*) _address;
    self->setName(_env->GetStringUTFChars(name, 0));
}
JNIEXPORT jstring JNICALL Java_physx_physics_PxArticulationBase__1getName(JNIEnv* _env, jclass, jlong _address) {
    physx::PxArticulationBase* self = (physx::PxArticulationBase*) _address;
    return _env->NewStringUTF(self->getName());
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationBase__1getWorldBounds(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxBounds3 _cache;
    physx::PxArticulationBase* self = (physx::PxArticulationBase*) _address;
    _cache = self->getWorldBounds();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationBase__1getAggregate(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationBase* self = (physx::PxArticulationBase*) _address;
    return (jlong) self->getAggregate();
}

// PxArticulationCache

// PxArticulationCacheFlags
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationCacheFlags__1PxArticulationCacheFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxArticulationCacheFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxArticulationCacheFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxArticulationCacheFlags* self = (physx::PxArticulationCacheFlags*) _address;
    return (jboolean) self->isSet((PxArticulationCacheEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCacheFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxArticulationCacheFlags* self = (physx::PxArticulationCacheFlags*) _address;
    self->set((PxArticulationCacheEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCacheFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxArticulationCacheFlags* self = (physx::PxArticulationCacheFlags*) _address;
    self->clear((PxArticulationCacheEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationCacheFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxArticulationCacheFlags*) _address;
}

// PxArticulationDriveCache

// PxArticulationFlags
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationFlags__1PxArticulationFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxArticulationFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxArticulationFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxArticulationFlags* self = (physx::PxArticulationFlags*) _address;
    return (jboolean) self->isSet((PxArticulationFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxArticulationFlags* self = (physx::PxArticulationFlags*) _address;
    self->set((PxArticulationFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxArticulationFlags* self = (physx::PxArticulationFlags*) _address;
    self->clear((PxArticulationFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxArticulationFlags*) _address;
}

// PxArticulationJoint
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJoint__1setTargetOrientation(JNIEnv*, jclass, jlong _address, jlong orientation) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    self->setTargetOrientation(*((physx::PxQuat*) orientation));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationJoint__1getTargetOrientation(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxQuat _cache;
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    _cache = self->getTargetOrientation();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJoint__1setTargetVelocity(JNIEnv*, jclass, jlong _address, jlong velocity) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    self->setTargetVelocity(*((physx::PxVec3*) velocity));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationJoint__1getTargetVelocity(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxVec3 _cache;
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    _cache = self->getTargetVelocity();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJoint__1setDriveType(JNIEnv*, jclass, jlong _address, jint driveType) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    self->setDriveType((PxArticulationJointDriveTypeEnum) driveType);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationJoint__1getDriveType(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    return (jint) self->getDriveType();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJoint__1setStiffness(JNIEnv*, jclass, jlong _address, jfloat spring) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    self->setStiffness(spring);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationJoint__1getStiffness(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    return (jfloat) self->getStiffness();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJoint__1setDamping(JNIEnv*, jclass, jlong _address, jfloat damping) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    self->setDamping(damping);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationJoint__1getDamping(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    return (jfloat) self->getDamping();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJoint__1setInternalCompliance(JNIEnv*, jclass, jlong _address, jfloat compliance) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    self->setInternalCompliance(compliance);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationJoint__1getInternalCompliance(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    return (jfloat) self->getInternalCompliance();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJoint__1setExternalCompliance(JNIEnv*, jclass, jlong _address, jfloat compliance) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    self->setExternalCompliance(compliance);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationJoint__1getExternalCompliance(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    return (jfloat) self->getExternalCompliance();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJoint__1setSwingLimit(JNIEnv*, jclass, jlong _address, jfloat zLimit, jfloat yLimit) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    self->setSwingLimit(zLimit, yLimit);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJoint__1setTangentialStiffness(JNIEnv*, jclass, jlong _address, jfloat spring) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    self->setTangentialStiffness(spring);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationJoint__1getTangentialStiffness(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    return (jfloat) self->getTangentialStiffness();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJoint__1setTangentialDamping(JNIEnv*, jclass, jlong _address, jfloat damping) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    self->setTangentialDamping(damping);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationJoint__1getTangentialDamping(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    return (jfloat) self->getTangentialDamping();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJoint__1setSwingLimitContactDistance(JNIEnv*, jclass, jlong _address, jfloat contactDistance) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    self->setSwingLimitContactDistance(contactDistance);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationJoint__1getSwingLimitContactDistance(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    return (jfloat) self->getSwingLimitContactDistance();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJoint__1setSwingLimitEnabled(JNIEnv*, jclass, jlong _address, jboolean enabled) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    self->setSwingLimitEnabled(enabled);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxArticulationJoint__1getSwingLimitEnabled(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    return (jboolean) self->getSwingLimitEnabled();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJoint__1setTwistLimit(JNIEnv*, jclass, jlong _address, jfloat lower, jfloat upper) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    self->setTwistLimit(lower, upper);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJoint__1setTwistLimitEnabled(JNIEnv*, jclass, jlong _address, jboolean enabled) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    self->setTwistLimitEnabled(enabled);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxArticulationJoint__1getTwistLimitEnabled(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    return (jboolean) self->getTwistLimitEnabled();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJoint__1setTwistLimitContactDistance(JNIEnv*, jclass, jlong _address, jfloat contactDistance) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    self->setTwistLimitContactDistance(contactDistance);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationJoint__1getTwistLimitContactDistance(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJoint* self = (physx::PxArticulationJoint*) _address;
    return (jfloat) self->getTwistLimitContactDistance();
}

// PxArticulationJointBase
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationJointBase__1getParentArticulationLink(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJointBase* self = (physx::PxArticulationJointBase*) _address;
    return (jlong) &self->getParentArticulationLink();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointBase__1setParentPose(JNIEnv*, jclass, jlong _address, jlong pose) {
    physx::PxArticulationJointBase* self = (physx::PxArticulationJointBase*) _address;
    self->setParentPose(*((physx::PxTransform*) pose));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationJointBase__1getParentPose(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxTransform _cache;
    physx::PxArticulationJointBase* self = (physx::PxArticulationJointBase*) _address;
    _cache = self->getParentPose();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationJointBase__1getChildArticulationLink(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJointBase* self = (physx::PxArticulationJointBase*) _address;
    return (jlong) &self->getChildArticulationLink();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointBase__1setChildPose(JNIEnv*, jclass, jlong _address, jlong pose) {
    physx::PxArticulationJointBase* self = (physx::PxArticulationJointBase*) _address;
    self->setChildPose(*((physx::PxTransform*) pose));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationJointBase__1getChildPose(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxTransform _cache;
    physx::PxArticulationJointBase* self = (physx::PxArticulationJointBase*) _address;
    _cache = self->getChildPose();
    return (jlong) &_cache;
}

// PxArticulationJointReducedCoordinate
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setJointType(JNIEnv*, jclass, jlong _address, jint jointType) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setJointType((PxArticulationJointTypeEnum) jointType);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1getJointType(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    return (jint) self->getJointType();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setMotion(JNIEnv*, jclass, jlong _address, jint axis, jint motion) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setMotion((PxArticulationAxisEnum) axis, (PxArticulationMotionEnum) motion);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1getMotion(JNIEnv*, jclass, jlong _address, jint axis) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    return (jint) self->getMotion((PxArticulationAxisEnum) axis);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setLimit(JNIEnv*, jclass, jlong _address, jint axis, jfloat lowLimit, jfloat highLimit) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setLimit((PxArticulationAxisEnum) axis, lowLimit, highLimit);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setDrive__JIFFF(JNIEnv*, jclass, jlong _address, jint axis, jfloat stiffness, jfloat damping, jfloat maxForce) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setDrive((PxArticulationAxisEnum) axis, stiffness, damping, maxForce);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setDrive__JIFFFI(JNIEnv*, jclass, jlong _address, jint axis, jfloat stiffness, jfloat damping, jfloat maxForce, jint driveType) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setDrive((PxArticulationAxisEnum) axis, stiffness, damping, maxForce, (PxArticulationDriveTypeEnum) driveType);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setDriveTarget(JNIEnv*, jclass, jlong _address, jint axis, jfloat target) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setDriveTarget((PxArticulationAxisEnum) axis, target);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setDriveVelocity(JNIEnv*, jclass, jlong _address, jint axis, jfloat targetVel) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setDriveVelocity((PxArticulationAxisEnum) axis, targetVel);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1getDriveTarget(JNIEnv*, jclass, jlong _address, jint axis) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    return (jfloat) self->getDriveTarget((PxArticulationAxisEnum) axis);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1getDriveVelocity(JNIEnv*, jclass, jlong _address, jint axis) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    return (jfloat) self->getDriveVelocity((PxArticulationAxisEnum) axis);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setFrictionCoefficient(JNIEnv*, jclass, jlong _address, jfloat coefficient) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setFrictionCoefficient(coefficient);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1getFrictionCoefficient(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    return (jfloat) self->getFrictionCoefficient();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1setMaxJointVelocity(JNIEnv*, jclass, jlong _address, jfloat maxJointV) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    self->setMaxJointVelocity(maxJointV);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxArticulationJointReducedCoordinate__1getMaxJointVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationJointReducedCoordinate* self = (physx::PxArticulationJointReducedCoordinate*) _address;
    return (jfloat) self->getMaxJointVelocity();
}

// PxArticulationLink
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationLink__1getArticulation(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationLink* self = (physx::PxArticulationLink*) _address;
    return (jlong) &self->getArticulation();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationLink__1getInboundJoint(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationLink* self = (physx::PxArticulationLink*) _address;
    return (jlong) self->getInboundJoint();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationLink__1getInboundJointDof(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationLink* self = (physx::PxArticulationLink*) _address;
    return (jint) self->getInboundJointDof();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationLink__1getNbChildren(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationLink* self = (physx::PxArticulationLink*) _address;
    return (jint) self->getNbChildren();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationLink__1getLinkIndex(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationLink* self = (physx::PxArticulationLink*) _address;
    return (jint) self->getLinkIndex();
}

// PxArticulationReducedCoordinate
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1setArticulationFlags(JNIEnv*, jclass, jlong _address, jlong flags) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->setArticulationFlags(*((physx::PxArticulationFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1setArticulationFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->setArticulationFlag((PxArticulationFlagEnum) flag, value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getArticulationFlags(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxArticulationFlags _cache;
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    _cache = self->getArticulationFlags();
    return (jlong) &_cache;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getDofs(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jint) self->getDofs();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1createCache(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jlong) self->createCache();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getCacheDataSize(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jint) self->getCacheDataSize();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1zeroCache(JNIEnv*, jclass, jlong _address, jlong cache) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->zeroCache(*((physx::PxArticulationCache*) cache));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1applyCache__JJJ(JNIEnv*, jclass, jlong _address, jlong cache, jlong flag) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->applyCache(*((physx::PxArticulationCache*) cache), *((physx::PxArticulationCacheFlags*) flag));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1applyCache__JJJZ(JNIEnv*, jclass, jlong _address, jlong cache, jlong flag, jboolean autowake) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->applyCache(*((physx::PxArticulationCache*) cache), *((physx::PxArticulationCacheFlags*) flag), autowake);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1copyInternalStateToCache(JNIEnv*, jclass, jlong _address, jlong cache, jlong flag) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->copyInternalStateToCache(*((physx::PxArticulationCache*) cache), *((physx::PxArticulationCacheFlags*) flag));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1releaseCache(JNIEnv*, jclass, jlong _address, jlong cache) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->releaseCache(*((physx::PxArticulationCache*) cache));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1packJointData(JNIEnv*, jclass, jlong _address, jlong maximum, jlong reduced) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->packJointData(*((PxRealPtr*) maximum), *((PxRealPtr*) reduced));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1unpackJointData(JNIEnv*, jclass, jlong _address, jlong reduced, jlong maximum) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->unpackJointData(*((PxRealPtr*) reduced), *((PxRealPtr*) maximum));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1commonInit(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->commonInit();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1computeGeneralizedGravityForce(JNIEnv*, jclass, jlong _address, jlong cache) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->computeGeneralizedGravityForce(*((physx::PxArticulationCache*) cache));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1computeCoriolisAndCentrifugalForce(JNIEnv*, jclass, jlong _address, jlong cache) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->computeCoriolisAndCentrifugalForce(*((physx::PxArticulationCache*) cache));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1computeGeneralizedExternalForce(JNIEnv*, jclass, jlong _address, jlong cache) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->computeGeneralizedExternalForce(*((physx::PxArticulationCache*) cache));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1computeJointAcceleration(JNIEnv*, jclass, jlong _address, jlong cache) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->computeJointAcceleration(*((physx::PxArticulationCache*) cache));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1computeJointForce(JNIEnv*, jclass, jlong _address, jlong cache) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->computeJointForce(*((physx::PxArticulationCache*) cache));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1computeCoefficientMatrix(JNIEnv*, jclass, jlong _address, jlong cache) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->computeCoefficientMatrix(*((physx::PxArticulationCache*) cache));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1computeLambda(JNIEnv*, jclass, jlong _address, jlong cache, jlong initialState, jlong jointTorque, jint maxIter) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->computeLambda(*((physx::PxArticulationCache*) cache), *((physx::PxArticulationCache*) initialState), *((PxRealPtr*) jointTorque), maxIter);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1computeGeneralizedMassMatrix(JNIEnv*, jclass, jlong _address, jlong cache) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->computeGeneralizedMassMatrix(*((physx::PxArticulationCache*) cache));
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1addLoopJoint(JNIEnv*, jclass, jlong _address, jlong joint) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->addLoopJoint((physx::PxJoint*) joint);
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1removeLoopJoint(JNIEnv*, jclass, jlong _address, jlong joint) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->removeLoopJoint((physx::PxJoint*) joint);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getNbLoopJoints(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jint) self->getNbLoopJoints();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getCoefficientMatrixSize(JNIEnv*, jclass, jlong _address) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    return (jint) self->getCoefficientMatrixSize();
}
JNIEXPORT void JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1teleportRootLink(JNIEnv*, jclass, jlong _address, jlong pose, jboolean autowake) {
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    self->teleportRootLink(*((physx::PxTransform*) pose), autowake);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getLinkVelocity(JNIEnv*, jclass, jlong _address, jint linkId) {
    static thread_local physx::PxSpatialVelocity _cache;
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    _cache = self->getLinkVelocity(linkId);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxArticulationReducedCoordinate__1getLinkAcceleration(JNIEnv*, jclass, jlong _address, jint linkId) {
    static thread_local physx::PxSpatialVelocity _cache;
    physx::PxArticulationReducedCoordinate* self = (physx::PxArticulationReducedCoordinate*) _address;
    _cache = self->getLinkAcceleration(linkId);
    return (jlong) &_cache;
}

// PxBatchQuery
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQuery__1execute(JNIEnv*, jclass, jlong _address) {
    physx::PxBatchQuery* self = (physx::PxBatchQuery*) _address;
    self->execute();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQuery__1getPreFilterShader(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxBatchQueryPreFilterShader _cache;
    physx::PxBatchQuery* self = (physx::PxBatchQuery*) _address;
    _cache = self->getPreFilterShader();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQuery__1getPostFilterShader(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxBatchQueryPostFilterShader _cache;
    physx::PxBatchQuery* self = (physx::PxBatchQuery*) _address;
    _cache = self->getPostFilterShader();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQuery__1getFilterShaderData(JNIEnv*, jclass, jlong _address) {
    physx::PxBatchQuery* self = (physx::PxBatchQuery*) _address;
    return (jlong) self->getFilterShaderData();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBatchQuery__1getFilterShaderDataSize(JNIEnv*, jclass, jlong _address) {
    physx::PxBatchQuery* self = (physx::PxBatchQuery*) _address;
    return (jint) self->getFilterShaderDataSize();
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQuery__1setUserMemory(JNIEnv*, jclass, jlong _address, jlong userMemory) {
    physx::PxBatchQuery* self = (physx::PxBatchQuery*) _address;
    self->setUserMemory(*((physx::PxBatchQueryMemory*) userMemory));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQuery__1getUserMemory(JNIEnv*, jclass, jlong _address) {
    physx::PxBatchQuery* self = (physx::PxBatchQuery*) _address;
    return (jlong) &self->getUserMemory();
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQuery__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxBatchQuery* self = (physx::PxBatchQuery*) _address;
    self->release();
}

// PxBatchQueryDesc
JNIEXPORT jint JNICALL Java_physx_physics_PxBatchQueryDesc__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxBatchQueryDesc);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryDesc__1_1placement_1new_1PxBatchQueryDesc(JNIEnv*, jclass, jlong _placement_address, jint maxRaycastsPerExecute, jint maxSweepsPerExecute, jint maxOverlapsPerExecute) {
    return (jlong) new((void*)_placement_address) physx::PxBatchQueryDesc(maxRaycastsPerExecute, maxSweepsPerExecute, maxOverlapsPerExecute);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryDesc__1PxBatchQueryDesc(JNIEnv*, jclass, jint maxRaycastsPerExecute, jint maxSweepsPerExecute, jint maxOverlapsPerExecute) {
    return (jlong) new physx::PxBatchQueryDesc(maxRaycastsPerExecute, maxSweepsPerExecute, maxOverlapsPerExecute);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxBatchQueryDesc__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxBatchQueryDesc* self = (physx::PxBatchQueryDesc*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBatchQueryDesc*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryDesc__1getFilterShaderData(JNIEnv*, jclass, jlong _address) {
    physx::PxBatchQueryDesc* _self = (physx::PxBatchQueryDesc*) _address;
    return (jlong) _self->filterShaderData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryDesc__1setFilterShaderData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBatchQueryDesc* _self = (physx::PxBatchQueryDesc*) _address;
    _self->filterShaderData = (void*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBatchQueryDesc__1getFilterShaderDataSize(JNIEnv*, jclass, jlong _address) {
    physx::PxBatchQueryDesc* _self = (physx::PxBatchQueryDesc*) _address;
    return (jint) _self->filterShaderDataSize;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryDesc__1setFilterShaderDataSize(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxBatchQueryDesc* _self = (physx::PxBatchQueryDesc*) _address;
    _self->filterShaderDataSize = value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryDesc__1getPreFilterShader(JNIEnv*, jclass, jlong _address) {
    physx::PxBatchQueryDesc* _self = (physx::PxBatchQueryDesc*) _address;
    return (jlong) &_self->preFilterShader;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryDesc__1setPreFilterShader(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBatchQueryDesc* _self = (physx::PxBatchQueryDesc*) _address;
    _self->preFilterShader = *((physx::PxBatchQueryPreFilterShader*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryDesc__1getPostFilterShader(JNIEnv*, jclass, jlong _address) {
    physx::PxBatchQueryDesc* _self = (physx::PxBatchQueryDesc*) _address;
    return (jlong) &_self->postFilterShader;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryDesc__1setPostFilterShader(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBatchQueryDesc* _self = (physx::PxBatchQueryDesc*) _address;
    _self->postFilterShader = *((physx::PxBatchQueryPostFilterShader*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryDesc__1getQueryMemory(JNIEnv*, jclass, jlong _address) {
    physx::PxBatchQueryDesc* _self = (physx::PxBatchQueryDesc*) _address;
    return (jlong) &_self->queryMemory;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryDesc__1setQueryMemory(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBatchQueryDesc* _self = (physx::PxBatchQueryDesc*) _address;
    _self->queryMemory = *((physx::PxBatchQueryMemory*) value);
}

// PxBatchQueryMemory
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryMemory__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBatchQueryMemory*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryMemory__1getUserRaycastResultBuffer(JNIEnv*, jclass, jlong _address) {
    physx::PxBatchQueryMemory* _self = (physx::PxBatchQueryMemory*) _address;
    return (jlong) _self->userRaycastResultBuffer;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryMemory__1setUserRaycastResultBuffer(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBatchQueryMemory* _self = (physx::PxBatchQueryMemory*) _address;
    _self->userRaycastResultBuffer = (physx::PxRaycastQueryResult*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryMemory__1getUserRaycastTouchBuffer(JNIEnv*, jclass, jlong _address) {
    physx::PxBatchQueryMemory* _self = (physx::PxBatchQueryMemory*) _address;
    return (jlong) _self->userRaycastTouchBuffer;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryMemory__1setUserRaycastTouchBuffer(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBatchQueryMemory* _self = (physx::PxBatchQueryMemory*) _address;
    _self->userRaycastTouchBuffer = (physx::PxRaycastHit*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryMemory__1getUserSweepResultBuffer(JNIEnv*, jclass, jlong _address) {
    physx::PxBatchQueryMemory* _self = (physx::PxBatchQueryMemory*) _address;
    return (jlong) _self->userSweepResultBuffer;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryMemory__1setUserSweepResultBuffer(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBatchQueryMemory* _self = (physx::PxBatchQueryMemory*) _address;
    _self->userSweepResultBuffer = (physx::PxSweepQueryResult*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryMemory__1getUserSweepTouchBuffer(JNIEnv*, jclass, jlong _address) {
    physx::PxBatchQueryMemory* _self = (physx::PxBatchQueryMemory*) _address;
    return (jlong) _self->userSweepTouchBuffer;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryMemory__1setUserSweepTouchBuffer(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBatchQueryMemory* _self = (physx::PxBatchQueryMemory*) _address;
    _self->userSweepTouchBuffer = (physx::PxSweepHit*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryMemory__1getUserOverlapResultBuffer(JNIEnv*, jclass, jlong _address) {
    physx::PxBatchQueryMemory* _self = (physx::PxBatchQueryMemory*) _address;
    return (jlong) _self->userOverlapResultBuffer;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryMemory__1setUserOverlapResultBuffer(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBatchQueryMemory* _self = (physx::PxBatchQueryMemory*) _address;
    _self->userOverlapResultBuffer = (physx::PxOverlapQueryResult*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryMemory__1getUserOverlapTouchBuffer(JNIEnv*, jclass, jlong _address) {
    physx::PxBatchQueryMemory* _self = (physx::PxBatchQueryMemory*) _address;
    return (jlong) _self->userOverlapTouchBuffer;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryMemory__1setUserOverlapTouchBuffer(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBatchQueryMemory* _self = (physx::PxBatchQueryMemory*) _address;
    _self->userOverlapTouchBuffer = (physx::PxOverlapHit*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBatchQueryMemory__1getRaycastTouchBufferSize(JNIEnv*, jclass, jlong _address) {
    physx::PxBatchQueryMemory* _self = (physx::PxBatchQueryMemory*) _address;
    return (jint) _self->raycastTouchBufferSize;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryMemory__1setRaycastTouchBufferSize(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxBatchQueryMemory* _self = (physx::PxBatchQueryMemory*) _address;
    _self->raycastTouchBufferSize = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBatchQueryMemory__1getSweepTouchBufferSize(JNIEnv*, jclass, jlong _address) {
    physx::PxBatchQueryMemory* _self = (physx::PxBatchQueryMemory*) _address;
    return (jint) _self->sweepTouchBufferSize;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryMemory__1setSweepTouchBufferSize(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxBatchQueryMemory* _self = (physx::PxBatchQueryMemory*) _address;
    _self->sweepTouchBufferSize = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBatchQueryMemory__1getOverlapTouchBufferSize(JNIEnv*, jclass, jlong _address) {
    physx::PxBatchQueryMemory* _self = (physx::PxBatchQueryMemory*) _address;
    return (jint) _self->overlapTouchBufferSize;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryMemory__1setOverlapTouchBufferSize(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxBatchQueryMemory* _self = (physx::PxBatchQueryMemory*) _address;
    _self->overlapTouchBufferSize = value;
}

// PxBatchQueryPostFilterShader
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryPostFilterShader__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBatchQueryPostFilterShader*) _address;
}

// PxBatchQueryPreFilterShader
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryPreFilterShader__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBatchQueryPreFilterShader*) _address;
}

// PxBroadPhaseCaps
JNIEXPORT jlong JNICALL Java_physx_physics_PxBroadPhaseCaps__1PxBroadPhaseCaps(JNIEnv*, jclass) {
    return (jlong) new physx::PxBroadPhaseCaps();
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseCaps__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBroadPhaseCaps*) _address;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBroadPhaseCaps__1getMaxNbRegions(JNIEnv*, jclass, jlong _address) {
    physx::PxBroadPhaseCaps* _self = (physx::PxBroadPhaseCaps*) _address;
    return (jint) _self->maxNbRegions;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseCaps__1setMaxNbRegions(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxBroadPhaseCaps* _self = (physx::PxBroadPhaseCaps*) _address;
    _self->maxNbRegions = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBroadPhaseCaps__1getMaxNbObjects(JNIEnv*, jclass, jlong _address) {
    physx::PxBroadPhaseCaps* _self = (physx::PxBroadPhaseCaps*) _address;
    return (jint) _self->maxNbObjects;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseCaps__1setMaxNbObjects(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxBroadPhaseCaps* _self = (physx::PxBroadPhaseCaps*) _address;
    _self->maxNbObjects = value;
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxBroadPhaseCaps__1getNeedsPredefinedBounds(JNIEnv*, jclass, jlong _address) {
    physx::PxBroadPhaseCaps* _self = (physx::PxBroadPhaseCaps*) _address;
    return (jboolean) _self->needsPredefinedBounds;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseCaps__1setNeedsPredefinedBounds(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxBroadPhaseCaps* _self = (physx::PxBroadPhaseCaps*) _address;
    _self->needsPredefinedBounds = value;
}

// PxBroadPhaseRegion
JNIEXPORT jlong JNICALL Java_physx_physics_PxBroadPhaseRegion__1PxBroadPhaseRegion(JNIEnv*, jclass) {
    return (jlong) new physx::PxBroadPhaseRegion();
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseRegion__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBroadPhaseRegion*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBroadPhaseRegion__1getBounds(JNIEnv*, jclass, jlong _address) {
    physx::PxBroadPhaseRegion* _self = (physx::PxBroadPhaseRegion*) _address;
    return (jlong) &_self->bounds;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseRegion__1setBounds(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBroadPhaseRegion* _self = (physx::PxBroadPhaseRegion*) _address;
    _self->bounds = *((physx::PxBounds3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBroadPhaseRegion__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxBroadPhaseRegion* _self = (physx::PxBroadPhaseRegion*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseRegion__1setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBroadPhaseRegion* _self = (physx::PxBroadPhaseRegion*) _address;
    _self->userData = (void*) value;
}

// PxBroadPhaseRegionInfo
JNIEXPORT jlong JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1PxBroadPhaseRegionInfo(JNIEnv*, jclass) {
    return (jlong) new physx::PxBroadPhaseRegionInfo();
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxBroadPhaseRegionInfo*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1getRegion(JNIEnv*, jclass, jlong _address) {
    physx::PxBroadPhaseRegionInfo* _self = (physx::PxBroadPhaseRegionInfo*) _address;
    return (jlong) &_self->region;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1setRegion(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxBroadPhaseRegionInfo* _self = (physx::PxBroadPhaseRegionInfo*) _address;
    _self->region = *((physx::PxBroadPhaseRegion*) value);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1getNbStaticObjects(JNIEnv*, jclass, jlong _address) {
    physx::PxBroadPhaseRegionInfo* _self = (physx::PxBroadPhaseRegionInfo*) _address;
    return (jint) _self->nbStaticObjects;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1setNbStaticObjects(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxBroadPhaseRegionInfo* _self = (physx::PxBroadPhaseRegionInfo*) _address;
    _self->nbStaticObjects = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1getNbDynamicObjects(JNIEnv*, jclass, jlong _address) {
    physx::PxBroadPhaseRegionInfo* _self = (physx::PxBroadPhaseRegionInfo*) _address;
    return (jint) _self->nbDynamicObjects;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1setNbDynamicObjects(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxBroadPhaseRegionInfo* _self = (physx::PxBroadPhaseRegionInfo*) _address;
    _self->nbDynamicObjects = value;
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1getActive(JNIEnv*, jclass, jlong _address) {
    physx::PxBroadPhaseRegionInfo* _self = (physx::PxBroadPhaseRegionInfo*) _address;
    return (jboolean) _self->active;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1setActive(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxBroadPhaseRegionInfo* _self = (physx::PxBroadPhaseRegionInfo*) _address;
    _self->active = value;
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1getOverlap(JNIEnv*, jclass, jlong _address) {
    physx::PxBroadPhaseRegionInfo* _self = (physx::PxBroadPhaseRegionInfo*) _address;
    return (jboolean) _self->overlap;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBroadPhaseRegionInfo__1setOverlap(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxBroadPhaseRegionInfo* _self = (physx::PxBroadPhaseRegionInfo*) _address;
    _self->overlap = value;
}

// PxConstraint
JNIEXPORT void JNICALL Java_physx_physics_PxConstraint__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    self->release();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxConstraint__1getScene(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    return (jlong) self->getScene();
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraint__1setActors(JNIEnv*, jclass, jlong _address, jlong actor0, jlong actor1) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    self->setActors((physx::PxRigidActor*) actor0, (physx::PxRigidActor*) actor1);
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraint__1markDirty(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    self->markDirty();
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraint__1setFlags(JNIEnv*, jclass, jlong _address, jlong flags) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    self->setFlags(*((physx::PxConstraintFlags*) flags));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxConstraint__1getFlags(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxConstraintFlags _cache;
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    _cache = self->getFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraint__1setFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    self->setFlag((PxConstraintFlagEnum) flag, value);
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraint__1getForce(JNIEnv*, jclass, jlong _address, jlong linear, jlong angular) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    self->getForce(*((physx::PxVec3*) linear), *((physx::PxVec3*) angular));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxConstraint__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraint__1setBreakForce(JNIEnv*, jclass, jlong _address, jfloat linear, jfloat angular) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    self->setBreakForce(linear, angular);
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraint__1setMinResponseThreshold(JNIEnv*, jclass, jlong _address, jfloat threshold) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    self->setMinResponseThreshold(threshold);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxConstraint__1getMinResponseThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraint* self = (physx::PxConstraint*) _address;
    return (jfloat) self->getMinResponseThreshold();
}

// PxConstraintFlags
JNIEXPORT jlong JNICALL Java_physx_physics_PxConstraintFlags__1PxConstraintFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxConstraintFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxConstraintFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxConstraintFlags* self = (physx::PxConstraintFlags*) _address;
    return (jboolean) self->isSet((PxConstraintFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxConstraintFlags* self = (physx::PxConstraintFlags*) _address;
    self->set((PxConstraintFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxConstraintFlags* self = (physx::PxConstraintFlags*) _address;
    self->clear((PxConstraintFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxConstraintFlags*) _address;
}

// PxConstraintInfo
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintInfo__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxConstraintInfo*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxConstraintInfo__1getConstraint(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraintInfo* _self = (physx::PxConstraintInfo*) _address;
    return (jlong) _self->constraint;
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintInfo__1setConstraint(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxConstraintInfo* _self = (physx::PxConstraintInfo*) _address;
    _self->constraint = (physx::PxConstraint*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxConstraintInfo__1getExternalReference(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraintInfo* _self = (physx::PxConstraintInfo*) _address;
    return (jlong) _self->externalReference;
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintInfo__1setExternalReference(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxConstraintInfo* _self = (physx::PxConstraintInfo*) _address;
    _self->externalReference = (void*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintInfo__1getType(JNIEnv*, jclass, jlong _address) {
    physx::PxConstraintInfo* _self = (physx::PxConstraintInfo*) _address;
    return (jint) _self->type;
}
JNIEXPORT void JNICALL Java_physx_physics_PxConstraintInfo__1setType(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxConstraintInfo* _self = (physx::PxConstraintInfo*) _address;
    _self->type = value;
}

// PxContactPairHeaderFlags
JNIEXPORT jlong JNICALL Java_physx_physics_PxContactPairHeaderFlags__1PxContactPairHeaderFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxContactPairHeaderFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxContactPairHeaderFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxContactPairHeaderFlags* self = (physx::PxContactPairHeaderFlags*) _address;
    return (jboolean) self->isSet((PxContactPairHeaderFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairHeaderFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxContactPairHeaderFlags* self = (physx::PxContactPairHeaderFlags*) _address;
    self->set((PxContactPairHeaderFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairHeaderFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxContactPairHeaderFlags* self = (physx::PxContactPairHeaderFlags*) _address;
    self->clear((PxContactPairHeaderFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairHeaderFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxContactPairHeaderFlags*) _address;
}

// PxContactPair
JNIEXPORT void JNICALL Java_physx_physics_PxContactPair__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxContactPair*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxContactPair__1getShapes(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::PxContactPair* _self = (physx::PxContactPair*) _address;
    return (jlong) _self->shapes[_index];
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPair__1setShapes(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    physx::PxContactPair* _self = (physx::PxContactPair*) _address;
    _self->shapes[_index] = (physx::PxShape*) value;
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxContactPair__1getContactCount(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPair* _self = (physx::PxContactPair*) _address;
    return (jbyte) _self->contactCount;
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPair__1setContactCount(JNIEnv*, jclass, jlong _address, jbyte value) {
    physx::PxContactPair* _self = (physx::PxContactPair*) _address;
    _self->contactCount = value;
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxContactPair__1getPatchCount(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPair* _self = (physx::PxContactPair*) _address;
    return (jbyte) _self->patchCount;
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPair__1setPatchCount(JNIEnv*, jclass, jlong _address, jbyte value) {
    physx::PxContactPair* _self = (physx::PxContactPair*) _address;
    _self->patchCount = value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxContactPair__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPair* _self = (physx::PxContactPair*) _address;
    return (jlong) &_self->flags;
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPair__1setFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxContactPair* _self = (physx::PxContactPair*) _address;
    _self->flags = *((physx::PxContactPairFlags*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxContactPair__1getEvents(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPair* _self = (physx::PxContactPair*) _address;
    return (jlong) &_self->events;
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPair__1setEvents(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxContactPair* _self = (physx::PxContactPair*) _address;
    _self->events = *((physx::PxPairFlags*) value);
}

// PxContactPairFlags
JNIEXPORT jlong JNICALL Java_physx_physics_PxContactPairFlags__1PxContactPairFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxContactPairFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxContactPairFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxContactPairFlags* self = (physx::PxContactPairFlags*) _address;
    return (jboolean) self->isSet((PxContactPairFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxContactPairFlags* self = (physx::PxContactPairFlags*) _address;
    self->set((PxContactPairFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxContactPairFlags* self = (physx::PxContactPairFlags*) _address;
    self->clear((PxContactPairFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxContactPairFlags*) _address;
}

// PxContactPairHeader
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairHeader__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxContactPairHeader*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxContactPairHeader__1getActors(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::PxContactPairHeader* _self = (physx::PxContactPairHeader*) _address;
    return (jlong) _self->actors[_index];
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairHeader__1setActors(JNIEnv*, jclass, jlong _address, jint _index, jlong value) {
    physx::PxContactPairHeader* _self = (physx::PxContactPairHeader*) _address;
    _self->actors[_index] = (physx::PxRigidActor*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxContactPairHeader__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPairHeader* _self = (physx::PxContactPairHeader*) _address;
    return (jlong) &_self->flags;
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairHeader__1setFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxContactPairHeader* _self = (physx::PxContactPairHeader*) _address;
    _self->flags = *((physx::PxContactPairHeaderFlags*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxContactPairHeader__1getPairs(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPairHeader* _self = (physx::PxContactPairHeader*) _address;
    return (jlong) _self->pairs;
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairHeader__1setPairs(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxContactPairHeader* _self = (physx::PxContactPairHeader*) _address;
    _self->pairs = (physx::PxContactPair*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairHeader__1getNbPairs(JNIEnv*, jclass, jlong _address) {
    physx::PxContactPairHeader* _self = (physx::PxContactPairHeader*) _address;
    return (jint) _self->nbPairs;
}
JNIEXPORT void JNICALL Java_physx_physics_PxContactPairHeader__1setNbPairs(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxContactPairHeader* _self = (physx::PxContactPairHeader*) _address;
    _self->nbPairs = value;
}

// PxDominanceGroupPair
JNIEXPORT jlong JNICALL Java_physx_physics_PxDominanceGroupPair__1PxDominanceGroupPair(JNIEnv*, jclass, jbyte a, jbyte b) {
    return (jlong) new physx::PxDominanceGroupPair(a, b);
}
JNIEXPORT void JNICALL Java_physx_physics_PxDominanceGroupPair__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxDominanceGroupPair*) _address;
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxDominanceGroupPair__1getDominance0(JNIEnv*, jclass, jlong _address) {
    physx::PxDominanceGroupPair* _self = (physx::PxDominanceGroupPair*) _address;
    return (jbyte) _self->dominance0;
}
JNIEXPORT void JNICALL Java_physx_physics_PxDominanceGroupPair__1setDominance0(JNIEnv*, jclass, jlong _address, jbyte value) {
    physx::PxDominanceGroupPair* _self = (physx::PxDominanceGroupPair*) _address;
    _self->dominance0 = value;
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxDominanceGroupPair__1getDominance1(JNIEnv*, jclass, jlong _address) {
    physx::PxDominanceGroupPair* _self = (physx::PxDominanceGroupPair*) _address;
    return (jbyte) _self->dominance1;
}
JNIEXPORT void JNICALL Java_physx_physics_PxDominanceGroupPair__1setDominance1(JNIEnv*, jclass, jlong _address, jbyte value) {
    physx::PxDominanceGroupPair* _self = (physx::PxDominanceGroupPair*) _address;
    _self->dominance1 = value;
}

// PxgDynamicsMemoryConfig
JNIEXPORT jlong JNICALL Java_physx_physics_PxgDynamicsMemoryConfig__1PxgDynamicsMemoryConfig(JNIEnv*, jclass) {
    return (jlong) new physx::PxgDynamicsMemoryConfig();
}
JNIEXPORT void JNICALL Java_physx_physics_PxgDynamicsMemoryConfig__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxgDynamicsMemoryConfig*) _address;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxgDynamicsMemoryConfig__1getConstraintBufferCapacity(JNIEnv*, jclass, jlong _address) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    return (jint) _self->constraintBufferCapacity;
}
JNIEXPORT void JNICALL Java_physx_physics_PxgDynamicsMemoryConfig__1setConstraintBufferCapacity(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    _self->constraintBufferCapacity = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxgDynamicsMemoryConfig__1getContactBufferCapacity(JNIEnv*, jclass, jlong _address) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    return (jint) _self->contactBufferCapacity;
}
JNIEXPORT void JNICALL Java_physx_physics_PxgDynamicsMemoryConfig__1setContactBufferCapacity(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    _self->contactBufferCapacity = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxgDynamicsMemoryConfig__1getTempBufferCapacity(JNIEnv*, jclass, jlong _address) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    return (jint) _self->tempBufferCapacity;
}
JNIEXPORT void JNICALL Java_physx_physics_PxgDynamicsMemoryConfig__1setTempBufferCapacity(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    _self->tempBufferCapacity = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxgDynamicsMemoryConfig__1getContactStreamSize(JNIEnv*, jclass, jlong _address) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    return (jint) _self->contactStreamSize;
}
JNIEXPORT void JNICALL Java_physx_physics_PxgDynamicsMemoryConfig__1setContactStreamSize(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    _self->contactStreamSize = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxgDynamicsMemoryConfig__1getPatchStreamSize(JNIEnv*, jclass, jlong _address) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    return (jint) _self->patchStreamSize;
}
JNIEXPORT void JNICALL Java_physx_physics_PxgDynamicsMemoryConfig__1setPatchStreamSize(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    _self->patchStreamSize = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxgDynamicsMemoryConfig__1getForceStreamCapacity(JNIEnv*, jclass, jlong _address) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    return (jint) _self->forceStreamCapacity;
}
JNIEXPORT void JNICALL Java_physx_physics_PxgDynamicsMemoryConfig__1setForceStreamCapacity(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    _self->forceStreamCapacity = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxgDynamicsMemoryConfig__1getHeapCapacity(JNIEnv*, jclass, jlong _address) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    return (jint) _self->heapCapacity;
}
JNIEXPORT void JNICALL Java_physx_physics_PxgDynamicsMemoryConfig__1setHeapCapacity(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    _self->heapCapacity = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxgDynamicsMemoryConfig__1getFoundLostPairsCapacity(JNIEnv*, jclass, jlong _address) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    return (jint) _self->foundLostPairsCapacity;
}
JNIEXPORT void JNICALL Java_physx_physics_PxgDynamicsMemoryConfig__1setFoundLostPairsCapacity(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxgDynamicsMemoryConfig* _self = (physx::PxgDynamicsMemoryConfig*) _address;
    _self->foundLostPairsCapacity = value;
}

// PxFilterData
JNIEXPORT jint JNICALL Java_physx_physics_PxFilterData__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxFilterData);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxFilterData__1_1placement_1new_1PxFilterData__J(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxFilterData();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxFilterData__1_1placement_1new_1PxFilterData__JIIII(JNIEnv*, jclass, jlong _placement_address, jint w0, jint w1, jint w2, jint w3) {
    return (jlong) new((void*)_placement_address) physx::PxFilterData(w0, w1, w2, w3);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxFilterData__1PxFilterData__(JNIEnv*, jclass) {
    return (jlong) new physx::PxFilterData();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxFilterData__1PxFilterData__IIII(JNIEnv*, jclass, jint w0, jint w1, jint w2, jint w3) {
    return (jlong) new physx::PxFilterData(w0, w1, w2, w3);
}
JNIEXPORT void JNICALL Java_physx_physics_PxFilterData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxFilterData*) _address;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFilterData__1getWord0(JNIEnv*, jclass, jlong _address) {
    physx::PxFilterData* _self = (physx::PxFilterData*) _address;
    return (jint) _self->word0;
}
JNIEXPORT void JNICALL Java_physx_physics_PxFilterData__1setWord0(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxFilterData* _self = (physx::PxFilterData*) _address;
    _self->word0 = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFilterData__1getWord1(JNIEnv*, jclass, jlong _address) {
    physx::PxFilterData* _self = (physx::PxFilterData*) _address;
    return (jint) _self->word1;
}
JNIEXPORT void JNICALL Java_physx_physics_PxFilterData__1setWord1(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxFilterData* _self = (physx::PxFilterData*) _address;
    _self->word1 = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFilterData__1getWord2(JNIEnv*, jclass, jlong _address) {
    physx::PxFilterData* _self = (physx::PxFilterData*) _address;
    return (jint) _self->word2;
}
JNIEXPORT void JNICALL Java_physx_physics_PxFilterData__1setWord2(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxFilterData* _self = (physx::PxFilterData*) _address;
    _self->word2 = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFilterData__1getWord3(JNIEnv*, jclass, jlong _address) {
    physx::PxFilterData* _self = (physx::PxFilterData*) _address;
    return (jint) _self->word3;
}
JNIEXPORT void JNICALL Java_physx_physics_PxFilterData__1setWord3(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxFilterData* _self = (physx::PxFilterData*) _address;
    _self->word3 = value;
}

// PxHitFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxHitFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxHitFlags__1_1placement_1new_1PxHitFlags(JNIEnv*, jclass, jlong _placement_address, jshort flags) {
    return (jlong) new((void*)_placement_address) physx::PxHitFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxHitFlags__1PxHitFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxHitFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxHitFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxHitFlags* self = (physx::PxHitFlags*) _address;
    return (jboolean) self->isSet((PxHitFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxHitFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxHitFlags* self = (physx::PxHitFlags*) _address;
    self->set((PxHitFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxHitFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxHitFlags* self = (physx::PxHitFlags*) _address;
    self->clear((PxHitFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxHitFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxHitFlags*) _address;
}

// PxLocationHit
JNIEXPORT void JNICALL Java_physx_physics_PxLocationHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxLocationHit*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxLocationHit__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxLocationHit* _self = (physx::PxLocationHit*) _address;
    return (jlong) &_self->flags;
}
JNIEXPORT void JNICALL Java_physx_physics_PxLocationHit__1setFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxLocationHit* _self = (physx::PxLocationHit*) _address;
    _self->flags = *((physx::PxHitFlags*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxLocationHit__1getPosition(JNIEnv*, jclass, jlong _address) {
    physx::PxLocationHit* _self = (physx::PxLocationHit*) _address;
    return (jlong) &_self->position;
}
JNIEXPORT void JNICALL Java_physx_physics_PxLocationHit__1setPosition(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxLocationHit* _self = (physx::PxLocationHit*) _address;
    _self->position = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxLocationHit__1getNormal(JNIEnv*, jclass, jlong _address) {
    physx::PxLocationHit* _self = (physx::PxLocationHit*) _address;
    return (jlong) &_self->normal;
}
JNIEXPORT void JNICALL Java_physx_physics_PxLocationHit__1setNormal(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxLocationHit* _self = (physx::PxLocationHit*) _address;
    _self->normal = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxLocationHit__1getDistance(JNIEnv*, jclass, jlong _address) {
    physx::PxLocationHit* _self = (physx::PxLocationHit*) _address;
    return (jfloat) _self->distance;
}
JNIEXPORT void JNICALL Java_physx_physics_PxLocationHit__1setDistance(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxLocationHit* _self = (physx::PxLocationHit*) _address;
    _self->distance = value;
}

// PxOverlapBuffer10
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapBuffer10__1PxOverlapBuffer10(JNIEnv*, jclass) {
    return (jlong) new PxOverlapBuffer10();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxOverlapBuffer10__1getNbAnyHits(JNIEnv*, jclass, jlong _address) {
    PxOverlapBuffer10* self = (PxOverlapBuffer10*) _address;
    return (jint) self->getNbAnyHits();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapBuffer10__1getAnyHit(JNIEnv*, jclass, jlong _address, jint index) {
    PxOverlapBuffer10* self = (PxOverlapBuffer10*) _address;
    return (jlong) &self->getAnyHit(index);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxOverlapBuffer10__1getNbTouches(JNIEnv*, jclass, jlong _address) {
    PxOverlapBuffer10* self = (PxOverlapBuffer10*) _address;
    return (jint) self->getNbTouches();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapBuffer10__1getTouches(JNIEnv*, jclass, jlong _address) {
    PxOverlapBuffer10* self = (PxOverlapBuffer10*) _address;
    return (jlong) self->getTouches();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapBuffer10__1getTouch(JNIEnv*, jclass, jlong _address, jint index) {
    PxOverlapBuffer10* self = (PxOverlapBuffer10*) _address;
    return (jlong) &self->getTouch(index);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxOverlapBuffer10__1getMaxNbTouches(JNIEnv*, jclass, jlong _address) {
    PxOverlapBuffer10* self = (PxOverlapBuffer10*) _address;
    return (jint) self->getMaxNbTouches();
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapBuffer10__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxOverlapBuffer10*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapBuffer10__1getBlock(JNIEnv*, jclass, jlong _address) {
    PxOverlapBuffer10* _self = (PxOverlapBuffer10*) _address;
    return (jlong) &_self->block;
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapBuffer10__1setBlock(JNIEnv*, jclass, jlong _address, jlong value) {
    PxOverlapBuffer10* _self = (PxOverlapBuffer10*) _address;
    _self->block = *((physx::PxOverlapHit*) value);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxOverlapBuffer10__1getHasBlock(JNIEnv*, jclass, jlong _address) {
    PxOverlapBuffer10* _self = (PxOverlapBuffer10*) _address;
    return (jboolean) _self->hasBlock;
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapBuffer10__1setHasBlock(JNIEnv*, jclass, jlong _address, jboolean value) {
    PxOverlapBuffer10* _self = (PxOverlapBuffer10*) _address;
    _self->hasBlock = value;
}

// PxOverlapCallback
JNIEXPORT jboolean JNICALL Java_physx_physics_PxOverlapCallback__1hasAnyHits(JNIEnv*, jclass, jlong _address) {
    physx::PxOverlapCallback* self = (physx::PxOverlapCallback*) _address;
    return (jboolean) self->hasAnyHits();
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxOverlapCallback*) _address;
}

// PxOverlapHit
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxOverlapHit*) _address;
}

// PxOverlapQueryResult
JNIEXPORT jint JNICALL Java_physx_physics_PxOverlapQueryResult__1getNbAnyHits(JNIEnv*, jclass, jlong _address) {
    physx::PxOverlapQueryResult* self = (physx::PxOverlapQueryResult*) _address;
    return (jint) self->getNbAnyHits();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapQueryResult__1getAnyHit(JNIEnv*, jclass, jlong _address, jint index) {
    physx::PxOverlapQueryResult* self = (physx::PxOverlapQueryResult*) _address;
    return (jlong) &self->getAnyHit(index);
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapQueryResult__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxOverlapQueryResult*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapQueryResult__1getBlock(JNIEnv*, jclass, jlong _address) {
    physx::PxOverlapQueryResult* _self = (physx::PxOverlapQueryResult*) _address;
    return (jlong) &_self->block;
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapQueryResult__1setBlock(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxOverlapQueryResult* _self = (physx::PxOverlapQueryResult*) _address;
    _self->block = *((physx::PxOverlapHit*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapQueryResult__1getTouches(JNIEnv*, jclass, jlong _address) {
    physx::PxOverlapQueryResult* _self = (physx::PxOverlapQueryResult*) _address;
    return (jlong) _self->touches;
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapQueryResult__1setTouches(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxOverlapQueryResult* _self = (physx::PxOverlapQueryResult*) _address;
    _self->touches = (physx::PxOverlapHit*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxOverlapQueryResult__1getNbTouches(JNIEnv*, jclass, jlong _address) {
    physx::PxOverlapQueryResult* _self = (physx::PxOverlapQueryResult*) _address;
    return (jint) _self->nbTouches;
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapQueryResult__1setNbTouches(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxOverlapQueryResult* _self = (physx::PxOverlapQueryResult*) _address;
    _self->nbTouches = value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapQueryResult__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxOverlapQueryResult* _self = (physx::PxOverlapQueryResult*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapQueryResult__1setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxOverlapQueryResult* _self = (physx::PxOverlapQueryResult*) _address;
    _self->userData = (void*) value;
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxOverlapQueryResult__1getQueryStatus(JNIEnv*, jclass, jlong _address) {
    physx::PxOverlapQueryResult* _self = (physx::PxOverlapQueryResult*) _address;
    return (jbyte) _self->queryStatus;
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapQueryResult__1setQueryStatus(JNIEnv*, jclass, jlong _address, jbyte value) {
    physx::PxOverlapQueryResult* _self = (physx::PxOverlapQueryResult*) _address;
    _self->queryStatus = value;
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxOverlapQueryResult__1getHasBlock(JNIEnv*, jclass, jlong _address) {
    physx::PxOverlapQueryResult* _self = (physx::PxOverlapQueryResult*) _address;
    return (jboolean) _self->hasBlock;
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapQueryResult__1setHasBlock(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxOverlapQueryResult* _self = (physx::PxOverlapQueryResult*) _address;
    _self->hasBlock = value;
}

// PxMaterial

// PxPairFlags
JNIEXPORT jlong JNICALL Java_physx_physics_PxPairFlags__1PxPairFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxPairFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxPairFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxPairFlags* self = (physx::PxPairFlags*) _address;
    return (jboolean) self->isSet((PxPairFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxPairFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxPairFlags* self = (physx::PxPairFlags*) _address;
    self->set((PxPairFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxPairFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxPairFlags* self = (physx::PxPairFlags*) _address;
    self->clear((PxPairFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxPairFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxPairFlags*) _address;
}

// PxPhysics
JNIEXPORT void JNICALL Java_physx_physics_PxPhysics__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    self->release();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1getFoundation(JNIEnv*, jclass, jlong _address) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) &self->getFoundation();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createAggregate(JNIEnv*, jclass, jlong _address, jint size, jboolean enableSelfCollision) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) self->createAggregate(size, enableSelfCollision);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1getTolerancesScale(JNIEnv*, jclass, jlong _address) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) &self->getTolerancesScale();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createScene(JNIEnv*, jclass, jlong _address, jlong sceneDesc) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) self->createScene(*((physx::PxSceneDesc*) sceneDesc));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createRigidStatic(JNIEnv*, jclass, jlong _address, jlong pose) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) self->createRigidStatic(*((physx::PxTransform*) pose));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createRigidDynamic(JNIEnv*, jclass, jlong _address, jlong pose) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) self->createRigidDynamic(*((physx::PxTransform*) pose));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createShape__JJJ(JNIEnv*, jclass, jlong _address, jlong geometry, jlong material) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) self->createShape(*((physx::PxGeometry*) geometry), *((physx::PxMaterial*) material));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createShape__JJJZ(JNIEnv*, jclass, jlong _address, jlong geometry, jlong material, jboolean isExclusive) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) self->createShape(*((physx::PxGeometry*) geometry), *((physx::PxMaterial*) material), isExclusive);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createShape__JJJZJ(JNIEnv*, jclass, jlong _address, jlong geometry, jlong material, jboolean isExclusive, jlong shapeFlags) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) self->createShape(*((physx::PxGeometry*) geometry), *((physx::PxMaterial*) material), isExclusive, *((physx::PxShapeFlags*) shapeFlags));
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPhysics__1getNbShapes(JNIEnv*, jclass, jlong _address) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jint) self->getNbShapes();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createArticulation(JNIEnv*, jclass, jlong _address) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) self->createArticulation();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createArticulationReducedCoordinate(JNIEnv*, jclass, jlong _address) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) self->createArticulationReducedCoordinate();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createMaterial(JNIEnv*, jclass, jlong _address, jfloat staticFriction, jfloat dynamicFriction, jfloat restitution) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) self->createMaterial(staticFriction, dynamicFriction, restitution);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1getPhysicsInsertionCallback(JNIEnv*, jclass, jlong _address) {
    physx::PxPhysics* self = (physx::PxPhysics*) _address;
    return (jlong) &self->getPhysicsInsertionCallback();
}
JNIEXPORT void JNICALL Java_physx_physics_PxPhysics__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxPhysics*) _address;
}

// PxQueryFilterData
JNIEXPORT jlong JNICALL Java_physx_physics_PxQueryFilterData__1PxQueryFilterData__(JNIEnv*, jclass) {
    return (jlong) new physx::PxQueryFilterData();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxQueryFilterData__1PxQueryFilterData__JJ(JNIEnv*, jclass, jlong fd, jlong f) {
    return (jlong) new physx::PxQueryFilterData(*((physx::PxFilterData*) fd), *((physx::PxQueryFlags*) f));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxQueryFilterData__1PxQueryFilterData__J(JNIEnv*, jclass, jlong f) {
    return (jlong) new physx::PxQueryFilterData(*((physx::PxQueryFlags*) f));
}
JNIEXPORT void JNICALL Java_physx_physics_PxQueryFilterData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxQueryFilterData*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxQueryFilterData__1getData(JNIEnv*, jclass, jlong _address) {
    physx::PxQueryFilterData* _self = (physx::PxQueryFilterData*) _address;
    return (jlong) &_self->data;
}
JNIEXPORT void JNICALL Java_physx_physics_PxQueryFilterData__1setData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxQueryFilterData* _self = (physx::PxQueryFilterData*) _address;
    _self->data = *((physx::PxFilterData*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxQueryFilterData__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxQueryFilterData* _self = (physx::PxQueryFilterData*) _address;
    return (jlong) &_self->flags;
}
JNIEXPORT void JNICALL Java_physx_physics_PxQueryFilterData__1setFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxQueryFilterData* _self = (physx::PxQueryFilterData*) _address;
    _self->flags = *((physx::PxQueryFlags*) value);
}

// PxQueryFlags
JNIEXPORT jlong JNICALL Java_physx_physics_PxQueryFlags__1PxQueryFlags(JNIEnv*, jclass, jshort flags) {
    return (jlong) new physx::PxQueryFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxQueryFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxQueryFlags* self = (physx::PxQueryFlags*) _address;
    return (jboolean) self->isSet((PxQueryFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxQueryFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxQueryFlags* self = (physx::PxQueryFlags*) _address;
    self->set((PxQueryFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxQueryFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxQueryFlags* self = (physx::PxQueryFlags*) _address;
    self->clear((PxQueryFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxQueryFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxQueryFlags*) _address;
}

// PxQueryHit
JNIEXPORT void JNICALL Java_physx_physics_PxQueryHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxQueryHit*) _address;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxQueryHit__1getFaceIndex(JNIEnv*, jclass, jlong _address) {
    physx::PxQueryHit* _self = (physx::PxQueryHit*) _address;
    return (jint) _self->faceIndex;
}
JNIEXPORT void JNICALL Java_physx_physics_PxQueryHit__1setFaceIndex(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxQueryHit* _self = (physx::PxQueryHit*) _address;
    _self->faceIndex = value;
}

// PxRaycastBuffer10
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastBuffer10__1PxRaycastBuffer10(JNIEnv*, jclass) {
    return (jlong) new PxRaycastBuffer10();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRaycastBuffer10__1getNbAnyHits(JNIEnv*, jclass, jlong _address) {
    PxRaycastBuffer10* self = (PxRaycastBuffer10*) _address;
    return (jint) self->getNbAnyHits();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastBuffer10__1getAnyHit(JNIEnv*, jclass, jlong _address, jint index) {
    PxRaycastBuffer10* self = (PxRaycastBuffer10*) _address;
    return (jlong) &self->getAnyHit(index);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRaycastBuffer10__1getNbTouches(JNIEnv*, jclass, jlong _address) {
    PxRaycastBuffer10* self = (PxRaycastBuffer10*) _address;
    return (jint) self->getNbTouches();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastBuffer10__1getTouches(JNIEnv*, jclass, jlong _address) {
    PxRaycastBuffer10* self = (PxRaycastBuffer10*) _address;
    return (jlong) self->getTouches();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastBuffer10__1getTouch(JNIEnv*, jclass, jlong _address, jint index) {
    PxRaycastBuffer10* self = (PxRaycastBuffer10*) _address;
    return (jlong) &self->getTouch(index);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRaycastBuffer10__1getMaxNbTouches(JNIEnv*, jclass, jlong _address) {
    PxRaycastBuffer10* self = (PxRaycastBuffer10*) _address;
    return (jint) self->getMaxNbTouches();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastBuffer10__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxRaycastBuffer10*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastBuffer10__1getBlock(JNIEnv*, jclass, jlong _address) {
    PxRaycastBuffer10* _self = (PxRaycastBuffer10*) _address;
    return (jlong) &_self->block;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastBuffer10__1setBlock(JNIEnv*, jclass, jlong _address, jlong value) {
    PxRaycastBuffer10* _self = (PxRaycastBuffer10*) _address;
    _self->block = *((physx::PxRaycastHit*) value);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxRaycastBuffer10__1getHasBlock(JNIEnv*, jclass, jlong _address) {
    PxRaycastBuffer10* _self = (PxRaycastBuffer10*) _address;
    return (jboolean) _self->hasBlock;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastBuffer10__1setHasBlock(JNIEnv*, jclass, jlong _address, jboolean value) {
    PxRaycastBuffer10* _self = (PxRaycastBuffer10*) _address;
    _self->hasBlock = value;
}

// PxRaycastCallback
JNIEXPORT jboolean JNICALL Java_physx_physics_PxRaycastCallback__1hasAnyHits(JNIEnv*, jclass, jlong _address) {
    physx::PxRaycastCallback* self = (physx::PxRaycastCallback*) _address;
    return (jboolean) self->hasAnyHits();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxRaycastCallback*) _address;
}

// PxRaycastHit
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastHit__1PxRaycastHit(JNIEnv*, jclass) {
    return (jlong) new physx::PxRaycastHit();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxRaycastHit*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRaycastHit__1getU(JNIEnv*, jclass, jlong _address) {
    physx::PxRaycastHit* _self = (physx::PxRaycastHit*) _address;
    return (jfloat) _self->u;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastHit__1setU(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxRaycastHit* _self = (physx::PxRaycastHit*) _address;
    _self->u = value;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRaycastHit__1getV(JNIEnv*, jclass, jlong _address) {
    physx::PxRaycastHit* _self = (physx::PxRaycastHit*) _address;
    return (jfloat) _self->v;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastHit__1setV(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxRaycastHit* _self = (physx::PxRaycastHit*) _address;
    _self->v = value;
}

// PxRaycastQueryResult
JNIEXPORT jint JNICALL Java_physx_physics_PxRaycastQueryResult__1getNbAnyHits(JNIEnv*, jclass, jlong _address) {
    physx::PxRaycastQueryResult* self = (physx::PxRaycastQueryResult*) _address;
    return (jint) self->getNbAnyHits();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastQueryResult__1getAnyHit(JNIEnv*, jclass, jlong _address, jint index) {
    physx::PxRaycastQueryResult* self = (physx::PxRaycastQueryResult*) _address;
    return (jlong) &self->getAnyHit(index);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastQueryResult__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxRaycastQueryResult*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastQueryResult__1getBlock(JNIEnv*, jclass, jlong _address) {
    physx::PxRaycastQueryResult* _self = (physx::PxRaycastQueryResult*) _address;
    return (jlong) &_self->block;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastQueryResult__1setBlock(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxRaycastQueryResult* _self = (physx::PxRaycastQueryResult*) _address;
    _self->block = *((physx::PxRaycastHit*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastQueryResult__1getTouches(JNIEnv*, jclass, jlong _address) {
    physx::PxRaycastQueryResult* _self = (physx::PxRaycastQueryResult*) _address;
    return (jlong) _self->touches;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastQueryResult__1setTouches(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxRaycastQueryResult* _self = (physx::PxRaycastQueryResult*) _address;
    _self->touches = (physx::PxRaycastHit*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRaycastQueryResult__1getNbTouches(JNIEnv*, jclass, jlong _address) {
    physx::PxRaycastQueryResult* _self = (physx::PxRaycastQueryResult*) _address;
    return (jint) _self->nbTouches;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastQueryResult__1setNbTouches(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxRaycastQueryResult* _self = (physx::PxRaycastQueryResult*) _address;
    _self->nbTouches = value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastQueryResult__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxRaycastQueryResult* _self = (physx::PxRaycastQueryResult*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastQueryResult__1setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxRaycastQueryResult* _self = (physx::PxRaycastQueryResult*) _address;
    _self->userData = (void*) value;
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxRaycastQueryResult__1getQueryStatus(JNIEnv*, jclass, jlong _address) {
    physx::PxRaycastQueryResult* _self = (physx::PxRaycastQueryResult*) _address;
    return (jbyte) _self->queryStatus;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastQueryResult__1setQueryStatus(JNIEnv*, jclass, jlong _address, jbyte value) {
    physx::PxRaycastQueryResult* _self = (physx::PxRaycastQueryResult*) _address;
    _self->queryStatus = value;
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxRaycastQueryResult__1getHasBlock(JNIEnv*, jclass, jlong _address) {
    physx::PxRaycastQueryResult* _self = (physx::PxRaycastQueryResult*) _address;
    return (jboolean) _self->hasBlock;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastQueryResult__1setHasBlock(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxRaycastQueryResult* _self = (physx::PxRaycastQueryResult*) _address;
    _self->hasBlock = value;
}

// PxRigidActor
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidActor__1getGlobalPose(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxTransform _cache;
    physx::PxRigidActor* self = (physx::PxRigidActor*) _address;
    _cache = self->getGlobalPose();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidActor__1setGlobalPose__JJ(JNIEnv*, jclass, jlong _address, jlong pose) {
    physx::PxRigidActor* self = (physx::PxRigidActor*) _address;
    self->setGlobalPose(*((physx::PxTransform*) pose));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidActor__1setGlobalPose__JJZ(JNIEnv*, jclass, jlong _address, jlong pose, jboolean autowake) {
    physx::PxRigidActor* self = (physx::PxRigidActor*) _address;
    self->setGlobalPose(*((physx::PxTransform*) pose), autowake);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxRigidActor__1attachShape(JNIEnv*, jclass, jlong _address, jlong shape) {
    physx::PxRigidActor* self = (physx::PxRigidActor*) _address;
    return (jboolean) self->attachShape(*((physx::PxShape*) shape));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidActor__1detachShape__JJ(JNIEnv*, jclass, jlong _address, jlong shape) {
    physx::PxRigidActor* self = (physx::PxRigidActor*) _address;
    self->detachShape(*((physx::PxShape*) shape));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidActor__1detachShape__JJZ(JNIEnv*, jclass, jlong _address, jlong shape, jboolean wakeOnLostTouch) {
    physx::PxRigidActor* self = (physx::PxRigidActor*) _address;
    self->detachShape(*((physx::PxShape*) shape), wakeOnLostTouch);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidActor__1getNbShapes(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidActor* self = (physx::PxRigidActor*) _address;
    return (jint) self->getNbShapes();
}

// PxRigidBody
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setCMassLocalPose(JNIEnv*, jclass, jlong _address, jlong pose) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setCMassLocalPose(*((physx::PxTransform*) pose));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBody__1getCMassLocalPose(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxTransform _cache;
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    _cache = self->getCMassLocalPose();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setMass(JNIEnv*, jclass, jlong _address, jfloat mass) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setMass(mass);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getMass(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    return (jfloat) self->getMass();
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getInvMass(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    return (jfloat) self->getInvMass();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setMassSpaceInertiaTensor(JNIEnv*, jclass, jlong _address, jlong m) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setMassSpaceInertiaTensor(*((physx::PxVec3*) m));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBody__1getMassSpaceInertiaTensor(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxVec3 _cache;
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    _cache = self->getMassSpaceInertiaTensor();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBody__1getMassSpaceInvInertiaTensor(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxVec3 _cache;
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    _cache = self->getMassSpaceInvInertiaTensor();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setLinearDamping(JNIEnv*, jclass, jlong _address, jfloat linDamp) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setLinearDamping(linDamp);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getLinearDamping(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    return (jfloat) self->getLinearDamping();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setAngularDamping(JNIEnv*, jclass, jlong _address, jfloat angDamp) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setAngularDamping(angDamp);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getAngularDamping(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    return (jfloat) self->getAngularDamping();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBody__1getLinearVelocity(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxVec3 _cache;
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    _cache = self->getLinearVelocity();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setLinearVelocity__JJ(JNIEnv*, jclass, jlong _address, jlong linVel) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setLinearVelocity(*((physx::PxVec3*) linVel));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setLinearVelocity__JJZ(JNIEnv*, jclass, jlong _address, jlong linVel, jboolean autowake) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setLinearVelocity(*((physx::PxVec3*) linVel), autowake);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBody__1getAngularVelocity(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxVec3 _cache;
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    _cache = self->getAngularVelocity();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setAngularVelocity__JJ(JNIEnv*, jclass, jlong _address, jlong angVel) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setAngularVelocity(*((physx::PxVec3*) angVel));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setAngularVelocity__JJZ(JNIEnv*, jclass, jlong _address, jlong angVel, jboolean autowake) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setAngularVelocity(*((physx::PxVec3*) angVel), autowake);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getMaxLinearVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    return (jfloat) self->getMaxLinearVelocity();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setMaxLinearVelocity(JNIEnv*, jclass, jlong _address, jfloat maxLinVel) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setMaxLinearVelocity(maxLinVel);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getMaxAngularVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    return (jfloat) self->getMaxAngularVelocity();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setMaxAngularVelocity(JNIEnv*, jclass, jlong _address, jfloat maxAngVel) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setMaxAngularVelocity(maxAngVel);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1addForce__JJ(JNIEnv*, jclass, jlong _address, jlong force) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->addForce(*((physx::PxVec3*) force));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1addForce__JJI(JNIEnv*, jclass, jlong _address, jlong force, jint mode) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->addForce(*((physx::PxVec3*) force), (PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1addForce__JJIZ(JNIEnv*, jclass, jlong _address, jlong force, jint mode, jboolean autowake) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->addForce(*((physx::PxVec3*) force), (PxForceModeEnum) mode, autowake);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1addTorque__JJ(JNIEnv*, jclass, jlong _address, jlong torque) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->addTorque(*((physx::PxVec3*) torque));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1addTorque__JJI(JNIEnv*, jclass, jlong _address, jlong torque, jint mode) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->addTorque(*((physx::PxVec3*) torque), (PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1addTorque__JJIZ(JNIEnv*, jclass, jlong _address, jlong torque, jint mode, jboolean autowake) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->addTorque(*((physx::PxVec3*) torque), (PxForceModeEnum) mode, autowake);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1clearForce(JNIEnv*, jclass, jlong _address, jint mode) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->clearForce((PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1clearTorque(JNIEnv*, jclass, jlong _address, jint mode) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->clearTorque((PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setForceAndTorque__JJJ(JNIEnv*, jclass, jlong _address, jlong force, jlong torque) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setForceAndTorque(*((physx::PxVec3*) force), *((physx::PxVec3*) torque));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setForceAndTorque__JJJI(JNIEnv*, jclass, jlong _address, jlong force, jlong torque, jint mode) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setForceAndTorque(*((physx::PxVec3*) force), *((physx::PxVec3*) torque), (PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setRigidBodyFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setRigidBodyFlag((PxRigidBodyFlagEnum) flag, value);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setRigidBodyFlags(JNIEnv*, jclass, jlong _address, jlong inFlags) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setRigidBodyFlags(*((physx::PxRigidBodyFlags*) inFlags));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBody__1getRigidBodyFlags(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxRigidBodyFlags _cache;
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    _cache = self->getRigidBodyFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setMinCCDAdvanceCoefficient(JNIEnv*, jclass, jlong _address, jfloat advanceCoefficient) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setMinCCDAdvanceCoefficient(advanceCoefficient);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getMinCCDAdvanceCoefficient(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    return (jfloat) self->getMinCCDAdvanceCoefficient();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setMaxDepenetrationVelocity(JNIEnv*, jclass, jlong _address, jfloat biasClamp) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setMaxDepenetrationVelocity(biasClamp);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getMaxDepenetrationVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    return (jfloat) self->getMaxDepenetrationVelocity();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setMaxContactImpulse(JNIEnv*, jclass, jlong _address, jfloat maxImpulse) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    self->setMaxContactImpulse(maxImpulse);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getMaxContactImpulse(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    return (jfloat) self->getMaxContactImpulse();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidBody__1getInternalIslandNodeIndex(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidBody* self = (physx::PxRigidBody*) _address;
    return (jint) self->getInternalIslandNodeIndex();
}

// PxRigidBodyFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidBodyFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxRigidBodyFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBodyFlags__1_1placement_1new_1PxRigidBodyFlags(JNIEnv*, jclass, jlong _placement_address, jbyte flags) {
    return (jlong) new((void*)_placement_address) physx::PxRigidBodyFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBodyFlags__1PxRigidBodyFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxRigidBodyFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxRigidBodyFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxRigidBodyFlags* self = (physx::PxRigidBodyFlags*) _address;
    return (jboolean) self->isSet((PxRigidBodyFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBodyFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxRigidBodyFlags* self = (physx::PxRigidBodyFlags*) _address;
    self->set((PxRigidBodyFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBodyFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxRigidBodyFlags* self = (physx::PxRigidBodyFlags*) _address;
    self->clear((PxRigidBodyFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBodyFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxRigidBodyFlags*) _address;
}

// PxRigidDynamic
JNIEXPORT jboolean JNICALL Java_physx_physics_PxRigidDynamic__1isSleeping(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    return (jboolean) self->isSleeping();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setSleepThreshold(JNIEnv*, jclass, jlong _address, jfloat threshold) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->setSleepThreshold(threshold);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidDynamic__1getSleepThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    return (jfloat) self->getSleepThreshold();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setStabilizationThreshold(JNIEnv*, jclass, jlong _address, jfloat threshold) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->setStabilizationThreshold(threshold);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidDynamic__1getStabilizationThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    return (jfloat) self->getStabilizationThreshold();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidDynamic__1getRigidDynamicLockFlags(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxRigidDynamicLockFlags _cache;
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    _cache = self->getRigidDynamicLockFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setRigidDynamicLockFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->setRigidDynamicLockFlag((PxRigidDynamicLockFlagEnum) flag, value);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setRigidDynamicLockFlags(JNIEnv*, jclass, jlong _address, jlong flags) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->setRigidDynamicLockFlags(*((physx::PxRigidDynamicLockFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setWakeCounter(JNIEnv*, jclass, jlong _address, jfloat wakeCounterValue) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->setWakeCounter(wakeCounterValue);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidDynamic__1getWakeCounter(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    return (jfloat) self->getWakeCounter();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1wakeUp(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->wakeUp();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1putToSleep(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->putToSleep();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setSolverIterationCounts__JI(JNIEnv*, jclass, jlong _address, jint minPositionIters) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->setSolverIterationCounts(minPositionIters);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setSolverIterationCounts__JII(JNIEnv*, jclass, jlong _address, jint minPositionIters, jint minVelocityIters) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->setSolverIterationCounts(minPositionIters, minVelocityIters);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidDynamic__1getContactReportThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    return (jfloat) self->getContactReportThreshold();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setContactReportThreshold(JNIEnv*, jclass, jlong _address, jfloat threshold) {
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) _address;
    self->setContactReportThreshold(threshold);
}

// PxRigidDynamicLockFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidDynamicLockFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxRigidDynamicLockFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidDynamicLockFlags__1_1placement_1new_1PxRigidDynamicLockFlags(JNIEnv*, jclass, jlong _placement_address, jbyte flags) {
    return (jlong) new((void*)_placement_address) physx::PxRigidDynamicLockFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidDynamicLockFlags__1PxRigidDynamicLockFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxRigidDynamicLockFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxRigidDynamicLockFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxRigidDynamicLockFlags* self = (physx::PxRigidDynamicLockFlags*) _address;
    return (jboolean) self->isSet((PxRigidDynamicLockFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamicLockFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxRigidDynamicLockFlags* self = (physx::PxRigidDynamicLockFlags*) _address;
    self->set((PxRigidDynamicLockFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamicLockFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxRigidDynamicLockFlags* self = (physx::PxRigidDynamicLockFlags*) _address;
    self->clear((PxRigidDynamicLockFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamicLockFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxRigidDynamicLockFlags*) _address;
}

// PxRigidStatic

// PxScene
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1addActor__JJ(JNIEnv*, jclass, jlong _address, jlong actor) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->addActor(*((physx::PxActor*) actor));
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1addActor__JJJ(JNIEnv*, jclass, jlong _address, jlong actor, jlong bvhStructure) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->addActor(*((physx::PxActor*) actor), (physx::PxBVHStructure*) bvhStructure);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1removeActor__JJ(JNIEnv*, jclass, jlong _address, jlong actor) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->removeActor(*((physx::PxActor*) actor));
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1removeActor__JJZ(JNIEnv*, jclass, jlong _address, jlong actor, jboolean wakeOnLostTouch) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->removeActor(*((physx::PxActor*) actor), wakeOnLostTouch);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1addAggregate(JNIEnv*, jclass, jlong _address, jlong aggregate) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->addAggregate(*((physx::PxAggregate*) aggregate));
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1removeAggregate__JJ(JNIEnv*, jclass, jlong _address, jlong aggregate) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->removeAggregate(*((physx::PxAggregate*) aggregate));
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1removeAggregate__JJZ(JNIEnv*, jclass, jlong _address, jlong aggregate, jboolean wakeOnLostTouch) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->removeAggregate(*((physx::PxAggregate*) aggregate), wakeOnLostTouch);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxScene__1getWakeCounterResetValue(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jfloat) self->getWakeCounterResetValue();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1shiftOrigin(JNIEnv*, jclass, jlong _address, jlong shift) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->shiftOrigin(*((physx::PxVec3*) shift));
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1addArticulation(JNIEnv*, jclass, jlong _address, jlong articulation) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->addArticulation(*((physx::PxArticulationBase*) articulation));
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1removeArticulation__JJ(JNIEnv*, jclass, jlong _address, jlong articulation) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->removeArticulation(*((physx::PxArticulationBase*) articulation));
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1removeArticulation__JJZ(JNIEnv*, jclass, jlong _address, jlong articulation, jboolean wakeOnLostTouch) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->removeArticulation(*((physx::PxArticulationBase*) articulation), wakeOnLostTouch);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getNbActors(JNIEnv*, jclass, jlong _address, jlong types) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getNbActors(*((physx::PxActorTypeFlags*) types));
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getNbArticulations(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getNbArticulations();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getNbConstraints(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getNbConstraints();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getNbAggregates(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getNbAggregates();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setDominanceGroupPair(JNIEnv*, jclass, jlong _address, jbyte group1, jbyte group2, jlong dominance) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setDominanceGroupPair(group1, group2, *((physx::PxDominanceGroupPair*) dominance));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getCpuDispatcher(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jlong) self->getCpuDispatcher();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getCudaContextManager(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jlong) self->getCudaContextManager();
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxScene__1createClient(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jbyte) self->createClient();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setSimulationEventCallback(JNIEnv*, jclass, jlong _address, jlong callback) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setSimulationEventCallback((physx::PxSimulationEventCallback*) callback);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getSimulationEventCallback(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jlong) self->getSimulationEventCallback();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setFilterShaderData(JNIEnv*, jclass, jlong _address, jlong data, jint dataSize) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setFilterShaderData((void*) data, dataSize);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getFilterShaderData(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jlong) self->getFilterShaderData();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getFilterShaderDataSize(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getFilterShaderDataSize();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getFilterShader(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxSimulationFilterShader _cache;
    physx::PxScene* self = (physx::PxScene*) _address;
    _cache = self->getFilterShader();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1resetFiltering(JNIEnv*, jclass, jlong _address, jlong actor) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->resetFiltering(*((physx::PxActor*) actor));
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getKinematicKinematicFilteringMode(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getKinematicKinematicFilteringMode();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getStaticKinematicFilteringMode(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getStaticKinematicFilteringMode();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1simulate__JF(JNIEnv*, jclass, jlong _address, jfloat elapsedTime) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->simulate(elapsedTime);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1simulate__JFJ(JNIEnv*, jclass, jlong _address, jfloat elapsedTime, jlong completionTask) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->simulate(elapsedTime, (physx::PxBaseTask*) completionTask);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1simulate__JFJJ(JNIEnv*, jclass, jlong _address, jfloat elapsedTime, jlong completionTask, jlong scratchMemBlock) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->simulate(elapsedTime, (physx::PxBaseTask*) completionTask, (void*) scratchMemBlock);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1simulate__JFJJI(JNIEnv*, jclass, jlong _address, jfloat elapsedTime, jlong completionTask, jlong scratchMemBlock, jint scratchMemBlockSize) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->simulate(elapsedTime, (physx::PxBaseTask*) completionTask, (void*) scratchMemBlock, scratchMemBlockSize);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1simulate__JFJJIZ(JNIEnv*, jclass, jlong _address, jfloat elapsedTime, jlong completionTask, jlong scratchMemBlock, jint scratchMemBlockSize, jboolean controlSimulation) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->simulate(elapsedTime, (physx::PxBaseTask*) completionTask, (void*) scratchMemBlock, scratchMemBlockSize, controlSimulation);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1advance__J(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->advance();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1advance__JJ(JNIEnv*, jclass, jlong _address, jlong completionTask) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->advance((physx::PxBaseTask*) completionTask);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1collide__JF(JNIEnv*, jclass, jlong _address, jfloat elapsedTime) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->collide(elapsedTime);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1collide__JFJ(JNIEnv*, jclass, jlong _address, jfloat elapsedTime, jlong completionTask) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->collide(elapsedTime, (physx::PxBaseTask*) completionTask);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1collide__JFJJ(JNIEnv*, jclass, jlong _address, jfloat elapsedTime, jlong completionTask, jlong scratchMemBlock) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->collide(elapsedTime, (physx::PxBaseTask*) completionTask, (void*) scratchMemBlock);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1collide__JFJJI(JNIEnv*, jclass, jlong _address, jfloat elapsedTime, jlong completionTask, jlong scratchMemBlock, jint scratchMemBlockSize) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->collide(elapsedTime, (physx::PxBaseTask*) completionTask, (void*) scratchMemBlock, scratchMemBlockSize);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1collide__JFJJIZ(JNIEnv*, jclass, jlong _address, jfloat elapsedTime, jlong completionTask, jlong scratchMemBlock, jint scratchMemBlockSize, jboolean controlSimulation) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->collide(elapsedTime, (physx::PxBaseTask*) completionTask, (void*) scratchMemBlock, scratchMemBlockSize, controlSimulation);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1checkResults__J(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->checkResults();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1checkResults__JZ(JNIEnv*, jclass, jlong _address, jboolean block) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->checkResults(block);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1fetchCollision__J(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->fetchCollision();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1fetchCollision__JZ(JNIEnv*, jclass, jlong _address, jboolean block) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->fetchCollision(block);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1fetchResults__J(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->fetchResults();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1fetchResults__JZ(JNIEnv*, jclass, jlong _address, jboolean block) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->fetchResults(block);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1processCallbacks(JNIEnv*, jclass, jlong _address, jlong continuation) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->processCallbacks((physx::PxBaseTask*) continuation);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1flushSimulation__J(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->flushSimulation();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1flushSimulation__JZ(JNIEnv*, jclass, jlong _address, jboolean sendPendingReports) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->flushSimulation(sendPendingReports);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setGravity(JNIEnv*, jclass, jlong _address, jlong vec) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setGravity(*((physx::PxVec3*) vec));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getGravity(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxVec3 _cache;
    physx::PxScene* self = (physx::PxScene*) _address;
    _cache = self->getGravity();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setBounceThresholdVelocity(JNIEnv*, jclass, jlong _address, jfloat t) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setBounceThresholdVelocity(t);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxScene__1getBounceThresholdVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jfloat) self->getBounceThresholdVelocity();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setCCDMaxPasses(JNIEnv*, jclass, jlong _address, jint ccdMaxPasses) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setCCDMaxPasses(ccdMaxPasses);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getCCDMaxPasses(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getCCDMaxPasses();
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxScene__1getFrictionOffsetThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jfloat) self->getFrictionOffsetThreshold();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setFrictionType(JNIEnv*, jclass, jlong _address, jint frictionType) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setFrictionType((PxFrictionTypeEnum) frictionType);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getFrictionType(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getFrictionType();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1getSimulationStatistics(JNIEnv*, jclass, jlong _address, jlong stats) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->getSimulationStatistics(*((physx::PxSimulationStatistics*) stats));
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getStaticStructure(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getStaticStructure();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getDynamicStructure(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getDynamicStructure();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1flushQueryUpdates(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->flushQueryUpdates();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1createBatchQuery(JNIEnv*, jclass, jlong _address, jlong desc) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jlong) self->createBatchQuery(*((physx::PxBatchQueryDesc*) desc));
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setDynamicTreeRebuildRateHint(JNIEnv*, jclass, jlong _address, jint dynamicTreeRebuildRateHint) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setDynamicTreeRebuildRateHint(dynamicTreeRebuildRateHint);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getDynamicTreeRebuildRateHint(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getDynamicTreeRebuildRateHint();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1forceDynamicTreeRebuild(JNIEnv*, jclass, jlong _address, jboolean rebuildStaticStructure, jboolean rebuildDynamicStructure) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->forceDynamicTreeRebuild(rebuildStaticStructure, rebuildDynamicStructure);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setSceneQueryUpdateMode(JNIEnv*, jclass, jlong _address, jint updateMode) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setSceneQueryUpdateMode((PxSceneQueryUpdateModeEnum) updateMode);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getSceneQueryUpdateMode(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getSceneQueryUpdateMode();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1sceneQueriesUpdate__J(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->sceneQueriesUpdate();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1sceneQueriesUpdate__JJ(JNIEnv*, jclass, jlong _address, jlong completionTask) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->sceneQueriesUpdate((physx::PxBaseTask*) completionTask);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1sceneQueriesUpdate__JJZ(JNIEnv*, jclass, jlong _address, jlong completionTask, jboolean controlSimulation) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->sceneQueriesUpdate((physx::PxBaseTask*) completionTask, controlSimulation);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1checkQueries__J(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->checkQueries();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1checkQueries__JZ(JNIEnv*, jclass, jlong _address, jboolean block) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->checkQueries(block);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1fetchQueries__J(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->fetchQueries();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1fetchQueries__JZ(JNIEnv*, jclass, jlong _address, jboolean block) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->fetchQueries(block);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1raycast__JJJFJ(JNIEnv*, jclass, jlong _address, jlong origin, jlong unitDir, jfloat distance, jlong hitCall) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->raycast(*((physx::PxVec3*) origin), *((physx::PxVec3*) unitDir), distance, *((physx::PxRaycastCallback*) hitCall));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1raycast__JJJFJJ(JNIEnv*, jclass, jlong _address, jlong origin, jlong unitDir, jfloat distance, jlong hitCall, jlong hitFlags) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->raycast(*((physx::PxVec3*) origin), *((physx::PxVec3*) unitDir), distance, *((physx::PxRaycastCallback*) hitCall), *((physx::PxHitFlags*) hitFlags));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1raycast__JJJFJJJ(JNIEnv*, jclass, jlong _address, jlong origin, jlong unitDir, jfloat distance, jlong hitCall, jlong hitFlags, jlong filterData) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->raycast(*((physx::PxVec3*) origin), *((physx::PxVec3*) unitDir), distance, *((physx::PxRaycastCallback*) hitCall), *((physx::PxHitFlags*) hitFlags), *((physx::PxQueryFilterData*) filterData));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1sweep__JJJJFJ(JNIEnv*, jclass, jlong _address, jlong geometry, jlong pose, jlong unitDir, jfloat distance, jlong hitCall) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->sweep(*((physx::PxGeometry*) geometry), *((physx::PxTransform*) pose), *((physx::PxVec3*) unitDir), distance, *((physx::PxSweepCallback*) hitCall));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1sweep__JJJJFJJ(JNIEnv*, jclass, jlong _address, jlong geometry, jlong pose, jlong unitDir, jfloat distance, jlong hitCall, jlong hitFlags) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->sweep(*((physx::PxGeometry*) geometry), *((physx::PxTransform*) pose), *((physx::PxVec3*) unitDir), distance, *((physx::PxSweepCallback*) hitCall), *((physx::PxHitFlags*) hitFlags));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1sweep__JJJJFJJJ(JNIEnv*, jclass, jlong _address, jlong geometry, jlong pose, jlong unitDir, jfloat distance, jlong hitCall, jlong hitFlags, jlong filterData) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->sweep(*((physx::PxGeometry*) geometry), *((physx::PxTransform*) pose), *((physx::PxVec3*) unitDir), distance, *((physx::PxSweepCallback*) hitCall), *((physx::PxHitFlags*) hitFlags), *((physx::PxQueryFilterData*) filterData));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1overlap__JJJJ(JNIEnv*, jclass, jlong _address, jlong geometry, jlong pose, jlong hitCall) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->overlap(*((physx::PxGeometry*) geometry), *((physx::PxTransform*) pose), *((physx::PxOverlapCallback*) hitCall));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1overlap__JJJJJ(JNIEnv*, jclass, jlong _address, jlong geometry, jlong pose, jlong hitCall, jlong filterData) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->overlap(*((physx::PxGeometry*) geometry), *((physx::PxTransform*) pose), *((physx::PxOverlapCallback*) hitCall), *((physx::PxQueryFilterData*) filterData));
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getSceneQueryStaticTimestamp(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getSceneQueryStaticTimestamp();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getBroadPhaseType(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getBroadPhaseType();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1getBroadPhaseCaps(JNIEnv*, jclass, jlong _address, jlong caps) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->getBroadPhaseCaps(*((physx::PxBroadPhaseCaps*) caps));
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getNbBroadPhaseRegions(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getNbBroadPhaseRegions();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getBroadPhaseRegions__JJI(JNIEnv*, jclass, jlong _address, jlong userBuffer, jint bufferSize) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getBroadPhaseRegions((physx::PxBroadPhaseRegionInfo*) userBuffer, bufferSize);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getBroadPhaseRegions__JJII(JNIEnv*, jclass, jlong _address, jlong userBuffer, jint bufferSize, jint startIndex) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getBroadPhaseRegions((physx::PxBroadPhaseRegionInfo*) userBuffer, bufferSize, startIndex);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1addBroadPhaseRegion__JJ(JNIEnv*, jclass, jlong _address, jlong region) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->addBroadPhaseRegion(*((physx::PxBroadPhaseRegion*) region));
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1addBroadPhaseRegion__JJZ(JNIEnv*, jclass, jlong _address, jlong region, jboolean populateRegion) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->addBroadPhaseRegion(*((physx::PxBroadPhaseRegion*) region), populateRegion);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1removeBroadPhaseRegion(JNIEnv*, jclass, jlong _address, jint handle) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jboolean) self->removeBroadPhaseRegion(handle);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1lockRead__J(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->lockRead();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1lockRead__JLjava_lang_String_2(JNIEnv* _env, jclass, jlong _address, jstring file) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->lockRead(_env->GetStringUTFChars(file, 0));
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1lockRead__JLjava_lang_String_2I(JNIEnv* _env, jclass, jlong _address, jstring file, jint line) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->lockRead(_env->GetStringUTFChars(file, 0), line);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1unlockRead(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->unlockRead();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1lockWrite__J(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->lockWrite();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1lockWrite__JLjava_lang_String_2(JNIEnv* _env, jclass, jlong _address, jstring file) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->lockWrite(_env->GetStringUTFChars(file, 0));
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1lockWrite__JLjava_lang_String_2I(JNIEnv* _env, jclass, jlong _address, jstring file, jint line) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->lockWrite(_env->GetStringUTFChars(file, 0), line);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1unlockWrite(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->unlockWrite();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setNbContactDataBlocks(JNIEnv*, jclass, jlong _address, jint numBlocks) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setNbContactDataBlocks(numBlocks);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getNbContactDataBlocksUsed(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getNbContactDataBlocksUsed();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getMaxNbContactDataBlocksUsed(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getMaxNbContactDataBlocksUsed();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getContactReportStreamBufferSize(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getContactReportStreamBufferSize();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setSolverBatchSize(JNIEnv*, jclass, jlong _address, jint solverBatchSize) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setSolverBatchSize(solverBatchSize);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getSolverBatchSize(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getSolverBatchSize();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setSolverArticulationBatchSize(JNIEnv*, jclass, jlong _address, jint solverBatchSize) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setSolverArticulationBatchSize(solverBatchSize);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getSolverArticulationBatchSize(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getSolverArticulationBatchSize();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->release();
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setFlag((PxSceneFlagEnum) flag, value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getFlags(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxSceneFlags _cache;
    physx::PxScene* self = (physx::PxScene*) _address;
    _cache = self->getFlags();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setLimits(JNIEnv*, jclass, jlong _address, jlong limits) {
    physx::PxScene* self = (physx::PxScene*) _address;
    self->setLimits(*((physx::PxSceneLimits*) limits));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getLimits(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxSceneLimits _cache;
    physx::PxScene* self = (physx::PxScene*) _address;
    _cache = self->getLimits();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getPhysics(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jlong) &self->getPhysics();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxScene__1getTimestamp(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* self = (physx::PxScene*) _address;
    return (jint) self->getTimestamp();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxScene* _self = (physx::PxScene*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxScene* _self = (physx::PxScene*) _address;
    _self->userData = (void*) value;
}

// PxSceneDesc
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSceneDesc);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1_1placement_1new_1PxSceneDesc(JNIEnv*, jclass, jlong _placement_address, jlong scale) {
    return (jlong) new((void*)_placement_address) physx::PxSceneDesc(*((physx::PxTolerancesScale*) scale));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1PxSceneDesc(JNIEnv*, jclass, jlong scale) {
    return (jlong) new physx::PxSceneDesc(*((physx::PxTolerancesScale*) scale));
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setToDefault(JNIEnv*, jclass, jlong _address, jlong scale) {
    physx::PxSceneDesc* self = (physx::PxSceneDesc*) _address;
    self->setToDefault(*((physx::PxTolerancesScale*) scale));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSceneDesc__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* self = (physx::PxSceneDesc*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSceneDesc*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getGravity(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) &_self->gravity;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setGravity(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->gravity = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getSimulationEventCallback(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) _self->simulationEventCallback;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setSimulationEventCallback(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->simulationEventCallback = (physx::PxSimulationEventCallback*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getFilterShaderData(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) _self->filterShaderData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setFilterShaderData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->filterShaderData = (void*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getFilterShaderDataSize(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->filterShaderDataSize;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setFilterShaderDataSize(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->filterShaderDataSize = value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getFilterShader(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) &_self->filterShader;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setFilterShader(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->filterShader = *((physx::PxSimulationFilterShader*) value);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getKineKineFilteringMode(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->kineKineFilteringMode;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setKineKineFilteringMode(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->kineKineFilteringMode = (PxPairFilteringModeEnum) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getStaticKineFilteringMode(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->staticKineFilteringMode;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setStaticKineFilteringMode(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->staticKineFilteringMode = (PxPairFilteringModeEnum) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getBroadPhaseType(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->broadPhaseType;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setBroadPhaseType(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->broadPhaseType = (PxBroadPhaseTypeEnum) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getLimits(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) &_self->limits;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setLimits(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->limits = *((physx::PxSceneLimits*) value);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getFrictionType(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->frictionType;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setFrictionType(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->frictionType = (PxFrictionTypeEnum) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getSolverType(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->solverType;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setSolverType(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->solverType = (PxSolverTypeEnum) value;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxSceneDesc__1getBounceThresholdVelocity(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jfloat) _self->bounceThresholdVelocity;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setBounceThresholdVelocity(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->bounceThresholdVelocity = value;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxSceneDesc__1getFrictionOffsetThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jfloat) _self->frictionOffsetThreshold;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setFrictionOffsetThreshold(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->frictionOffsetThreshold = value;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxSceneDesc__1getCcdMaxSeparation(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jfloat) _self->ccdMaxSeparation;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setCcdMaxSeparation(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->ccdMaxSeparation = value;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxSceneDesc__1getSolverOffsetSlop(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jfloat) _self->solverOffsetSlop;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setSolverOffsetSlop(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->solverOffsetSlop = value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) &_self->flags;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->flags = *((physx::PxSceneFlags*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getCpuDispatcher(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) _self->cpuDispatcher;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setCpuDispatcher(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->cpuDispatcher = (physx::PxCpuDispatcher*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getCudaContextManager(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) _self->cudaContextManager;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setCudaContextManager(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->cudaContextManager = (physx::PxCudaContextManager*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getStaticStructure(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->staticStructure;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setStaticStructure(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->staticStructure = (PxPruningStructureTypeEnum) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getDynamicStructure(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->dynamicStructure;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setDynamicStructure(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->dynamicStructure = (PxPruningStructureTypeEnum) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getDynamicTreeRebuildRateHint(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->dynamicTreeRebuildRateHint;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setDynamicTreeRebuildRateHint(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->dynamicTreeRebuildRateHint = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getSceneQueryUpdateMode(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->sceneQueryUpdateMode;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setSceneQueryUpdateMode(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->sceneQueryUpdateMode = (PxSceneQueryUpdateModeEnum) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->userData = (void*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getSolverBatchSize(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->solverBatchSize;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setSolverBatchSize(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->solverBatchSize = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getSolverArticulationBatchSize(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->solverArticulationBatchSize;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setSolverArticulationBatchSize(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->solverArticulationBatchSize = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getNbContactDataBlocks(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->nbContactDataBlocks;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setNbContactDataBlocks(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->nbContactDataBlocks = value;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxSceneDesc__1getMaxBiasCoefficient(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jfloat) _self->maxBiasCoefficient;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setMaxBiasCoefficient(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->maxBiasCoefficient = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getContactReportStreamBufferSize(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->contactReportStreamBufferSize;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setContactReportStreamBufferSize(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->contactReportStreamBufferSize = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getCcdMaxPasses(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->ccdMaxPasses;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setCcdMaxPasses(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->ccdMaxPasses = value;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxSceneDesc__1getCcdThreshold(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jfloat) _self->ccdThreshold;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setCcdThreshold(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->ccdThreshold = value;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxSceneDesc__1getWakeCounterResetValue(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jfloat) _self->wakeCounterResetValue;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setWakeCounterResetValue(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->wakeCounterResetValue = value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getSanityBounds(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) &_self->sanityBounds;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setSanityBounds(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->sanityBounds = *((physx::PxBounds3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getGpuDynamicsConfig(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jlong) &_self->gpuDynamicsConfig;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setGpuDynamicsConfig(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->gpuDynamicsConfig = *((physx::PxgDynamicsMemoryConfig*) value);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getGpuMaxNumPartitions(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->gpuMaxNumPartitions;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setGpuMaxNumPartitions(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->gpuMaxNumPartitions = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneDesc__1getGpuComputeVersion(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    return (jint) _self->gpuComputeVersion;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setGpuComputeVersion(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneDesc* _self = (physx::PxSceneDesc*) _address;
    _self->gpuComputeVersion = value;
}

// PxSceneFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSceneFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneFlags__1_1placement_1new_1PxSceneFlags(JNIEnv*, jclass, jlong _placement_address, jint flags) {
    return (jlong) new((void*)_placement_address) physx::PxSceneFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneFlags__1PxSceneFlags(JNIEnv*, jclass, jint flags) {
    return (jlong) new physx::PxSceneFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSceneFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxSceneFlags* self = (physx::PxSceneFlags*) _address;
    return (jboolean) self->isSet((PxSceneFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxSceneFlags* self = (physx::PxSceneFlags*) _address;
    self->set((PxSceneFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxSceneFlags* self = (physx::PxSceneFlags*) _address;
    self->clear((PxSceneFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSceneFlags*) _address;
}

// PxSceneLimits
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneLimits__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxSceneLimits);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneLimits__1_1placement_1new_1PxSceneLimits(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxSceneLimits();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneLimits__1PxSceneLimits(JNIEnv*, jclass) {
    return (jlong) new physx::PxSceneLimits();
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneLimits__1setToDefault(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneLimits* self = (physx::PxSceneLimits*) _address;
    self->setToDefault();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSceneLimits__1isValid(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneLimits* self = (physx::PxSceneLimits*) _address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneLimits__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSceneLimits*) _address;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneLimits__1getMaxNbActors(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    return (jint) _self->maxNbActors;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneLimits__1setMaxNbActors(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    _self->maxNbActors = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneLimits__1getMaxNbBodies(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    return (jint) _self->maxNbBodies;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneLimits__1setMaxNbBodies(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    _self->maxNbBodies = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneLimits__1getMaxNbStaticShapes(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    return (jint) _self->maxNbStaticShapes;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneLimits__1setMaxNbStaticShapes(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    _self->maxNbStaticShapes = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneLimits__1getMaxNbDynamicShapes(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    return (jint) _self->maxNbDynamicShapes;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneLimits__1setMaxNbDynamicShapes(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    _self->maxNbDynamicShapes = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneLimits__1getMaxNbAggregates(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    return (jint) _self->maxNbAggregates;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneLimits__1setMaxNbAggregates(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    _self->maxNbAggregates = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneLimits__1getMaxNbConstraints(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    return (jint) _self->maxNbConstraints;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneLimits__1setMaxNbConstraints(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    _self->maxNbConstraints = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneLimits__1getMaxNbRegions(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    return (jint) _self->maxNbRegions;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneLimits__1setMaxNbRegions(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    _self->maxNbRegions = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneLimits__1getMaxNbBroadPhaseOverlaps(JNIEnv*, jclass, jlong _address) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    return (jint) _self->maxNbBroadPhaseOverlaps;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneLimits__1setMaxNbBroadPhaseOverlaps(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSceneLimits* _self = (physx::PxSceneLimits*) _address;
    _self->maxNbBroadPhaseOverlaps = value;
}

// PxShape
JNIEXPORT jint JNICALL Java_physx_physics_PxShape__1getReferenceCount(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jint) self->getReferenceCount();
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1acquireReference(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->acquireReference();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxShape__1getGeometryType(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jint) self->getGeometryType();
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setGeometry(JNIEnv*, jclass, jlong _address, jlong geometry) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setGeometry(*((physx::PxGeometry*) geometry));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShape__1getGeometry(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxGeometryHolder _cache;
    physx::PxShape* self = (physx::PxShape*) _address;
    _cache = self->getGeometry();
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxShape__1getBoxGeometry(JNIEnv*, jclass, jlong _address, jlong geometry) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jboolean) self->getBoxGeometry(*((physx::PxBoxGeometry*) geometry));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxShape__1getSphereGeometry(JNIEnv*, jclass, jlong _address, jlong geometry) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jboolean) self->getSphereGeometry(*((physx::PxSphereGeometry*) geometry));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxShape__1getCapsuleGeometry(JNIEnv*, jclass, jlong _address, jlong geometry) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jboolean) self->getCapsuleGeometry(*((physx::PxCapsuleGeometry*) geometry));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxShape__1getPlaneGeometry(JNIEnv*, jclass, jlong _address, jlong geometry) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jboolean) self->getPlaneGeometry(*((physx::PxPlaneGeometry*) geometry));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxShape__1getConvexMeshGeometry(JNIEnv*, jclass, jlong _address, jlong geometry) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jboolean) self->getConvexMeshGeometry(*((physx::PxConvexMeshGeometry*) geometry));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxShape__1getTriangleMeshGeometry(JNIEnv*, jclass, jlong _address, jlong geometry) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jboolean) self->getTriangleMeshGeometry(*((physx::PxTriangleMeshGeometry*) geometry));
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxShape__1getHeightFieldGeometry(JNIEnv*, jclass, jlong _address, jlong geometry) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jboolean) self->getHeightFieldGeometry(*((physx::PxHeightFieldGeometry*) geometry));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShape__1getActor(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jlong) self->getActor();
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setMaterials(JNIEnv*, jclass, jlong _address, jlong materials, jshort materialCount) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setMaterials((PxMaterialPtr*) materials, materialCount);
}
JNIEXPORT jshort JNICALL Java_physx_physics_PxShape__1getNbMaterials(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jshort) self->getNbMaterials();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxShape__1getMaterials(JNIEnv*, jclass, jlong _address, jlong userBuffer, jint bufferSize, jint startIndex) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jint) self->getMaterials((PxMaterialPtr*) userBuffer, bufferSize, startIndex);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShape__1getMaterialFromInternalFaceIndex(JNIEnv*, jclass, jlong _address, jint faceIndex) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jlong) self->getMaterialFromInternalFaceIndex(faceIndex);
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setContactOffset(JNIEnv*, jclass, jlong _address, jfloat contactOffset) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setContactOffset(contactOffset);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxShape__1getContactOffset(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jfloat) self->getContactOffset();
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setRestOffset(JNIEnv*, jclass, jlong _address, jfloat restOffset) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setRestOffset(restOffset);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxShape__1getRestOffset(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jfloat) self->getRestOffset();
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setTorsionalPatchRadius(JNIEnv*, jclass, jlong _address, jfloat radius) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setTorsionalPatchRadius(radius);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxShape__1getTorsionalPatchRadius(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jfloat) self->getTorsionalPatchRadius();
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setMinTorsionalPatchRadius(JNIEnv*, jclass, jlong _address, jfloat radius) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setMinTorsionalPatchRadius(radius);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxShape__1getMinTorsionalPatchRadius(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jfloat) self->getMinTorsionalPatchRadius();
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setFlag(JNIEnv*, jclass, jlong _address, jint flag, jboolean value) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setFlag((PxShapeFlagEnum) flag, value);
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setFlags(JNIEnv*, jclass, jlong _address, jlong inFlags) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setFlags(*((physx::PxShapeFlags*) inFlags));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShape__1getFlags(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxShapeFlags _cache;
    physx::PxShape* self = (physx::PxShape*) _address;
    _cache = self->getFlags();
    return (jlong) &_cache;
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxShape__1isExclusive(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return (jboolean) self->isExclusive();
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setName(JNIEnv* _env, jclass, jlong _address, jstring name) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setName(_env->GetStringUTFChars(name, 0));
}
JNIEXPORT jstring JNICALL Java_physx_physics_PxShape__1getName(JNIEnv* _env, jclass, jlong _address) {
    physx::PxShape* self = (physx::PxShape*) _address;
    return _env->NewStringUTF(self->getName());
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setLocalPose(JNIEnv*, jclass, jlong _address, jlong pose) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setLocalPose(*((physx::PxTransform*) pose));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShape__1getLocalPose(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxTransform _cache;
    physx::PxShape* self = (physx::PxShape*) _address;
    _cache = self->getLocalPose();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setSimulationFilterData(JNIEnv*, jclass, jlong _address, jlong data) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setSimulationFilterData(*((physx::PxFilterData*) data));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShape__1getSimulationFilterData(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxFilterData _cache;
    physx::PxShape* self = (physx::PxShape*) _address;
    _cache = self->getSimulationFilterData();
    return (jlong) &_cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setQueryFilterData(JNIEnv*, jclass, jlong _address, jlong data) {
    physx::PxShape* self = (physx::PxShape*) _address;
    self->setQueryFilterData(*((physx::PxFilterData*) data));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShape__1getQueryFilterData(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxFilterData _cache;
    physx::PxShape* self = (physx::PxShape*) _address;
    _cache = self->getQueryFilterData();
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShape__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxShape* _self = (physx::PxShape*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxShape* _self = (physx::PxShape*) _address;
    _self->userData = (void*) value;
}

// PxShapeFlags
JNIEXPORT jint JNICALL Java_physx_physics_PxShapeFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxShapeFlags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShapeFlags__1_1placement_1new_1PxShapeFlags(JNIEnv*, jclass, jlong _placement_address, jbyte flags) {
    return (jlong) new((void*)_placement_address) physx::PxShapeFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShapeFlags__1PxShapeFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxShapeFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxShapeFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxShapeFlags* self = (physx::PxShapeFlags*) _address;
    return (jboolean) self->isSet((PxShapeFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxShapeFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxShapeFlags* self = (physx::PxShapeFlags*) _address;
    self->set((PxShapeFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxShapeFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxShapeFlags* self = (physx::PxShapeFlags*) _address;
    self->clear((PxShapeFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxShapeFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxShapeFlags*) _address;
}

// PxSimulationEventCallback
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationEventCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSimulationEventCallback*) _address;
}

// SimpleSimulationEventCallback
JNIEXPORT void JNICALL Java_physx_physics_SimpleSimulationEventCallback__1onConstraintBreak(JNIEnv*, jclass, jlong _address, jlong constraints, jint count) {
    SimpleSimulationEventCallback* self = (SimpleSimulationEventCallback*) _address;
    self->onConstraintBreak((physx::PxConstraintInfo*) constraints, count);
}
JNIEXPORT void JNICALL Java_physx_physics_SimpleSimulationEventCallback__1onWake(JNIEnv*, jclass, jlong _address, jlong actors, jint count) {
    SimpleSimulationEventCallback* self = (SimpleSimulationEventCallback*) _address;
    self->onWake((PxActorPtr*) actors, count);
}
JNIEXPORT void JNICALL Java_physx_physics_SimpleSimulationEventCallback__1onSleep(JNIEnv*, jclass, jlong _address, jlong actors, jint count) {
    SimpleSimulationEventCallback* self = (SimpleSimulationEventCallback*) _address;
    self->onSleep((PxActorPtr*) actors, count);
}
JNIEXPORT void JNICALL Java_physx_physics_SimpleSimulationEventCallback__1onContact(JNIEnv*, jclass, jlong _address, jlong pairHeader, jlong pairs, jint nbPairs) {
    SimpleSimulationEventCallback* self = (SimpleSimulationEventCallback*) _address;
    self->onContact(*((physx::PxContactPairHeader*) pairHeader), (physx::PxContactPair*) pairs, nbPairs);
}
JNIEXPORT void JNICALL Java_physx_physics_SimpleSimulationEventCallback__1onTrigger(JNIEnv*, jclass, jlong _address, jlong pairs, jint count) {
    SimpleSimulationEventCallback* self = (SimpleSimulationEventCallback*) _address;
    self->onTrigger((physx::PxTriggerPair*) pairs, count);
}
JNIEXPORT void JNICALL Java_physx_physics_SimpleSimulationEventCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (SimpleSimulationEventCallback*) _address;
}

// JavaSimulationEventCallback
JNIEXPORT jlong JNICALL Java_physx_physics_JavaSimulationEventCallback__1JavaSimulationEventCallback(JNIEnv* env, jobject obj) {
    return (jlong) new JavaSimulationEventCallback(env, obj);
}
JNIEXPORT void JNICALL Java_physx_physics_JavaSimulationEventCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (JavaSimulationEventCallback*) address;
}

// PxSimulationFilterShader
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationFilterShader__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSimulationFilterShader*) _address;
}

// PxSimulationStatistics
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSimulationStatistics*) _address;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbActiveConstraints(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbActiveConstraints;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbActiveConstraints(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbActiveConstraints = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbActiveDynamicBodies(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbActiveDynamicBodies;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbActiveDynamicBodies(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbActiveDynamicBodies = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbActiveKinematicBodies(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbActiveKinematicBodies;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbActiveKinematicBodies(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbActiveKinematicBodies = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbStaticBodies(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbStaticBodies;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbStaticBodies(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbStaticBodies = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbDynamicBodies(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbDynamicBodies;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbDynamicBodies(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbDynamicBodies = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbKinematicBodies(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbKinematicBodies;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbKinematicBodies(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbKinematicBodies = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbShapes(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbShapes[_index];
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbShapes(JNIEnv*, jclass, jlong _address, jint _index, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbShapes[_index] = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbAggregates(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbAggregates;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbAggregates(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbAggregates = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbArticulations(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbArticulations;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbArticulations(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbArticulations = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbAxisSolverConstraints(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbAxisSolverConstraints;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbAxisSolverConstraints(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbAxisSolverConstraints = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getCompressedContactSize(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->compressedContactSize;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setCompressedContactSize(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->compressedContactSize = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getRequiredContactConstraintMemory(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->requiredContactConstraintMemory;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setRequiredContactConstraintMemory(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->requiredContactConstraintMemory = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getPeakConstraintMemory(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->peakConstraintMemory;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setPeakConstraintMemory(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->peakConstraintMemory = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbDiscreteContactPairsTotal(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbDiscreteContactPairsTotal;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbDiscreteContactPairsTotal(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbDiscreteContactPairsTotal = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbDiscreteContactPairsWithCacheHits(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbDiscreteContactPairsWithCacheHits;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbDiscreteContactPairsWithCacheHits(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbDiscreteContactPairsWithCacheHits = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbDiscreteContactPairsWithContacts(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbDiscreteContactPairsWithContacts;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbDiscreteContactPairsWithContacts(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbDiscreteContactPairsWithContacts = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbNewPairs(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbNewPairs;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbNewPairs(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbNewPairs = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbLostPairs(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbLostPairs;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbLostPairs(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbLostPairs = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbNewTouches(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbNewTouches;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbNewTouches(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbNewTouches = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbLostTouches(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbLostTouches;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbLostTouches(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbLostTouches = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbPartitions(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbPartitions;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbPartitions(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbPartitions = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbBroadPhaseAdds(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbBroadPhaseAdds;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbBroadPhaseAdds(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbBroadPhaseAdds = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSimulationStatistics__1getNbBroadPhaseRemoves(JNIEnv*, jclass, jlong _address) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    return (jint) _self->nbBroadPhaseRemoves;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationStatistics__1setNbBroadPhaseRemoves(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSimulationStatistics* _self = (physx::PxSimulationStatistics*) _address;
    _self->nbBroadPhaseRemoves = value;
}

// PxSpatialVelocity
JNIEXPORT void JNICALL Java_physx_physics_PxSpatialVelocity__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSpatialVelocity*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSpatialVelocity__1getLinear(JNIEnv*, jclass, jlong _address) {
    physx::PxSpatialVelocity* _self = (physx::PxSpatialVelocity*) _address;
    return (jlong) &_self->linear;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSpatialVelocity__1setLinear(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSpatialVelocity* _self = (physx::PxSpatialVelocity*) _address;
    _self->linear = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSpatialVelocity__1getAngular(JNIEnv*, jclass, jlong _address) {
    physx::PxSpatialVelocity* _self = (physx::PxSpatialVelocity*) _address;
    return (jlong) &_self->angular;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSpatialVelocity__1setAngular(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSpatialVelocity* _self = (physx::PxSpatialVelocity*) _address;
    _self->angular = *((physx::PxVec3*) value);
}

// PxSweepBuffer10
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepBuffer10__1PxSweepBuffer10(JNIEnv*, jclass) {
    return (jlong) new PxSweepBuffer10();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSweepBuffer10__1getNbAnyHits(JNIEnv*, jclass, jlong _address) {
    PxSweepBuffer10* self = (PxSweepBuffer10*) _address;
    return (jint) self->getNbAnyHits();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepBuffer10__1getAnyHit(JNIEnv*, jclass, jlong _address, jint index) {
    PxSweepBuffer10* self = (PxSweepBuffer10*) _address;
    return (jlong) &self->getAnyHit(index);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSweepBuffer10__1getNbTouches(JNIEnv*, jclass, jlong _address) {
    PxSweepBuffer10* self = (PxSweepBuffer10*) _address;
    return (jint) self->getNbTouches();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepBuffer10__1getTouches(JNIEnv*, jclass, jlong _address) {
    PxSweepBuffer10* self = (PxSweepBuffer10*) _address;
    return (jlong) self->getTouches();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepBuffer10__1getTouch(JNIEnv*, jclass, jlong _address, jint index) {
    PxSweepBuffer10* self = (PxSweepBuffer10*) _address;
    return (jlong) &self->getTouch(index);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSweepBuffer10__1getMaxNbTouches(JNIEnv*, jclass, jlong _address) {
    PxSweepBuffer10* self = (PxSweepBuffer10*) _address;
    return (jint) self->getMaxNbTouches();
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepBuffer10__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxSweepBuffer10*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepBuffer10__1getBlock(JNIEnv*, jclass, jlong _address) {
    PxSweepBuffer10* _self = (PxSweepBuffer10*) _address;
    return (jlong) &_self->block;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepBuffer10__1setBlock(JNIEnv*, jclass, jlong _address, jlong value) {
    PxSweepBuffer10* _self = (PxSweepBuffer10*) _address;
    _self->block = *((physx::PxSweepHit*) value);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSweepBuffer10__1getHasBlock(JNIEnv*, jclass, jlong _address) {
    PxSweepBuffer10* _self = (PxSweepBuffer10*) _address;
    return (jboolean) _self->hasBlock;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepBuffer10__1setHasBlock(JNIEnv*, jclass, jlong _address, jboolean value) {
    PxSweepBuffer10* _self = (PxSweepBuffer10*) _address;
    _self->hasBlock = value;
}

// PxSweepCallback
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSweepCallback__1hasAnyHits(JNIEnv*, jclass, jlong _address) {
    physx::PxSweepCallback* self = (physx::PxSweepCallback*) _address;
    return (jboolean) self->hasAnyHits();
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSweepCallback*) _address;
}

// PxSweepHit
JNIEXPORT void JNICALL Java_physx_physics_PxSweepHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSweepHit*) _address;
}

// PxSweepQueryResult
JNIEXPORT jint JNICALL Java_physx_physics_PxSweepQueryResult__1getNbAnyHits(JNIEnv*, jclass, jlong _address) {
    physx::PxSweepQueryResult* self = (physx::PxSweepQueryResult*) _address;
    return (jint) self->getNbAnyHits();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepQueryResult__1getAnyHit(JNIEnv*, jclass, jlong _address, jint index) {
    physx::PxSweepQueryResult* self = (physx::PxSweepQueryResult*) _address;
    return (jlong) &self->getAnyHit(index);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepQueryResult__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxSweepQueryResult*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepQueryResult__1getBlock(JNIEnv*, jclass, jlong _address) {
    physx::PxSweepQueryResult* _self = (physx::PxSweepQueryResult*) _address;
    return (jlong) &_self->block;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepQueryResult__1setBlock(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSweepQueryResult* _self = (physx::PxSweepQueryResult*) _address;
    _self->block = *((physx::PxSweepHit*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepQueryResult__1getTouches(JNIEnv*, jclass, jlong _address) {
    physx::PxSweepQueryResult* _self = (physx::PxSweepQueryResult*) _address;
    return (jlong) _self->touches;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepQueryResult__1setTouches(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSweepQueryResult* _self = (physx::PxSweepQueryResult*) _address;
    _self->touches = (physx::PxSweepHit*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSweepQueryResult__1getNbTouches(JNIEnv*, jclass, jlong _address) {
    physx::PxSweepQueryResult* _self = (physx::PxSweepQueryResult*) _address;
    return (jint) _self->nbTouches;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepQueryResult__1setNbTouches(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxSweepQueryResult* _self = (physx::PxSweepQueryResult*) _address;
    _self->nbTouches = value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepQueryResult__1getUserData(JNIEnv*, jclass, jlong _address) {
    physx::PxSweepQueryResult* _self = (physx::PxSweepQueryResult*) _address;
    return (jlong) _self->userData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepQueryResult__1setUserData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxSweepQueryResult* _self = (physx::PxSweepQueryResult*) _address;
    _self->userData = (void*) value;
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxSweepQueryResult__1getQueryStatus(JNIEnv*, jclass, jlong _address) {
    physx::PxSweepQueryResult* _self = (physx::PxSweepQueryResult*) _address;
    return (jbyte) _self->queryStatus;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepQueryResult__1setQueryStatus(JNIEnv*, jclass, jlong _address, jbyte value) {
    physx::PxSweepQueryResult* _self = (physx::PxSweepQueryResult*) _address;
    _self->queryStatus = value;
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSweepQueryResult__1getHasBlock(JNIEnv*, jclass, jlong _address) {
    physx::PxSweepQueryResult* _self = (physx::PxSweepQueryResult*) _address;
    return (jboolean) _self->hasBlock;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepQueryResult__1setHasBlock(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxSweepQueryResult* _self = (physx::PxSweepQueryResult*) _address;
    _self->hasBlock = value;
}

// PxTriggerPair
JNIEXPORT void JNICALL Java_physx_physics_PxTriggerPair__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxTriggerPair*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxTriggerPair__1getTriggerShape(JNIEnv*, jclass, jlong _address) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    return (jlong) _self->triggerShape;
}
JNIEXPORT void JNICALL Java_physx_physics_PxTriggerPair__1setTriggerShape(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    _self->triggerShape = (physx::PxShape*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxTriggerPair__1getTriggerActor(JNIEnv*, jclass, jlong _address) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    return (jlong) _self->triggerActor;
}
JNIEXPORT void JNICALL Java_physx_physics_PxTriggerPair__1setTriggerActor(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    _self->triggerActor = (physx::PxRigidActor*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxTriggerPair__1getOtherShape(JNIEnv*, jclass, jlong _address) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    return (jlong) _self->otherShape;
}
JNIEXPORT void JNICALL Java_physx_physics_PxTriggerPair__1setOtherShape(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    _self->otherShape = (physx::PxShape*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxTriggerPair__1getOtherActor(JNIEnv*, jclass, jlong _address) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    return (jlong) _self->otherActor;
}
JNIEXPORT void JNICALL Java_physx_physics_PxTriggerPair__1setOtherActor(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    _self->otherActor = (physx::PxRigidActor*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxTriggerPair__1getStatus(JNIEnv*, jclass, jlong _address) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    return (jint) _self->status;
}
JNIEXPORT void JNICALL Java_physx_physics_PxTriggerPair__1setStatus(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    _self->status = (PxPairFlagEnum) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxTriggerPair__1getFlags(JNIEnv*, jclass, jlong _address) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    return (jlong) &_self->flags;
}
JNIEXPORT void JNICALL Java_physx_physics_PxTriggerPair__1setFlags(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxTriggerPair* _self = (physx::PxTriggerPair*) _address;
    _self->flags = *((physx::PxTriggerPairFlags*) value);
}

// PxTriggerPairFlags
JNIEXPORT jlong JNICALL Java_physx_physics_PxTriggerPairFlags__1PxTriggerPairFlags(JNIEnv*, jclass, jbyte flags) {
    return (jlong) new physx::PxTriggerPairFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxTriggerPairFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxTriggerPairFlags* self = (physx::PxTriggerPairFlags*) _address;
    return (jboolean) self->isSet((PxTriggerPairFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxTriggerPairFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxTriggerPairFlags* self = (physx::PxTriggerPairFlags*) _address;
    self->set((PxTriggerPairFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxTriggerPairFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxTriggerPairFlags* self = (physx::PxTriggerPairFlags*) _address;
    self->clear((PxTriggerPairFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxTriggerPairFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxTriggerPairFlags*) _address;
}

// PxActorFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxActorFlagEnum__1geteVISUALIZATION(JNIEnv*, jclass) {
    return PxActorFlagEnum::eVISUALIZATION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActorFlagEnum__1geteDISABLE_1GRAVITY(JNIEnv*, jclass) {
    return PxActorFlagEnum::eDISABLE_GRAVITY;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActorFlagEnum__1geteSEND_1SLEEP_1NOTIFIES(JNIEnv*, jclass) {
    return PxActorFlagEnum::eSEND_SLEEP_NOTIFIES;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActorFlagEnum__1geteDISABLE_1SIMULATION(JNIEnv*, jclass) {
    return PxActorFlagEnum::eDISABLE_SIMULATION;
}

// PxActorTypeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxActorTypeEnum__1geteRIGID_1STATIC(JNIEnv*, jclass) {
    return PxActorTypeEnum::eRIGID_STATIC;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActorTypeEnum__1geteRIGID_1DYNAMIC(JNIEnv*, jclass) {
    return PxActorTypeEnum::eRIGID_DYNAMIC;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActorTypeEnum__1geteARTICULATION_1LINK(JNIEnv*, jclass) {
    return PxActorTypeEnum::eARTICULATION_LINK;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActorTypeEnum__1geteACTOR_1COUNT(JNIEnv*, jclass) {
    return PxActorTypeEnum::eACTOR_COUNT;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActorTypeEnum__1geteACTOR_1FORCE_1DWORD(JNIEnv*, jclass) {
    return PxActorTypeEnum::eACTOR_FORCE_DWORD;
}

// PxActorTypeFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxActorTypeFlagEnum__1geteRIGID_1STATIC(JNIEnv*, jclass) {
    return PxActorTypeFlagEnum::eRIGID_STATIC;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxActorTypeFlagEnum__1geteRIGID_1DYNAMIC(JNIEnv*, jclass) {
    return PxActorTypeFlagEnum::eRIGID_DYNAMIC;
}

// PxArticulationAxisEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationAxisEnum__1geteTWIST(JNIEnv*, jclass) {
    return PxArticulationAxisEnum::eTWIST;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationAxisEnum__1geteSWING1(JNIEnv*, jclass) {
    return PxArticulationAxisEnum::eSWING1;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationAxisEnum__1geteSWING2(JNIEnv*, jclass) {
    return PxArticulationAxisEnum::eSWING2;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationAxisEnum__1geteX(JNIEnv*, jclass) {
    return PxArticulationAxisEnum::eX;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationAxisEnum__1geteY(JNIEnv*, jclass) {
    return PxArticulationAxisEnum::eY;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationAxisEnum__1geteZ(JNIEnv*, jclass) {
    return PxArticulationAxisEnum::eZ;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationAxisEnum__1geteCOUNT(JNIEnv*, jclass) {
    return PxArticulationAxisEnum::eCOUNT;
}

// PxArticulationCacheEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCacheEnum__1geteVELOCITY(JNIEnv*, jclass) {
    return PxArticulationCacheEnum::eVELOCITY;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCacheEnum__1geteACCELERATION(JNIEnv*, jclass) {
    return PxArticulationCacheEnum::eACCELERATION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCacheEnum__1getePOSITION(JNIEnv*, jclass) {
    return PxArticulationCacheEnum::ePOSITION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCacheEnum__1geteFORCE(JNIEnv*, jclass) {
    return PxArticulationCacheEnum::eFORCE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCacheEnum__1geteLINKVELOCITY(JNIEnv*, jclass) {
    return PxArticulationCacheEnum::eLINKVELOCITY;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCacheEnum__1geteLINKACCELERATION(JNIEnv*, jclass) {
    return PxArticulationCacheEnum::eLINKACCELERATION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCacheEnum__1geteROOT(JNIEnv*, jclass) {
    return PxArticulationCacheEnum::eROOT;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationCacheEnum__1geteALL(JNIEnv*, jclass) {
    return PxArticulationCacheEnum::eALL;
}

// PxArticulationDriveTypeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationDriveTypeEnum__1geteFORCE(JNIEnv*, jclass) {
    return PxArticulationDriveTypeEnum::eFORCE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationDriveTypeEnum__1geteACCELERATION(JNIEnv*, jclass) {
    return PxArticulationDriveTypeEnum::eACCELERATION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationDriveTypeEnum__1geteTARGET(JNIEnv*, jclass) {
    return PxArticulationDriveTypeEnum::eTARGET;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationDriveTypeEnum__1geteVELOCITY(JNIEnv*, jclass) {
    return PxArticulationDriveTypeEnum::eVELOCITY;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationDriveTypeEnum__1geteNONE(JNIEnv*, jclass) {
    return PxArticulationDriveTypeEnum::eNONE;
}

// PxArticulationFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationFlagEnum__1geteFIX_1BASE(JNIEnv*, jclass) {
    return PxArticulationFlagEnum::eFIX_BASE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationFlagEnum__1geteDRIVE_1LIMITS_1ARE_1FORCES(JNIEnv*, jclass) {
    return PxArticulationFlagEnum::eDRIVE_LIMITS_ARE_FORCES;
}

// PxArticulationJointDriveTypeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationJointDriveTypeEnum__1geteTARGET(JNIEnv*, jclass) {
    return PxArticulationJointDriveTypeEnum::eTARGET;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationJointDriveTypeEnum__1geteERROR(JNIEnv*, jclass) {
    return PxArticulationJointDriveTypeEnum::eERROR;
}

// PxArticulationMotionEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationMotionEnum__1geteLOCKED(JNIEnv*, jclass) {
    return PxArticulationMotionEnum::eLOCKED;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationMotionEnum__1geteLIMITED(JNIEnv*, jclass) {
    return PxArticulationMotionEnum::eLIMITED;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationMotionEnum__1geteFREE(JNIEnv*, jclass) {
    return PxArticulationMotionEnum::eFREE;
}

// PxArticulationJointTypeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationJointTypeEnum__1getePRISMATIC(JNIEnv*, jclass) {
    return PxArticulationJointTypeEnum::ePRISMATIC;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationJointTypeEnum__1geteREVOLUTE(JNIEnv*, jclass) {
    return PxArticulationJointTypeEnum::eREVOLUTE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationJointTypeEnum__1geteSPHERICAL(JNIEnv*, jclass) {
    return PxArticulationJointTypeEnum::eSPHERICAL;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationJointTypeEnum__1geteFIX(JNIEnv*, jclass) {
    return PxArticulationJointTypeEnum::eFIX;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxArticulationJointTypeEnum__1geteUNDEFINED(JNIEnv*, jclass) {
    return PxArticulationJointTypeEnum::eUNDEFINED;
}

// PxBroadPhaseTypeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxBroadPhaseTypeEnum__1geteSAP(JNIEnv*, jclass) {
    return PxBroadPhaseTypeEnum::eSAP;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBroadPhaseTypeEnum__1geteMBP(JNIEnv*, jclass) {
    return PxBroadPhaseTypeEnum::eMBP;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBroadPhaseTypeEnum__1geteABP(JNIEnv*, jclass) {
    return PxBroadPhaseTypeEnum::eABP;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBroadPhaseTypeEnum__1geteGPU(JNIEnv*, jclass) {
    return PxBroadPhaseTypeEnum::eGPU;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBroadPhaseTypeEnum__1geteLAST(JNIEnv*, jclass) {
    return PxBroadPhaseTypeEnum::eLAST;
}

// PxConstraintFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1geteBROKEN(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::eBROKEN;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1getePROJECT_1TO_1ACTOR0(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::ePROJECT_TO_ACTOR0;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1getePROJECT_1TO_1ACTOR1(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::ePROJECT_TO_ACTOR1;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1getePROJECTION(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::ePROJECTION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1geteCOLLISION_1ENABLED(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::eCOLLISION_ENABLED;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1geteVISUALIZATION(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::eVISUALIZATION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1geteDRIVE_1LIMITS_1ARE_1FORCES(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::eDRIVE_LIMITS_ARE_FORCES;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1geteIMPROVED_1SLERP(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::eIMPROVED_SLERP;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1geteDISABLE_1PREPROCESSING(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::eDISABLE_PREPROCESSING;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1geteENABLE_1EXTENDED_1LIMITS(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::eENABLE_EXTENDED_LIMITS;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxConstraintFlagEnum__1geteGPU_1COMPATIBLE(JNIEnv*, jclass) {
    return PxConstraintFlagEnum::eGPU_COMPATIBLE;
}

// PxContactPairHeaderFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairHeaderFlagEnum__1geteREMOVED_1ACTOR_10(JNIEnv*, jclass) {
    return PxContactPairHeaderFlagEnum::eREMOVED_ACTOR_0;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairHeaderFlagEnum__1geteREMOVED_1ACTOR_11(JNIEnv*, jclass) {
    return PxContactPairHeaderFlagEnum::eREMOVED_ACTOR_1;
}

// PxContactPairFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairFlagEnum__1geteREMOVED_1SHAPE_10(JNIEnv*, jclass) {
    return PxContactPairFlagEnum::eREMOVED_SHAPE_0;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairFlagEnum__1geteREMOVED_1SHAPE_11(JNIEnv*, jclass) {
    return PxContactPairFlagEnum::eREMOVED_SHAPE_1;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairFlagEnum__1geteACTOR_1PAIR_1HAS_1FIRST_1TOUCH(JNIEnv*, jclass) {
    return PxContactPairFlagEnum::eACTOR_PAIR_HAS_FIRST_TOUCH;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairFlagEnum__1geteACTOR_1PAIR_1LOST_1TOUCH(JNIEnv*, jclass) {
    return PxContactPairFlagEnum::eACTOR_PAIR_LOST_TOUCH;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairFlagEnum__1geteINTERNAL_1HAS_1IMPULSES(JNIEnv*, jclass) {
    return PxContactPairFlagEnum::eINTERNAL_HAS_IMPULSES;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxContactPairFlagEnum__1geteINTERNAL_1CONTACTS_1ARE_1FLIPPED(JNIEnv*, jclass) {
    return PxContactPairFlagEnum::eINTERNAL_CONTACTS_ARE_FLIPPED;
}

// PxForceModeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxForceModeEnum__1geteFORCE(JNIEnv*, jclass) {
    return PxForceModeEnum::eFORCE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxForceModeEnum__1geteIMPULSE(JNIEnv*, jclass) {
    return PxForceModeEnum::eIMPULSE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxForceModeEnum__1geteVELOCITY_1CHANGE(JNIEnv*, jclass) {
    return PxForceModeEnum::eVELOCITY_CHANGE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxForceModeEnum__1geteACCELERATION(JNIEnv*, jclass) {
    return PxForceModeEnum::eACCELERATION;
}

// PxFrictionTypeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxFrictionTypeEnum__1getePATCH(JNIEnv*, jclass) {
    return PxFrictionTypeEnum::ePATCH;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFrictionTypeEnum__1geteONE_1DIRECTIONAL(JNIEnv*, jclass) {
    return PxFrictionTypeEnum::eONE_DIRECTIONAL;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFrictionTypeEnum__1geteTWO_1DIRECTIONAL(JNIEnv*, jclass) {
    return PxFrictionTypeEnum::eTWO_DIRECTIONAL;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFrictionTypeEnum__1geteFRICTION_1COUNT(JNIEnv*, jclass) {
    return PxFrictionTypeEnum::eFRICTION_COUNT;
}

// PxHitFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1getePOSITION(JNIEnv*, jclass) {
    return PxHitFlagEnum::ePOSITION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1geteNORMAL(JNIEnv*, jclass) {
    return PxHitFlagEnum::eNORMAL;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1geteUV(JNIEnv*, jclass) {
    return PxHitFlagEnum::eUV;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1geteASSUME_1NO_1INITIAL_1OVERLAP(JNIEnv*, jclass) {
    return PxHitFlagEnum::eASSUME_NO_INITIAL_OVERLAP;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1geteMESH_1MULTIPLE(JNIEnv*, jclass) {
    return PxHitFlagEnum::eMESH_MULTIPLE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1geteMESH_1ANY(JNIEnv*, jclass) {
    return PxHitFlagEnum::eMESH_ANY;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1geteMESH_1BOTH_1SIDES(JNIEnv*, jclass) {
    return PxHitFlagEnum::eMESH_BOTH_SIDES;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1getePRECISE_1SWEEP(JNIEnv*, jclass) {
    return PxHitFlagEnum::ePRECISE_SWEEP;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1geteMTD(JNIEnv*, jclass) {
    return PxHitFlagEnum::eMTD;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1geteFACE_1INDEX(JNIEnv*, jclass) {
    return PxHitFlagEnum::eFACE_INDEX;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1geteDEFAULT(JNIEnv*, jclass) {
    return PxHitFlagEnum::eDEFAULT;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxHitFlagEnum__1geteMODIFIABLE_1FLAGS(JNIEnv*, jclass) {
    return PxHitFlagEnum::eMODIFIABLE_FLAGS;
}

// PxPairFilteringModeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFilteringModeEnum__1geteKEEP(JNIEnv*, jclass) {
    return PxPairFilteringModeEnum::eKEEP;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFilteringModeEnum__1geteSUPPRESS(JNIEnv*, jclass) {
    return PxPairFilteringModeEnum::eSUPPRESS;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFilteringModeEnum__1geteKILL(JNIEnv*, jclass) {
    return PxPairFilteringModeEnum::eKILL;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFilteringModeEnum__1geteDEFAULT(JNIEnv*, jclass) {
    return PxPairFilteringModeEnum::eDEFAULT;
}

// PxPairFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteSOLVE_1CONTACT(JNIEnv*, jclass) {
    return PxPairFlagEnum::eSOLVE_CONTACT;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteMODIFY_1CONTACTS(JNIEnv*, jclass) {
    return PxPairFlagEnum::eMODIFY_CONTACTS;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteNOTIFY_1TOUCH_1FOUND(JNIEnv*, jclass) {
    return PxPairFlagEnum::eNOTIFY_TOUCH_FOUND;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteNOTIFY_1TOUCH_1PERSISTS(JNIEnv*, jclass) {
    return PxPairFlagEnum::eNOTIFY_TOUCH_PERSISTS;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteNOTIFY_1TOUCH_1LOST(JNIEnv*, jclass) {
    return PxPairFlagEnum::eNOTIFY_TOUCH_LOST;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteNOTIFY_1TOUCH_1CCD(JNIEnv*, jclass) {
    return PxPairFlagEnum::eNOTIFY_TOUCH_CCD;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteNOTIFY_1THRESHOLD_1FORCE_1FOUND(JNIEnv*, jclass) {
    return PxPairFlagEnum::eNOTIFY_THRESHOLD_FORCE_FOUND;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteNOTIFY_1THRESHOLD_1FORCE_1PERSISTS(JNIEnv*, jclass) {
    return PxPairFlagEnum::eNOTIFY_THRESHOLD_FORCE_PERSISTS;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteNOTIFY_1THRESHOLD_1FORCE_1LOST(JNIEnv*, jclass) {
    return PxPairFlagEnum::eNOTIFY_THRESHOLD_FORCE_LOST;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteNOTIFY_1CONTACT_1POINTS(JNIEnv*, jclass) {
    return PxPairFlagEnum::eNOTIFY_CONTACT_POINTS;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteDETECT_1DISCRETE_1CONTACT(JNIEnv*, jclass) {
    return PxPairFlagEnum::eDETECT_DISCRETE_CONTACT;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteDETECT_1CCD_1CONTACT(JNIEnv*, jclass) {
    return PxPairFlagEnum::eDETECT_CCD_CONTACT;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1getePRE_1SOLVER_1VELOCITY(JNIEnv*, jclass) {
    return PxPairFlagEnum::ePRE_SOLVER_VELOCITY;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1getePOST_1SOLVER_1VELOCITY(JNIEnv*, jclass) {
    return PxPairFlagEnum::ePOST_SOLVER_VELOCITY;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteCONTACT_1EVENT_1POSE(JNIEnv*, jclass) {
    return PxPairFlagEnum::eCONTACT_EVENT_POSE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteNEXT_1FREE(JNIEnv*, jclass) {
    return PxPairFlagEnum::eNEXT_FREE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPairFlagEnum__1geteCONTACT_1DEFAULT(JNIEnv*, jclass) {
    return PxPairFlagEnum::eCONTACT_DEFAULT;
}

// PxPruningStructureTypeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxPruningStructureTypeEnum__1geteNONE(JNIEnv*, jclass) {
    return PxPruningStructureTypeEnum::eNONE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPruningStructureTypeEnum__1geteDYNAMIC_1AABB_1TREE(JNIEnv*, jclass) {
    return PxPruningStructureTypeEnum::eDYNAMIC_AABB_TREE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPruningStructureTypeEnum__1geteSTATIC_1AABB_1TREE(JNIEnv*, jclass) {
    return PxPruningStructureTypeEnum::eSTATIC_AABB_TREE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPruningStructureTypeEnum__1geteLAST(JNIEnv*, jclass) {
    return PxPruningStructureTypeEnum::eLAST;
}

// PxQueryFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxQueryFlagEnum__1geteSTATIC(JNIEnv*, jclass) {
    return PxQueryFlagEnum::eSTATIC;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxQueryFlagEnum__1geteDYNAMIC(JNIEnv*, jclass) {
    return PxQueryFlagEnum::eDYNAMIC;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxQueryFlagEnum__1getePREFILTER(JNIEnv*, jclass) {
    return PxQueryFlagEnum::ePREFILTER;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxQueryFlagEnum__1getePOSTFILTER(JNIEnv*, jclass) {
    return PxQueryFlagEnum::ePOSTFILTER;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxQueryFlagEnum__1geteANY_1HIT(JNIEnv*, jclass) {
    return PxQueryFlagEnum::eANY_HIT;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxQueryFlagEnum__1geteNO_1BLOCK(JNIEnv*, jclass) {
    return PxQueryFlagEnum::eNO_BLOCK;
}

// PxRigidBodyFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidBodyFlagEnum__1geteKINEMATIC(JNIEnv*, jclass) {
    return PxRigidBodyFlagEnum::eKINEMATIC;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidBodyFlagEnum__1geteUSE_1KINEMATIC_1TARGET_1FOR_1SCENE_1QUERIES(JNIEnv*, jclass) {
    return PxRigidBodyFlagEnum::eUSE_KINEMATIC_TARGET_FOR_SCENE_QUERIES;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidBodyFlagEnum__1geteENABLE_1CCD(JNIEnv*, jclass) {
    return PxRigidBodyFlagEnum::eENABLE_CCD;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidBodyFlagEnum__1geteENABLE_1CCD_1FRICTION(JNIEnv*, jclass) {
    return PxRigidBodyFlagEnum::eENABLE_CCD_FRICTION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidBodyFlagEnum__1geteENABLE_1POSE_1INTEGRATION_1PREVIEW(JNIEnv*, jclass) {
    return PxRigidBodyFlagEnum::eENABLE_POSE_INTEGRATION_PREVIEW;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidBodyFlagEnum__1geteENABLE_1SPECULATIVE_1CCD(JNIEnv*, jclass) {
    return PxRigidBodyFlagEnum::eENABLE_SPECULATIVE_CCD;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidBodyFlagEnum__1geteENABLE_1CCD_1MAX_1CONTACT_1IMPULSE(JNIEnv*, jclass) {
    return PxRigidBodyFlagEnum::eENABLE_CCD_MAX_CONTACT_IMPULSE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidBodyFlagEnum__1geteRETAIN_1ACCELERATIONS(JNIEnv*, jclass) {
    return PxRigidBodyFlagEnum::eRETAIN_ACCELERATIONS;
}

// PxRigidDynamicLockFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidDynamicLockFlagEnum__1geteLOCK_1LINEAR_1X(JNIEnv*, jclass) {
    return PxRigidDynamicLockFlagEnum::eLOCK_LINEAR_X;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidDynamicLockFlagEnum__1geteLOCK_1LINEAR_1Y(JNIEnv*, jclass) {
    return PxRigidDynamicLockFlagEnum::eLOCK_LINEAR_Y;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidDynamicLockFlagEnum__1geteLOCK_1LINEAR_1Z(JNIEnv*, jclass) {
    return PxRigidDynamicLockFlagEnum::eLOCK_LINEAR_Z;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidDynamicLockFlagEnum__1geteLOCK_1ANGULAR_1X(JNIEnv*, jclass) {
    return PxRigidDynamicLockFlagEnum::eLOCK_ANGULAR_X;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidDynamicLockFlagEnum__1geteLOCK_1ANGULAR_1Y(JNIEnv*, jclass) {
    return PxRigidDynamicLockFlagEnum::eLOCK_ANGULAR_Y;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidDynamicLockFlagEnum__1geteLOCK_1ANGULAR_1Z(JNIEnv*, jclass) {
    return PxRigidDynamicLockFlagEnum::eLOCK_ANGULAR_Z;
}

// PxSceneFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteENABLE_1ACTIVE_1ACTORS(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eENABLE_ACTIVE_ACTORS;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteENABLE_1CCD(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eENABLE_CCD;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteDISABLE_1CCD_1RESWEEP(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eDISABLE_CCD_RESWEEP;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteADAPTIVE_1FORCE(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eADAPTIVE_FORCE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteENABLE_1PCM(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eENABLE_PCM;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteDISABLE_1CONTACT_1REPORT_1BUFFER_1RESIZE(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eDISABLE_CONTACT_REPORT_BUFFER_RESIZE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteDISABLE_1CONTACT_1CACHE(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eDISABLE_CONTACT_CACHE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteREQUIRE_1RW_1LOCK(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eREQUIRE_RW_LOCK;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteENABLE_1STABILIZATION(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eENABLE_STABILIZATION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteENABLE_1AVERAGE_1POINT(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eENABLE_AVERAGE_POINT;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteEXCLUDE_1KINEMATICS_1FROM_1ACTIVE_1ACTORS(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eEXCLUDE_KINEMATICS_FROM_ACTIVE_ACTORS;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteENABLE_1GPU_1DYNAMICS(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eENABLE_GPU_DYNAMICS;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteENABLE_1ENHANCED_1DETERMINISM(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eENABLE_ENHANCED_DETERMINISM;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteENABLE_1FRICTION_1EVERY_1ITERATION(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eENABLE_FRICTION_EVERY_ITERATION;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneFlagEnum__1geteMUTABLE_1FLAGS(JNIEnv*, jclass) {
    return PxSceneFlagEnum::eMUTABLE_FLAGS;
}

// PxSceneQueryUpdateModeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneQueryUpdateModeEnum__1geteBUILD_1ENABLED_1COMMIT_1ENABLED(JNIEnv*, jclass) {
    return PxSceneQueryUpdateModeEnum::eBUILD_ENABLED_COMMIT_ENABLED;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneQueryUpdateModeEnum__1geteBUILD_1ENABLED_1COMMIT_1DISABLED(JNIEnv*, jclass) {
    return PxSceneQueryUpdateModeEnum::eBUILD_ENABLED_COMMIT_DISABLED;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSceneQueryUpdateModeEnum__1geteBUILD_1DISABLED_1COMMIT_1DISABLED(JNIEnv*, jclass) {
    return PxSceneQueryUpdateModeEnum::eBUILD_DISABLED_COMMIT_DISABLED;
}

// PxShapeFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxShapeFlagEnum__1geteSIMULATION_1SHAPE(JNIEnv*, jclass) {
    return PxShapeFlagEnum::eSIMULATION_SHAPE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxShapeFlagEnum__1geteSCENE_1QUERY_1SHAPE(JNIEnv*, jclass) {
    return PxShapeFlagEnum::eSCENE_QUERY_SHAPE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxShapeFlagEnum__1geteTRIGGER_1SHAPE(JNIEnv*, jclass) {
    return PxShapeFlagEnum::eTRIGGER_SHAPE;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxShapeFlagEnum__1geteVISUALIZATION(JNIEnv*, jclass) {
    return PxShapeFlagEnum::eVISUALIZATION;
}

// PxSolverTypeEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxSolverTypeEnum__1getePGS(JNIEnv*, jclass) {
    return PxSolverTypeEnum::ePGS;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSolverTypeEnum__1geteTGS(JNIEnv*, jclass) {
    return PxSolverTypeEnum::eTGS;
}

// PxTriggerPairFlagEnum
JNIEXPORT jint JNICALL Java_physx_physics_PxTriggerPairFlagEnum__1geteREMOVED_1SHAPE_1TRIGGER(JNIEnv*, jclass) {
    return PxTriggerPairFlagEnum::eREMOVED_SHAPE_TRIGGER;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxTriggerPairFlagEnum__1geteREMOVED_1SHAPE_1OTHER(JNIEnv*, jclass) {
    return PxTriggerPairFlagEnum::eREMOVED_SHAPE_OTHER;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxTriggerPairFlagEnum__1geteNEXT_1FREE(JNIEnv*, jclass) {
    return PxTriggerPairFlagEnum::eNEXT_FREE;
}

// PxActorPtr
JNIEXPORT void JNICALL Java_physx_support_PxActorPtr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxActorPtr*) _address;
}

// PxMaterialPtr
JNIEXPORT void JNICALL Java_physx_support_PxMaterialPtr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxMaterialPtr*) _address;
}

// PxMaterialConstPtr
JNIEXPORT void JNICALL Java_physx_support_PxMaterialConstPtr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxMaterialConstPtr*) _address;
}

// PxVehicleWheelsPtr
JNIEXPORT void JNICALL Java_physx_support_PxVehicleWheelsPtr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxVehicleWheelsPtr*) _address;
}

// PxRealPtr
JNIEXPORT void JNICALL Java_physx_support_PxRealPtr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxRealPtr*) _address;
}

// PxU8Ptr
JNIEXPORT void JNICALL Java_physx_support_PxU8Ptr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxU8Ptr*) _address;
}

// PxU8ConstPtr
JNIEXPORT void JNICALL Java_physx_support_PxU8ConstPtr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxU8ConstPtr*) _address;
}

// PxU16Ptr
JNIEXPORT void JNICALL Java_physx_support_PxU16Ptr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxU16Ptr*) _address;
}

// PxU16ConstPtr
JNIEXPORT void JNICALL Java_physx_support_PxU16ConstPtr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxU16ConstPtr*) _address;
}

// PxU32Ptr
JNIEXPORT void JNICALL Java_physx_support_PxU32Ptr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxU32Ptr*) _address;
}

// PxU32ConstPtr
JNIEXPORT void JNICALL Java_physx_support_PxU32ConstPtr__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxU32ConstPtr*) _address;
}

// TypeHelpers
JNIEXPORT jbyte JNICALL Java_physx_support_TypeHelpers__1getU8At(JNIEnv*, jclass, jlong base, jint index) {
    return (jbyte) TypeHelpers::getU8At(*((PxU8ConstPtr*) base), index);
}
JNIEXPORT jshort JNICALL Java_physx_support_TypeHelpers__1getU16At(JNIEnv*, jclass, jlong base, jint index) {
    return (jshort) TypeHelpers::getU16At(*((PxU16ConstPtr*) base), index);
}
JNIEXPORT jint JNICALL Java_physx_support_TypeHelpers__1getU32At(JNIEnv*, jclass, jlong base, jint index) {
    return (jint) TypeHelpers::getU32At(*((PxU32ConstPtr*) base), index);
}
JNIEXPORT jfloat JNICALL Java_physx_support_TypeHelpers__1getRealAt(JNIEnv*, jclass, jlong base, jint index) {
    return (jfloat) TypeHelpers::getRealAt(*((PxRealPtr*) base), index);
}
JNIEXPORT jlong JNICALL Java_physx_support_TypeHelpers__1getContactPairAt(JNIEnv*, jclass, jlong base, jint index) {
    return (jlong) TypeHelpers::getContactPairAt((physx::PxContactPair*) base, index);
}
JNIEXPORT jlong JNICALL Java_physx_support_TypeHelpers__1getTriggerPairAt(JNIEnv*, jclass, jlong base, jint index) {
    return (jlong) TypeHelpers::getTriggerPairAt((physx::PxTriggerPair*) base, index);
}
JNIEXPORT jlong JNICALL Java_physx_support_TypeHelpers__1getVec3At(JNIEnv*, jclass, jlong base, jint index) {
    return (jlong) TypeHelpers::getVec3At((physx::PxVec3*) base, index);
}
JNIEXPORT jlong JNICALL Java_physx_support_TypeHelpers__1voidToU8ConstPtr(JNIEnv*, jclass, jlong voidPtr) {
    static thread_local PxU8ConstPtr _cache;
    _cache = TypeHelpers::voidToU8ConstPtr((void*) voidPtr);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_support_TypeHelpers__1voidToU16ConstPtr(JNIEnv*, jclass, jlong voidPtr) {
    static thread_local PxU16ConstPtr _cache;
    _cache = TypeHelpers::voidToU16ConstPtr((void*) voidPtr);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_support_TypeHelpers__1voidToU32ConstPtr(JNIEnv*, jclass, jlong voidPtr) {
    static thread_local PxU32ConstPtr _cache;
    _cache = TypeHelpers::voidToU32ConstPtr((void*) voidPtr);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_support_TypeHelpers__1voidToRealPtr(JNIEnv*, jclass, jlong voidPtr) {
    static thread_local PxRealPtr _cache;
    _cache = TypeHelpers::voidToRealPtr((void*) voidPtr);
    return (jlong) &_cache;
}
JNIEXPORT jlong JNICALL Java_physx_support_TypeHelpers__1voidToAny(JNIEnv*, jclass, jlong voidPtr) {
    return (jlong) TypeHelpers::voidToAny((void*) voidPtr);
}
JNIEXPORT void JNICALL Java_physx_support_TypeHelpers__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (TypeHelpers*) _address;
}

// Vector_PxMaterialConst
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxMaterialConst__1Vector_1PxMaterialConst__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxMaterialConst();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxMaterialConst__1Vector_1PxMaterialConst__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxMaterialConst(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxMaterialConst__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxMaterialConst* self = (Vector_PxMaterialConst*) _address;
    return (jlong) self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxMaterialConst__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxMaterialConst* self = (Vector_PxMaterialConst*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxMaterialConst__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxMaterialConst* self = (Vector_PxMaterialConst*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxMaterialConst__1push_1back(JNIEnv*, jclass, jlong _address, jlong value) {
    Vector_PxMaterialConst* self = (Vector_PxMaterialConst*) _address;
    self->push_back((physx::PxMaterial*) value);
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxMaterialConst__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxMaterialConst*) _address;
}

// Vector_PxHeightFieldSample
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxHeightFieldSample__1Vector_1PxHeightFieldSample__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxHeightFieldSample();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxHeightFieldSample__1Vector_1PxHeightFieldSample__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxHeightFieldSample(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxHeightFieldSample__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxHeightFieldSample* self = (Vector_PxHeightFieldSample*) _address;
    return (jlong) &self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxHeightFieldSample__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxHeightFieldSample* self = (Vector_PxHeightFieldSample*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxHeightFieldSample__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxHeightFieldSample* self = (Vector_PxHeightFieldSample*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxHeightFieldSample__1push_1back(JNIEnv*, jclass, jlong _address, jlong value) {
    Vector_PxHeightFieldSample* self = (Vector_PxHeightFieldSample*) _address;
    self->push_back(*((physx::PxHeightFieldSample*) value));
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxHeightFieldSample__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxHeightFieldSample*) _address;
}

// Vector_PxReal
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxReal__1Vector_1PxReal__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxReal();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxReal__1Vector_1PxReal__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxReal(size);
}
JNIEXPORT jfloat JNICALL Java_physx_support_Vector_1PxReal__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxReal* self = (Vector_PxReal*) _address;
    return (jfloat) self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxReal__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxReal* self = (Vector_PxReal*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxReal__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxReal* self = (Vector_PxReal*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxReal__1push_1back(JNIEnv*, jclass, jlong _address, jfloat value) {
    Vector_PxReal* self = (Vector_PxReal*) _address;
    self->push_back(value);
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxReal__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxReal*) _address;
}

// Vector_PxU16
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxU16__1Vector_1PxU16__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxU16();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxU16__1Vector_1PxU16__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxU16(size);
}
JNIEXPORT jshort JNICALL Java_physx_support_Vector_1PxU16__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxU16* self = (Vector_PxU16*) _address;
    return (jshort) self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxU16__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxU16* self = (Vector_PxU16*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxU16__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxU16* self = (Vector_PxU16*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxU16__1push_1back(JNIEnv*, jclass, jlong _address, jshort value) {
    Vector_PxU16* self = (Vector_PxU16*) _address;
    self->push_back(value);
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxU16__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxU16*) _address;
}

// Vector_PxU32
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxU32__1Vector_1PxU32__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxU32();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxU32__1Vector_1PxU32__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxU32(size);
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxU32__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxU32* self = (Vector_PxU32*) _address;
    return (jint) self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxU32__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxU32* self = (Vector_PxU32*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxU32__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxU32* self = (Vector_PxU32*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxU32__1push_1back(JNIEnv*, jclass, jlong _address, jint value) {
    Vector_PxU32* self = (Vector_PxU32*) _address;
    self->push_back(value);
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxU32__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxU32*) _address;
}

// Vector_PxVec3
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVec3__1Vector_1PxVec3__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxVec3();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVec3__1Vector_1PxVec3__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxVec3(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVec3__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxVec3* self = (Vector_PxVec3*) _address;
    return (jlong) &self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVec3__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxVec3* self = (Vector_PxVec3*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxVec3__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxVec3* self = (Vector_PxVec3*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxVec3__1push_1back(JNIEnv*, jclass, jlong _address, jlong value) {
    Vector_PxVec3* self = (Vector_PxVec3*) _address;
    self->push_back(*((physx::PxVec3*) value));
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxVec3__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxVec3*) _address;
}

// Vector_PxRaycastQueryResult
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxRaycastQueryResult__1Vector_1PxRaycastQueryResult__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxRaycastQueryResult();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxRaycastQueryResult__1Vector_1PxRaycastQueryResult__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxRaycastQueryResult(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxRaycastQueryResult__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxRaycastQueryResult* self = (Vector_PxRaycastQueryResult*) _address;
    return (jlong) &self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxRaycastQueryResult__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxRaycastQueryResult* self = (Vector_PxRaycastQueryResult*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxRaycastQueryResult__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxRaycastQueryResult* self = (Vector_PxRaycastQueryResult*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxRaycastQueryResult__1push_1back(JNIEnv*, jclass, jlong _address, jlong value) {
    Vector_PxRaycastQueryResult* self = (Vector_PxRaycastQueryResult*) _address;
    self->push_back(*((physx::PxRaycastQueryResult*) value));
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxRaycastQueryResult__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxRaycastQueryResult*) _address;
}

// Vector_PxSweepQueryResult
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxSweepQueryResult__1Vector_1PxSweepQueryResult__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxSweepQueryResult();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxSweepQueryResult__1Vector_1PxSweepQueryResult__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxSweepQueryResult(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxSweepQueryResult__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxSweepQueryResult* self = (Vector_PxSweepQueryResult*) _address;
    return (jlong) &self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxSweepQueryResult__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxSweepQueryResult* self = (Vector_PxSweepQueryResult*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxSweepQueryResult__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxSweepQueryResult* self = (Vector_PxSweepQueryResult*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxSweepQueryResult__1push_1back(JNIEnv*, jclass, jlong _address, jlong value) {
    Vector_PxSweepQueryResult* self = (Vector_PxSweepQueryResult*) _address;
    self->push_back(*((physx::PxSweepQueryResult*) value));
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxSweepQueryResult__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxSweepQueryResult*) _address;
}

// Vector_PxRaycastHit
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxRaycastHit__1Vector_1PxRaycastHit__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxRaycastHit();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxRaycastHit__1Vector_1PxRaycastHit__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxRaycastHit(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxRaycastHit__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxRaycastHit* self = (Vector_PxRaycastHit*) _address;
    return (jlong) &self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxRaycastHit__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxRaycastHit* self = (Vector_PxRaycastHit*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxRaycastHit__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxRaycastHit* self = (Vector_PxRaycastHit*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxRaycastHit__1push_1back(JNIEnv*, jclass, jlong _address, jlong value) {
    Vector_PxRaycastHit* self = (Vector_PxRaycastHit*) _address;
    self->push_back(*((physx::PxRaycastHit*) value));
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxRaycastHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxRaycastHit*) _address;
}

// Vector_PxSweepHit
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxSweepHit__1Vector_1PxSweepHit__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxSweepHit();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxSweepHit__1Vector_1PxSweepHit__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxSweepHit(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxSweepHit__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxSweepHit* self = (Vector_PxSweepHit*) _address;
    return (jlong) &self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxSweepHit__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxSweepHit* self = (Vector_PxSweepHit*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxSweepHit__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxSweepHit* self = (Vector_PxSweepHit*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxSweepHit__1push_1back(JNIEnv*, jclass, jlong _address, jlong value) {
    Vector_PxSweepHit* self = (Vector_PxSweepHit*) _address;
    self->push_back(*((physx::PxSweepHit*) value));
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxSweepHit__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxSweepHit*) _address;
}

// Vector_PxVehicleDrivableSurfaceType
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVehicleDrivableSurfaceType__1Vector_1PxVehicleDrivableSurfaceType__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxVehicleDrivableSurfaceType();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVehicleDrivableSurfaceType__1Vector_1PxVehicleDrivableSurfaceType__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxVehicleDrivableSurfaceType(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVehicleDrivableSurfaceType__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxVehicleDrivableSurfaceType* self = (Vector_PxVehicleDrivableSurfaceType*) _address;
    return (jlong) &self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVehicleDrivableSurfaceType__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxVehicleDrivableSurfaceType* self = (Vector_PxVehicleDrivableSurfaceType*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxVehicleDrivableSurfaceType__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxVehicleDrivableSurfaceType* self = (Vector_PxVehicleDrivableSurfaceType*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxVehicleDrivableSurfaceType__1push_1back(JNIEnv*, jclass, jlong _address, jlong value) {
    Vector_PxVehicleDrivableSurfaceType* self = (Vector_PxVehicleDrivableSurfaceType*) _address;
    self->push_back(*((physx::PxVehicleDrivableSurfaceType*) value));
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxVehicleDrivableSurfaceType__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxVehicleDrivableSurfaceType*) _address;
}

// Vector_PxWheelQueryResult
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxWheelQueryResult__1Vector_1PxWheelQueryResult__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxWheelQueryResult();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxWheelQueryResult__1Vector_1PxWheelQueryResult__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxWheelQueryResult(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxWheelQueryResult__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxWheelQueryResult* self = (Vector_PxWheelQueryResult*) _address;
    return (jlong) &self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxWheelQueryResult__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxWheelQueryResult* self = (Vector_PxWheelQueryResult*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxWheelQueryResult__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxWheelQueryResult* self = (Vector_PxWheelQueryResult*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxWheelQueryResult__1push_1back(JNIEnv*, jclass, jlong _address, jlong value) {
    Vector_PxWheelQueryResult* self = (Vector_PxWheelQueryResult*) _address;
    self->push_back(*((physx::PxWheelQueryResult*) value));
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxWheelQueryResult__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxWheelQueryResult*) _address;
}

// Vector_PxVehicleWheels
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVehicleWheels__1Vector_1PxVehicleWheels__(JNIEnv*, jclass) {
    return (jlong) new Vector_PxVehicleWheels();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVehicleWheels__1Vector_1PxVehicleWheels__I(JNIEnv*, jclass, jint size) {
    return (jlong) new Vector_PxVehicleWheels(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVehicleWheels__1at(JNIEnv*, jclass, jlong _address, jint index) {
    Vector_PxVehicleWheels* self = (Vector_PxVehicleWheels*) _address;
    return (jlong) self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVehicleWheels__1data(JNIEnv*, jclass, jlong _address) {
    Vector_PxVehicleWheels* self = (Vector_PxVehicleWheels*) _address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxVehicleWheels__1size(JNIEnv*, jclass, jlong _address) {
    Vector_PxVehicleWheels* self = (Vector_PxVehicleWheels*) _address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxVehicleWheels__1push_1back(JNIEnv*, jclass, jlong _address, jlong value) {
    Vector_PxVehicleWheels* self = (Vector_PxVehicleWheels*) _address;
    self->push_back((physx::PxVehicleWheels*) value);
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxVehicleWheels__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (Vector_PxVehicleWheels*) _address;
}

// PxVehicleTopLevelFunctions
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxVehicleTopLevelFunctions__1InitVehicleSDK(JNIEnv*, jclass, jlong physics) {
    return (jboolean) PxVehicleTopLevelFunctions::InitVehicleSDK(*((physx::PxPhysics*) physics));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTopLevelFunctions__1PxVehicleComputeSprungMasses(JNIEnv*, jclass, jint nbSprungMasses, jlong sprungMassCoordinates, jlong centreOfMass, jfloat totalMass, jint gravityDirection, jlong sprungMasses) {
    PxVehicleTopLevelFunctions::PxVehicleComputeSprungMasses(nbSprungMasses, (physx::PxVec3*) sprungMassCoordinates, *((physx::PxVec3*) centreOfMass), totalMass, gravityDirection, *((PxRealPtr*) sprungMasses));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTopLevelFunctions__1PxVehicleSuspensionRaycasts(JNIEnv*, jclass, jlong batchQuery, jlong vehicles, jint nbSceneQueryResults, jlong sceneQueryResults) {
    PxVehicleTopLevelFunctions::PxVehicleSuspensionRaycasts((physx::PxBatchQuery*) batchQuery, *((Vector_PxVehicleWheels*) vehicles), nbSceneQueryResults, (physx::PxRaycastQueryResult*) sceneQueryResults);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTopLevelFunctions__1PxVehicleUpdates(JNIEnv*, jclass, jfloat timestep, jlong gravity, jlong vehicleDrivableSurfaceToTireFrictionPairs, jlong vehicles, jlong vehicleWheelQueryResults) {
    PxVehicleTopLevelFunctions::PxVehicleUpdates(timestep, *((physx::PxVec3*) gravity), *((physx::PxVehicleDrivableSurfaceToTireFrictionPairs*) vehicleDrivableSurfaceToTireFrictionPairs), *((Vector_PxVehicleWheels*) vehicles), (physx::PxVehicleWheelQueryResult*) vehicleWheelQueryResults);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTopLevelFunctions__1VehicleSetBasisVectors(JNIEnv*, jclass, jlong up, jlong forward) {
    PxVehicleTopLevelFunctions::VehicleSetBasisVectors(*((physx::PxVec3*) up), *((physx::PxVec3*) forward));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTopLevelFunctions__1VehicleSetUpdateMode(JNIEnv*, jclass, jint vehicleUpdateMode) {
    PxVehicleTopLevelFunctions::VehicleSetUpdateMode((PxVehicleUpdateModeEnum) vehicleUpdateMode);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleTopLevelFunctions__1PxVehicleTireData_1getFrictionVsSlipGraph(JNIEnv*, jclass, jlong tireData, jint m, jint n) {
    return (jfloat) PxVehicleTopLevelFunctions::PxVehicleTireData_getFrictionVsSlipGraph((physx::PxVehicleTireData*) tireData, m, n);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTopLevelFunctions__1PxVehicleTireData_1setFrictionVsSlipGraph(JNIEnv*, jclass, jlong tireData, jint m, jint n, jfloat value) {
    PxVehicleTopLevelFunctions::PxVehicleTireData_setFrictionVsSlipGraph((physx::PxVehicleTireData*) tireData, m, n, value);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTopLevelFunctions__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxVehicleTopLevelFunctions*) _address;
}

// PxVehicleAckermannGeometryData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleAckermannGeometryData__1PxVehicleAckermannGeometryData(JNIEnv*, jclass) {
    return (jlong) new physx::PxVehicleAckermannGeometryData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAckermannGeometryData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVehicleAckermannGeometryData*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleAckermannGeometryData__1getMAccuracy(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleAckermannGeometryData* _self = (physx::PxVehicleAckermannGeometryData*) _address;
    return (jfloat) _self->mAccuracy;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAckermannGeometryData__1setMAccuracy(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleAckermannGeometryData* _self = (physx::PxVehicleAckermannGeometryData*) _address;
    _self->mAccuracy = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleAckermannGeometryData__1getMFrontWidth(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleAckermannGeometryData* _self = (physx::PxVehicleAckermannGeometryData*) _address;
    return (jfloat) _self->mFrontWidth;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAckermannGeometryData__1setMFrontWidth(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleAckermannGeometryData* _self = (physx::PxVehicleAckermannGeometryData*) _address;
    _self->mFrontWidth = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleAckermannGeometryData__1getMRearWidth(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleAckermannGeometryData* _self = (physx::PxVehicleAckermannGeometryData*) _address;
    return (jfloat) _self->mRearWidth;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAckermannGeometryData__1setMRearWidth(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleAckermannGeometryData* _self = (physx::PxVehicleAckermannGeometryData*) _address;
    _self->mRearWidth = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleAckermannGeometryData__1getMAxleSeparation(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleAckermannGeometryData* _self = (physx::PxVehicleAckermannGeometryData*) _address;
    return (jfloat) _self->mAxleSeparation;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAckermannGeometryData__1setMAxleSeparation(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleAckermannGeometryData* _self = (physx::PxVehicleAckermannGeometryData*) _address;
    _self->mAxleSeparation = value;
}

// PxVehicleAntiRollBarData
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleAntiRollBarData__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxVehicleAntiRollBarData);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleAntiRollBarData__1_1placement_1new_1PxVehicleAntiRollBarData(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxVehicleAntiRollBarData();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleAntiRollBarData__1PxVehicleAntiRollBarData(JNIEnv*, jclass) {
    return (jlong) new physx::PxVehicleAntiRollBarData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAntiRollBarData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVehicleAntiRollBarData*) _address;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleAntiRollBarData__1getMWheel0(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleAntiRollBarData* _self = (physx::PxVehicleAntiRollBarData*) _address;
    return (jint) _self->mWheel0;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAntiRollBarData__1setMWheel0(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxVehicleAntiRollBarData* _self = (physx::PxVehicleAntiRollBarData*) _address;
    _self->mWheel0 = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleAntiRollBarData__1getMWheel1(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleAntiRollBarData* _self = (physx::PxVehicleAntiRollBarData*) _address;
    return (jint) _self->mWheel1;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAntiRollBarData__1setMWheel1(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxVehicleAntiRollBarData* _self = (physx::PxVehicleAntiRollBarData*) _address;
    _self->mWheel1 = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleAntiRollBarData__1getMStiffness(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleAntiRollBarData* _self = (physx::PxVehicleAntiRollBarData*) _address;
    return (jfloat) _self->mStiffness;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAntiRollBarData__1setMStiffness(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleAntiRollBarData* _self = (physx::PxVehicleAntiRollBarData*) _address;
    _self->mStiffness = value;
}

// PxVehicleAutoBoxData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1PxVehicleAutoBoxData(JNIEnv*, jclass) {
    return (jlong) new physx::PxVehicleAutoBoxData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1setLatency(JNIEnv*, jclass, jlong _address, jfloat latency) {
    physx::PxVehicleAutoBoxData* self = (physx::PxVehicleAutoBoxData*) _address;
    self->setLatency(latency);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1getLatency(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleAutoBoxData* self = (physx::PxVehicleAutoBoxData*) _address;
    return (jfloat) self->getLatency();
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1getUpRatios(JNIEnv*, jclass, jlong _address, jint a) {
    physx::PxVehicleAutoBoxData* self = (physx::PxVehicleAutoBoxData*) _address;
    return (jfloat) self->getUpRatios((PxVehicleGearEnum) a);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1setUpRatios(JNIEnv*, jclass, jlong _address, jint a, jfloat ratio) {
    physx::PxVehicleAutoBoxData* self = (physx::PxVehicleAutoBoxData*) _address;
    self->setUpRatios((PxVehicleGearEnum) a, ratio);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1getDownRatios(JNIEnv*, jclass, jlong _address, jint a) {
    physx::PxVehicleAutoBoxData* self = (physx::PxVehicleAutoBoxData*) _address;
    return (jfloat) self->getDownRatios((PxVehicleGearEnum) a);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1setDownRatios(JNIEnv*, jclass, jlong _address, jint a, jfloat ratio) {
    physx::PxVehicleAutoBoxData* self = (physx::PxVehicleAutoBoxData*) _address;
    self->setDownRatios((PxVehicleGearEnum) a, ratio);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVehicleAutoBoxData*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1getMUpRatios(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::PxVehicleAutoBoxData* _self = (physx::PxVehicleAutoBoxData*) _address;
    return (jfloat) _self->mUpRatios[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1setMUpRatios(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::PxVehicleAutoBoxData* _self = (physx::PxVehicleAutoBoxData*) _address;
    _self->mUpRatios[_index] = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1getMDownRatios(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::PxVehicleAutoBoxData* _self = (physx::PxVehicleAutoBoxData*) _address;
    return (jfloat) _self->mDownRatios[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1setMDownRatios(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::PxVehicleAutoBoxData* _self = (physx::PxVehicleAutoBoxData*) _address;
    _self->mDownRatios[_index] = value;
}

// PxVehicleChassisData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleChassisData__1PxVehicleChassisData(JNIEnv*, jclass) {
    return (jlong) new physx::PxVehicleChassisData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleChassisData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVehicleChassisData*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleChassisData__1getMMOI(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleChassisData* _self = (physx::PxVehicleChassisData*) _address;
    return (jlong) &_self->mMOI;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleChassisData__1setMMOI(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxVehicleChassisData* _self = (physx::PxVehicleChassisData*) _address;
    _self->mMOI = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleChassisData__1getMMass(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleChassisData* _self = (physx::PxVehicleChassisData*) _address;
    return (jfloat) _self->mMass;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleChassisData__1setMMass(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleChassisData* _self = (physx::PxVehicleChassisData*) _address;
    _self->mMass = value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleChassisData__1getMCMOffset(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleChassisData* _self = (physx::PxVehicleChassisData*) _address;
    return (jlong) &_self->mCMOffset;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleChassisData__1setMCMOffset(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxVehicleChassisData* _self = (physx::PxVehicleChassisData*) _address;
    _self->mCMOffset = *((physx::PxVec3*) value);
}

// PxVehicleClutchData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleClutchData__1PxVehicleClutchData(JNIEnv*, jclass) {
    return (jlong) new physx::PxVehicleClutchData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleClutchData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVehicleClutchData*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleClutchData__1getMStrength(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleClutchData* _self = (physx::PxVehicleClutchData*) _address;
    return (jfloat) _self->mStrength;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleClutchData__1setMStrength(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleClutchData* _self = (physx::PxVehicleClutchData*) _address;
    _self->mStrength = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleClutchData__1getMAccuracyMode(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleClutchData* _self = (physx::PxVehicleClutchData*) _address;
    return (jint) _self->mAccuracyMode;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleClutchData__1setMAccuracyMode(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxVehicleClutchData* _self = (physx::PxVehicleClutchData*) _address;
    _self->mAccuracyMode = (PxVehicleClutchAccuracyModeEnum) value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleClutchData__1getMEstimateIterations(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleClutchData* _self = (physx::PxVehicleClutchData*) _address;
    return (jint) _self->mEstimateIterations;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleClutchData__1setMEstimateIterations(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxVehicleClutchData* _self = (physx::PxVehicleClutchData*) _address;
    _self->mEstimateIterations = value;
}

// PxVehicleDifferential4WData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1PxVehicleDifferential4WData(JNIEnv*, jclass) {
    return (jlong) new physx::PxVehicleDifferential4WData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVehicleDifferential4WData*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1getMFrontRearSplit(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDifferential4WData* _self = (physx::PxVehicleDifferential4WData*) _address;
    return (jfloat) _self->mFrontRearSplit;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1setMFrontRearSplit(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleDifferential4WData* _self = (physx::PxVehicleDifferential4WData*) _address;
    _self->mFrontRearSplit = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1getMFrontLeftRightSplit(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDifferential4WData* _self = (physx::PxVehicleDifferential4WData*) _address;
    return (jfloat) _self->mFrontLeftRightSplit;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1setMFrontLeftRightSplit(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleDifferential4WData* _self = (physx::PxVehicleDifferential4WData*) _address;
    _self->mFrontLeftRightSplit = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1getMRearLeftRightSplit(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDifferential4WData* _self = (physx::PxVehicleDifferential4WData*) _address;
    return (jfloat) _self->mRearLeftRightSplit;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1setMRearLeftRightSplit(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleDifferential4WData* _self = (physx::PxVehicleDifferential4WData*) _address;
    _self->mRearLeftRightSplit = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1getMCentreBias(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDifferential4WData* _self = (physx::PxVehicleDifferential4WData*) _address;
    return (jfloat) _self->mCentreBias;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1setMCentreBias(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleDifferential4WData* _self = (physx::PxVehicleDifferential4WData*) _address;
    _self->mCentreBias = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1getMFrontBias(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDifferential4WData* _self = (physx::PxVehicleDifferential4WData*) _address;
    return (jfloat) _self->mFrontBias;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1setMFrontBias(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleDifferential4WData* _self = (physx::PxVehicleDifferential4WData*) _address;
    _self->mFrontBias = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1getMRearBias(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDifferential4WData* _self = (physx::PxVehicleDifferential4WData*) _address;
    return (jfloat) _self->mRearBias;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1setMRearBias(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleDifferential4WData* _self = (physx::PxVehicleDifferential4WData*) _address;
    _self->mRearBias = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1getMType(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDifferential4WData* _self = (physx::PxVehicleDifferential4WData*) _address;
    return (jint) _self->mType;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1setMType(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxVehicleDifferential4WData* _self = (physx::PxVehicleDifferential4WData*) _address;
    _self->mType = (PxVehicleDifferential4WDataEnum) value;
}

// PxVehicleDrivableSurfaceToTireFrictionPairs
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceToTireFrictionPairs__1allocate(JNIEnv*, jclass, jint maxNbTireTypes, jint maxNbSurfaceTypes) {
    return (jlong) physx::PxVehicleDrivableSurfaceToTireFrictionPairs::allocate(maxNbTireTypes, maxNbSurfaceTypes);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceToTireFrictionPairs__1setup(JNIEnv*, jclass, jlong _address, jint nbTireTypes, jint nbSurfaceTypes, jlong drivableSurfaceMaterials, jlong drivableSurfaceTypes) {
    physx::PxVehicleDrivableSurfaceToTireFrictionPairs* self = (physx::PxVehicleDrivableSurfaceToTireFrictionPairs*) _address;
    self->setup(nbTireTypes, nbSurfaceTypes, (PxMaterialConstPtr*) drivableSurfaceMaterials, (physx::PxVehicleDrivableSurfaceType*) drivableSurfaceTypes);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceToTireFrictionPairs__1release(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDrivableSurfaceToTireFrictionPairs* self = (physx::PxVehicleDrivableSurfaceToTireFrictionPairs*) _address;
    self->release();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceToTireFrictionPairs__1setTypePairFriction(JNIEnv*, jclass, jlong _address, jint surfaceType, jint tireType, jfloat value) {
    physx::PxVehicleDrivableSurfaceToTireFrictionPairs* self = (physx::PxVehicleDrivableSurfaceToTireFrictionPairs*) _address;
    self->setTypePairFriction(surfaceType, tireType, value);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceToTireFrictionPairs__1getTypePairFriction(JNIEnv*, jclass, jlong _address, jint surfaceType, jint tireType) {
    physx::PxVehicleDrivableSurfaceToTireFrictionPairs* self = (physx::PxVehicleDrivableSurfaceToTireFrictionPairs*) _address;
    return (jfloat) self->getTypePairFriction(surfaceType, tireType);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceToTireFrictionPairs__1getMaxNbSurfaceTypes(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDrivableSurfaceToTireFrictionPairs* self = (physx::PxVehicleDrivableSurfaceToTireFrictionPairs*) _address;
    return (jint) self->getMaxNbSurfaceTypes();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceToTireFrictionPairs__1getMaxNbTireTypes(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDrivableSurfaceToTireFrictionPairs* self = (physx::PxVehicleDrivableSurfaceToTireFrictionPairs*) _address;
    return (jint) self->getMaxNbTireTypes();
}

// PxVehicleDrivableSurfaceType
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceType__1PxVehicleDrivableSurfaceType(JNIEnv*, jclass) {
    return (jlong) new physx::PxVehicleDrivableSurfaceType();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceType__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVehicleDrivableSurfaceType*) _address;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceType__1getMType(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDrivableSurfaceType* _self = (physx::PxVehicleDrivableSurfaceType*) _address;
    return (jint) _self->mType;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceType__1setMType(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxVehicleDrivableSurfaceType* _self = (physx::PxVehicleDrivableSurfaceType*) _address;
    _self->mType = value;
}

// PxVehicleDrive
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDrive__1getMDriveDynData(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDrive* _self = (physx::PxVehicleDrive*) _address;
    return (jlong) &_self->mDriveDynData;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDrive__1setMDriveDynData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxVehicleDrive* _self = (physx::PxVehicleDrive*) _address;
    _self->mDriveDynData = *((physx::PxVehicleDriveDynData*) value);
}

// PxVehicleDrive4W
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDrive4W__1allocate(JNIEnv*, jclass, jint nbWheels) {
    return (jlong) physx::PxVehicleDrive4W::allocate(nbWheels);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDrive4W__1free(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDrive4W* self = (physx::PxVehicleDrive4W*) _address;
    self->free();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDrive4W__1setup(JNIEnv*, jclass, jlong _address, jlong physics, jlong vehActor, jlong wheelsData, jlong driveData, jint nbNonDrivenWheels) {
    physx::PxVehicleDrive4W* self = (physx::PxVehicleDrive4W*) _address;
    self->setup((physx::PxPhysics*) physics, (physx::PxRigidDynamic*) vehActor, *((physx::PxVehicleWheelsSimData*) wheelsData), *((physx::PxVehicleDriveSimData4W*) driveData), nbNonDrivenWheels);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDrive4W__1setToRestState(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDrive4W* self = (physx::PxVehicleDrive4W*) _address;
    self->setToRestState();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDrive4W__1getMDriveSimData(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDrive4W* _self = (physx::PxVehicleDrive4W*) _address;
    return (jlong) &_self->mDriveSimData;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDrive4W__1setMDriveSimData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxVehicleDrive4W* _self = (physx::PxVehicleDrive4W*) _address;
    _self->mDriveSimData = *((physx::PxVehicleDriveSimData4W*) value);
}

// PxVehicleDriveDynData
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setToRestState(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    self->setToRestState();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setAnalogInput(JNIEnv*, jclass, jlong _address, jint type, jfloat analogVal) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    self->setAnalogInput(type, analogVal);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getAnalogInput(JNIEnv*, jclass, jlong _address, jint type) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    return (jfloat) self->getAnalogInput(type);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setGearUp(JNIEnv*, jclass, jlong _address, jboolean digitalVal) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    self->setGearUp(digitalVal);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setGearDown(JNIEnv*, jclass, jlong _address, jboolean digitalVal) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    self->setGearDown(digitalVal);
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getGearUp(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    return (jboolean) self->getGearUp();
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getGearDown(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    return (jboolean) self->getGearDown();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setUseAutoGears(JNIEnv*, jclass, jlong _address, jboolean useAutoGears) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    self->setUseAutoGears(useAutoGears);
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getUseAutoGears(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    return (jboolean) self->getUseAutoGears();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1toggleAutoGears(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    self->toggleAutoGears();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setCurrentGear(JNIEnv*, jclass, jlong _address, jint currentGear) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    self->setCurrentGear(currentGear);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getCurrentGear(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    return (jint) self->getCurrentGear();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setTargetGear(JNIEnv*, jclass, jlong _address, jint targetGear) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    self->setTargetGear(targetGear);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getTargetGear(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    return (jint) self->getTargetGear();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1startGearChange(JNIEnv*, jclass, jlong _address, jint targetGear) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    self->startGearChange(targetGear);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1forceGearChange(JNIEnv*, jclass, jlong _address, jint targetGear) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    self->forceGearChange(targetGear);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setEngineRotationSpeed(JNIEnv*, jclass, jlong _address, jfloat speed) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    self->setEngineRotationSpeed(speed);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getEngineRotationSpeed(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    return (jfloat) self->getEngineRotationSpeed();
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getGearSwitchTime(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    return (jfloat) self->getGearSwitchTime();
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getAutoBoxSwitchTime(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    return (jfloat) self->getAutoBoxSwitchTime();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getNbAnalogInput(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    return (jint) self->getNbAnalogInput();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setGearChange(JNIEnv*, jclass, jlong _address, jint gearChange) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    self->setGearChange(gearChange);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getGearChange(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    return (jint) self->getGearChange();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setGearSwitchTime(JNIEnv*, jclass, jlong _address, jfloat switchTime) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    self->setGearSwitchTime(switchTime);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setAutoBoxSwitchTime(JNIEnv*, jclass, jlong _address, jfloat autoBoxSwitchTime) {
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) _address;
    self->setAutoBoxSwitchTime(autoBoxSwitchTime);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVehicleDriveDynData*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getMControlAnalogVals(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::PxVehicleDriveDynData* _self = (physx::PxVehicleDriveDynData*) _address;
    return (jfloat) _self->mControlAnalogVals[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setMControlAnalogVals(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::PxVehicleDriveDynData* _self = (physx::PxVehicleDriveDynData*) _address;
    _self->mControlAnalogVals[_index] = value;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getMUseAutoGears(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveDynData* _self = (physx::PxVehicleDriveDynData*) _address;
    return (jboolean) _self->mUseAutoGears;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setMUseAutoGears(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxVehicleDriveDynData* _self = (physx::PxVehicleDriveDynData*) _address;
    _self->mUseAutoGears = value;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getMGearUpPressed(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveDynData* _self = (physx::PxVehicleDriveDynData*) _address;
    return (jboolean) _self->mGearUpPressed;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setMGearUpPressed(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxVehicleDriveDynData* _self = (physx::PxVehicleDriveDynData*) _address;
    _self->mGearUpPressed = value;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getMGearDownPressed(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveDynData* _self = (physx::PxVehicleDriveDynData*) _address;
    return (jboolean) _self->mGearDownPressed;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setMGearDownPressed(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxVehicleDriveDynData* _self = (physx::PxVehicleDriveDynData*) _address;
    _self->mGearDownPressed = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getMCurrentGear(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveDynData* _self = (physx::PxVehicleDriveDynData*) _address;
    return (jint) _self->mCurrentGear;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setMCurrentGear(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxVehicleDriveDynData* _self = (physx::PxVehicleDriveDynData*) _address;
    _self->mCurrentGear = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getMTargetGear(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveDynData* _self = (physx::PxVehicleDriveDynData*) _address;
    return (jint) _self->mTargetGear;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setMTargetGear(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxVehicleDriveDynData* _self = (physx::PxVehicleDriveDynData*) _address;
    _self->mTargetGear = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getMEnginespeed(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveDynData* _self = (physx::PxVehicleDriveDynData*) _address;
    return (jfloat) _self->mEnginespeed;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setMEnginespeed(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleDriveDynData* _self = (physx::PxVehicleDriveDynData*) _address;
    _self->mEnginespeed = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getMGearSwitchTime(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveDynData* _self = (physx::PxVehicleDriveDynData*) _address;
    return (jfloat) _self->mGearSwitchTime;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setMGearSwitchTime(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleDriveDynData* _self = (physx::PxVehicleDriveDynData*) _address;
    _self->mGearSwitchTime = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getMAutoBoxSwitchTime(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveDynData* _self = (physx::PxVehicleDriveDynData*) _address;
    return (jfloat) _self->mAutoBoxSwitchTime;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setMAutoBoxSwitchTime(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleDriveDynData* _self = (physx::PxVehicleDriveDynData*) _address;
    _self->mAutoBoxSwitchTime = value;
}

// PxVehicleDriveSimData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDriveSimData__1PxVehicleDriveSimData(JNIEnv*, jclass) {
    return (jlong) new physx::PxVehicleDriveSimData();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDriveSimData__1getEngineData(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveSimData* self = (physx::PxVehicleDriveSimData*) _address;
    return (jlong) &self->getEngineData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveSimData__1setEngineData(JNIEnv*, jclass, jlong _address, jlong engine) {
    physx::PxVehicleDriveSimData* self = (physx::PxVehicleDriveSimData*) _address;
    self->setEngineData(*((physx::PxVehicleEngineData*) engine));
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDriveSimData__1getGearsData(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveSimData* self = (physx::PxVehicleDriveSimData*) _address;
    return (jlong) &self->getGearsData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveSimData__1setGearsData(JNIEnv*, jclass, jlong _address, jlong gears) {
    physx::PxVehicleDriveSimData* self = (physx::PxVehicleDriveSimData*) _address;
    self->setGearsData(*((physx::PxVehicleGearsData*) gears));
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDriveSimData__1getClutchData(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveSimData* self = (physx::PxVehicleDriveSimData*) _address;
    return (jlong) &self->getClutchData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveSimData__1setClutchData(JNIEnv*, jclass, jlong _address, jlong clutch) {
    physx::PxVehicleDriveSimData* self = (physx::PxVehicleDriveSimData*) _address;
    self->setClutchData(*((physx::PxVehicleClutchData*) clutch));
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDriveSimData__1getAutoBoxData(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveSimData* self = (physx::PxVehicleDriveSimData*) _address;
    return (jlong) &self->getAutoBoxData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveSimData__1setAutoBoxData(JNIEnv*, jclass, jlong _address, jlong clutch) {
    physx::PxVehicleDriveSimData* self = (physx::PxVehicleDriveSimData*) _address;
    self->setAutoBoxData(*((physx::PxVehicleAutoBoxData*) clutch));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveSimData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVehicleDriveSimData*) _address;
}

// PxVehicleDriveSimData4W
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDriveSimData4W__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxVehicleDriveSimData4W);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDriveSimData4W__1_1placement_1new_1PxVehicleDriveSimData4W(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxVehicleDriveSimData4W();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDriveSimData4W__1PxVehicleDriveSimData4W(JNIEnv*, jclass) {
    return (jlong) new physx::PxVehicleDriveSimData4W();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDriveSimData4W__1getDiffData(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveSimData4W* self = (physx::PxVehicleDriveSimData4W*) _address;
    return (jlong) &self->getDiffData();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDriveSimData4W__1getAckermannGeometryData(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleDriveSimData4W* self = (physx::PxVehicleDriveSimData4W*) _address;
    return (jlong) &self->getAckermannGeometryData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveSimData4W__1setDiffData(JNIEnv*, jclass, jlong _address, jlong diff) {
    physx::PxVehicleDriveSimData4W* self = (physx::PxVehicleDriveSimData4W*) _address;
    self->setDiffData(*((physx::PxVehicleDifferential4WData*) diff));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveSimData4W__1setAckermannGeometryData(JNIEnv*, jclass, jlong _address, jlong ackermannData) {
    physx::PxVehicleDriveSimData4W* self = (physx::PxVehicleDriveSimData4W*) _address;
    self->setAckermannGeometryData(*((physx::PxVehicleAckermannGeometryData*) ackermannData));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveSimData4W__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVehicleDriveSimData4W*) _address;
}

// PxVehicleEngineData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleEngineData__1PxVehicleEngineData(JNIEnv*, jclass) {
    return (jlong) new physx::PxVehicleEngineData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleEngineData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVehicleEngineData*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleEngineData__1getMTorqueCurve(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleEngineData* _self = (physx::PxVehicleEngineData*) _address;
    return (jlong) &_self->mTorqueCurve;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleEngineData__1setMTorqueCurve(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxVehicleEngineData* _self = (physx::PxVehicleEngineData*) _address;
    _self->mTorqueCurve = *((PxEngineTorqueLookupTable*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleEngineData__1getMMOI(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleEngineData* _self = (physx::PxVehicleEngineData*) _address;
    return (jfloat) _self->mMOI;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleEngineData__1setMMOI(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleEngineData* _self = (physx::PxVehicleEngineData*) _address;
    _self->mMOI = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleEngineData__1getMPeakTorque(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleEngineData* _self = (physx::PxVehicleEngineData*) _address;
    return (jfloat) _self->mPeakTorque;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleEngineData__1setMPeakTorque(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleEngineData* _self = (physx::PxVehicleEngineData*) _address;
    _self->mPeakTorque = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleEngineData__1getMMaxOmega(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleEngineData* _self = (physx::PxVehicleEngineData*) _address;
    return (jfloat) _self->mMaxOmega;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleEngineData__1setMMaxOmega(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleEngineData* _self = (physx::PxVehicleEngineData*) _address;
    _self->mMaxOmega = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleEngineData__1getMDampingRateFullThrottle(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleEngineData* _self = (physx::PxVehicleEngineData*) _address;
    return (jfloat) _self->mDampingRateFullThrottle;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleEngineData__1setMDampingRateFullThrottle(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleEngineData* _self = (physx::PxVehicleEngineData*) _address;
    _self->mDampingRateFullThrottle = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleEngineData__1getMDampingRateZeroThrottleClutchEngaged(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleEngineData* _self = (physx::PxVehicleEngineData*) _address;
    return (jfloat) _self->mDampingRateZeroThrottleClutchEngaged;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleEngineData__1setMDampingRateZeroThrottleClutchEngaged(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleEngineData* _self = (physx::PxVehicleEngineData*) _address;
    _self->mDampingRateZeroThrottleClutchEngaged = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleEngineData__1getMDampingRateZeroThrottleClutchDisengaged(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleEngineData* _self = (physx::PxVehicleEngineData*) _address;
    return (jfloat) _self->mDampingRateZeroThrottleClutchDisengaged;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleEngineData__1setMDampingRateZeroThrottleClutchDisengaged(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleEngineData* _self = (physx::PxVehicleEngineData*) _address;
    _self->mDampingRateZeroThrottleClutchDisengaged = value;
}

// PxEngineTorqueLookupTable
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1PxEngineTorqueLookupTable(JNIEnv*, jclass) {
    return (jlong) new PxEngineTorqueLookupTable();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1addPair(JNIEnv*, jclass, jlong _address, jfloat x, jfloat y) {
    PxEngineTorqueLookupTable* self = (PxEngineTorqueLookupTable*) _address;
    self->addPair(x, y);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1getYVal(JNIEnv*, jclass, jlong _address, jfloat x) {
    PxEngineTorqueLookupTable* self = (PxEngineTorqueLookupTable*) _address;
    return (jfloat) self->getYVal(x);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1getNbDataPairs(JNIEnv*, jclass, jlong _address) {
    PxEngineTorqueLookupTable* self = (PxEngineTorqueLookupTable*) _address;
    return (jint) self->getNbDataPairs();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1clear(JNIEnv*, jclass, jlong _address) {
    PxEngineTorqueLookupTable* self = (PxEngineTorqueLookupTable*) _address;
    self->clear();
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1getX(JNIEnv*, jclass, jlong _address, jint i) {
    PxEngineTorqueLookupTable* self = (PxEngineTorqueLookupTable*) _address;
    return (jfloat) self->getX(i);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1getY(JNIEnv*, jclass, jlong _address, jint i) {
    PxEngineTorqueLookupTable* self = (PxEngineTorqueLookupTable*) _address;
    return (jfloat) self->getY(i);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (PxEngineTorqueLookupTable*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1getMDataPairs(JNIEnv*, jclass, jlong _address, jint _index) {
    PxEngineTorqueLookupTable* _self = (PxEngineTorqueLookupTable*) _address;
    return (jfloat) _self->mDataPairs[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1setMDataPairs(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    PxEngineTorqueLookupTable* _self = (PxEngineTorqueLookupTable*) _address;
    _self->mDataPairs[_index] = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1getMNbDataPairs(JNIEnv*, jclass, jlong _address) {
    PxEngineTorqueLookupTable* _self = (PxEngineTorqueLookupTable*) _address;
    return (jint) _self->mNbDataPairs;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1setMNbDataPairs(JNIEnv*, jclass, jlong _address, jint value) {
    PxEngineTorqueLookupTable* _self = (PxEngineTorqueLookupTable*) _address;
    _self->mNbDataPairs = value;
}

// PxVehicleGearsData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleGearsData__1PxVehicleGearsData(JNIEnv*, jclass) {
    return (jlong) new physx::PxVehicleGearsData();
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleGearsData__1getGearRatio(JNIEnv*, jclass, jlong _address, jint a) {
    physx::PxVehicleGearsData* self = (physx::PxVehicleGearsData*) _address;
    return (jfloat) self->getGearRatio((PxVehicleGearEnum) a);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleGearsData__1setGearRatio(JNIEnv*, jclass, jlong _address, jint a, jfloat ratio) {
    physx::PxVehicleGearsData* self = (physx::PxVehicleGearsData*) _address;
    self->setGearRatio((PxVehicleGearEnum) a, ratio);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleGearsData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVehicleGearsData*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleGearsData__1getMRatios(JNIEnv*, jclass, jlong _address, jint _index) {
    physx::PxVehicleGearsData* _self = (physx::PxVehicleGearsData*) _address;
    return (jfloat) _self->mRatios[_index];
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleGearsData__1setMRatios(JNIEnv*, jclass, jlong _address, jint _index, jfloat value) {
    physx::PxVehicleGearsData* _self = (physx::PxVehicleGearsData*) _address;
    _self->mRatios[_index] = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleGearsData__1getMFinalRatio(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleGearsData* _self = (physx::PxVehicleGearsData*) _address;
    return (jfloat) _self->mFinalRatio;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleGearsData__1setMFinalRatio(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleGearsData* _self = (physx::PxVehicleGearsData*) _address;
    _self->mFinalRatio = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearsData__1getMNbRatios(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleGearsData* _self = (physx::PxVehicleGearsData*) _address;
    return (jint) _self->mNbRatios;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleGearsData__1setMNbRatios(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxVehicleGearsData* _self = (physx::PxVehicleGearsData*) _address;
    _self->mNbRatios = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleGearsData__1getMSwitchTime(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleGearsData* _self = (physx::PxVehicleGearsData*) _address;
    return (jfloat) _self->mSwitchTime;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleGearsData__1setMSwitchTime(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleGearsData* _self = (physx::PxVehicleGearsData*) _address;
    _self->mSwitchTime = value;
}

// PxVehicleSuspensionData
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxVehicleSuspensionData);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1_1placement_1new_1PxVehicleSuspensionData(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxVehicleSuspensionData();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1PxVehicleSuspensionData(JNIEnv*, jclass) {
    return (jlong) new physx::PxVehicleSuspensionData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1setMassAndPreserveNaturalFrequency(JNIEnv*, jclass, jlong _address, jfloat newSprungMass) {
    physx::PxVehicleSuspensionData* self = (physx::PxVehicleSuspensionData*) _address;
    self->setMassAndPreserveNaturalFrequency(newSprungMass);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVehicleSuspensionData*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1getMSpringStrength(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleSuspensionData* _self = (physx::PxVehicleSuspensionData*) _address;
    return (jfloat) _self->mSpringStrength;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1setMSpringStrength(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleSuspensionData* _self = (physx::PxVehicleSuspensionData*) _address;
    _self->mSpringStrength = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1getMSpringDamperRate(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleSuspensionData* _self = (physx::PxVehicleSuspensionData*) _address;
    return (jfloat) _self->mSpringDamperRate;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1setMSpringDamperRate(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleSuspensionData* _self = (physx::PxVehicleSuspensionData*) _address;
    _self->mSpringDamperRate = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1getMMaxCompression(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleSuspensionData* _self = (physx::PxVehicleSuspensionData*) _address;
    return (jfloat) _self->mMaxCompression;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1setMMaxCompression(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleSuspensionData* _self = (physx::PxVehicleSuspensionData*) _address;
    _self->mMaxCompression = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1getMMaxDroop(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleSuspensionData* _self = (physx::PxVehicleSuspensionData*) _address;
    return (jfloat) _self->mMaxDroop;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1setMMaxDroop(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleSuspensionData* _self = (physx::PxVehicleSuspensionData*) _address;
    _self->mMaxDroop = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1getMSprungMass(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleSuspensionData* _self = (physx::PxVehicleSuspensionData*) _address;
    return (jfloat) _self->mSprungMass;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1setMSprungMass(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleSuspensionData* _self = (physx::PxVehicleSuspensionData*) _address;
    _self->mSprungMass = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1getMCamberAtRest(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleSuspensionData* _self = (physx::PxVehicleSuspensionData*) _address;
    return (jfloat) _self->mCamberAtRest;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1setMCamberAtRest(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleSuspensionData* _self = (physx::PxVehicleSuspensionData*) _address;
    _self->mCamberAtRest = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1getMCamberAtMaxCompression(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleSuspensionData* _self = (physx::PxVehicleSuspensionData*) _address;
    return (jfloat) _self->mCamberAtMaxCompression;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1setMCamberAtMaxCompression(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleSuspensionData* _self = (physx::PxVehicleSuspensionData*) _address;
    _self->mCamberAtMaxCompression = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1getMCamberAtMaxDroop(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleSuspensionData* _self = (physx::PxVehicleSuspensionData*) _address;
    return (jfloat) _self->mCamberAtMaxDroop;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1setMCamberAtMaxDroop(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleSuspensionData* _self = (physx::PxVehicleSuspensionData*) _address;
    _self->mCamberAtMaxDroop = value;
}

// PxVehicleTireData
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleTireData__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxVehicleTireData);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleTireData__1_1placement_1new_1PxVehicleTireData(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxVehicleTireData();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleTireData__1PxVehicleTireData(JNIEnv*, jclass) {
    return (jlong) new physx::PxVehicleTireData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVehicleTireData*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleTireData__1getMLatStiffX(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleTireData* _self = (physx::PxVehicleTireData*) _address;
    return (jfloat) _self->mLatStiffX;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireData__1setMLatStiffX(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleTireData* _self = (physx::PxVehicleTireData*) _address;
    _self->mLatStiffX = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleTireData__1getMLatStiffY(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleTireData* _self = (physx::PxVehicleTireData*) _address;
    return (jfloat) _self->mLatStiffY;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireData__1setMLatStiffY(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleTireData* _self = (physx::PxVehicleTireData*) _address;
    _self->mLatStiffY = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleTireData__1getMLongitudinalStiffnessPerUnitGravity(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleTireData* _self = (physx::PxVehicleTireData*) _address;
    return (jfloat) _self->mLongitudinalStiffnessPerUnitGravity;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireData__1setMLongitudinalStiffnessPerUnitGravity(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleTireData* _self = (physx::PxVehicleTireData*) _address;
    _self->mLongitudinalStiffnessPerUnitGravity = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleTireData__1getMCamberStiffnessPerUnitGravity(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleTireData* _self = (physx::PxVehicleTireData*) _address;
    return (jfloat) _self->mCamberStiffnessPerUnitGravity;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireData__1setMCamberStiffnessPerUnitGravity(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleTireData* _self = (physx::PxVehicleTireData*) _address;
    _self->mCamberStiffnessPerUnitGravity = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleTireData__1getMType(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleTireData* _self = (physx::PxVehicleTireData*) _address;
    return (jint) _self->mType;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireData__1setMType(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxVehicleTireData* _self = (physx::PxVehicleTireData*) _address;
    _self->mType = value;
}

// PxVehicleTireLoadFilterData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1PxVehicleTireLoadFilterData(JNIEnv*, jclass) {
    return (jlong) new physx::PxVehicleTireLoadFilterData();
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1getDenominator(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleTireLoadFilterData* self = (physx::PxVehicleTireLoadFilterData*) _address;
    return (jfloat) self->getDenominator();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVehicleTireLoadFilterData*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1getMMinNormalisedLoad(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleTireLoadFilterData* _self = (physx::PxVehicleTireLoadFilterData*) _address;
    return (jfloat) _self->mMinNormalisedLoad;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1setMMinNormalisedLoad(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleTireLoadFilterData* _self = (physx::PxVehicleTireLoadFilterData*) _address;
    _self->mMinNormalisedLoad = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1getMMinFilteredNormalisedLoad(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleTireLoadFilterData* _self = (physx::PxVehicleTireLoadFilterData*) _address;
    return (jfloat) _self->mMinFilteredNormalisedLoad;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1setMMinFilteredNormalisedLoad(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleTireLoadFilterData* _self = (physx::PxVehicleTireLoadFilterData*) _address;
    _self->mMinFilteredNormalisedLoad = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1getMMaxNormalisedLoad(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleTireLoadFilterData* _self = (physx::PxVehicleTireLoadFilterData*) _address;
    return (jfloat) _self->mMaxNormalisedLoad;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1setMMaxNormalisedLoad(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleTireLoadFilterData* _self = (physx::PxVehicleTireLoadFilterData*) _address;
    _self->mMaxNormalisedLoad = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1getMMaxFilteredNormalisedLoad(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleTireLoadFilterData* _self = (physx::PxVehicleTireLoadFilterData*) _address;
    return (jfloat) _self->mMaxFilteredNormalisedLoad;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1setMMaxFilteredNormalisedLoad(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleTireLoadFilterData* _self = (physx::PxVehicleTireLoadFilterData*) _address;
    _self->mMaxFilteredNormalisedLoad = value;
}

// PxVehicleWheelData
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelData__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxVehicleWheelData);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelData__1_1placement_1new_1PxVehicleWheelData(JNIEnv*, jclass, jlong _placement_address) {
    return (jlong) new((void*)_placement_address) physx::PxVehicleWheelData();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelData__1PxVehicleWheelData(JNIEnv*, jclass) {
    return (jlong) new physx::PxVehicleWheelData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVehicleWheelData*) _address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelData__1getMRadius(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelData* _self = (physx::PxVehicleWheelData*) _address;
    return (jfloat) _self->mRadius;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelData__1setMRadius(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleWheelData* _self = (physx::PxVehicleWheelData*) _address;
    _self->mRadius = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelData__1getMWidth(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelData* _self = (physx::PxVehicleWheelData*) _address;
    return (jfloat) _self->mWidth;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelData__1setMWidth(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleWheelData* _self = (physx::PxVehicleWheelData*) _address;
    _self->mWidth = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelData__1getMMass(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelData* _self = (physx::PxVehicleWheelData*) _address;
    return (jfloat) _self->mMass;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelData__1setMMass(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleWheelData* _self = (physx::PxVehicleWheelData*) _address;
    _self->mMass = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelData__1getMMOI(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelData* _self = (physx::PxVehicleWheelData*) _address;
    return (jfloat) _self->mMOI;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelData__1setMMOI(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleWheelData* _self = (physx::PxVehicleWheelData*) _address;
    _self->mMOI = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelData__1getMDampingRate(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelData* _self = (physx::PxVehicleWheelData*) _address;
    return (jfloat) _self->mDampingRate;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelData__1setMDampingRate(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleWheelData* _self = (physx::PxVehicleWheelData*) _address;
    _self->mDampingRate = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelData__1getMMaxBrakeTorque(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelData* _self = (physx::PxVehicleWheelData*) _address;
    return (jfloat) _self->mMaxBrakeTorque;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelData__1setMMaxBrakeTorque(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleWheelData* _self = (physx::PxVehicleWheelData*) _address;
    _self->mMaxBrakeTorque = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelData__1getMMaxHandBrakeTorque(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelData* _self = (physx::PxVehicleWheelData*) _address;
    return (jfloat) _self->mMaxHandBrakeTorque;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelData__1setMMaxHandBrakeTorque(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleWheelData* _self = (physx::PxVehicleWheelData*) _address;
    _self->mMaxHandBrakeTorque = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelData__1getMMaxSteer(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelData* _self = (physx::PxVehicleWheelData*) _address;
    return (jfloat) _self->mMaxSteer;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelData__1setMMaxSteer(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleWheelData* _self = (physx::PxVehicleWheelData*) _address;
    _self->mMaxSteer = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelData__1getMToeAngle(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelData* _self = (physx::PxVehicleWheelData*) _address;
    return (jfloat) _self->mToeAngle;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelData__1setMToeAngle(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxVehicleWheelData* _self = (physx::PxVehicleWheelData*) _address;
    _self->mToeAngle = value;
}

// PxVehicleWheelQueryResult
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelQueryResult__1PxVehicleWheelQueryResult(JNIEnv*, jclass) {
    return (jlong) new physx::PxVehicleWheelQueryResult();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelQueryResult__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVehicleWheelQueryResult*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelQueryResult__1getWheelQueryResults(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelQueryResult* _self = (physx::PxVehicleWheelQueryResult*) _address;
    return (jlong) _self->wheelQueryResults;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelQueryResult__1setWheelQueryResults(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxVehicleWheelQueryResult* _self = (physx::PxVehicleWheelQueryResult*) _address;
    _self->wheelQueryResults = (physx::PxWheelQueryResult*) value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelQueryResult__1getNbWheelQueryResults(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelQueryResult* _self = (physx::PxVehicleWheelQueryResult*) _address;
    return (jint) _self->nbWheelQueryResults;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelQueryResult__1setNbWheelQueryResults(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxVehicleWheelQueryResult* _self = (physx::PxVehicleWheelQueryResult*) _address;
    _self->nbWheelQueryResults = value;
}

// PxVehicleWheels
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheels__1getVehicleType(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheels* self = (physx::PxVehicleWheels*) _address;
    return (jint) self->getVehicleType();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheels__1getRigidDynamicActor(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheels* self = (physx::PxVehicleWheels*) _address;
    return (jlong) self->getRigidDynamicActor();
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheels__1computeForwardSpeed(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheels* self = (physx::PxVehicleWheels*) _address;
    return (jfloat) self->computeForwardSpeed();
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheels__1computeSidewaysSpeed(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheels* self = (physx::PxVehicleWheels*) _address;
    return (jfloat) self->computeSidewaysSpeed();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheels__1getNbNonDrivenWheels(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheels* self = (physx::PxVehicleWheels*) _address;
    return (jint) self->getNbNonDrivenWheels();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheels__1getMWheelsSimData(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheels* _self = (physx::PxVehicleWheels*) _address;
    return (jlong) &_self->mWheelsSimData;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheels__1setMWheelsSimData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxVehicleWheels* _self = (physx::PxVehicleWheels*) _address;
    _self->mWheelsSimData = *((physx::PxVehicleWheelsSimData*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheels__1getMWheelsDynData(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheels* _self = (physx::PxVehicleWheels*) _address;
    return (jlong) &_self->mWheelsDynData;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheels__1setMWheelsDynData(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxVehicleWheels* _self = (physx::PxVehicleWheels*) _address;
    _self->mWheelsDynData = *((physx::PxVehicleWheelsDynData*) value);
}

// PxVehicleWheelsDynData
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsDynData__1setToRestState(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsDynData* self = (physx::PxVehicleWheelsDynData*) _address;
    self->setToRestState();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsDynData__1setWheelRotationSpeed(JNIEnv*, jclass, jlong _address, jint wheelIdx, jfloat speed) {
    physx::PxVehicleWheelsDynData* self = (physx::PxVehicleWheelsDynData*) _address;
    self->setWheelRotationSpeed(wheelIdx, speed);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelsDynData__1getWheelRotationSpeed(JNIEnv*, jclass, jlong _address, jint wheelIdx) {
    physx::PxVehicleWheelsDynData* self = (physx::PxVehicleWheelsDynData*) _address;
    return (jfloat) self->getWheelRotationSpeed(wheelIdx);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsDynData__1setWheelRotationAngle(JNIEnv*, jclass, jlong _address, jint wheelIdx, jfloat angle) {
    physx::PxVehicleWheelsDynData* self = (physx::PxVehicleWheelsDynData*) _address;
    self->setWheelRotationAngle(wheelIdx, angle);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelsDynData__1getWheelRotationAngle(JNIEnv*, jclass, jlong _address, jint wheelIdx) {
    physx::PxVehicleWheelsDynData* self = (physx::PxVehicleWheelsDynData*) _address;
    return (jfloat) self->getWheelRotationAngle(wheelIdx);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsDynData__1copy(JNIEnv*, jclass, jlong _address, jlong src, jint srcWheel, jint trgWheel) {
    physx::PxVehicleWheelsDynData* self = (physx::PxVehicleWheelsDynData*) _address;
    self->copy(*((physx::PxVehicleWheelsDynData*) src), srcWheel, trgWheel);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsDynData__1getNbWheelRotationSpeed(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsDynData* self = (physx::PxVehicleWheelsDynData*) _address;
    return (jint) self->getNbWheelRotationSpeed();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsDynData__1getNbWheelRotationAngle(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsDynData* self = (physx::PxVehicleWheelsDynData*) _address;
    return (jint) self->getNbWheelRotationAngle();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsDynData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVehicleWheelsDynData*) _address;
}

// PxVehicleWheelsSimData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1allocate(JNIEnv*, jclass, jint nbWheels) {
    return (jlong) physx::PxVehicleWheelsSimData::allocate(nbWheels);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setChassisMass(JNIEnv*, jclass, jlong _address, jfloat chassisMass) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->setChassisMass(chassisMass);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1free(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->free();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1copy(JNIEnv*, jclass, jlong _address, jlong src, jint srcWheel, jint trgWheel) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->copy(*((physx::PxVehicleWheelsSimData*) src), srcWheel, trgWheel);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbWheels(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jint) self->getNbWheels();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getSuspensionData(JNIEnv*, jclass, jlong _address, jint id) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jlong) &self->getSuspensionData(id);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getWheelData(JNIEnv*, jclass, jlong _address, jint id) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jlong) &self->getWheelData(id);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getTireData(JNIEnv*, jclass, jlong _address, jint id) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jlong) &self->getTireData(id);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getSuspTravelDirection(JNIEnv*, jclass, jlong _address, jint id) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jlong) &self->getSuspTravelDirection(id);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getSuspForceAppPointOffset(JNIEnv*, jclass, jlong _address, jint id) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jlong) &self->getSuspForceAppPointOffset(id);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getTireForceAppPointOffset(JNIEnv*, jclass, jlong _address, jint id) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jlong) &self->getTireForceAppPointOffset(id);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getWheelCentreOffset(JNIEnv*, jclass, jlong _address, jint id) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jlong) &self->getWheelCentreOffset(id);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getWheelShapeMapping(JNIEnv*, jclass, jlong _address, jint wheelId) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jint) self->getWheelShapeMapping(wheelId);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getSceneQueryFilterData(JNIEnv*, jclass, jlong _address, jint suspId) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jlong) &self->getSceneQueryFilterData(suspId);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbAntiRollBars(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jint) self->getNbAntiRollBars();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getAntiRollBarData(JNIEnv*, jclass, jlong _address, jint antiRollId) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jlong) &self->getAntiRollBarData(antiRollId);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getTireLoadFilterData(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jlong) &self->getTireLoadFilterData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setSuspensionData(JNIEnv*, jclass, jlong _address, jint id, jlong susp) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->setSuspensionData(id, *((physx::PxVehicleSuspensionData*) susp));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setWheelData(JNIEnv*, jclass, jlong _address, jint id, jlong wheel) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->setWheelData(id, *((physx::PxVehicleWheelData*) wheel));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setTireData(JNIEnv*, jclass, jlong _address, jint id, jlong tire) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->setTireData(id, *((physx::PxVehicleTireData*) tire));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setSuspTravelDirection(JNIEnv*, jclass, jlong _address, jint id, jlong dir) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->setSuspTravelDirection(id, *((physx::PxVec3*) dir));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setSuspForceAppPointOffset(JNIEnv*, jclass, jlong _address, jint id, jlong offset) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->setSuspForceAppPointOffset(id, *((physx::PxVec3*) offset));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setTireForceAppPointOffset(JNIEnv*, jclass, jlong _address, jint id, jlong offset) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->setTireForceAppPointOffset(id, *((physx::PxVec3*) offset));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setWheelCentreOffset(JNIEnv*, jclass, jlong _address, jint id, jlong offset) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->setWheelCentreOffset(id, *((physx::PxVec3*) offset));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setWheelShapeMapping(JNIEnv*, jclass, jlong _address, jint wheelId, jint shapeId) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->setWheelShapeMapping(wheelId, shapeId);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setSceneQueryFilterData(JNIEnv*, jclass, jlong _address, jint suspId, jlong sqFilterData) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->setSceneQueryFilterData(suspId, *((physx::PxFilterData*) sqFilterData));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setTireLoadFilterData(JNIEnv*, jclass, jlong _address, jlong tireLoadFilter) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->setTireLoadFilterData(*((physx::PxVehicleTireLoadFilterData*) tireLoadFilter));
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1addAntiRollBarData(JNIEnv*, jclass, jlong _address, jlong antiRoll) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jint) self->addAntiRollBarData(*((physx::PxVehicleAntiRollBarData*) antiRoll));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1disableWheel(JNIEnv*, jclass, jlong _address, jint wheel) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->disableWheel(wheel);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1enableWheel(JNIEnv*, jclass, jlong _address, jint wheel) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->enableWheel(wheel);
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getIsWheelDisabled(JNIEnv*, jclass, jlong _address, jint wheel) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jboolean) self->getIsWheelDisabled(wheel);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setSubStepCount(JNIEnv*, jclass, jlong _address, jfloat thresholdLongitudinalSpeed, jint lowForwardSpeedSubStepCount, jint highForwardSpeedSubStepCount) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->setSubStepCount(thresholdLongitudinalSpeed, lowForwardSpeedSubStepCount, highForwardSpeedSubStepCount);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setMinLongSlipDenominator(JNIEnv*, jclass, jlong _address, jfloat minLongSlipDenominator) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->setMinLongSlipDenominator(minLongSlipDenominator);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setFlags(JNIEnv*, jclass, jlong _address, jlong flags) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->setFlags(*((physx::PxVehicleWheelsSimFlags*) flags));
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getFlags(JNIEnv*, jclass, jlong _address) {
    static thread_local physx::PxVehicleWheelsSimFlags _cache;
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    _cache = self->getFlags();
    return (jlong) &_cache;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbWheels4(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jint) self->getNbWheels4();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbSuspensionData(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jint) self->getNbSuspensionData();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbWheelData(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jint) self->getNbWheelData();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbSuspTravelDirection(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jint) self->getNbSuspTravelDirection();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbTireData(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jint) self->getNbTireData();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbSuspForceAppPointOffset(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jint) self->getNbSuspForceAppPointOffset();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbTireForceAppPointOffset(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jint) self->getNbTireForceAppPointOffset();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbWheelCentreOffset(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jint) self->getNbWheelCentreOffset();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbWheelShapeMapping(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jint) self->getNbWheelShapeMapping();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbSceneQueryFilterData(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jint) self->getNbSceneQueryFilterData();
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getMinLongSlipDenominator(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jfloat) self->getMinLongSlipDenominator();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setThresholdLongSpeed(JNIEnv*, jclass, jlong _address, jfloat f) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->setThresholdLongSpeed(f);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getThresholdLongSpeed(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jfloat) self->getThresholdLongSpeed();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setLowForwardSpeedSubStepCount(JNIEnv*, jclass, jlong _address, jint f) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->setLowForwardSpeedSubStepCount(f);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getLowForwardSpeedSubStepCount(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jint) self->getLowForwardSpeedSubStepCount();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setHighForwardSpeedSubStepCount(JNIEnv*, jclass, jlong _address, jint f) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->setHighForwardSpeedSubStepCount(f);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getHighForwardSpeedSubStepCount(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jint) self->getHighForwardSpeedSubStepCount();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setWheelEnabledState(JNIEnv*, jclass, jlong _address, jint wheel, jboolean state) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->setWheelEnabledState(wheel, state);
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getWheelEnabledState(JNIEnv*, jclass, jlong _address, jint wheel) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jboolean) self->getWheelEnabledState(wheel);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbWheelEnabledState(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jint) self->getNbWheelEnabledState();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbAntiRollBars4(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jint) self->getNbAntiRollBars4();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbAntiRollBarData(JNIEnv*, jclass, jlong _address) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    return (jint) self->getNbAntiRollBarData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setAntiRollBarData(JNIEnv*, jclass, jlong _address, jint id, jlong antiRoll) {
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) _address;
    self->setAntiRollBarData(id, *((physx::PxVehicleAntiRollBarData*) antiRoll));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVehicleWheelsSimData*) _address;
}

// PxVehicleWheelsSimFlags
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimFlags__1_1sizeOf(JNIEnv*, jclass) {
    return sizeof(physx::PxVehicleWheelsSimFlags);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimFlags__1_1placement_1new_1PxVehicleWheelsSimFlags(JNIEnv*, jclass, jlong _placement_address, jint flags) {
    return (jlong) new((void*)_placement_address) physx::PxVehicleWheelsSimFlags(flags);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimFlags__1PxVehicleWheelsSimFlags(JNIEnv*, jclass, jint flags) {
    return (jlong) new physx::PxVehicleWheelsSimFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxVehicleWheelsSimFlags__1isSet(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxVehicleWheelsSimFlags* self = (physx::PxVehicleWheelsSimFlags*) _address;
    return (jboolean) self->isSet((PxVehicleWheelsSimFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimFlags__1set(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxVehicleWheelsSimFlags* self = (physx::PxVehicleWheelsSimFlags*) _address;
    self->set((PxVehicleWheelsSimFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimFlags__1clear(JNIEnv*, jclass, jlong _address, jint flag) {
    physx::PxVehicleWheelsSimFlags* self = (physx::PxVehicleWheelsSimFlags*) _address;
    self->clear((PxVehicleWheelsSimFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxVehicleWheelsSimFlags*) _address;
}

// PxWheelQueryResult
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1PxWheelQueryResult(JNIEnv*, jclass) {
    return (jlong) new physx::PxWheelQueryResult();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1delete_1native_1instance(JNIEnv*, jclass, jlong _address) {
    delete (physx::PxWheelQueryResult*) _address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1getSuspLineStart(JNIEnv*, jclass, jlong _address) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    return (jlong) &_self->suspLineStart;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setSuspLineStart(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    _self->suspLineStart = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1getSuspLineDir(JNIEnv*, jclass, jlong _address) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    return (jlong) &_self->suspLineDir;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setSuspLineDir(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    _self->suspLineDir = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxWheelQueryResult__1getSuspLineLength(JNIEnv*, jclass, jlong _address) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    return (jfloat) _self->suspLineLength;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setSuspLineLength(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    _self->suspLineLength = value;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxWheelQueryResult__1getIsInAir(JNIEnv*, jclass, jlong _address) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    return (jboolean) _self->isInAir;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setIsInAir(JNIEnv*, jclass, jlong _address, jboolean value) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    _self->isInAir = value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1getTireContactActor(JNIEnv*, jclass, jlong _address) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    return (jlong) _self->tireContactActor;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setTireContactActor(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    _self->tireContactActor = (physx::PxActor*) value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1getTireContactShape(JNIEnv*, jclass, jlong _address) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    return (jlong) _self->tireContactShape;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setTireContactShape(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    _self->tireContactShape = (physx::PxShape*) value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1getTireSurfaceMaterial(JNIEnv*, jclass, jlong _address) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    return (jlong) _self->tireSurfaceMaterial;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setTireSurfaceMaterial(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    _self->tireSurfaceMaterial = (physx::PxMaterial*) value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxWheelQueryResult__1getTireSurfaceType(JNIEnv*, jclass, jlong _address) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    return (jint) _self->tireSurfaceType;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setTireSurfaceType(JNIEnv*, jclass, jlong _address, jint value) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    _self->tireSurfaceType = value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1getTireContactPoint(JNIEnv*, jclass, jlong _address) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    return (jlong) &_self->tireContactPoint;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setTireContactPoint(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    _self->tireContactPoint = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1getTireContactNormal(JNIEnv*, jclass, jlong _address) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    return (jlong) &_self->tireContactNormal;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setTireContactNormal(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    _self->tireContactNormal = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxWheelQueryResult__1getTireFriction(JNIEnv*, jclass, jlong _address) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    return (jfloat) _self->tireFriction;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setTireFriction(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    _self->tireFriction = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxWheelQueryResult__1getSuspJounce(JNIEnv*, jclass, jlong _address) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    return (jfloat) _self->suspJounce;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setSuspJounce(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    _self->suspJounce = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxWheelQueryResult__1getSuspSpringForce(JNIEnv*, jclass, jlong _address) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    return (jfloat) _self->suspSpringForce;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setSuspSpringForce(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    _self->suspSpringForce = value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1getTireLongitudinalDir(JNIEnv*, jclass, jlong _address) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    return (jlong) &_self->tireLongitudinalDir;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setTireLongitudinalDir(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    _self->tireLongitudinalDir = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1getTireLateralDir(JNIEnv*, jclass, jlong _address) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    return (jlong) &_self->tireLateralDir;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setTireLateralDir(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    _self->tireLateralDir = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxWheelQueryResult__1getLongitudinalSlip(JNIEnv*, jclass, jlong _address) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    return (jfloat) _self->longitudinalSlip;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setLongitudinalSlip(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    _self->longitudinalSlip = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxWheelQueryResult__1getLateralSlip(JNIEnv*, jclass, jlong _address) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    return (jfloat) _self->lateralSlip;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setLateralSlip(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    _self->lateralSlip = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxWheelQueryResult__1getSteerAngle(JNIEnv*, jclass, jlong _address) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    return (jfloat) _self->steerAngle;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setSteerAngle(JNIEnv*, jclass, jlong _address, jfloat value) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    _self->steerAngle = value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1getLocalPose(JNIEnv*, jclass, jlong _address) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    return (jlong) &_self->localPose;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setLocalPose(JNIEnv*, jclass, jlong _address, jlong value) {
    physx::PxWheelQueryResult* _self = (physx::PxWheelQueryResult*) _address;
    _self->localPose = *((physx::PxTransform*) value);
}

// PxVehicleClutchAccuracyModeEnum
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleClutchAccuracyModeEnum__1geteESTIMATE(JNIEnv*, jclass) {
    return PxVehicleClutchAccuracyModeEnum::eESTIMATE;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleClutchAccuracyModeEnum__1geteBEST_1POSSIBLE(JNIEnv*, jclass) {
    return PxVehicleClutchAccuracyModeEnum::eBEST_POSSIBLE;
}

// PxVehicleDifferential4WDataEnum
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDifferential4WDataEnum__1geteDIFF_1TYPE_1LS_14WD(JNIEnv*, jclass) {
    return PxVehicleDifferential4WDataEnum::eDIFF_TYPE_LS_4WD;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDifferential4WDataEnum__1geteDIFF_1TYPE_1LS_1FRONTWD(JNIEnv*, jclass) {
    return PxVehicleDifferential4WDataEnum::eDIFF_TYPE_LS_FRONTWD;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDifferential4WDataEnum__1geteDIFF_1TYPE_1LS_1REARWD(JNIEnv*, jclass) {
    return PxVehicleDifferential4WDataEnum::eDIFF_TYPE_LS_REARWD;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDifferential4WDataEnum__1geteDIFF_1TYPE_1OPEN_14WD(JNIEnv*, jclass) {
    return PxVehicleDifferential4WDataEnum::eDIFF_TYPE_OPEN_4WD;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDifferential4WDataEnum__1geteDIFF_1TYPE_1OPEN_1FRONTWD(JNIEnv*, jclass) {
    return PxVehicleDifferential4WDataEnum::eDIFF_TYPE_OPEN_FRONTWD;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDifferential4WDataEnum__1geteDIFF_1TYPE_1OPEN_1REARWD(JNIEnv*, jclass) {
    return PxVehicleDifferential4WDataEnum::eDIFF_TYPE_OPEN_REARWD;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDifferential4WDataEnum__1geteMAX_1NB_1DIFF_1TYPES(JNIEnv*, jclass) {
    return PxVehicleDifferential4WDataEnum::eMAX_NB_DIFF_TYPES;
}

// PxVehicleDrive4WControlEnum
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDrive4WControlEnum__1geteANALOG_1INPUT_1ACCEL(JNIEnv*, jclass) {
    return PxVehicleDrive4WControlEnum::eANALOG_INPUT_ACCEL;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDrive4WControlEnum__1geteANALOG_1INPUT_1BRAKE(JNIEnv*, jclass) {
    return PxVehicleDrive4WControlEnum::eANALOG_INPUT_BRAKE;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDrive4WControlEnum__1geteANALOG_1INPUT_1HANDBRAKE(JNIEnv*, jclass) {
    return PxVehicleDrive4WControlEnum::eANALOG_INPUT_HANDBRAKE;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDrive4WControlEnum__1geteANALOG_1INPUT_1STEER_1LEFT(JNIEnv*, jclass) {
    return PxVehicleDrive4WControlEnum::eANALOG_INPUT_STEER_LEFT;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDrive4WControlEnum__1geteANALOG_1INPUT_1STEER_1RIGHT(JNIEnv*, jclass) {
    return PxVehicleDrive4WControlEnum::eANALOG_INPUT_STEER_RIGHT;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDrive4WControlEnum__1geteMAX_1NB_1DRIVE4W_1ANALOG_1INPUTS(JNIEnv*, jclass) {
    return PxVehicleDrive4WControlEnum::eMAX_NB_DRIVE4W_ANALOG_INPUTS;
}

// PxVehicleGearEnum
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteREVERSE(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eREVERSE;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteNEUTRAL(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eNEUTRAL;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteFIRST(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eFIRST;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteSECOND(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eSECOND;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteTHIRD(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eTHIRD;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteFOURTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eFOURTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteFIFTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eFIFTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteSIXTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eSIXTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteSEVENTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eSEVENTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteEIGHTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eEIGHTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteNINTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eNINTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteTENTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eTENTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteELEVENTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eELEVENTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteTWELFTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eTWELFTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteTHIRTEENTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eTHIRTEENTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteFOURTEENTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eFOURTEENTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteFIFTEENTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eFIFTEENTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteSIXTEENTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eSIXTEENTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteSEVENTEENTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eSEVENTEENTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteEIGHTEENTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eEIGHTEENTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteNINETEENTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eNINETEENTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteTWENTIETH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eTWENTIETH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteTWENTYFIRST(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eTWENTYFIRST;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteTWENTYSECOND(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eTWENTYSECOND;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteTWENTYTHIRD(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eTWENTYTHIRD;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteTWENTYFOURTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eTWENTYFOURTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteTWENTYFIFTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eTWENTYFIFTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteTWENTYSIXTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eTWENTYSIXTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteTWENTYSEVENTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eTWENTYSEVENTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteTWENTYEIGHTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eTWENTYEIGHTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteTWENTYNINTH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eTWENTYNINTH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteTHIRTIETH(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eTHIRTIETH;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearEnum__1geteGEARSRATIO_1COUNT(JNIEnv*, jclass) {
    return PxVehicleGearEnum::eGEARSRATIO_COUNT;
}

// PxVehicleUpdateModeEnum
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleUpdateModeEnum__1geteVELOCITY_1CHANGE(JNIEnv*, jclass) {
    return PxVehicleUpdateModeEnum::eVELOCITY_CHANGE;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleUpdateModeEnum__1geteACCELERATION(JNIEnv*, jclass) {
    return PxVehicleUpdateModeEnum::eACCELERATION;
}

// PxVehicleWheelsSimFlagEnum
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimFlagEnum__1geteLIMIT_1SUSPENSION_1EXPANSION_1VELOCITY(JNIEnv*, jclass) {
    return PxVehicleWheelsSimFlagEnum::eLIMIT_SUSPENSION_EXPANSION_VELOCITY;
}

// VehicleSurfaceTypeMask
JNIEXPORT jint JNICALL Java_physx_vehicle_VehicleSurfaceTypeMask__1getDRIVABLE_1SURFACE(JNIEnv*, jclass) {
    return DRIVABLE_SURFACE;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_VehicleSurfaceTypeMask__1getUNDRIVABLE_1SURFACE(JNIEnv*, jclass) {
    return UNDRIVABLE_SURFACE;
}

} // /extern "C"
