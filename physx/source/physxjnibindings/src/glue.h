/*
 * JNI glue code. You should not edit this file.
 * Generated from WebIDL model 'PhysXJs' by webidl-util.
 */
#include <jni.h>

extern "C" {

// PxTopLevelFunctions
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1DefaultFilterShader(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxSimulationFilterShader cache;
    cache = PxTopLevelFunctions::DefaultFilterShader();
    return (jlong) &cache;
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1DefaultWheelSceneQueryPreFilterBlocking(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxBatchQueryPreFilterShader cache;
    cache = PxTopLevelFunctions::DefaultWheelSceneQueryPreFilterBlocking();
    return (jlong) &cache;
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1DefaultWheelSceneQueryPostFilterBlocking(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxBatchQueryPostFilterShader cache;
    cache = PxTopLevelFunctions::DefaultWheelSceneQueryPostFilterBlocking();
    return (jlong) &cache;
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1CreateCooking(JNIEnv* env, jclass, jint version, jlong foundation, jlong scale) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) PxTopLevelFunctions::CreateCooking(version, *((physx::PxFoundation*) foundation), *((physx::PxCookingParams*) scale));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1CreateFoundation(JNIEnv* env, jclass, jint version, jlong allocator, jlong errorCallback) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) PxTopLevelFunctions::CreateFoundation(version, *((physx::PxDefaultAllocator*) allocator), *((physx::PxDefaultErrorCallback*) errorCallback));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1CreatePhysics(JNIEnv* env, jclass, jint version, jlong foundation, jlong params) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) PxTopLevelFunctions::CreatePhysics(version, *((physx::PxFoundation*) foundation), *((physx::PxTolerancesScale*) params));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1DefaultCpuDispatcherCreate(JNIEnv* env, jclass, jint numThreads) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) PxTopLevelFunctions::DefaultCpuDispatcherCreate(numThreads);
}
JNIEXPORT jboolean JNICALL Java_physx_PxTopLevelFunctions__1InitExtensions(JNIEnv* env, jclass, jlong physics) {
    (void) env;    // avoid unused parameter warning / error
    return (jboolean) PxTopLevelFunctions::InitExtensions(*((physx::PxPhysics*) physics));
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1RevoluteJointCreate(JNIEnv* env, jclass, jlong physics, jlong actor0, jlong localFrame0, jlong actor1, jlong localFrame1) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) PxTopLevelFunctions::RevoluteJointCreate(*((physx::PxPhysics*) physics), (physx::PxRigidActor*) actor0, *((physx::PxTransform*) localFrame0), (physx::PxRigidActor*) actor1, *((physx::PxTransform*) localFrame1));
}
JNIEXPORT jint JNICALL Java_physx_PxTopLevelFunctions__1getU8At(JNIEnv* env, jclass, jlong base, jint index) {
    (void) env;    // avoid unused parameter warning / error
    return (jint) PxTopLevelFunctions::getU8At(*((PxU8Ptr*) base), index);
}
JNIEXPORT jlong JNICALL Java_physx_PxTopLevelFunctions__1getVec3At(JNIEnv* env, jclass, jlong base, jint index) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxVec3 cache;
    cache = PxTopLevelFunctions::getVec3At((physx::PxVec3*) base, index);
    return (jlong) &cache;
}
JNIEXPORT void JNICALL Java_physx_PxTopLevelFunctions__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (PxTopLevelFunctions*) address;
}
JNIEXPORT jint JNICALL Java_physx_PxTopLevelFunctions__1getPHYSICS_1VERSION(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jint) PxTopLevelFunctions::PHYSICS_VERSION;
}

// PxBase
JNIEXPORT void JNICALL Java_physx_common_PxBase__1release(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBase* self = (physx::PxBase*) address;
    self->release();
}
JNIEXPORT jstring JNICALL Java_physx_common_PxBase__1getConcreteTypeName(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBase* self = (physx::PxBase*) address;
    return env->NewStringUTF(self->getConcreteTypeName());
}
JNIEXPORT jint JNICALL Java_physx_common_PxBase__1getConcreteType(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBase* self = (physx::PxBase*) address;
    return (jint) self->getConcreteType();
}
JNIEXPORT void JNICALL Java_physx_common_PxBase__1setBaseFlag(JNIEnv* env, jclass, jlong address, jint flag, jboolean value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBase* self = (physx::PxBase*) address;
    self->setBaseFlag((PxBaseFlagEnum) flag, value);
}
JNIEXPORT void JNICALL Java_physx_common_PxBase__1setBaseFlags(JNIEnv* env, jclass, jlong address, jlong inFlags) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBase* self = (physx::PxBase*) address;
    self->setBaseFlags(*((physx::PxBaseFlags*) inFlags));
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBase__1getBaseFlags(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxBaseFlags cache;
    physx::PxBase* self = (physx::PxBase*) address;
    cache = self->getBaseFlags();
    return (jlong) &cache;
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBase__1isReleasable(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBase* self = (physx::PxBase*) address;
    return (jboolean) self->isReleasable();
}

// PxBaseFlags
JNIEXPORT jlong JNICALL Java_physx_common_PxBaseFlags__1PxBaseFlags(JNIEnv* env, jclass, jshort flags) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxBaseFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBaseFlags__1isSet(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBaseFlags* self = (physx::PxBaseFlags*) address;
    return (jboolean) self->isSet((PxBaseFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_common_PxBaseFlags__1set(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBaseFlags* self = (physx::PxBaseFlags*) address;
    self->set((PxBaseFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_common_PxBaseFlags__1clear(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBaseFlags* self = (physx::PxBaseFlags*) address;
    self->clear((PxBaseFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_common_PxBaseFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxBaseFlags*) address;
}

// PxBaseTask
JNIEXPORT void JNICALL Java_physx_common_PxBaseTask__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxBaseTask*) address;
}

// PxBoundedData
JNIEXPORT void JNICALL Java_physx_common_PxBoundedData__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxBoundedData*) address;
}
JNIEXPORT jint JNICALL Java_physx_common_PxBoundedData__1getCount(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBoundedData* self = (physx::PxBoundedData*) address;
    return (jint) self->count;
}
JNIEXPORT void JNICALL Java_physx_common_PxBoundedData__1setCount(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBoundedData* self = (physx::PxBoundedData*) address;
    self->count = value;
}
JNIEXPORT jint JNICALL Java_physx_common_PxBoundedData__1getStride(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBoundedData* self = (physx::PxBoundedData*) address;
    return (jint) self->stride;
}
JNIEXPORT void JNICALL Java_physx_common_PxBoundedData__1setStride(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBoundedData* self = (physx::PxBoundedData*) address;
    self->stride = value;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBoundedData__1getData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBoundedData* self = (physx::PxBoundedData*) address;
    return (jlong) self->data;
}
JNIEXPORT void JNICALL Java_physx_common_PxBoundedData__1setData(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBoundedData* self = (physx::PxBoundedData*) address;
    self->data = (void*) value;
}

// PxBounds3
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1PxBounds3__(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxBounds3();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1PxBounds3__JJ(JNIEnv* env, jclass, jlong minimum, jlong maximum) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxBounds3(*((physx::PxVec3*) minimum), *((physx::PxVec3*) maximum));
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1setEmpty(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBounds3* self = (physx::PxBounds3*) address;
    self->setEmpty();
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1setMaximal(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBounds3* self = (physx::PxBounds3*) address;
    self->setMaximal();
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1include(JNIEnv* env, jclass, jlong address, jlong v) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBounds3* self = (physx::PxBounds3*) address;
    self->include(*((physx::PxVec3*) v));
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBounds3__1isEmpty(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBounds3* self = (physx::PxBounds3*) address;
    return (jboolean) self->isEmpty();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBounds3__1intersects(JNIEnv* env, jclass, jlong address, jlong b) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBounds3* self = (physx::PxBounds3*) address;
    return (jboolean) self->intersects(*((physx::PxBounds3*) b));
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBounds3__1intersects1D(JNIEnv* env, jclass, jlong address, jlong b, jint axis) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBounds3* self = (physx::PxBounds3*) address;
    return (jboolean) self->intersects1D(*((physx::PxBounds3*) b), axis);
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBounds3__1contains(JNIEnv* env, jclass, jlong address, jlong v) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBounds3* self = (physx::PxBounds3*) address;
    return (jboolean) self->contains(*((physx::PxVec3*) v));
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBounds3__1isInside(JNIEnv* env, jclass, jlong address, jlong box) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBounds3* self = (physx::PxBounds3*) address;
    return (jboolean) self->isInside(*((physx::PxBounds3*) box));
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1getCenter(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxVec3 cache;
    physx::PxBounds3* self = (physx::PxBounds3*) address;
    cache = self->getCenter();
    return (jlong) &cache;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1getDimensions(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxVec3 cache;
    physx::PxBounds3* self = (physx::PxBounds3*) address;
    cache = self->getDimensions();
    return (jlong) &cache;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1getExtents(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxVec3 cache;
    physx::PxBounds3* self = (physx::PxBounds3*) address;
    cache = self->getExtents();
    return (jlong) &cache;
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1scaleSafe(JNIEnv* env, jclass, jlong address, jfloat scale) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBounds3* self = (physx::PxBounds3*) address;
    self->scaleSafe(scale);
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1scaleFast(JNIEnv* env, jclass, jlong address, jfloat scale) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBounds3* self = (physx::PxBounds3*) address;
    self->scaleFast(scale);
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1fattenSafe(JNIEnv* env, jclass, jlong address, jfloat distance) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBounds3* self = (physx::PxBounds3*) address;
    self->fattenSafe(distance);
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1fattenFast(JNIEnv* env, jclass, jlong address, jfloat distance) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBounds3* self = (physx::PxBounds3*) address;
    self->fattenFast(distance);
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBounds3__1isFinite(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBounds3* self = (physx::PxBounds3*) address;
    return (jboolean) self->isFinite();
}
JNIEXPORT jboolean JNICALL Java_physx_common_PxBounds3__1isValid(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBounds3* self = (physx::PxBounds3*) address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxBounds3*) address;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1getMinimum(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBounds3* self = (physx::PxBounds3*) address;
    return (jlong) &self->minimum;
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1setMinimum(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBounds3* self = (physx::PxBounds3*) address;
    self->minimum = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxBounds3__1getMaximum(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBounds3* self = (physx::PxBounds3*) address;
    return (jlong) &self->maximum;
}
JNIEXPORT void JNICALL Java_physx_common_PxBounds3__1setMaximum(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBounds3* self = (physx::PxBounds3*) address;
    self->maximum = *((physx::PxVec3*) value);
}

// PxCpuDispatcher
JNIEXPORT void JNICALL Java_physx_common_PxCpuDispatcher__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxCpuDispatcher*) address;
}

// PxDefaultErrorCallback
JNIEXPORT jlong JNICALL Java_physx_common_PxDefaultErrorCallback__1PxDefaultErrorCallback(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxDefaultErrorCallback();
}
JNIEXPORT void JNICALL Java_physx_common_PxDefaultErrorCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxDefaultErrorCallback*) address;
}

// PxFoundation

// PxPhysicsInsertionCallback

// PxQuat
JNIEXPORT jlong JNICALL Java_physx_common_PxQuat__1PxQuat__(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxQuat();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxQuat__1PxQuat__FFFF(JNIEnv* env, jclass, jfloat x, jfloat y, jfloat z, jfloat w) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxQuat(x, y, z, w);
}
JNIEXPORT void JNICALL Java_physx_common_PxQuat__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxQuat*) address;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxQuat__1getX(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxQuat* self = (physx::PxQuat*) address;
    return (jfloat) self->x;
}
JNIEXPORT void JNICALL Java_physx_common_PxQuat__1setX(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxQuat* self = (physx::PxQuat*) address;
    self->x = value;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxQuat__1getY(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxQuat* self = (physx::PxQuat*) address;
    return (jfloat) self->y;
}
JNIEXPORT void JNICALL Java_physx_common_PxQuat__1setY(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxQuat* self = (physx::PxQuat*) address;
    self->y = value;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxQuat__1getZ(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxQuat* self = (physx::PxQuat*) address;
    return (jfloat) self->z;
}
JNIEXPORT void JNICALL Java_physx_common_PxQuat__1setZ(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxQuat* self = (physx::PxQuat*) address;
    self->z = value;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxQuat__1getW(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxQuat* self = (physx::PxQuat*) address;
    return (jfloat) self->w;
}
JNIEXPORT void JNICALL Java_physx_common_PxQuat__1setW(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxQuat* self = (physx::PxQuat*) address;
    self->w = value;
}

// PxTolerancesScale
JNIEXPORT jlong JNICALL Java_physx_common_PxTolerancesScale__1PxTolerancesScale(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxTolerancesScale();
}
JNIEXPORT void JNICALL Java_physx_common_PxTolerancesScale__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxTolerancesScale*) address;
}

// PxTransform
JNIEXPORT jlong JNICALL Java_physx_common_PxTransform__1PxTransform__I(JNIEnv* env, jclass, jint r) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxTransform((PxIDENTITYEnum) r);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxTransform__1PxTransform__JJ(JNIEnv* env, jclass, jlong p0, jlong q0) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxTransform(*((physx::PxVec3*) p0), *((physx::PxQuat*) q0));
}
JNIEXPORT void JNICALL Java_physx_common_PxTransform__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxTransform*) address;
}
JNIEXPORT jlong JNICALL Java_physx_common_PxTransform__1getQ(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxTransform* self = (physx::PxTransform*) address;
    return (jlong) &self->q;
}
JNIEXPORT void JNICALL Java_physx_common_PxTransform__1setQ(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxTransform* self = (physx::PxTransform*) address;
    self->q = *((physx::PxQuat*) value);
}
JNIEXPORT jlong JNICALL Java_physx_common_PxTransform__1getP(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxTransform* self = (physx::PxTransform*) address;
    return (jlong) &self->p;
}
JNIEXPORT void JNICALL Java_physx_common_PxTransform__1setP(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxTransform* self = (physx::PxTransform*) address;
    self->p = *((physx::PxVec3*) value);
}

// PxRealPtr
JNIEXPORT void JNICALL Java_physx_common_PxRealPtr__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (PxRealPtr*) address;
}

// PxU8Ptr
JNIEXPORT void JNICALL Java_physx_common_PxU8Ptr__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (PxU8Ptr*) address;
}

// PxVec3
JNIEXPORT jlong JNICALL Java_physx_common_PxVec3__1PxVec3__(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxVec3();
}
JNIEXPORT jlong JNICALL Java_physx_common_PxVec3__1PxVec3__FFF(JNIEnv* env, jclass, jfloat x, jfloat y, jfloat z) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxVec3(x, y, z);
}
JNIEXPORT void JNICALL Java_physx_common_PxVec3__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxVec3*) address;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxVec3__1getX(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVec3* self = (physx::PxVec3*) address;
    return (jfloat) self->x;
}
JNIEXPORT void JNICALL Java_physx_common_PxVec3__1setX(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVec3* self = (physx::PxVec3*) address;
    self->x = value;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxVec3__1getY(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVec3* self = (physx::PxVec3*) address;
    return (jfloat) self->y;
}
JNIEXPORT void JNICALL Java_physx_common_PxVec3__1setY(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVec3* self = (physx::PxVec3*) address;
    self->y = value;
}
JNIEXPORT jfloat JNICALL Java_physx_common_PxVec3__1getZ(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVec3* self = (physx::PxVec3*) address;
    return (jfloat) self->z;
}
JNIEXPORT void JNICALL Java_physx_common_PxVec3__1setZ(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVec3* self = (physx::PxVec3*) address;
    self->z = value;
}

// PxBaseFlagEnum
JNIEXPORT jint JNICALL Java_physx_common_PxBaseFlagEnum__1geteOWNS_1MEMORY(JNIEnv*, jclass) {
    return PxBaseFlagEnum::eOWNS_MEMORY;
}
JNIEXPORT jint JNICALL Java_physx_common_PxBaseFlagEnum__1geteIS_1RELEASABLE(JNIEnv*, jclass) {
    return PxBaseFlagEnum::eIS_RELEASABLE;
}

// PxIDENTITYEnum
JNIEXPORT jint JNICALL Java_physx_common_PxIDENTITYEnum__1getPxIdentity(JNIEnv*, jclass) {
    return PxIDENTITYEnum::PxIdentity;
}

// PxConvexFlags
JNIEXPORT jlong JNICALL Java_physx_cooking_PxConvexFlags__1PxConvexFlags(JNIEnv* env, jclass, jshort flags) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxConvexFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_cooking_PxConvexFlags__1isSet(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxConvexFlags* self = (physx::PxConvexFlags*) address;
    return (jboolean) self->isSet((PxConvexFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_cooking_PxConvexFlags__1set(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxConvexFlags* self = (physx::PxConvexFlags*) address;
    self->set((PxConvexFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_cooking_PxConvexFlags__1clear(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxConvexFlags* self = (physx::PxConvexFlags*) address;
    self->clear((PxConvexFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_cooking_PxConvexFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxConvexFlags*) address;
}

// PxConvexMeshDesc
JNIEXPORT jlong JNICALL Java_physx_cooking_PxConvexMeshDesc__1PxConvexMeshDesc(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxConvexMeshDesc();
}
JNIEXPORT void JNICALL Java_physx_cooking_PxConvexMeshDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxConvexMeshDesc*) address;
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxConvexMeshDesc__1getPoints(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxConvexMeshDesc* self = (physx::PxConvexMeshDesc*) address;
    return (jlong) &self->points;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxConvexMeshDesc__1setPoints(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxConvexMeshDesc* self = (physx::PxConvexMeshDesc*) address;
    self->points = *((physx::PxBoundedData*) value);
}
JNIEXPORT jlong JNICALL Java_physx_cooking_PxConvexMeshDesc__1getFlags(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxConvexMeshDesc* self = (physx::PxConvexMeshDesc*) address;
    return (jlong) &self->flags;
}
JNIEXPORT void JNICALL Java_physx_cooking_PxConvexMeshDesc__1setFlags(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxConvexMeshDesc* self = (physx::PxConvexMeshDesc*) address;
    self->flags = *((physx::PxConvexFlags*) value);
}

// PxCooking
JNIEXPORT jlong JNICALL Java_physx_cooking_PxCooking__1createConvexMesh(JNIEnv* env, jclass, jlong address, jlong desc, jlong insertionCallback) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxCooking* self = (physx::PxCooking*) address;
    return (jlong) self->createConvexMesh(*((physx::PxConvexMeshDesc*) desc), *((physx::PxPhysicsInsertionCallback*) insertionCallback));
}

// PxCookingParams
JNIEXPORT jlong JNICALL Java_physx_cooking_PxCookingParams__1PxCookingParams(JNIEnv* env, jclass, jlong sc) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxCookingParams(*((physx::PxTolerancesScale*) sc));
}
JNIEXPORT void JNICALL Java_physx_cooking_PxCookingParams__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxCookingParams*) address;
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

// PxDefaultAllocator
JNIEXPORT jlong JNICALL Java_physx_extensions_PxDefaultAllocator__1PxDefaultAllocator(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxDefaultAllocator();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxDefaultAllocator__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxDefaultAllocator*) address;
}

// PxDefaultCpuDispatcher
JNIEXPORT void JNICALL Java_physx_extensions_PxDefaultCpuDispatcher__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxDefaultCpuDispatcher*) address;
}

// PxJoint

// PxRevoluteJoint
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setDriveVelocity__JF(JNIEnv* env, jclass, jlong address, jfloat velocity) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) address;
    self->setDriveVelocity(velocity);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setDriveVelocity__JFZ(JNIEnv* env, jclass, jlong address, jfloat velocity, jboolean autowake) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) address;
    self->setDriveVelocity(velocity, autowake);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxRevoluteJoint__1getDriveVelocity(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) address;
    return (jfloat) self->getDriveVelocity();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setDriveForceLimit(JNIEnv* env, jclass, jlong address, jfloat limit) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) address;
    self->setDriveForceLimit(limit);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxRevoluteJoint__1getDriveForceLimit(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) address;
    return (jfloat) self->getDriveForceLimit();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setDriveGearRatio(JNIEnv* env, jclass, jlong address, jfloat ratio) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) address;
    self->setDriveGearRatio(ratio);
}
JNIEXPORT jfloat JNICALL Java_physx_extensions_PxRevoluteJoint__1getDriveGearRatio(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) address;
    return (jfloat) self->getDriveGearRatio();
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1setRevoluteJointFlags(JNIEnv* env, jclass, jlong address, jlong flags) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) address;
    self->setRevoluteJointFlags(*((physx::PxRevoluteJointFlags*) flags));
}
JNIEXPORT jlong JNICALL Java_physx_extensions_PxRevoluteJoint__1getRevoluteJointFlags(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxRevoluteJointFlags cache;
    physx::PxRevoluteJoint* self = (physx::PxRevoluteJoint*) address;
    cache = self->getRevoluteJointFlags();
    return (jlong) &cache;
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJoint__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxRevoluteJoint*) address;
}

// PxRevoluteJointFlags
JNIEXPORT jlong JNICALL Java_physx_extensions_PxRevoluteJointFlags__1PxRevoluteJointFlags(JNIEnv* env, jclass, jshort flags) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxRevoluteJointFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_extensions_PxRevoluteJointFlags__1isSet(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRevoluteJointFlags* self = (physx::PxRevoluteJointFlags*) address;
    return (jboolean) self->isSet((PxRevoluteJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJointFlags__1set(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRevoluteJointFlags* self = (physx::PxRevoluteJointFlags*) address;
    self->set((PxRevoluteJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJointFlags__1clear(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRevoluteJointFlags* self = (physx::PxRevoluteJointFlags*) address;
    self->clear((PxRevoluteJointFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_extensions_PxRevoluteJointFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxRevoluteJointFlags*) address;
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

// PxBoxGeometry
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxBoxGeometry__1PxBoxGeometry(JNIEnv* env, jclass, jfloat hx, jfloat hy, jfloat hz) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxBoxGeometry(hx, hy, hz);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxBoxGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxBoxGeometry*) address;
}

// PxBVHStructure

// PxCapsuleGeometry
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxCapsuleGeometry__1PxCapsuleGeometry(JNIEnv* env, jclass, jfloat radius, jfloat halfHeight) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxCapsuleGeometry(radius, halfHeight);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxCapsuleGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxCapsuleGeometry*) address;
}

// PxConvexMesh
JNIEXPORT jint JNICALL Java_physx_geomutils_PxConvexMesh__1getNbVertices(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) address;
    return (jint) self->getNbVertices();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxConvexMesh__1getVertices(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) address;
    return (jlong) self->getVertices();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxConvexMesh__1getIndexBuffer(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static PxU8Ptr cache;
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) address;
    cache = self->getIndexBuffer();
    return (jlong) &cache;
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxConvexMesh__1getNbPolygons(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) address;
    return (jint) self->getNbPolygons();
}
JNIEXPORT jboolean JNICALL Java_physx_geomutils_PxConvexMesh__1getPolygonData(JNIEnv* env, jclass, jlong address, jint index, jlong data) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) address;
    return (jboolean) self->getPolygonData(index, *((physx::PxHullPolygon*) data));
}
JNIEXPORT jint JNICALL Java_physx_geomutils_PxConvexMesh__1getReferenceCount(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) address;
    return (jint) self->getReferenceCount();
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxConvexMesh__1acquireReference(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) address;
    self->acquireReference();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxConvexMesh__1getLocalBounds(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxBounds3 cache;
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) address;
    cache = self->getLocalBounds();
    return (jlong) &cache;
}
JNIEXPORT jboolean JNICALL Java_physx_geomutils_PxConvexMesh__1isGpuCompatible(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxConvexMesh* self = (physx::PxConvexMesh*) address;
    return (jboolean) self->isGpuCompatible();
}

// PxConvexMeshGeometry
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxConvexMeshGeometry__1PxConvexMeshGeometry__J(JNIEnv* env, jclass, jlong mesh) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxConvexMeshGeometry((physx::PxConvexMesh*) mesh);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxConvexMeshGeometry__1PxConvexMeshGeometry__JJ(JNIEnv* env, jclass, jlong mesh, jlong scaling) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxConvexMeshGeometry((physx::PxConvexMesh*) mesh, *((physx::PxMeshScale*) scaling));
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxConvexMeshGeometry__1PxConvexMeshGeometry__JJJ(JNIEnv* env, jclass, jlong mesh, jlong scaling, jlong flags) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxConvexMeshGeometry((physx::PxConvexMesh*) mesh, *((physx::PxMeshScale*) scaling), *((physx::PxConvexMeshGeometryFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxConvexMeshGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxConvexMeshGeometry*) address;
}

// PxConvexMeshGeometryFlags
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxConvexMeshGeometryFlags__1PxConvexMeshGeometryFlags(JNIEnv* env, jclass, jbyte flags) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxConvexMeshGeometryFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_geomutils_PxConvexMeshGeometryFlags__1isSet(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxConvexMeshGeometryFlags* self = (physx::PxConvexMeshGeometryFlags*) address;
    return (jboolean) self->isSet((PxConvexMeshGeometryFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxConvexMeshGeometryFlags__1set(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxConvexMeshGeometryFlags* self = (physx::PxConvexMeshGeometryFlags*) address;
    self->set((PxConvexMeshGeometryFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxConvexMeshGeometryFlags__1clear(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxConvexMeshGeometryFlags* self = (physx::PxConvexMeshGeometryFlags*) address;
    self->clear((PxConvexMeshGeometryFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxConvexMeshGeometryFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxConvexMeshGeometryFlags*) address;
}

// PxGeometry
JNIEXPORT void JNICALL Java_physx_geomutils_PxGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxGeometry*) address;
}

// PxHullPolygon
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxHullPolygon__1PxHullPolygon(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxHullPolygon();
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHullPolygon__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxHullPolygon*) address;
}
JNIEXPORT jfloat JNICALL Java_physx_geomutils_PxHullPolygon__1getMPlane(JNIEnv* env, jclass, jlong address, jint index) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxHullPolygon* self = (physx::PxHullPolygon*) address;
    return (jfloat) self->mPlane[index];
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHullPolygon__1setMPlane(JNIEnv* env, jclass, jlong address, jint index, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxHullPolygon* self = (physx::PxHullPolygon*) address;
    self->mPlane[index] = value;
}
JNIEXPORT jshort JNICALL Java_physx_geomutils_PxHullPolygon__1getMNbVerts(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxHullPolygon* self = (physx::PxHullPolygon*) address;
    return (jshort) self->mNbVerts;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHullPolygon__1setMNbVerts(JNIEnv* env, jclass, jlong address, jshort value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxHullPolygon* self = (physx::PxHullPolygon*) address;
    self->mNbVerts = value;
}
JNIEXPORT jshort JNICALL Java_physx_geomutils_PxHullPolygon__1getMIndexBase(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxHullPolygon* self = (physx::PxHullPolygon*) address;
    return (jshort) self->mIndexBase;
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxHullPolygon__1setMIndexBase(JNIEnv* env, jclass, jlong address, jshort value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxHullPolygon* self = (physx::PxHullPolygon*) address;
    self->mIndexBase = value;
}

// PxMeshScale
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxMeshScale__1PxMeshScale__(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxMeshScale();
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxMeshScale__1PxMeshScale__F(JNIEnv* env, jclass, jfloat r) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxMeshScale(r);
}
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxMeshScale__1PxMeshScale__JJ(JNIEnv* env, jclass, jlong s, jlong r) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxMeshScale(*((physx::PxVec3*) s), *((physx::PxQuat*) r));
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxMeshScale__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxMeshScale*) address;
}

// PxPlaneGeometry
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxPlaneGeometry__1PxPlaneGeometry(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxPlaneGeometry();
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxPlaneGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxPlaneGeometry*) address;
}

// PxSphereGeometry
JNIEXPORT jlong JNICALL Java_physx_geomutils_PxSphereGeometry__1PxSphereGeometry(JNIEnv* env, jclass, jfloat ir) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxSphereGeometry(ir);
}
JNIEXPORT void JNICALL Java_physx_geomutils_PxSphereGeometry__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxSphereGeometry*) address;
}

// PxConvexMeshGeometryFlagEnum
JNIEXPORT jint JNICALL Java_physx_geomutils_PxConvexMeshGeometryFlagEnum__1geteTIGHT_1BOUNDS(JNIEnv*, jclass) {
    return PxConvexMeshGeometryFlagEnum::eTIGHT_BOUNDS;
}

// PxActor
JNIEXPORT jint JNICALL Java_physx_physics_PxActor__1getType(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxActor* self = (physx::PxActor*) address;
    return (PxActorTypeEnum) self->getType();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActor__1getScene(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxActor* self = (physx::PxActor*) address;
    return (jlong) self->getScene();
}
JNIEXPORT void JNICALL Java_physx_physics_PxActor__1setName(JNIEnv* env, jclass, jlong address, jstring name) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxActor* self = (physx::PxActor*) address;
    self->setName(env->GetStringUTFChars(name, 0));
}
JNIEXPORT jstring JNICALL Java_physx_physics_PxActor__1getName(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxActor* self = (physx::PxActor*) address;
    return env->NewStringUTF(self->getName());
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActor__1getWorldBounds__J(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxBounds3 cache;
    physx::PxActor* self = (physx::PxActor*) address;
    cache = self->getWorldBounds();
    return (jlong) &cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActor__1getWorldBounds__JF(JNIEnv* env, jclass, jlong address, jfloat inflation) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxBounds3 cache;
    physx::PxActor* self = (physx::PxActor*) address;
    cache = self->getWorldBounds(inflation);
    return (jlong) &cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxActor__1setActorFlags(JNIEnv* env, jclass, jlong address, jlong flags) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxActor* self = (physx::PxActor*) address;
    self->setActorFlags(*((physx::PxActorFlags*) flags));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActor__1getActorFlags(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxActorFlags cache;
    physx::PxActor* self = (physx::PxActor*) address;
    cache = self->getActorFlags();
    return (jlong) &cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxActor__1setDominanceGroup(JNIEnv* env, jclass, jlong address, jbyte dominanceGroup) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxActor* self = (physx::PxActor*) address;
    self->setDominanceGroup(dominanceGroup);
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxActor__1getDominanceGroup(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxActor* self = (physx::PxActor*) address;
    return (jbyte) self->getDominanceGroup();
}
JNIEXPORT void JNICALL Java_physx_physics_PxActor__1setOwnerClient(JNIEnv* env, jclass, jlong address, jbyte inClient) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxActor* self = (physx::PxActor*) address;
    self->setOwnerClient(inClient);
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxActor__1getOwnerClient(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxActor* self = (physx::PxActor*) address;
    return (jbyte) self->getOwnerClient();
}

// PxActorFlags
JNIEXPORT jlong JNICALL Java_physx_physics_PxActorFlags__1PxActorFlags(JNIEnv* env, jclass, jbyte flags) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxActorFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxActorFlags__1isSet(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxActorFlags* self = (physx::PxActorFlags*) address;
    return (jboolean) self->isSet((PxActorFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxActorFlags__1set(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxActorFlags* self = (physx::PxActorFlags*) address;
    self->set((PxActorFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxActorFlags__1clear(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxActorFlags* self = (physx::PxActorFlags*) address;
    self->clear((PxActorFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxActorFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxActorFlags*) address;
}

// PxActorShape
JNIEXPORT void JNICALL Java_physx_physics_PxActorShape__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxActorShape*) address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActorShape__1getActor(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxActorShape* self = (physx::PxActorShape*) address;
    return (jlong) self->actor;
}
JNIEXPORT void JNICALL Java_physx_physics_PxActorShape__1setActor(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxActorShape* self = (physx::PxActorShape*) address;
    self->actor = (physx::PxRigidActor*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxActorShape__1getShape(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxActorShape* self = (physx::PxActorShape*) address;
    return (jlong) self->shape;
}
JNIEXPORT void JNICALL Java_physx_physics_PxActorShape__1setShape(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxActorShape* self = (physx::PxActorShape*) address;
    self->shape = (physx::PxShape*) value;
}

// PxBatchQuery
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQuery__1execute(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQuery* self = (physx::PxBatchQuery*) address;
    self->execute();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQuery__1getPreFilterShader(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxBatchQueryPreFilterShader cache;
    physx::PxBatchQuery* self = (physx::PxBatchQuery*) address;
    cache = self->getPreFilterShader();
    return (jlong) &cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQuery__1getPostFilterShader(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxBatchQueryPostFilterShader cache;
    physx::PxBatchQuery* self = (physx::PxBatchQuery*) address;
    cache = self->getPostFilterShader();
    return (jlong) &cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQuery__1getFilterShaderData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQuery* self = (physx::PxBatchQuery*) address;
    return (jlong) self->getFilterShaderData();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBatchQuery__1getFilterShaderDataSize(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQuery* self = (physx::PxBatchQuery*) address;
    return (jint) self->getFilterShaderDataSize();
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQuery__1setUserMemory(JNIEnv* env, jclass, jlong address, jlong userMemory) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQuery* self = (physx::PxBatchQuery*) address;
    self->setUserMemory(*((physx::PxBatchQueryMemory*) userMemory));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQuery__1getUserMemory(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQuery* self = (physx::PxBatchQuery*) address;
    return (jlong) &self->getUserMemory();
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQuery__1release(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQuery* self = (physx::PxBatchQuery*) address;
    self->release();
}

// PxBatchQueryDesc
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryDesc__1PxBatchQueryDesc(JNIEnv* env, jclass, jint maxRaycastsPerExecute, jint maxSweepsPerExecute, jint maxOverlapsPerExecute) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxBatchQueryDesc(maxRaycastsPerExecute, maxSweepsPerExecute, maxOverlapsPerExecute);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxBatchQueryDesc__1isValid(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryDesc* self = (physx::PxBatchQueryDesc*) address;
    return (jboolean) self->isValid();
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxBatchQueryDesc*) address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryDesc__1getFilterShaderData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryDesc* self = (physx::PxBatchQueryDesc*) address;
    return (jlong) self->filterShaderData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryDesc__1setFilterShaderData(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryDesc* self = (physx::PxBatchQueryDesc*) address;
    self->filterShaderData = (void*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBatchQueryDesc__1getFilterShaderDataSize(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryDesc* self = (physx::PxBatchQueryDesc*) address;
    return (jint) self->filterShaderDataSize;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryDesc__1setFilterShaderDataSize(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryDesc* self = (physx::PxBatchQueryDesc*) address;
    self->filterShaderDataSize = value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryDesc__1getPreFilterShader(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryDesc* self = (physx::PxBatchQueryDesc*) address;
    return (jlong) &self->preFilterShader;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryDesc__1setPreFilterShader(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryDesc* self = (physx::PxBatchQueryDesc*) address;
    self->preFilterShader = *((physx::PxBatchQueryPreFilterShader*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryDesc__1getPostFilterShader(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryDesc* self = (physx::PxBatchQueryDesc*) address;
    return (jlong) &self->postFilterShader;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryDesc__1setPostFilterShader(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryDesc* self = (physx::PxBatchQueryDesc*) address;
    self->postFilterShader = *((physx::PxBatchQueryPostFilterShader*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryDesc__1getQueryMemory(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryDesc* self = (physx::PxBatchQueryDesc*) address;
    return (jlong) &self->queryMemory;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryDesc__1setQueryMemory(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryDesc* self = (physx::PxBatchQueryDesc*) address;
    self->queryMemory = *((physx::PxBatchQueryMemory*) value);
}

// PxBatchQueryMemory
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryMemory__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxBatchQueryMemory*) address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryMemory__1getUserRaycastResultBuffer(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryMemory* self = (physx::PxBatchQueryMemory*) address;
    return (jlong) self->userRaycastResultBuffer;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryMemory__1setUserRaycastResultBuffer(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryMemory* self = (physx::PxBatchQueryMemory*) address;
    self->userRaycastResultBuffer = (physx::PxRaycastQueryResult*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryMemory__1getUserRaycastTouchBuffer(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryMemory* self = (physx::PxBatchQueryMemory*) address;
    return (jlong) self->userRaycastTouchBuffer;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryMemory__1setUserRaycastTouchBuffer(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryMemory* self = (physx::PxBatchQueryMemory*) address;
    self->userRaycastTouchBuffer = (physx::PxRaycastHit*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryMemory__1getUserSweepResultBuffer(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryMemory* self = (physx::PxBatchQueryMemory*) address;
    return (jlong) self->userSweepResultBuffer;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryMemory__1setUserSweepResultBuffer(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryMemory* self = (physx::PxBatchQueryMemory*) address;
    self->userSweepResultBuffer = (physx::PxSweepQueryResult*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryMemory__1getUserSweepTouchBuffer(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryMemory* self = (physx::PxBatchQueryMemory*) address;
    return (jlong) self->userSweepTouchBuffer;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryMemory__1setUserSweepTouchBuffer(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryMemory* self = (physx::PxBatchQueryMemory*) address;
    self->userSweepTouchBuffer = (physx::PxSweepHit*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryMemory__1getUserOverlapResultBuffer(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryMemory* self = (physx::PxBatchQueryMemory*) address;
    return (jlong) self->userOverlapResultBuffer;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryMemory__1setUserOverlapResultBuffer(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryMemory* self = (physx::PxBatchQueryMemory*) address;
    self->userOverlapResultBuffer = (physx::PxOverlapQueryResult*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxBatchQueryMemory__1getUserOverlapTouchBuffer(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryMemory* self = (physx::PxBatchQueryMemory*) address;
    return (jlong) self->userOverlapTouchBuffer;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryMemory__1setUserOverlapTouchBuffer(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryMemory* self = (physx::PxBatchQueryMemory*) address;
    self->userOverlapTouchBuffer = (physx::PxOverlapHit*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBatchQueryMemory__1getRaycastTouchBufferSize(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryMemory* self = (physx::PxBatchQueryMemory*) address;
    return (jint) self->raycastTouchBufferSize;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryMemory__1setRaycastTouchBufferSize(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryMemory* self = (physx::PxBatchQueryMemory*) address;
    self->raycastTouchBufferSize = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBatchQueryMemory__1getSweepTouchBufferSize(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryMemory* self = (physx::PxBatchQueryMemory*) address;
    return (jint) self->sweepTouchBufferSize;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryMemory__1setSweepTouchBufferSize(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryMemory* self = (physx::PxBatchQueryMemory*) address;
    self->sweepTouchBufferSize = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxBatchQueryMemory__1getOverlapTouchBufferSize(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryMemory* self = (physx::PxBatchQueryMemory*) address;
    return (jint) self->overlapTouchBufferSize;
}
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryMemory__1setOverlapTouchBufferSize(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxBatchQueryMemory* self = (physx::PxBatchQueryMemory*) address;
    self->overlapTouchBufferSize = value;
}

// PxBatchQueryPostFilterShader
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryPostFilterShader__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxBatchQueryPostFilterShader*) address;
}

// PxBatchQueryPreFilterShader
JNIEXPORT void JNICALL Java_physx_physics_PxBatchQueryPreFilterShader__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxBatchQueryPreFilterShader*) address;
}

// PxFilterData
JNIEXPORT jlong JNICALL Java_physx_physics_PxFilterData__1PxFilterData__(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxFilterData();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxFilterData__1PxFilterData__IIII(JNIEnv* env, jclass, jint w0, jint w1, jint w2, jint w3) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxFilterData(w0, w1, w2, w3);
}
JNIEXPORT void JNICALL Java_physx_physics_PxFilterData__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxFilterData*) address;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFilterData__1getWord0(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxFilterData* self = (physx::PxFilterData*) address;
    return (jint) self->word0;
}
JNIEXPORT void JNICALL Java_physx_physics_PxFilterData__1setWord0(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxFilterData* self = (physx::PxFilterData*) address;
    self->word0 = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFilterData__1getWord1(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxFilterData* self = (physx::PxFilterData*) address;
    return (jint) self->word1;
}
JNIEXPORT void JNICALL Java_physx_physics_PxFilterData__1setWord1(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxFilterData* self = (physx::PxFilterData*) address;
    self->word1 = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFilterData__1getWord2(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxFilterData* self = (physx::PxFilterData*) address;
    return (jint) self->word2;
}
JNIEXPORT void JNICALL Java_physx_physics_PxFilterData__1setWord2(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxFilterData* self = (physx::PxFilterData*) address;
    self->word2 = value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxFilterData__1getWord3(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxFilterData* self = (physx::PxFilterData*) address;
    return (jint) self->word3;
}
JNIEXPORT void JNICALL Java_physx_physics_PxFilterData__1setWord3(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxFilterData* self = (physx::PxFilterData*) address;
    self->word3 = value;
}

// PxHitFlags
JNIEXPORT jlong JNICALL Java_physx_physics_PxHitFlags__1PxHitFlags(JNIEnv* env, jclass, jshort flags) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxHitFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxHitFlags__1isSet(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxHitFlags* self = (physx::PxHitFlags*) address;
    return (jboolean) self->isSet((PxHitFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxHitFlags__1set(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxHitFlags* self = (physx::PxHitFlags*) address;
    self->set((PxHitFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxHitFlags__1clear(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxHitFlags* self = (physx::PxHitFlags*) address;
    self->clear((PxHitFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxHitFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxHitFlags*) address;
}

// PxLocationHit
JNIEXPORT void JNICALL Java_physx_physics_PxLocationHit__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxLocationHit*) address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxLocationHit__1getFlags(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxLocationHit* self = (physx::PxLocationHit*) address;
    return (jlong) &self->flags;
}
JNIEXPORT void JNICALL Java_physx_physics_PxLocationHit__1setFlags(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxLocationHit* self = (physx::PxLocationHit*) address;
    self->flags = *((physx::PxHitFlags*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxLocationHit__1getPosition(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxLocationHit* self = (physx::PxLocationHit*) address;
    return (jlong) &self->position;
}
JNIEXPORT void JNICALL Java_physx_physics_PxLocationHit__1setPosition(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxLocationHit* self = (physx::PxLocationHit*) address;
    self->position = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxLocationHit__1getNormal(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxLocationHit* self = (physx::PxLocationHit*) address;
    return (jlong) &self->normal;
}
JNIEXPORT void JNICALL Java_physx_physics_PxLocationHit__1setNormal(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxLocationHit* self = (physx::PxLocationHit*) address;
    self->normal = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxLocationHit__1getDistance(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxLocationHit* self = (physx::PxLocationHit*) address;
    return (jfloat) self->distance;
}
JNIEXPORT void JNICALL Java_physx_physics_PxLocationHit__1setDistance(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxLocationHit* self = (physx::PxLocationHit*) address;
    self->distance = value;
}

// PxOverlapHit
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapHit__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxOverlapHit*) address;
}

// PxOverlapQueryResult
JNIEXPORT jint JNICALL Java_physx_physics_PxOverlapQueryResult__1getNbAnyHits(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxOverlapQueryResult* self = (physx::PxOverlapQueryResult*) address;
    return (jint) self->getNbAnyHits();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapQueryResult__1getAnyHit(JNIEnv* env, jclass, jlong address, jint index) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxOverlapQueryResult* self = (physx::PxOverlapQueryResult*) address;
    return (jlong) &self->getAnyHit(index);
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapQueryResult__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxOverlapQueryResult*) address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapQueryResult__1getBlock(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxOverlapQueryResult* self = (physx::PxOverlapQueryResult*) address;
    return (jlong) &self->block;
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapQueryResult__1setBlock(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxOverlapQueryResult* self = (physx::PxOverlapQueryResult*) address;
    self->block = *((physx::PxOverlapHit*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapQueryResult__1getTouches(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxOverlapQueryResult* self = (physx::PxOverlapQueryResult*) address;
    return (jlong) self->touches;
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapQueryResult__1setTouches(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxOverlapQueryResult* self = (physx::PxOverlapQueryResult*) address;
    self->touches = (physx::PxOverlapHit*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxOverlapQueryResult__1getNbTouches(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxOverlapQueryResult* self = (physx::PxOverlapQueryResult*) address;
    return (jint) self->nbTouches;
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapQueryResult__1setNbTouches(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxOverlapQueryResult* self = (physx::PxOverlapQueryResult*) address;
    self->nbTouches = value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxOverlapQueryResult__1getUserData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxOverlapQueryResult* self = (physx::PxOverlapQueryResult*) address;
    return (jlong) self->userData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapQueryResult__1setUserData(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxOverlapQueryResult* self = (physx::PxOverlapQueryResult*) address;
    self->userData = (void*) value;
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxOverlapQueryResult__1getQueryStatus(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxOverlapQueryResult* self = (physx::PxOverlapQueryResult*) address;
    return (jbyte) self->queryStatus;
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapQueryResult__1setQueryStatus(JNIEnv* env, jclass, jlong address, jbyte value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxOverlapQueryResult* self = (physx::PxOverlapQueryResult*) address;
    self->queryStatus = value;
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxOverlapQueryResult__1getHasBlock(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxOverlapQueryResult* self = (physx::PxOverlapQueryResult*) address;
    return (jboolean) self->hasBlock;
}
JNIEXPORT void JNICALL Java_physx_physics_PxOverlapQueryResult__1setHasBlock(JNIEnv* env, jclass, jlong address, jboolean value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxOverlapQueryResult* self = (physx::PxOverlapQueryResult*) address;
    self->hasBlock = value;
}

// PxMaterial

// PxPhysics
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1getFoundation(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxPhysics* self = (physx::PxPhysics*) address;
    return (jlong) &self->getFoundation();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1getTolerancesScale(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxPhysics* self = (physx::PxPhysics*) address;
    return (jlong) &self->getTolerancesScale();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createScene(JNIEnv* env, jclass, jlong address, jlong sceneDesc) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxPhysics* self = (physx::PxPhysics*) address;
    return (jlong) self->createScene(*((physx::PxSceneDesc*) sceneDesc));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createRigidStatic(JNIEnv* env, jclass, jlong address, jlong pose) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxPhysics* self = (physx::PxPhysics*) address;
    return (jlong) self->createRigidStatic(*((physx::PxTransform*) pose));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createRigidDynamic(JNIEnv* env, jclass, jlong address, jlong pose) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxPhysics* self = (physx::PxPhysics*) address;
    return (jlong) self->createRigidDynamic(*((physx::PxTransform*) pose));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createShape__JJJ(JNIEnv* env, jclass, jlong address, jlong geometry, jlong material) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxPhysics* self = (physx::PxPhysics*) address;
    return (jlong) self->createShape(*((physx::PxGeometry*) geometry), *((physx::PxMaterial*) material));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createShape__JJJZ(JNIEnv* env, jclass, jlong address, jlong geometry, jlong material, jboolean isExclusive) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxPhysics* self = (physx::PxPhysics*) address;
    return (jlong) self->createShape(*((physx::PxGeometry*) geometry), *((physx::PxMaterial*) material), isExclusive);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createShape__JJJZJ(JNIEnv* env, jclass, jlong address, jlong geometry, jlong material, jboolean isExclusive, jlong shapeFlags) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxPhysics* self = (physx::PxPhysics*) address;
    return (jlong) self->createShape(*((physx::PxGeometry*) geometry), *((physx::PxMaterial*) material), isExclusive, *((physx::PxShapeFlags*) shapeFlags));
}
JNIEXPORT jint JNICALL Java_physx_physics_PxPhysics__1getNbShapes(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxPhysics* self = (physx::PxPhysics*) address;
    return (jint) self->getNbShapes();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1createMaterial(JNIEnv* env, jclass, jlong address, jfloat staticFriction, jfloat dynamicFriction, jfloat restitution) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxPhysics* self = (physx::PxPhysics*) address;
    return (jlong) self->createMaterial(staticFriction, dynamicFriction, restitution);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxPhysics__1getPhysicsInsertionCallback(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxPhysics* self = (physx::PxPhysics*) address;
    return (jlong) &self->getPhysicsInsertionCallback();
}
JNIEXPORT void JNICALL Java_physx_physics_PxPhysics__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxPhysics*) address;
}

// PxQueryHit
JNIEXPORT void JNICALL Java_physx_physics_PxQueryHit__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxQueryHit*) address;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxQueryHit__1getFaceIndex(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxQueryHit* self = (physx::PxQueryHit*) address;
    return (jint) self->faceIndex;
}
JNIEXPORT void JNICALL Java_physx_physics_PxQueryHit__1setFaceIndex(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxQueryHit* self = (physx::PxQueryHit*) address;
    self->faceIndex = value;
}

// PxRaycastHit
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastHit__1PxRaycastHit(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxRaycastHit();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastHit__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxRaycastHit*) address;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRaycastHit__1getU(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRaycastHit* self = (physx::PxRaycastHit*) address;
    return (jfloat) self->u;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastHit__1setU(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRaycastHit* self = (physx::PxRaycastHit*) address;
    self->u = value;
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRaycastHit__1getV(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRaycastHit* self = (physx::PxRaycastHit*) address;
    return (jfloat) self->v;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastHit__1setV(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRaycastHit* self = (physx::PxRaycastHit*) address;
    self->v = value;
}

// PxRaycastQueryResult
JNIEXPORT jint JNICALL Java_physx_physics_PxRaycastQueryResult__1getNbAnyHits(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRaycastQueryResult* self = (physx::PxRaycastQueryResult*) address;
    return (jint) self->getNbAnyHits();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastQueryResult__1getAnyHit(JNIEnv* env, jclass, jlong address, jint index) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRaycastQueryResult* self = (physx::PxRaycastQueryResult*) address;
    return (jlong) &self->getAnyHit(index);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastQueryResult__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxRaycastQueryResult*) address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastQueryResult__1getBlock(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRaycastQueryResult* self = (physx::PxRaycastQueryResult*) address;
    return (jlong) &self->block;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastQueryResult__1setBlock(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRaycastQueryResult* self = (physx::PxRaycastQueryResult*) address;
    self->block = *((physx::PxRaycastHit*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastQueryResult__1getTouches(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRaycastQueryResult* self = (physx::PxRaycastQueryResult*) address;
    return (jlong) self->touches;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastQueryResult__1setTouches(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRaycastQueryResult* self = (physx::PxRaycastQueryResult*) address;
    self->touches = (physx::PxRaycastHit*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRaycastQueryResult__1getNbTouches(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRaycastQueryResult* self = (physx::PxRaycastQueryResult*) address;
    return (jint) self->nbTouches;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastQueryResult__1setNbTouches(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRaycastQueryResult* self = (physx::PxRaycastQueryResult*) address;
    self->nbTouches = value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRaycastQueryResult__1getUserData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRaycastQueryResult* self = (physx::PxRaycastQueryResult*) address;
    return (jlong) self->userData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastQueryResult__1setUserData(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRaycastQueryResult* self = (physx::PxRaycastQueryResult*) address;
    self->userData = (void*) value;
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxRaycastQueryResult__1getQueryStatus(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRaycastQueryResult* self = (physx::PxRaycastQueryResult*) address;
    return (jbyte) self->queryStatus;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastQueryResult__1setQueryStatus(JNIEnv* env, jclass, jlong address, jbyte value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRaycastQueryResult* self = (physx::PxRaycastQueryResult*) address;
    self->queryStatus = value;
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxRaycastQueryResult__1getHasBlock(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRaycastQueryResult* self = (physx::PxRaycastQueryResult*) address;
    return (jboolean) self->hasBlock;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRaycastQueryResult__1setHasBlock(JNIEnv* env, jclass, jlong address, jboolean value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRaycastQueryResult* self = (physx::PxRaycastQueryResult*) address;
    self->hasBlock = value;
}

// PxRigidActor
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidActor__1getGlobalPose(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxTransform cache;
    physx::PxRigidActor* self = (physx::PxRigidActor*) address;
    cache = self->getGlobalPose();
    return (jlong) &cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidActor__1setGlobalPose__JJ(JNIEnv* env, jclass, jlong address, jlong pose) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidActor* self = (physx::PxRigidActor*) address;
    self->setGlobalPose(*((physx::PxTransform*) pose));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidActor__1setGlobalPose__JJZ(JNIEnv* env, jclass, jlong address, jlong pose, jboolean autowake) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidActor* self = (physx::PxRigidActor*) address;
    self->setGlobalPose(*((physx::PxTransform*) pose), autowake);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxRigidActor__1attachShape(JNIEnv* env, jclass, jlong address, jlong shape) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidActor* self = (physx::PxRigidActor*) address;
    return (jboolean) self->attachShape(*((physx::PxShape*) shape));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidActor__1detachShape__JJ(JNIEnv* env, jclass, jlong address, jlong shape) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidActor* self = (physx::PxRigidActor*) address;
    self->detachShape(*((physx::PxShape*) shape));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidActor__1detachShape__JJZ(JNIEnv* env, jclass, jlong address, jlong shape, jboolean wakeOnLostTouch) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidActor* self = (physx::PxRigidActor*) address;
    self->detachShape(*((physx::PxShape*) shape), wakeOnLostTouch);
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidActor__1getNbShapes(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidActor* self = (physx::PxRigidActor*) address;
    return (jint) self->getNbShapes();
}

// PxRigidBody
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setCMassLocalPose(JNIEnv* env, jclass, jlong address, jlong pose) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->setCMassLocalPose(*((physx::PxTransform*) pose));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBody__1getCMassLocalPose(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxTransform cache;
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    cache = self->getCMassLocalPose();
    return (jlong) &cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setMass(JNIEnv* env, jclass, jlong address, jfloat mass) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->setMass(mass);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getMass(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    return (jfloat) self->getMass();
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getInvMass(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    return (jfloat) self->getInvMass();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setMassSpaceInertiaTensor(JNIEnv* env, jclass, jlong address, jlong m) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->setMassSpaceInertiaTensor(*((physx::PxVec3*) m));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBody__1getMassSpaceInertiaTensor(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxVec3 cache;
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    cache = self->getMassSpaceInertiaTensor();
    return (jlong) &cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBody__1getMassSpaceInvInertiaTensor(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxVec3 cache;
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    cache = self->getMassSpaceInvInertiaTensor();
    return (jlong) &cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setLinearDamping(JNIEnv* env, jclass, jlong address, jfloat linDamp) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->setLinearDamping(linDamp);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getLinearDamping(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    return (jfloat) self->getLinearDamping();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setAngularDamping(JNIEnv* env, jclass, jlong address, jfloat angDamp) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->setAngularDamping(angDamp);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getAngularDamping(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    return (jfloat) self->getAngularDamping();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBody__1getLinearVelocity(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxVec3 cache;
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    cache = self->getLinearVelocity();
    return (jlong) &cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setLinearVelocity__JJ(JNIEnv* env, jclass, jlong address, jlong linVel) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->setLinearVelocity(*((physx::PxVec3*) linVel));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setLinearVelocity__JJZ(JNIEnv* env, jclass, jlong address, jlong linVel, jboolean autowake) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->setLinearVelocity(*((physx::PxVec3*) linVel), autowake);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBody__1getAngularVelocity(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxVec3 cache;
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    cache = self->getAngularVelocity();
    return (jlong) &cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setAngularVelocity__JJ(JNIEnv* env, jclass, jlong address, jlong angVel) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->setAngularVelocity(*((physx::PxVec3*) angVel));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setAngularVelocity__JJZ(JNIEnv* env, jclass, jlong address, jlong angVel, jboolean autowake) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->setAngularVelocity(*((physx::PxVec3*) angVel), autowake);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getMaxLinearVelocity(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    return (jfloat) self->getMaxLinearVelocity();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setMaxLinearVelocity(JNIEnv* env, jclass, jlong address, jfloat maxLinVel) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->setMaxLinearVelocity(maxLinVel);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getMaxAngularVelocity(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    return (jfloat) self->getMaxAngularVelocity();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setMaxAngularVelocity(JNIEnv* env, jclass, jlong address, jfloat maxAngVel) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->setMaxAngularVelocity(maxAngVel);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1addForce__JJ(JNIEnv* env, jclass, jlong address, jlong force) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->addForce(*((physx::PxVec3*) force));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1addForce__JJI(JNIEnv* env, jclass, jlong address, jlong force, jint mode) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->addForce(*((physx::PxVec3*) force), (PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1addForce__JJIZ(JNIEnv* env, jclass, jlong address, jlong force, jint mode, jboolean autowake) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->addForce(*((physx::PxVec3*) force), (PxForceModeEnum) mode, autowake);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1addTorque__JJ(JNIEnv* env, jclass, jlong address, jlong torque) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->addTorque(*((physx::PxVec3*) torque));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1addTorque__JJI(JNIEnv* env, jclass, jlong address, jlong torque, jint mode) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->addTorque(*((physx::PxVec3*) torque), (PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1addTorque__JJIZ(JNIEnv* env, jclass, jlong address, jlong torque, jint mode, jboolean autowake) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->addTorque(*((physx::PxVec3*) torque), (PxForceModeEnum) mode, autowake);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1clearForce(JNIEnv* env, jclass, jlong address, jint mode) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->clearForce((PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1clearTorque(JNIEnv* env, jclass, jlong address, jint mode) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->clearTorque((PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setForceAndTorque__JJJ(JNIEnv* env, jclass, jlong address, jlong force, jlong torque) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->setForceAndTorque(*((physx::PxVec3*) force), *((physx::PxVec3*) torque));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setForceAndTorque__JJJI(JNIEnv* env, jclass, jlong address, jlong force, jlong torque, jint mode) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->setForceAndTorque(*((physx::PxVec3*) force), *((physx::PxVec3*) torque), (PxForceModeEnum) mode);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setRigidBodyFlag(JNIEnv* env, jclass, jlong address, jint flag, jboolean value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->setRigidBodyFlag((PxRigidBodyFlagEnum) flag, value);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setRigidBodyFlags(JNIEnv* env, jclass, jlong address, jlong inFlags) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->setRigidBodyFlags(*((physx::PxRigidBodyFlags*) inFlags));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBody__1getRigidBodyFlags(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxRigidBodyFlags cache;
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    cache = self->getRigidBodyFlags();
    return (jlong) &cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setMinCCDAdvanceCoefficient(JNIEnv* env, jclass, jlong address, jfloat advanceCoefficient) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->setMinCCDAdvanceCoefficient(advanceCoefficient);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getMinCCDAdvanceCoefficient(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    return (jfloat) self->getMinCCDAdvanceCoefficient();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setMaxDepenetrationVelocity(JNIEnv* env, jclass, jlong address, jfloat biasClamp) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->setMaxDepenetrationVelocity(biasClamp);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getMaxDepenetrationVelocity(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    return (jfloat) self->getMaxDepenetrationVelocity();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBody__1setMaxContactImpulse(JNIEnv* env, jclass, jlong address, jfloat maxImpulse) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    self->setMaxContactImpulse(maxImpulse);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidBody__1getMaxContactImpulse(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    return (jfloat) self->getMaxContactImpulse();
}
JNIEXPORT jint JNICALL Java_physx_physics_PxRigidBody__1getInternalIslandNodeIndex(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBody* self = (physx::PxRigidBody*) address;
    return (jint) self->getInternalIslandNodeIndex();
}

// PxRigidBodyFlags
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidBodyFlags__1PxRigidBodyFlags(JNIEnv* env, jclass, jbyte flags) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxRigidBodyFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxRigidBodyFlags__1isSet(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBodyFlags* self = (physx::PxRigidBodyFlags*) address;
    return (jboolean) self->isSet((PxRigidBodyFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBodyFlags__1set(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBodyFlags* self = (physx::PxRigidBodyFlags*) address;
    self->set((PxRigidBodyFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBodyFlags__1clear(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidBodyFlags* self = (physx::PxRigidBodyFlags*) address;
    self->clear((PxRigidBodyFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidBodyFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxRigidBodyFlags*) address;
}

// PxRigidDynamic
JNIEXPORT jboolean JNICALL Java_physx_physics_PxRigidDynamic__1isSleeping(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) address;
    return (jboolean) self->isSleeping();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setSleepThreshold(JNIEnv* env, jclass, jlong address, jfloat threshold) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) address;
    self->setSleepThreshold(threshold);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidDynamic__1getSleepThreshold(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) address;
    return (jfloat) self->getSleepThreshold();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setStabilizationThreshold(JNIEnv* env, jclass, jlong address, jfloat threshold) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) address;
    self->setStabilizationThreshold(threshold);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidDynamic__1getStabilizationThreshold(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) address;
    return (jfloat) self->getStabilizationThreshold();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidDynamic__1getRigidDynamicLockFlags(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxRigidDynamicLockFlags cache;
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) address;
    cache = self->getRigidDynamicLockFlags();
    return (jlong) &cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setRigidDynamicLockFlag(JNIEnv* env, jclass, jlong address, jint flag, jboolean value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) address;
    self->setRigidDynamicLockFlag((PxRigidDynamicLockFlagEnum) flag, value);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setRigidDynamicLockFlags(JNIEnv* env, jclass, jlong address, jlong flags) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) address;
    self->setRigidDynamicLockFlags(*((physx::PxRigidDynamicLockFlags*) flags));
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setWakeCounter(JNIEnv* env, jclass, jlong address, jfloat wakeCounterValue) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) address;
    self->setWakeCounter(wakeCounterValue);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidDynamic__1getWakeCounter(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) address;
    return (jfloat) self->getWakeCounter();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1wakeUp(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) address;
    self->wakeUp();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1putToSleep(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) address;
    self->putToSleep();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setSolverIterationCounts__JI(JNIEnv* env, jclass, jlong address, jint minPositionIters) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) address;
    self->setSolverIterationCounts(minPositionIters);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setSolverIterationCounts__JII(JNIEnv* env, jclass, jlong address, jint minPositionIters, jint minVelocityIters) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) address;
    self->setSolverIterationCounts(minPositionIters, minVelocityIters);
}
JNIEXPORT jfloat JNICALL Java_physx_physics_PxRigidDynamic__1getContactReportThreshold(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) address;
    return (jfloat) self->getContactReportThreshold();
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamic__1setContactReportThreshold(JNIEnv* env, jclass, jlong address, jfloat threshold) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidDynamic* self = (physx::PxRigidDynamic*) address;
    self->setContactReportThreshold(threshold);
}

// PxRigidDynamicLockFlags
JNIEXPORT jlong JNICALL Java_physx_physics_PxRigidDynamicLockFlags__1PxRigidDynamicLockFlags(JNIEnv* env, jclass, jbyte flags) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxRigidDynamicLockFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxRigidDynamicLockFlags__1isSet(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidDynamicLockFlags* self = (physx::PxRigidDynamicLockFlags*) address;
    return (jboolean) self->isSet((PxRigidDynamicLockFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamicLockFlags__1set(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidDynamicLockFlags* self = (physx::PxRigidDynamicLockFlags*) address;
    self->set((PxRigidDynamicLockFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamicLockFlags__1clear(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxRigidDynamicLockFlags* self = (physx::PxRigidDynamicLockFlags*) address;
    self->clear((PxRigidDynamicLockFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxRigidDynamicLockFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxRigidDynamicLockFlags*) address;
}

// PxRigidStatic

// PxScene
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1addActor__JJ(JNIEnv* env, jclass, jlong address, jlong actor) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxScene* self = (physx::PxScene*) address;
    self->addActor(*((physx::PxActor*) actor));
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1addActor__JJJ(JNIEnv* env, jclass, jlong address, jlong actor, jlong bvhStructure) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxScene* self = (physx::PxScene*) address;
    self->addActor(*((physx::PxActor*) actor), (physx::PxBVHStructure*) bvhStructure);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1removeActor__JJ(JNIEnv* env, jclass, jlong address, jlong actor) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxScene* self = (physx::PxScene*) address;
    self->removeActor(*((physx::PxActor*) actor));
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1removeActor__JJZ(JNIEnv* env, jclass, jlong address, jlong actor, jboolean wakeOnLostTouch) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxScene* self = (physx::PxScene*) address;
    self->removeActor(*((physx::PxActor*) actor), wakeOnLostTouch);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1simulate__JF(JNIEnv* env, jclass, jlong address, jfloat elapsedTime) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxScene* self = (physx::PxScene*) address;
    self->simulate(elapsedTime);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1simulate__JFJ(JNIEnv* env, jclass, jlong address, jfloat elapsedTime, jlong completionTask) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxScene* self = (physx::PxScene*) address;
    self->simulate(elapsedTime, (physx::PxBaseTask*) completionTask);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1simulate__JFJJ(JNIEnv* env, jclass, jlong address, jfloat elapsedTime, jlong completionTask, jlong scratchMemBlock) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxScene* self = (physx::PxScene*) address;
    self->simulate(elapsedTime, (physx::PxBaseTask*) completionTask, (void*) scratchMemBlock);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1simulate__JFJJI(JNIEnv* env, jclass, jlong address, jfloat elapsedTime, jlong completionTask, jlong scratchMemBlock, jint scratchMemBlockSize) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxScene* self = (physx::PxScene*) address;
    self->simulate(elapsedTime, (physx::PxBaseTask*) completionTask, (void*) scratchMemBlock, scratchMemBlockSize);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1simulate__JFJJIZ(JNIEnv* env, jclass, jlong address, jfloat elapsedTime, jlong completionTask, jlong scratchMemBlock, jint scratchMemBlockSize, jboolean controlSimulation) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxScene* self = (physx::PxScene*) address;
    self->simulate(elapsedTime, (physx::PxBaseTask*) completionTask, (void*) scratchMemBlock, scratchMemBlockSize, controlSimulation);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1fetchResults__J(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxScene* self = (physx::PxScene*) address;
    return (jboolean) self->fetchResults();
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxScene__1fetchResults__JZ(JNIEnv* env, jclass, jlong address, jboolean block) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxScene* self = (physx::PxScene*) address;
    return (jboolean) self->fetchResults(block);
}
JNIEXPORT void JNICALL Java_physx_physics_PxScene__1setGravity(JNIEnv* env, jclass, jlong address, jlong vec) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxScene* self = (physx::PxScene*) address;
    self->setGravity(*((physx::PxVec3*) vec));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1getGravity(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxVec3 cache;
    physx::PxScene* self = (physx::PxScene*) address;
    cache = self->getGravity();
    return (jlong) &cache;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxScene__1createBatchQuery(JNIEnv* env, jclass, jlong address, jlong desc) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxScene* self = (physx::PxScene*) address;
    return (jlong) self->createBatchQuery(*((physx::PxBatchQueryDesc*) desc));
}

// PxSceneDesc
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1PxSceneDesc(JNIEnv* env, jclass, jlong scale) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxSceneDesc(*((physx::PxTolerancesScale*) scale));
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxSceneDesc*) address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getGravity(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSceneDesc* self = (physx::PxSceneDesc*) address;
    return (jlong) &self->gravity;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setGravity(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSceneDesc* self = (physx::PxSceneDesc*) address;
    self->gravity = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getSimulationEventCallback(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSceneDesc* self = (physx::PxSceneDesc*) address;
    return (jlong) self->simulationEventCallback;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setSimulationEventCallback(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSceneDesc* self = (physx::PxSceneDesc*) address;
    self->simulationEventCallback = (physx::PxSimulationEventCallback*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getFilterShader(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSceneDesc* self = (physx::PxSceneDesc*) address;
    return (jlong) &self->filterShader;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setFilterShader(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSceneDesc* self = (physx::PxSceneDesc*) address;
    self->filterShader = *((physx::PxSimulationFilterShader*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getCpuDispatcher(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSceneDesc* self = (physx::PxSceneDesc*) address;
    return (jlong) self->cpuDispatcher;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setCpuDispatcher(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSceneDesc* self = (physx::PxSceneDesc*) address;
    self->cpuDispatcher = (physx::PxCpuDispatcher*) value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneDesc__1getFlags(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSceneDesc* self = (physx::PxSceneDesc*) address;
    return (jlong) &self->flags;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneDesc__1setFlags(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSceneDesc* self = (physx::PxSceneDesc*) address;
    self->flags = *((physx::PxSceneFlags*) value);
}

// PxSceneFlags
JNIEXPORT jlong JNICALL Java_physx_physics_PxSceneFlags__1PxSceneFlags(JNIEnv* env, jclass, jint flags) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxSceneFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSceneFlags__1isSet(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSceneFlags* self = (physx::PxSceneFlags*) address;
    return (jboolean) self->isSet((PxSceneFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneFlags__1set(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSceneFlags* self = (physx::PxSceneFlags*) address;
    self->set((PxSceneFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneFlags__1clear(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSceneFlags* self = (physx::PxSceneFlags*) address;
    self->clear((PxSceneFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSceneFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxSceneFlags*) address;
}

// PxShape
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setLocalPose(JNIEnv* env, jclass, jlong address, jlong pose) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxShape* self = (physx::PxShape*) address;
    self->setLocalPose(*((physx::PxTransform*) pose));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShape__1getLocalPose(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxTransform cache;
    physx::PxShape* self = (physx::PxShape*) address;
    cache = self->getLocalPose();
    return (jlong) &cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setSimulationFilterData(JNIEnv* env, jclass, jlong address, jlong data) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxShape* self = (physx::PxShape*) address;
    self->setSimulationFilterData(*((physx::PxFilterData*) data));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShape__1getSimulationFilterData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxFilterData cache;
    physx::PxShape* self = (physx::PxShape*) address;
    cache = self->getSimulationFilterData();
    return (jlong) &cache;
}
JNIEXPORT void JNICALL Java_physx_physics_PxShape__1setQueryFilterData(JNIEnv* env, jclass, jlong address, jlong data) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxShape* self = (physx::PxShape*) address;
    self->setQueryFilterData(*((physx::PxFilterData*) data));
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxShape__1getQueryFilterData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxFilterData cache;
    physx::PxShape* self = (physx::PxShape*) address;
    cache = self->getQueryFilterData();
    return (jlong) &cache;
}

// PxShapeFlags
JNIEXPORT jlong JNICALL Java_physx_physics_PxShapeFlags__1PxShapeFlags(JNIEnv* env, jclass, jbyte flags) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxShapeFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxShapeFlags__1isSet(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxShapeFlags* self = (physx::PxShapeFlags*) address;
    return (jboolean) self->isSet((PxShapeFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxShapeFlags__1set(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxShapeFlags* self = (physx::PxShapeFlags*) address;
    self->set((PxShapeFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxShapeFlags__1clear(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxShapeFlags* self = (physx::PxShapeFlags*) address;
    self->clear((PxShapeFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_physics_PxShapeFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxShapeFlags*) address;
}

// PxSimulationEventCallback
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationEventCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxSimulationEventCallback*) address;
}

// SimplePxSimulationEventCallback
JNIEXPORT void JNICALL Java_physx_physics_SimplePxSimulationEventCallback__1cbFun(JNIEnv* env, jclass, jlong address, jint count) {
    (void) env;    // avoid unused parameter warning / error
    SimplePxSimulationEventCallback* self = (SimplePxSimulationEventCallback*) address;
    self->cbFun(count);
}
JNIEXPORT void JNICALL Java_physx_physics_SimplePxSimulationEventCallback__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (SimplePxSimulationEventCallback*) address;
}

// PxSimulationFilterShader
JNIEXPORT void JNICALL Java_physx_physics_PxSimulationFilterShader__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxSimulationFilterShader*) address;
}

// PxSweepHit
JNIEXPORT void JNICALL Java_physx_physics_PxSweepHit__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxSweepHit*) address;
}

// PxSweepQueryResult
JNIEXPORT jint JNICALL Java_physx_physics_PxSweepQueryResult__1getNbAnyHits(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSweepQueryResult* self = (physx::PxSweepQueryResult*) address;
    return (jint) self->getNbAnyHits();
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepQueryResult__1getAnyHit(JNIEnv* env, jclass, jlong address, jint index) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSweepQueryResult* self = (physx::PxSweepQueryResult*) address;
    return (jlong) &self->getAnyHit(index);
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepQueryResult__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxSweepQueryResult*) address;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepQueryResult__1getBlock(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSweepQueryResult* self = (physx::PxSweepQueryResult*) address;
    return (jlong) &self->block;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepQueryResult__1setBlock(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSweepQueryResult* self = (physx::PxSweepQueryResult*) address;
    self->block = *((physx::PxSweepHit*) value);
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepQueryResult__1getTouches(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSweepQueryResult* self = (physx::PxSweepQueryResult*) address;
    return (jlong) self->touches;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepQueryResult__1setTouches(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSweepQueryResult* self = (physx::PxSweepQueryResult*) address;
    self->touches = (physx::PxSweepHit*) value;
}
JNIEXPORT jint JNICALL Java_physx_physics_PxSweepQueryResult__1getNbTouches(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSweepQueryResult* self = (physx::PxSweepQueryResult*) address;
    return (jint) self->nbTouches;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepQueryResult__1setNbTouches(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSweepQueryResult* self = (physx::PxSweepQueryResult*) address;
    self->nbTouches = value;
}
JNIEXPORT jlong JNICALL Java_physx_physics_PxSweepQueryResult__1getUserData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSweepQueryResult* self = (physx::PxSweepQueryResult*) address;
    return (jlong) self->userData;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepQueryResult__1setUserData(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSweepQueryResult* self = (physx::PxSweepQueryResult*) address;
    self->userData = (void*) value;
}
JNIEXPORT jbyte JNICALL Java_physx_physics_PxSweepQueryResult__1getQueryStatus(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSweepQueryResult* self = (physx::PxSweepQueryResult*) address;
    return (jbyte) self->queryStatus;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepQueryResult__1setQueryStatus(JNIEnv* env, jclass, jlong address, jbyte value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSweepQueryResult* self = (physx::PxSweepQueryResult*) address;
    self->queryStatus = value;
}
JNIEXPORT jboolean JNICALL Java_physx_physics_PxSweepQueryResult__1getHasBlock(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSweepQueryResult* self = (physx::PxSweepQueryResult*) address;
    return (jboolean) self->hasBlock;
}
JNIEXPORT void JNICALL Java_physx_physics_PxSweepQueryResult__1setHasBlock(JNIEnv* env, jclass, jlong address, jboolean value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxSweepQueryResult* self = (physx::PxSweepQueryResult*) address;
    self->hasBlock = value;
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

// PxMaterialPtr
JNIEXPORT void JNICALL Java_physx_support_PxMaterialPtr__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (PxMaterialPtr*) address;
}

// Vector_PxMaterial
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxMaterial__1Vector_1PxMaterial__(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new Vector_PxMaterial();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxMaterial__1Vector_1PxMaterial__I(JNIEnv* env, jclass, jint size) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new Vector_PxMaterial(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxMaterial__1at(JNIEnv* env, jclass, jlong address, jint index) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxMaterial* self = (Vector_PxMaterial*) address;
    return (jlong) self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxMaterial__1data(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxMaterial* self = (Vector_PxMaterial*) address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxMaterial__1size(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxMaterial* self = (Vector_PxMaterial*) address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxMaterial__1push_1back(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxMaterial* self = (Vector_PxMaterial*) address;
    self->push_back((physx::PxMaterial*) value);
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxMaterial__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (Vector_PxMaterial*) address;
}

// Vector_PxReal
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxReal__1Vector_1PxReal__(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new Vector_PxReal();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxReal__1Vector_1PxReal__I(JNIEnv* env, jclass, jint size) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new Vector_PxReal(size);
}
JNIEXPORT jfloat JNICALL Java_physx_support_Vector_1PxReal__1at(JNIEnv* env, jclass, jlong address, jint index) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxReal* self = (Vector_PxReal*) address;
    return (jfloat) self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxReal__1data(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static PxRealPtr cache;
    Vector_PxReal* self = (Vector_PxReal*) address;
    cache = self->data();
    return (jlong) &cache;
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxReal__1size(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxReal* self = (Vector_PxReal*) address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxReal__1push_1back(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxReal* self = (Vector_PxReal*) address;
    self->push_back(value);
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxReal__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (Vector_PxReal*) address;
}

// Vector_PxVec3
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVec3__1Vector_1PxVec3__(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new Vector_PxVec3();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVec3__1Vector_1PxVec3__I(JNIEnv* env, jclass, jint size) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new Vector_PxVec3(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVec3__1at(JNIEnv* env, jclass, jlong address, jint index) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxVec3* self = (Vector_PxVec3*) address;
    return (jlong) &self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVec3__1data(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxVec3* self = (Vector_PxVec3*) address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxVec3__1size(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxVec3* self = (Vector_PxVec3*) address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxVec3__1push_1back(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxVec3* self = (Vector_PxVec3*) address;
    self->push_back(*((physx::PxVec3*) value));
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxVec3__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (Vector_PxVec3*) address;
}

// Vector_PxRaycastQueryResult
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxRaycastQueryResult__1Vector_1PxRaycastQueryResult__(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new Vector_PxRaycastQueryResult();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxRaycastQueryResult__1Vector_1PxRaycastQueryResult__I(JNIEnv* env, jclass, jint size) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new Vector_PxRaycastQueryResult(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxRaycastQueryResult__1at(JNIEnv* env, jclass, jlong address, jint index) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxRaycastQueryResult* self = (Vector_PxRaycastQueryResult*) address;
    return (jlong) &self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxRaycastQueryResult__1data(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxRaycastQueryResult* self = (Vector_PxRaycastQueryResult*) address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxRaycastQueryResult__1size(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxRaycastQueryResult* self = (Vector_PxRaycastQueryResult*) address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxRaycastQueryResult__1push_1back(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxRaycastQueryResult* self = (Vector_PxRaycastQueryResult*) address;
    self->push_back(*((physx::PxRaycastQueryResult*) value));
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxRaycastQueryResult__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (Vector_PxRaycastQueryResult*) address;
}

// Vector_PxSweepQueryResult
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxSweepQueryResult__1Vector_1PxSweepQueryResult__(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new Vector_PxSweepQueryResult();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxSweepQueryResult__1Vector_1PxSweepQueryResult__I(JNIEnv* env, jclass, jint size) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new Vector_PxSweepQueryResult(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxSweepQueryResult__1at(JNIEnv* env, jclass, jlong address, jint index) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxSweepQueryResult* self = (Vector_PxSweepQueryResult*) address;
    return (jlong) &self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxSweepQueryResult__1data(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxSweepQueryResult* self = (Vector_PxSweepQueryResult*) address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxSweepQueryResult__1size(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxSweepQueryResult* self = (Vector_PxSweepQueryResult*) address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxSweepQueryResult__1push_1back(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxSweepQueryResult* self = (Vector_PxSweepQueryResult*) address;
    self->push_back(*((physx::PxSweepQueryResult*) value));
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxSweepQueryResult__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (Vector_PxSweepQueryResult*) address;
}

// Vector_PxRaycastHit
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxRaycastHit__1Vector_1PxRaycastHit__(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new Vector_PxRaycastHit();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxRaycastHit__1Vector_1PxRaycastHit__I(JNIEnv* env, jclass, jint size) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new Vector_PxRaycastHit(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxRaycastHit__1at(JNIEnv* env, jclass, jlong address, jint index) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxRaycastHit* self = (Vector_PxRaycastHit*) address;
    return (jlong) &self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxRaycastHit__1data(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxRaycastHit* self = (Vector_PxRaycastHit*) address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxRaycastHit__1size(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxRaycastHit* self = (Vector_PxRaycastHit*) address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxRaycastHit__1push_1back(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxRaycastHit* self = (Vector_PxRaycastHit*) address;
    self->push_back(*((physx::PxRaycastHit*) value));
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxRaycastHit__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (Vector_PxRaycastHit*) address;
}

// Vector_PxSweepHit
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxSweepHit__1Vector_1PxSweepHit__(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new Vector_PxSweepHit();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxSweepHit__1Vector_1PxSweepHit__I(JNIEnv* env, jclass, jint size) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new Vector_PxSweepHit(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxSweepHit__1at(JNIEnv* env, jclass, jlong address, jint index) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxSweepHit* self = (Vector_PxSweepHit*) address;
    return (jlong) &self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxSweepHit__1data(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxSweepHit* self = (Vector_PxSweepHit*) address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxSweepHit__1size(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxSweepHit* self = (Vector_PxSweepHit*) address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxSweepHit__1push_1back(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxSweepHit* self = (Vector_PxSweepHit*) address;
    self->push_back(*((physx::PxSweepHit*) value));
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxSweepHit__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (Vector_PxSweepHit*) address;
}

// Vector_PxVehicleDrivableSurfaceType
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVehicleDrivableSurfaceType__1Vector_1PxVehicleDrivableSurfaceType__(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new Vector_PxVehicleDrivableSurfaceType();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVehicleDrivableSurfaceType__1Vector_1PxVehicleDrivableSurfaceType__I(JNIEnv* env, jclass, jint size) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new Vector_PxVehicleDrivableSurfaceType(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVehicleDrivableSurfaceType__1at(JNIEnv* env, jclass, jlong address, jint index) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxVehicleDrivableSurfaceType* self = (Vector_PxVehicleDrivableSurfaceType*) address;
    return (jlong) &self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVehicleDrivableSurfaceType__1data(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxVehicleDrivableSurfaceType* self = (Vector_PxVehicleDrivableSurfaceType*) address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxVehicleDrivableSurfaceType__1size(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxVehicleDrivableSurfaceType* self = (Vector_PxVehicleDrivableSurfaceType*) address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxVehicleDrivableSurfaceType__1push_1back(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxVehicleDrivableSurfaceType* self = (Vector_PxVehicleDrivableSurfaceType*) address;
    self->push_back(*((physx::PxVehicleDrivableSurfaceType*) value));
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxVehicleDrivableSurfaceType__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (Vector_PxVehicleDrivableSurfaceType*) address;
}

// Vector_PxWheelQueryResult
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxWheelQueryResult__1Vector_1PxWheelQueryResult__(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new Vector_PxWheelQueryResult();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxWheelQueryResult__1Vector_1PxWheelQueryResult__I(JNIEnv* env, jclass, jint size) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new Vector_PxWheelQueryResult(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxWheelQueryResult__1at(JNIEnv* env, jclass, jlong address, jint index) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxWheelQueryResult* self = (Vector_PxWheelQueryResult*) address;
    return (jlong) &self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxWheelQueryResult__1data(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxWheelQueryResult* self = (Vector_PxWheelQueryResult*) address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxWheelQueryResult__1size(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxWheelQueryResult* self = (Vector_PxWheelQueryResult*) address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxWheelQueryResult__1push_1back(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxWheelQueryResult* self = (Vector_PxWheelQueryResult*) address;
    self->push_back(*((physx::PxWheelQueryResult*) value));
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxWheelQueryResult__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (Vector_PxWheelQueryResult*) address;
}

// PxVehicleWheelsPtr
JNIEXPORT void JNICALL Java_physx_support_PxVehicleWheelsPtr__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (PxVehicleWheelsPtr*) address;
}

// Vector_PxVehicleWheels
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVehicleWheels__1Vector_1PxVehicleWheels__(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new Vector_PxVehicleWheels();
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVehicleWheels__1Vector_1PxVehicleWheels__I(JNIEnv* env, jclass, jint size) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new Vector_PxVehicleWheels(size);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVehicleWheels__1at(JNIEnv* env, jclass, jlong address, jint index) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxVehicleWheels* self = (Vector_PxVehicleWheels*) address;
    return (jlong) self->at(index);
}
JNIEXPORT jlong JNICALL Java_physx_support_Vector_1PxVehicleWheels__1data(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxVehicleWheels* self = (Vector_PxVehicleWheels*) address;
    return (jlong) self->data();
}
JNIEXPORT jint JNICALL Java_physx_support_Vector_1PxVehicleWheels__1size(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxVehicleWheels* self = (Vector_PxVehicleWheels*) address;
    return (jint) self->size();
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxVehicleWheels__1push_1back(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    Vector_PxVehicleWheels* self = (Vector_PxVehicleWheels*) address;
    self->push_back((physx::PxVehicleWheels*) value);
}
JNIEXPORT void JNICALL Java_physx_support_Vector_1PxVehicleWheels__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (Vector_PxVehicleWheels*) address;
}

// PxVehicleTopLevelFunctions
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxVehicleTopLevelFunctions__1InitVehicleSDK(JNIEnv* env, jclass, jlong physics) {
    (void) env;    // avoid unused parameter warning / error
    return (jboolean) PxVehicleTopLevelFunctions::InitVehicleSDK(*((physx::PxPhysics*) physics));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTopLevelFunctions__1PxVehicleComputeSprungMasses(JNIEnv* env, jclass, jint nbSprungMasses, jlong sprungMassCoordinates, jlong centreOfMass, jfloat totalMass, jint gravityDirection, jlong sprungMasses) {
    (void) env;    // avoid unused parameter warning / error
    PxVehicleTopLevelFunctions::PxVehicleComputeSprungMasses(nbSprungMasses, (physx::PxVec3*) sprungMassCoordinates, *((physx::PxVec3*) centreOfMass), totalMass, gravityDirection, *((PxRealPtr*) sprungMasses));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTopLevelFunctions__1PxVehicleSuspensionRaycasts(JNIEnv* env, jclass, jlong batchQuery, jlong vehicles, jint nbSceneQueryResults, jlong sceneQueryResults) {
    (void) env;    // avoid unused parameter warning / error
    PxVehicleTopLevelFunctions::PxVehicleSuspensionRaycasts((physx::PxBatchQuery*) batchQuery, *((Vector_PxVehicleWheels*) vehicles), nbSceneQueryResults, (physx::PxRaycastQueryResult*) sceneQueryResults);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTopLevelFunctions__1PxVehicleUpdates(JNIEnv* env, jclass, jfloat timestep, jlong gravity, jlong vehicleDrivableSurfaceToTireFrictionPairs, jlong vehicles, jlong vehicleWheelQueryResults) {
    (void) env;    // avoid unused parameter warning / error
    PxVehicleTopLevelFunctions::PxVehicleUpdates(timestep, *((physx::PxVec3*) gravity), *((physx::PxVehicleDrivableSurfaceToTireFrictionPairs*) vehicleDrivableSurfaceToTireFrictionPairs), *((Vector_PxVehicleWheels*) vehicles), (physx::PxVehicleWheelQueryResult*) vehicleWheelQueryResults);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTopLevelFunctions__1VehicleSetBasisVectors(JNIEnv* env, jclass, jlong up, jlong forward) {
    (void) env;    // avoid unused parameter warning / error
    PxVehicleTopLevelFunctions::VehicleSetBasisVectors(*((physx::PxVec3*) up), *((physx::PxVec3*) forward));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTopLevelFunctions__1VehicleSetUpdateMode(JNIEnv* env, jclass, jint vehicleUpdateMode) {
    (void) env;    // avoid unused parameter warning / error
    PxVehicleTopLevelFunctions::VehicleSetUpdateMode((PxVehicleUpdateModeEnum) vehicleUpdateMode);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleTopLevelFunctions__1PxVehicleTireData_1getFrictionVsSlipGraph(JNIEnv* env, jclass, jlong tireData, jint m, jint n) {
    (void) env;    // avoid unused parameter warning / error
    return (jfloat) PxVehicleTopLevelFunctions::PxVehicleTireData_getFrictionVsSlipGraph((physx::PxVehicleTireData*) tireData, m, n);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTopLevelFunctions__1PxVehicleTireData_1setFrictionVsSlipGraph(JNIEnv* env, jclass, jlong tireData, jint m, jint n, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    PxVehicleTopLevelFunctions::PxVehicleTireData_setFrictionVsSlipGraph((physx::PxVehicleTireData*) tireData, m, n, value);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTopLevelFunctions__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (PxVehicleTopLevelFunctions*) address;
}

// PxVehicleAckermannGeometryData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleAckermannGeometryData__1PxVehicleAckermannGeometryData(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxVehicleAckermannGeometryData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAckermannGeometryData__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxVehicleAckermannGeometryData*) address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleAckermannGeometryData__1getMAccuracy(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAckermannGeometryData* self = (physx::PxVehicleAckermannGeometryData*) address;
    return (jfloat) self->mAccuracy;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAckermannGeometryData__1setMAccuracy(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAckermannGeometryData* self = (physx::PxVehicleAckermannGeometryData*) address;
    self->mAccuracy = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleAckermannGeometryData__1getMFrontWidth(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAckermannGeometryData* self = (physx::PxVehicleAckermannGeometryData*) address;
    return (jfloat) self->mFrontWidth;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAckermannGeometryData__1setMFrontWidth(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAckermannGeometryData* self = (physx::PxVehicleAckermannGeometryData*) address;
    self->mFrontWidth = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleAckermannGeometryData__1getMRearWidth(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAckermannGeometryData* self = (physx::PxVehicleAckermannGeometryData*) address;
    return (jfloat) self->mRearWidth;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAckermannGeometryData__1setMRearWidth(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAckermannGeometryData* self = (physx::PxVehicleAckermannGeometryData*) address;
    self->mRearWidth = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleAckermannGeometryData__1getMAxleSeparation(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAckermannGeometryData* self = (physx::PxVehicleAckermannGeometryData*) address;
    return (jfloat) self->mAxleSeparation;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAckermannGeometryData__1setMAxleSeparation(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAckermannGeometryData* self = (physx::PxVehicleAckermannGeometryData*) address;
    self->mAxleSeparation = value;
}

// PxVehicleAntiRollBarData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleAntiRollBarData__1PxVehicleAntiRollBarData(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxVehicleAntiRollBarData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAntiRollBarData__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxVehicleAntiRollBarData*) address;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleAntiRollBarData__1getMWheel0(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAntiRollBarData* self = (physx::PxVehicleAntiRollBarData*) address;
    return (jint) self->mWheel0;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAntiRollBarData__1setMWheel0(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAntiRollBarData* self = (physx::PxVehicleAntiRollBarData*) address;
    self->mWheel0 = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleAntiRollBarData__1getMWheel1(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAntiRollBarData* self = (physx::PxVehicleAntiRollBarData*) address;
    return (jint) self->mWheel1;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAntiRollBarData__1setMWheel1(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAntiRollBarData* self = (physx::PxVehicleAntiRollBarData*) address;
    self->mWheel1 = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleAntiRollBarData__1getMStiffness(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAntiRollBarData* self = (physx::PxVehicleAntiRollBarData*) address;
    return (jfloat) self->mStiffness;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAntiRollBarData__1setMStiffness(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAntiRollBarData* self = (physx::PxVehicleAntiRollBarData*) address;
    self->mStiffness = value;
}

// PxVehicleAutoBoxData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1PxVehicleAutoBoxData(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxVehicleAutoBoxData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1setLatency(JNIEnv* env, jclass, jlong address, jfloat latency) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAutoBoxData* self = (physx::PxVehicleAutoBoxData*) address;
    self->setLatency(latency);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1getLatency(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAutoBoxData* self = (physx::PxVehicleAutoBoxData*) address;
    return (jfloat) self->getLatency();
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1getUpRatios(JNIEnv* env, jclass, jlong address, jint a) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAutoBoxData* self = (physx::PxVehicleAutoBoxData*) address;
    return (jfloat) self->getUpRatios((PxVehicleGearEnum) a);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1setUpRatios(JNIEnv* env, jclass, jlong address, jint a, jfloat ratio) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAutoBoxData* self = (physx::PxVehicleAutoBoxData*) address;
    self->setUpRatios((PxVehicleGearEnum) a, ratio);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1getDownRatios(JNIEnv* env, jclass, jlong address, jint a) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAutoBoxData* self = (physx::PxVehicleAutoBoxData*) address;
    return (jfloat) self->getDownRatios((PxVehicleGearEnum) a);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1setDownRatios(JNIEnv* env, jclass, jlong address, jint a, jfloat ratio) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAutoBoxData* self = (physx::PxVehicleAutoBoxData*) address;
    self->setDownRatios((PxVehicleGearEnum) a, ratio);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxVehicleAutoBoxData*) address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1getMUpRatios(JNIEnv* env, jclass, jlong address, jint index) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAutoBoxData* self = (physx::PxVehicleAutoBoxData*) address;
    return (jfloat) self->mUpRatios[index];
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1setMUpRatios(JNIEnv* env, jclass, jlong address, jint index, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAutoBoxData* self = (physx::PxVehicleAutoBoxData*) address;
    self->mUpRatios[index] = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1getMDownRatios(JNIEnv* env, jclass, jlong address, jint index) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAutoBoxData* self = (physx::PxVehicleAutoBoxData*) address;
    return (jfloat) self->mDownRatios[index];
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleAutoBoxData__1setMDownRatios(JNIEnv* env, jclass, jlong address, jint index, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleAutoBoxData* self = (physx::PxVehicleAutoBoxData*) address;
    self->mDownRatios[index] = value;
}

// PxVehicleChassisData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleChassisData__1PxVehicleChassisData(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxVehicleChassisData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleChassisData__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxVehicleChassisData*) address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleChassisData__1getMMOI(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleChassisData* self = (physx::PxVehicleChassisData*) address;
    return (jlong) &self->mMOI;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleChassisData__1setMMOI(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleChassisData* self = (physx::PxVehicleChassisData*) address;
    self->mMOI = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleChassisData__1getMMass(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleChassisData* self = (physx::PxVehicleChassisData*) address;
    return (jfloat) self->mMass;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleChassisData__1setMMass(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleChassisData* self = (physx::PxVehicleChassisData*) address;
    self->mMass = value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleChassisData__1getMCMOffset(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleChassisData* self = (physx::PxVehicleChassisData*) address;
    return (jlong) &self->mCMOffset;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleChassisData__1setMCMOffset(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleChassisData* self = (physx::PxVehicleChassisData*) address;
    self->mCMOffset = *((physx::PxVec3*) value);
}

// PxVehicleClutchData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleClutchData__1PxVehicleClutchData(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxVehicleClutchData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleClutchData__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxVehicleClutchData*) address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleClutchData__1getMStrength(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleClutchData* self = (physx::PxVehicleClutchData*) address;
    return (jfloat) self->mStrength;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleClutchData__1setMStrength(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleClutchData* self = (physx::PxVehicleClutchData*) address;
    self->mStrength = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleClutchData__1getMAccuracyMode(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleClutchData* self = (physx::PxVehicleClutchData*) address;
    return (PxVehicleClutchAccuracyModeEnum) self->mAccuracyMode;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleClutchData__1setMAccuracyMode(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleClutchData* self = (physx::PxVehicleClutchData*) address;
    self->mAccuracyMode = (PxVehicleClutchAccuracyModeEnum) value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleClutchData__1getMEstimateIterations(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleClutchData* self = (physx::PxVehicleClutchData*) address;
    return (jint) self->mEstimateIterations;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleClutchData__1setMEstimateIterations(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleClutchData* self = (physx::PxVehicleClutchData*) address;
    self->mEstimateIterations = value;
}

// PxVehicleDifferential4WData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1PxVehicleDifferential4WData(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxVehicleDifferential4WData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxVehicleDifferential4WData*) address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1getMFrontRearSplit(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDifferential4WData* self = (physx::PxVehicleDifferential4WData*) address;
    return (jfloat) self->mFrontRearSplit;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1setMFrontRearSplit(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDifferential4WData* self = (physx::PxVehicleDifferential4WData*) address;
    self->mFrontRearSplit = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1getMFrontLeftRightSplit(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDifferential4WData* self = (physx::PxVehicleDifferential4WData*) address;
    return (jfloat) self->mFrontLeftRightSplit;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1setMFrontLeftRightSplit(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDifferential4WData* self = (physx::PxVehicleDifferential4WData*) address;
    self->mFrontLeftRightSplit = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1getMRearLeftRightSplit(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDifferential4WData* self = (physx::PxVehicleDifferential4WData*) address;
    return (jfloat) self->mRearLeftRightSplit;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1setMRearLeftRightSplit(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDifferential4WData* self = (physx::PxVehicleDifferential4WData*) address;
    self->mRearLeftRightSplit = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1getMCentreBias(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDifferential4WData* self = (physx::PxVehicleDifferential4WData*) address;
    return (jfloat) self->mCentreBias;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1setMCentreBias(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDifferential4WData* self = (physx::PxVehicleDifferential4WData*) address;
    self->mCentreBias = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1getMFrontBias(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDifferential4WData* self = (physx::PxVehicleDifferential4WData*) address;
    return (jfloat) self->mFrontBias;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1setMFrontBias(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDifferential4WData* self = (physx::PxVehicleDifferential4WData*) address;
    self->mFrontBias = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1getMRearBias(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDifferential4WData* self = (physx::PxVehicleDifferential4WData*) address;
    return (jfloat) self->mRearBias;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1setMRearBias(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDifferential4WData* self = (physx::PxVehicleDifferential4WData*) address;
    self->mRearBias = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1getMType(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDifferential4WData* self = (physx::PxVehicleDifferential4WData*) address;
    return (PxVehicleDifferential4WDataEnum) self->mType;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDifferential4WData__1setMType(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDifferential4WData* self = (physx::PxVehicleDifferential4WData*) address;
    self->mType = (PxVehicleDifferential4WDataEnum) value;
}

// PxVehicleDrivableSurfaceToTireFrictionPairs
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceToTireFrictionPairs__1allocate(JNIEnv* env, jclass, jint maxNbTireTypes, jint maxNbSurfaceTypes) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) physx::PxVehicleDrivableSurfaceToTireFrictionPairs::allocate(maxNbTireTypes, maxNbSurfaceTypes);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceToTireFrictionPairs__1setup(JNIEnv* env, jclass, jlong address, jint nbTireTypes, jint nbSurfaceTypes, jlong drivableSurfaceMaterials, jlong drivableSurfaceTypes) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDrivableSurfaceToTireFrictionPairs* self = (physx::PxVehicleDrivableSurfaceToTireFrictionPairs*) address;
    self->setup(nbTireTypes, nbSurfaceTypes, (PxMaterialPtr*) drivableSurfaceMaterials, (physx::PxVehicleDrivableSurfaceType*) drivableSurfaceTypes);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceToTireFrictionPairs__1release(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDrivableSurfaceToTireFrictionPairs* self = (physx::PxVehicleDrivableSurfaceToTireFrictionPairs*) address;
    self->release();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceToTireFrictionPairs__1setTypePairFriction(JNIEnv* env, jclass, jlong address, jint surfaceType, jint tireType, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDrivableSurfaceToTireFrictionPairs* self = (physx::PxVehicleDrivableSurfaceToTireFrictionPairs*) address;
    self->setTypePairFriction(surfaceType, tireType, value);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceToTireFrictionPairs__1getTypePairFriction(JNIEnv* env, jclass, jlong address, jint surfaceType, jint tireType) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDrivableSurfaceToTireFrictionPairs* self = (physx::PxVehicleDrivableSurfaceToTireFrictionPairs*) address;
    return (jfloat) self->getTypePairFriction(surfaceType, tireType);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceToTireFrictionPairs__1getMaxNbSurfaceTypes(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDrivableSurfaceToTireFrictionPairs* self = (physx::PxVehicleDrivableSurfaceToTireFrictionPairs*) address;
    return (jint) self->getMaxNbSurfaceTypes();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceToTireFrictionPairs__1getMaxNbTireTypes(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDrivableSurfaceToTireFrictionPairs* self = (physx::PxVehicleDrivableSurfaceToTireFrictionPairs*) address;
    return (jint) self->getMaxNbTireTypes();
}

// PxVehicleDrivableSurfaceType
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceType__1PxVehicleDrivableSurfaceType(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxVehicleDrivableSurfaceType();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceType__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxVehicleDrivableSurfaceType*) address;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceType__1getMType(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDrivableSurfaceType* self = (physx::PxVehicleDrivableSurfaceType*) address;
    return (jint) self->mType;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDrivableSurfaceType__1setMType(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDrivableSurfaceType* self = (physx::PxVehicleDrivableSurfaceType*) address;
    self->mType = value;
}

// PxVehicleDrive
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDrive__1getMDriveDynData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDrive* self = (physx::PxVehicleDrive*) address;
    return (jlong) &self->mDriveDynData;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDrive__1setMDriveDynData(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDrive* self = (physx::PxVehicleDrive*) address;
    self->mDriveDynData = *((physx::PxVehicleDriveDynData*) value);
}

// PxVehicleDrive4W
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDrive4W__1allocate(JNIEnv* env, jclass, jint nbWheels) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) physx::PxVehicleDrive4W::allocate(nbWheels);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDrive4W__1free(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDrive4W* self = (physx::PxVehicleDrive4W*) address;
    self->free();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDrive4W__1setup(JNIEnv* env, jclass, jlong address, jlong physics, jlong vehActor, jlong wheelsData, jlong driveData, jint nbNonDrivenWheels) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDrive4W* self = (physx::PxVehicleDrive4W*) address;
    self->setup((physx::PxPhysics*) physics, (physx::PxRigidDynamic*) vehActor, *((physx::PxVehicleWheelsSimData*) wheelsData), *((physx::PxVehicleDriveSimData4W*) driveData), nbNonDrivenWheels);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDrive4W__1setToRestState(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDrive4W* self = (physx::PxVehicleDrive4W*) address;
    self->setToRestState();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDrive4W__1getMDriveSimData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDrive4W* self = (physx::PxVehicleDrive4W*) address;
    return (jlong) &self->mDriveSimData;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDrive4W__1setMDriveSimData(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDrive4W* self = (physx::PxVehicleDrive4W*) address;
    self->mDriveSimData = *((physx::PxVehicleDriveSimData4W*) value);
}

// PxVehicleDriveDynData
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setToRestState(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->setToRestState();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setAnalogInput(JNIEnv* env, jclass, jlong address, jint type, jfloat analogVal) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->setAnalogInput(type, analogVal);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getAnalogInput(JNIEnv* env, jclass, jlong address, jint type) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    return (jfloat) self->getAnalogInput(type);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setGearUp(JNIEnv* env, jclass, jlong address, jboolean digitalVal) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->setGearUp(digitalVal);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setGearDown(JNIEnv* env, jclass, jlong address, jboolean digitalVal) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->setGearDown(digitalVal);
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getGearUp(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    return (jboolean) self->getGearUp();
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getGearDown(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    return (jboolean) self->getGearDown();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setUseAutoGears(JNIEnv* env, jclass, jlong address, jboolean useAutoGears) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->setUseAutoGears(useAutoGears);
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getUseAutoGears(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    return (jboolean) self->getUseAutoGears();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1toggleAutoGears(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->toggleAutoGears();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setCurrentGear(JNIEnv* env, jclass, jlong address, jint currentGear) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->setCurrentGear(currentGear);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getCurrentGear(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    return (jint) self->getCurrentGear();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setTargetGear(JNIEnv* env, jclass, jlong address, jint targetGear) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->setTargetGear(targetGear);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getTargetGear(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    return (jint) self->getTargetGear();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1startGearChange(JNIEnv* env, jclass, jlong address, jint targetGear) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->startGearChange(targetGear);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1forceGearChange(JNIEnv* env, jclass, jlong address, jint targetGear) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->forceGearChange(targetGear);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setEngineRotationSpeed(JNIEnv* env, jclass, jlong address, jfloat speed) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->setEngineRotationSpeed(speed);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getEngineRotationSpeed(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    return (jfloat) self->getEngineRotationSpeed();
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getGearSwitchTime(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    return (jfloat) self->getGearSwitchTime();
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getAutoBoxSwitchTime(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    return (jfloat) self->getAutoBoxSwitchTime();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getNbAnalogInput(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    return (jint) self->getNbAnalogInput();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setGearChange(JNIEnv* env, jclass, jlong address, jint gearChange) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->setGearChange(gearChange);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getGearChange(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    return (jint) self->getGearChange();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setGearSwitchTime(JNIEnv* env, jclass, jlong address, jfloat switchTime) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->setGearSwitchTime(switchTime);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setAutoBoxSwitchTime(JNIEnv* env, jclass, jlong address, jfloat autoBoxSwitchTime) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->setAutoBoxSwitchTime(autoBoxSwitchTime);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxVehicleDriveDynData*) address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getMControlAnalogVals(JNIEnv* env, jclass, jlong address, jint index) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    return (jfloat) self->mControlAnalogVals[index];
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setMControlAnalogVals(JNIEnv* env, jclass, jlong address, jint index, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->mControlAnalogVals[index] = value;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getMUseAutoGears(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    return (jboolean) self->mUseAutoGears;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setMUseAutoGears(JNIEnv* env, jclass, jlong address, jboolean value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->mUseAutoGears = value;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getMGearUpPressed(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    return (jboolean) self->mGearUpPressed;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setMGearUpPressed(JNIEnv* env, jclass, jlong address, jboolean value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->mGearUpPressed = value;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getMGearDownPressed(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    return (jboolean) self->mGearDownPressed;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setMGearDownPressed(JNIEnv* env, jclass, jlong address, jboolean value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->mGearDownPressed = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getMCurrentGear(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    return (jint) self->mCurrentGear;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setMCurrentGear(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->mCurrentGear = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getMTargetGear(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    return (jint) self->mTargetGear;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setMTargetGear(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->mTargetGear = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getMEnginespeed(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    return (jfloat) self->mEnginespeed;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setMEnginespeed(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->mEnginespeed = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getMGearSwitchTime(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    return (jfloat) self->mGearSwitchTime;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setMGearSwitchTime(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->mGearSwitchTime = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1getMAutoBoxSwitchTime(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    return (jfloat) self->mAutoBoxSwitchTime;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveDynData__1setMAutoBoxSwitchTime(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveDynData* self = (physx::PxVehicleDriveDynData*) address;
    self->mAutoBoxSwitchTime = value;
}

// PxVehicleDriveSimData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDriveSimData__1PxVehicleDriveSimData(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxVehicleDriveSimData();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDriveSimData__1getEngineData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveSimData* self = (physx::PxVehicleDriveSimData*) address;
    return (jlong) &self->getEngineData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveSimData__1setEngineData(JNIEnv* env, jclass, jlong address, jlong engine) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveSimData* self = (physx::PxVehicleDriveSimData*) address;
    self->setEngineData(*((physx::PxVehicleEngineData*) engine));
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDriveSimData__1getGearsData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveSimData* self = (physx::PxVehicleDriveSimData*) address;
    return (jlong) &self->getGearsData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveSimData__1setGearsData(JNIEnv* env, jclass, jlong address, jlong gears) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveSimData* self = (physx::PxVehicleDriveSimData*) address;
    self->setGearsData(*((physx::PxVehicleGearsData*) gears));
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDriveSimData__1getClutchData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveSimData* self = (physx::PxVehicleDriveSimData*) address;
    return (jlong) &self->getClutchData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveSimData__1setClutchData(JNIEnv* env, jclass, jlong address, jlong clutch) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveSimData* self = (physx::PxVehicleDriveSimData*) address;
    self->setClutchData(*((physx::PxVehicleClutchData*) clutch));
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDriveSimData__1getAutoBoxData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveSimData* self = (physx::PxVehicleDriveSimData*) address;
    return (jlong) &self->getAutoBoxData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveSimData__1setAutoBoxData(JNIEnv* env, jclass, jlong address, jlong clutch) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveSimData* self = (physx::PxVehicleDriveSimData*) address;
    self->setAutoBoxData(*((physx::PxVehicleAutoBoxData*) clutch));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveSimData__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxVehicleDriveSimData*) address;
}

// PxVehicleDriveSimData4W
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDriveSimData4W__1PxVehicleDriveSimData4W(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxVehicleDriveSimData4W();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDriveSimData4W__1getDiffData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveSimData4W* self = (physx::PxVehicleDriveSimData4W*) address;
    return (jlong) &self->getDiffData();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleDriveSimData4W__1getAckermannGeometryData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveSimData4W* self = (physx::PxVehicleDriveSimData4W*) address;
    return (jlong) &self->getAckermannGeometryData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveSimData4W__1setDiffData(JNIEnv* env, jclass, jlong address, jlong diff) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveSimData4W* self = (physx::PxVehicleDriveSimData4W*) address;
    self->setDiffData(*((physx::PxVehicleDifferential4WData*) diff));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveSimData4W__1setAckermannGeometryData(JNIEnv* env, jclass, jlong address, jlong ackermannData) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleDriveSimData4W* self = (physx::PxVehicleDriveSimData4W*) address;
    self->setAckermannGeometryData(*((physx::PxVehicleAckermannGeometryData*) ackermannData));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleDriveSimData4W__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxVehicleDriveSimData4W*) address;
}

// PxVehicleEngineData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleEngineData__1PxVehicleEngineData(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxVehicleEngineData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleEngineData__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxVehicleEngineData*) address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleEngineData__1getMTorqueCurve(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleEngineData* self = (physx::PxVehicleEngineData*) address;
    return (jlong) &self->mTorqueCurve;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleEngineData__1setMTorqueCurve(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleEngineData* self = (physx::PxVehicleEngineData*) address;
    self->mTorqueCurve = *((PxEngineTorqueLookupTable*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleEngineData__1getMMOI(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleEngineData* self = (physx::PxVehicleEngineData*) address;
    return (jfloat) self->mMOI;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleEngineData__1setMMOI(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleEngineData* self = (physx::PxVehicleEngineData*) address;
    self->mMOI = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleEngineData__1getMPeakTorque(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleEngineData* self = (physx::PxVehicleEngineData*) address;
    return (jfloat) self->mPeakTorque;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleEngineData__1setMPeakTorque(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleEngineData* self = (physx::PxVehicleEngineData*) address;
    self->mPeakTorque = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleEngineData__1getMMaxOmega(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleEngineData* self = (physx::PxVehicleEngineData*) address;
    return (jfloat) self->mMaxOmega;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleEngineData__1setMMaxOmega(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleEngineData* self = (physx::PxVehicleEngineData*) address;
    self->mMaxOmega = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleEngineData__1getMDampingRateFullThrottle(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleEngineData* self = (physx::PxVehicleEngineData*) address;
    return (jfloat) self->mDampingRateFullThrottle;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleEngineData__1setMDampingRateFullThrottle(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleEngineData* self = (physx::PxVehicleEngineData*) address;
    self->mDampingRateFullThrottle = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleEngineData__1getMDampingRateZeroThrottleClutchEngaged(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleEngineData* self = (physx::PxVehicleEngineData*) address;
    return (jfloat) self->mDampingRateZeroThrottleClutchEngaged;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleEngineData__1setMDampingRateZeroThrottleClutchEngaged(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleEngineData* self = (physx::PxVehicleEngineData*) address;
    self->mDampingRateZeroThrottleClutchEngaged = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleEngineData__1getMDampingRateZeroThrottleClutchDisengaged(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleEngineData* self = (physx::PxVehicleEngineData*) address;
    return (jfloat) self->mDampingRateZeroThrottleClutchDisengaged;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleEngineData__1setMDampingRateZeroThrottleClutchDisengaged(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleEngineData* self = (physx::PxVehicleEngineData*) address;
    self->mDampingRateZeroThrottleClutchDisengaged = value;
}

// PxEngineTorqueLookupTable
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1PxEngineTorqueLookupTable(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new PxEngineTorqueLookupTable();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1addPair(JNIEnv* env, jclass, jlong address, jfloat x, jfloat y) {
    (void) env;    // avoid unused parameter warning / error
    PxEngineTorqueLookupTable* self = (PxEngineTorqueLookupTable*) address;
    self->addPair(x, y);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1getYVal(JNIEnv* env, jclass, jlong address, jfloat x) {
    (void) env;    // avoid unused parameter warning / error
    PxEngineTorqueLookupTable* self = (PxEngineTorqueLookupTable*) address;
    return (jfloat) self->getYVal(x);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1getNbDataPairs(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    PxEngineTorqueLookupTable* self = (PxEngineTorqueLookupTable*) address;
    return (jint) self->getNbDataPairs();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1clear(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    PxEngineTorqueLookupTable* self = (PxEngineTorqueLookupTable*) address;
    self->clear();
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1getX(JNIEnv* env, jclass, jlong address, jint i) {
    (void) env;    // avoid unused parameter warning / error
    PxEngineTorqueLookupTable* self = (PxEngineTorqueLookupTable*) address;
    return (jfloat) self->getX(i);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1getY(JNIEnv* env, jclass, jlong address, jint i) {
    (void) env;    // avoid unused parameter warning / error
    PxEngineTorqueLookupTable* self = (PxEngineTorqueLookupTable*) address;
    return (jfloat) self->getY(i);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (PxEngineTorqueLookupTable*) address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1getMDataPairs(JNIEnv* env, jclass, jlong address, jint index) {
    (void) env;    // avoid unused parameter warning / error
    PxEngineTorqueLookupTable* self = (PxEngineTorqueLookupTable*) address;
    return (jfloat) self->mDataPairs[index];
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1setMDataPairs(JNIEnv* env, jclass, jlong address, jint index, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    PxEngineTorqueLookupTable* self = (PxEngineTorqueLookupTable*) address;
    self->mDataPairs[index] = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1getMNbDataPairs(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    PxEngineTorqueLookupTable* self = (PxEngineTorqueLookupTable*) address;
    return (jint) self->mNbDataPairs;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxEngineTorqueLookupTable__1setMNbDataPairs(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    PxEngineTorqueLookupTable* self = (PxEngineTorqueLookupTable*) address;
    self->mNbDataPairs = value;
}

// PxVehicleGearsData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleGearsData__1PxVehicleGearsData(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxVehicleGearsData();
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleGearsData__1getGearRatio(JNIEnv* env, jclass, jlong address, jint a) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleGearsData* self = (physx::PxVehicleGearsData*) address;
    return (jfloat) self->getGearRatio((PxVehicleGearEnum) a);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleGearsData__1setGearRatio(JNIEnv* env, jclass, jlong address, jint a, jfloat ratio) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleGearsData* self = (physx::PxVehicleGearsData*) address;
    self->setGearRatio((PxVehicleGearEnum) a, ratio);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleGearsData__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxVehicleGearsData*) address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleGearsData__1getMRatios(JNIEnv* env, jclass, jlong address, jint index) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleGearsData* self = (physx::PxVehicleGearsData*) address;
    return (jfloat) self->mRatios[index];
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleGearsData__1setMRatios(JNIEnv* env, jclass, jlong address, jint index, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleGearsData* self = (physx::PxVehicleGearsData*) address;
    self->mRatios[index] = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleGearsData__1getMFinalRatio(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleGearsData* self = (physx::PxVehicleGearsData*) address;
    return (jfloat) self->mFinalRatio;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleGearsData__1setMFinalRatio(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleGearsData* self = (physx::PxVehicleGearsData*) address;
    self->mFinalRatio = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleGearsData__1getMNbRatios(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleGearsData* self = (physx::PxVehicleGearsData*) address;
    return (jint) self->mNbRatios;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleGearsData__1setMNbRatios(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleGearsData* self = (physx::PxVehicleGearsData*) address;
    self->mNbRatios = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleGearsData__1getMSwitchTime(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleGearsData* self = (physx::PxVehicleGearsData*) address;
    return (jfloat) self->mSwitchTime;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleGearsData__1setMSwitchTime(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleGearsData* self = (physx::PxVehicleGearsData*) address;
    self->mSwitchTime = value;
}

// PxVehicleSuspensionData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1PxVehicleSuspensionData(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxVehicleSuspensionData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1setMassAndPreserveNaturalFrequency(JNIEnv* env, jclass, jlong address, jfloat newSprungMass) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleSuspensionData* self = (physx::PxVehicleSuspensionData*) address;
    self->setMassAndPreserveNaturalFrequency(newSprungMass);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxVehicleSuspensionData*) address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1getMSpringStrength(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleSuspensionData* self = (physx::PxVehicleSuspensionData*) address;
    return (jfloat) self->mSpringStrength;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1setMSpringStrength(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleSuspensionData* self = (physx::PxVehicleSuspensionData*) address;
    self->mSpringStrength = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1getMSpringDamperRate(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleSuspensionData* self = (physx::PxVehicleSuspensionData*) address;
    return (jfloat) self->mSpringDamperRate;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1setMSpringDamperRate(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleSuspensionData* self = (physx::PxVehicleSuspensionData*) address;
    self->mSpringDamperRate = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1getMMaxCompression(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleSuspensionData* self = (physx::PxVehicleSuspensionData*) address;
    return (jfloat) self->mMaxCompression;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1setMMaxCompression(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleSuspensionData* self = (physx::PxVehicleSuspensionData*) address;
    self->mMaxCompression = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1getMMaxDroop(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleSuspensionData* self = (physx::PxVehicleSuspensionData*) address;
    return (jfloat) self->mMaxDroop;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1setMMaxDroop(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleSuspensionData* self = (physx::PxVehicleSuspensionData*) address;
    self->mMaxDroop = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1getMSprungMass(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleSuspensionData* self = (physx::PxVehicleSuspensionData*) address;
    return (jfloat) self->mSprungMass;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1setMSprungMass(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleSuspensionData* self = (physx::PxVehicleSuspensionData*) address;
    self->mSprungMass = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1getMCamberAtRest(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleSuspensionData* self = (physx::PxVehicleSuspensionData*) address;
    return (jfloat) self->mCamberAtRest;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1setMCamberAtRest(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleSuspensionData* self = (physx::PxVehicleSuspensionData*) address;
    self->mCamberAtRest = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1getMCamberAtMaxCompression(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleSuspensionData* self = (physx::PxVehicleSuspensionData*) address;
    return (jfloat) self->mCamberAtMaxCompression;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1setMCamberAtMaxCompression(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleSuspensionData* self = (physx::PxVehicleSuspensionData*) address;
    self->mCamberAtMaxCompression = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1getMCamberAtMaxDroop(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleSuspensionData* self = (physx::PxVehicleSuspensionData*) address;
    return (jfloat) self->mCamberAtMaxDroop;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleSuspensionData__1setMCamberAtMaxDroop(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleSuspensionData* self = (physx::PxVehicleSuspensionData*) address;
    self->mCamberAtMaxDroop = value;
}

// PxVehicleTireData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleTireData__1PxVehicleTireData(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxVehicleTireData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireData__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxVehicleTireData*) address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleTireData__1getMLatStiffX(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleTireData* self = (physx::PxVehicleTireData*) address;
    return (jfloat) self->mLatStiffX;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireData__1setMLatStiffX(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleTireData* self = (physx::PxVehicleTireData*) address;
    self->mLatStiffX = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleTireData__1getMLatStiffY(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleTireData* self = (physx::PxVehicleTireData*) address;
    return (jfloat) self->mLatStiffY;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireData__1setMLatStiffY(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleTireData* self = (physx::PxVehicleTireData*) address;
    self->mLatStiffY = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleTireData__1getMLongitudinalStiffnessPerUnitGravity(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleTireData* self = (physx::PxVehicleTireData*) address;
    return (jfloat) self->mLongitudinalStiffnessPerUnitGravity;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireData__1setMLongitudinalStiffnessPerUnitGravity(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleTireData* self = (physx::PxVehicleTireData*) address;
    self->mLongitudinalStiffnessPerUnitGravity = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleTireData__1getMCamberStiffnessPerUnitGravity(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleTireData* self = (physx::PxVehicleTireData*) address;
    return (jfloat) self->mCamberStiffnessPerUnitGravity;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireData__1setMCamberStiffnessPerUnitGravity(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleTireData* self = (physx::PxVehicleTireData*) address;
    self->mCamberStiffnessPerUnitGravity = value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleTireData__1getMType(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleTireData* self = (physx::PxVehicleTireData*) address;
    return (jint) self->mType;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireData__1setMType(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleTireData* self = (physx::PxVehicleTireData*) address;
    self->mType = value;
}

// PxVehicleTireLoadFilterData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1PxVehicleTireLoadFilterData(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxVehicleTireLoadFilterData();
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1getDenominator(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleTireLoadFilterData* self = (physx::PxVehicleTireLoadFilterData*) address;
    return (jfloat) self->getDenominator();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxVehicleTireLoadFilterData*) address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1getMMinNormalisedLoad(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleTireLoadFilterData* self = (physx::PxVehicleTireLoadFilterData*) address;
    return (jfloat) self->mMinNormalisedLoad;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1setMMinNormalisedLoad(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleTireLoadFilterData* self = (physx::PxVehicleTireLoadFilterData*) address;
    self->mMinNormalisedLoad = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1getMMinFilteredNormalisedLoad(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleTireLoadFilterData* self = (physx::PxVehicleTireLoadFilterData*) address;
    return (jfloat) self->mMinFilteredNormalisedLoad;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1setMMinFilteredNormalisedLoad(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleTireLoadFilterData* self = (physx::PxVehicleTireLoadFilterData*) address;
    self->mMinFilteredNormalisedLoad = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1getMMaxNormalisedLoad(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleTireLoadFilterData* self = (physx::PxVehicleTireLoadFilterData*) address;
    return (jfloat) self->mMaxNormalisedLoad;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1setMMaxNormalisedLoad(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleTireLoadFilterData* self = (physx::PxVehicleTireLoadFilterData*) address;
    self->mMaxNormalisedLoad = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1getMMaxFilteredNormalisedLoad(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleTireLoadFilterData* self = (physx::PxVehicleTireLoadFilterData*) address;
    return (jfloat) self->mMaxFilteredNormalisedLoad;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleTireLoadFilterData__1setMMaxFilteredNormalisedLoad(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleTireLoadFilterData* self = (physx::PxVehicleTireLoadFilterData*) address;
    self->mMaxFilteredNormalisedLoad = value;
}

// PxVehicleWheelData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelData__1PxVehicleWheelData(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxVehicleWheelData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelData__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxVehicleWheelData*) address;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelData__1getMRadius(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelData* self = (physx::PxVehicleWheelData*) address;
    return (jfloat) self->mRadius;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelData__1setMRadius(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelData* self = (physx::PxVehicleWheelData*) address;
    self->mRadius = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelData__1getMWidth(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelData* self = (physx::PxVehicleWheelData*) address;
    return (jfloat) self->mWidth;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelData__1setMWidth(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelData* self = (physx::PxVehicleWheelData*) address;
    self->mWidth = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelData__1getMMass(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelData* self = (physx::PxVehicleWheelData*) address;
    return (jfloat) self->mMass;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelData__1setMMass(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelData* self = (physx::PxVehicleWheelData*) address;
    self->mMass = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelData__1getMMOI(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelData* self = (physx::PxVehicleWheelData*) address;
    return (jfloat) self->mMOI;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelData__1setMMOI(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelData* self = (physx::PxVehicleWheelData*) address;
    self->mMOI = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelData__1getMDampingRate(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelData* self = (physx::PxVehicleWheelData*) address;
    return (jfloat) self->mDampingRate;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelData__1setMDampingRate(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelData* self = (physx::PxVehicleWheelData*) address;
    self->mDampingRate = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelData__1getMMaxBrakeTorque(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelData* self = (physx::PxVehicleWheelData*) address;
    return (jfloat) self->mMaxBrakeTorque;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelData__1setMMaxBrakeTorque(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelData* self = (physx::PxVehicleWheelData*) address;
    self->mMaxBrakeTorque = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelData__1getMMaxHandBrakeTorque(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelData* self = (physx::PxVehicleWheelData*) address;
    return (jfloat) self->mMaxHandBrakeTorque;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelData__1setMMaxHandBrakeTorque(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelData* self = (physx::PxVehicleWheelData*) address;
    self->mMaxHandBrakeTorque = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelData__1getMMaxSteer(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelData* self = (physx::PxVehicleWheelData*) address;
    return (jfloat) self->mMaxSteer;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelData__1setMMaxSteer(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelData* self = (physx::PxVehicleWheelData*) address;
    self->mMaxSteer = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelData__1getMToeAngle(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelData* self = (physx::PxVehicleWheelData*) address;
    return (jfloat) self->mToeAngle;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelData__1setMToeAngle(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelData* self = (physx::PxVehicleWheelData*) address;
    self->mToeAngle = value;
}

// PxVehicleWheelQueryResult
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelQueryResult__1PxVehicleWheelQueryResult(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxVehicleWheelQueryResult();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelQueryResult__1getWheelQueryResults(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelQueryResult* self = (physx::PxVehicleWheelQueryResult*) address;
    return (jlong) self->wheelQueryResults;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelQueryResult__1setWheelQueryResults(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelQueryResult* self = (physx::PxVehicleWheelQueryResult*) address;
    self->wheelQueryResults = (physx::PxWheelQueryResult*) value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelQueryResult__1getNbWheelQueryResults(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelQueryResult* self = (physx::PxVehicleWheelQueryResult*) address;
    return (jint) self->nbWheelQueryResults;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelQueryResult__1setNbWheelQueryResults(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelQueryResult* self = (physx::PxVehicleWheelQueryResult*) address;
    self->nbWheelQueryResults = value;
}

// PxVehicleWheels
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheels__1getVehicleType(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheels* self = (physx::PxVehicleWheels*) address;
    return (jint) self->getVehicleType();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheels__1getRigidDynamicActor(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheels* self = (physx::PxVehicleWheels*) address;
    return (jlong) self->getRigidDynamicActor();
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheels__1computeForwardSpeed(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheels* self = (physx::PxVehicleWheels*) address;
    return (jfloat) self->computeForwardSpeed();
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheels__1computeSidewaysSpeed(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheels* self = (physx::PxVehicleWheels*) address;
    return (jfloat) self->computeSidewaysSpeed();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheels__1getNbNonDrivenWheels(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheels* self = (physx::PxVehicleWheels*) address;
    return (jint) self->getNbNonDrivenWheels();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheels__1getMWheelsSimData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheels* self = (physx::PxVehicleWheels*) address;
    return (jlong) &self->mWheelsSimData;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheels__1setMWheelsSimData(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheels* self = (physx::PxVehicleWheels*) address;
    self->mWheelsSimData = *((physx::PxVehicleWheelsSimData*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheels__1getMWheelsDynData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheels* self = (physx::PxVehicleWheels*) address;
    return (jlong) &self->mWheelsDynData;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheels__1setMWheelsDynData(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheels* self = (physx::PxVehicleWheels*) address;
    self->mWheelsDynData = *((physx::PxVehicleWheelsDynData*) value);
}

// PxVehicleWheelsDynData
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsDynData__1setToRestState(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsDynData* self = (physx::PxVehicleWheelsDynData*) address;
    self->setToRestState();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsDynData__1setWheelRotationSpeed(JNIEnv* env, jclass, jlong address, jint wheelIdx, jfloat speed) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsDynData* self = (physx::PxVehicleWheelsDynData*) address;
    self->setWheelRotationSpeed(wheelIdx, speed);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelsDynData__1getWheelRotationSpeed(JNIEnv* env, jclass, jlong address, jint wheelIdx) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsDynData* self = (physx::PxVehicleWheelsDynData*) address;
    return (jfloat) self->getWheelRotationSpeed(wheelIdx);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsDynData__1setWheelRotationAngle(JNIEnv* env, jclass, jlong address, jint wheelIdx, jfloat angle) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsDynData* self = (physx::PxVehicleWheelsDynData*) address;
    self->setWheelRotationAngle(wheelIdx, angle);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelsDynData__1getWheelRotationAngle(JNIEnv* env, jclass, jlong address, jint wheelIdx) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsDynData* self = (physx::PxVehicleWheelsDynData*) address;
    return (jfloat) self->getWheelRotationAngle(wheelIdx);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsDynData__1copy(JNIEnv* env, jclass, jlong address, jlong src, jint srcWheel, jint trgWheel) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsDynData* self = (physx::PxVehicleWheelsDynData*) address;
    self->copy(*((physx::PxVehicleWheelsDynData*) src), srcWheel, trgWheel);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsDynData__1getNbWheelRotationSpeed(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsDynData* self = (physx::PxVehicleWheelsDynData*) address;
    return (jint) self->getNbWheelRotationSpeed();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsDynData__1getNbWheelRotationAngle(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsDynData* self = (physx::PxVehicleWheelsDynData*) address;
    return (jint) self->getNbWheelRotationAngle();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsDynData__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxVehicleWheelsDynData*) address;
}

// PxVehicleWheelsSimData
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1allocate(JNIEnv* env, jclass, jint nbWheels) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) physx::PxVehicleWheelsSimData::allocate(nbWheels);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setChassisMass(JNIEnv* env, jclass, jlong address, jfloat chassisMass) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->setChassisMass(chassisMass);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1free(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->free();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1copy(JNIEnv* env, jclass, jlong address, jlong src, jint srcWheel, jint trgWheel) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->copy(*((physx::PxVehicleWheelsSimData*) src), srcWheel, trgWheel);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbWheels(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jint) self->getNbWheels();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getSuspensionData(JNIEnv* env, jclass, jlong address, jint id) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jlong) &self->getSuspensionData(id);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getWheelData(JNIEnv* env, jclass, jlong address, jint id) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jlong) &self->getWheelData(id);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getTireData(JNIEnv* env, jclass, jlong address, jint id) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jlong) &self->getTireData(id);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getSuspTravelDirection(JNIEnv* env, jclass, jlong address, jint id) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jlong) &self->getSuspTravelDirection(id);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getSuspForceAppPointOffset(JNIEnv* env, jclass, jlong address, jint id) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jlong) &self->getSuspForceAppPointOffset(id);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getTireForceAppPointOffset(JNIEnv* env, jclass, jlong address, jint id) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jlong) &self->getTireForceAppPointOffset(id);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getWheelCentreOffset(JNIEnv* env, jclass, jlong address, jint id) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jlong) &self->getWheelCentreOffset(id);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getWheelShapeMapping(JNIEnv* env, jclass, jlong address, jint wheelId) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jint) self->getWheelShapeMapping(wheelId);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getSceneQueryFilterData(JNIEnv* env, jclass, jlong address, jint suspId) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jlong) &self->getSceneQueryFilterData(suspId);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbAntiRollBars(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jint) self->getNbAntiRollBars();
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getAntiRollBarData(JNIEnv* env, jclass, jlong address, jint antiRollId) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jlong) &self->getAntiRollBarData(antiRollId);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getTireLoadFilterData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jlong) &self->getTireLoadFilterData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setSuspensionData(JNIEnv* env, jclass, jlong address, jint id, jlong susp) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->setSuspensionData(id, *((physx::PxVehicleSuspensionData*) susp));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setWheelData(JNIEnv* env, jclass, jlong address, jint id, jlong wheel) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->setWheelData(id, *((physx::PxVehicleWheelData*) wheel));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setTireData(JNIEnv* env, jclass, jlong address, jint id, jlong tire) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->setTireData(id, *((physx::PxVehicleTireData*) tire));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setSuspTravelDirection(JNIEnv* env, jclass, jlong address, jint id, jlong dir) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->setSuspTravelDirection(id, *((physx::PxVec3*) dir));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setSuspForceAppPointOffset(JNIEnv* env, jclass, jlong address, jint id, jlong offset) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->setSuspForceAppPointOffset(id, *((physx::PxVec3*) offset));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setTireForceAppPointOffset(JNIEnv* env, jclass, jlong address, jint id, jlong offset) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->setTireForceAppPointOffset(id, *((physx::PxVec3*) offset));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setWheelCentreOffset(JNIEnv* env, jclass, jlong address, jint id, jlong offset) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->setWheelCentreOffset(id, *((physx::PxVec3*) offset));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setWheelShapeMapping(JNIEnv* env, jclass, jlong address, jint wheelId, jint shapeId) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->setWheelShapeMapping(wheelId, shapeId);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setSceneQueryFilterData(JNIEnv* env, jclass, jlong address, jint suspId, jlong sqFilterData) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->setSceneQueryFilterData(suspId, *((physx::PxFilterData*) sqFilterData));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setTireLoadFilterData(JNIEnv* env, jclass, jlong address, jlong tireLoadFilter) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->setTireLoadFilterData(*((physx::PxVehicleTireLoadFilterData*) tireLoadFilter));
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1addAntiRollBarData(JNIEnv* env, jclass, jlong address, jlong antiRoll) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jint) self->addAntiRollBarData(*((physx::PxVehicleAntiRollBarData*) antiRoll));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1disableWheel(JNIEnv* env, jclass, jlong address, jint wheel) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->disableWheel(wheel);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1enableWheel(JNIEnv* env, jclass, jlong address, jint wheel) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->enableWheel(wheel);
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getIsWheelDisabled(JNIEnv* env, jclass, jlong address, jint wheel) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jboolean) self->getIsWheelDisabled(wheel);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setSubStepCount(JNIEnv* env, jclass, jlong address, jfloat thresholdLongitudinalSpeed, jint lowForwardSpeedSubStepCount, jint highForwardSpeedSubStepCount) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->setSubStepCount(thresholdLongitudinalSpeed, lowForwardSpeedSubStepCount, highForwardSpeedSubStepCount);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setMinLongSlipDenominator(JNIEnv* env, jclass, jlong address, jfloat minLongSlipDenominator) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->setMinLongSlipDenominator(minLongSlipDenominator);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setFlags(JNIEnv* env, jclass, jlong address, jlong flags) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->setFlags(*((physx::PxVehicleWheelsSimFlags*) flags));
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getFlags(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    static physx::PxVehicleWheelsSimFlags cache;
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    cache = self->getFlags();
    return (jlong) &cache;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbWheels4(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jint) self->getNbWheels4();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbSuspensionData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jint) self->getNbSuspensionData();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbWheelData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jint) self->getNbWheelData();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbSuspTravelDirection(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jint) self->getNbSuspTravelDirection();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbTireData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jint) self->getNbTireData();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbSuspForceAppPointOffset(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jint) self->getNbSuspForceAppPointOffset();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbTireForceAppPointOffset(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jint) self->getNbTireForceAppPointOffset();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbWheelCentreOffset(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jint) self->getNbWheelCentreOffset();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbWheelShapeMapping(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jint) self->getNbWheelShapeMapping();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbSceneQueryFilterData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jint) self->getNbSceneQueryFilterData();
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getMinLongSlipDenominator(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jfloat) self->getMinLongSlipDenominator();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setThresholdLongSpeed(JNIEnv* env, jclass, jlong address, jfloat f) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->setThresholdLongSpeed(f);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getThresholdLongSpeed(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jfloat) self->getThresholdLongSpeed();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setLowForwardSpeedSubStepCount(JNIEnv* env, jclass, jlong address, jint f) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->setLowForwardSpeedSubStepCount(f);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getLowForwardSpeedSubStepCount(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jint) self->getLowForwardSpeedSubStepCount();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setHighForwardSpeedSubStepCount(JNIEnv* env, jclass, jlong address, jint f) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->setHighForwardSpeedSubStepCount(f);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getHighForwardSpeedSubStepCount(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jint) self->getHighForwardSpeedSubStepCount();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setWheelEnabledState(JNIEnv* env, jclass, jlong address, jint wheel, jboolean state) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->setWheelEnabledState(wheel, state);
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getWheelEnabledState(JNIEnv* env, jclass, jlong address, jint wheel) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jboolean) self->getWheelEnabledState(wheel);
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbWheelEnabledState(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jint) self->getNbWheelEnabledState();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbAntiRollBars4(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jint) self->getNbAntiRollBars4();
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1getNbAntiRollBarData(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    return (jint) self->getNbAntiRollBarData();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1setAntiRollBarData(JNIEnv* env, jclass, jlong address, jint id, jlong antiRoll) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimData* self = (physx::PxVehicleWheelsSimData*) address;
    self->setAntiRollBarData(id, *((physx::PxVehicleAntiRollBarData*) antiRoll));
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimData__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxVehicleWheelsSimData*) address;
}

// PxVehicleWheelsSimFlags
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxVehicleWheelsSimFlags__1PxVehicleWheelsSimFlags(JNIEnv* env, jclass, jint flags) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxVehicleWheelsSimFlags(flags);
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxVehicleWheelsSimFlags__1isSet(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimFlags* self = (physx::PxVehicleWheelsSimFlags*) address;
    return (jboolean) self->isSet((PxVehicleWheelsSimFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimFlags__1set(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimFlags* self = (physx::PxVehicleWheelsSimFlags*) address;
    self->set((PxVehicleWheelsSimFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimFlags__1clear(JNIEnv* env, jclass, jlong address, jint flag) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxVehicleWheelsSimFlags* self = (physx::PxVehicleWheelsSimFlags*) address;
    self->clear((PxVehicleWheelsSimFlagEnum) flag);
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxVehicleWheelsSimFlags__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxVehicleWheelsSimFlags*) address;
}

// PxWheelQueryResult
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1PxWheelQueryResult(JNIEnv* env, jclass) {
    (void) env;    // avoid unused parameter warning / error
    return (jlong) new physx::PxWheelQueryResult();
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1delete_1native_1instance(JNIEnv*, jclass, jlong address) {
    delete (physx::PxWheelQueryResult*) address;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1getSuspLineStart(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    return (jlong) &self->suspLineStart;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setSuspLineStart(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    self->suspLineStart = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1getSuspLineDir(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    return (jlong) &self->suspLineDir;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setSuspLineDir(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    self->suspLineDir = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxWheelQueryResult__1getSuspLineLength(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    return (jfloat) self->suspLineLength;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setSuspLineLength(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    self->suspLineLength = value;
}
JNIEXPORT jboolean JNICALL Java_physx_vehicle_PxWheelQueryResult__1getIsInAir(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    return (jboolean) self->isInAir;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setIsInAir(JNIEnv* env, jclass, jlong address, jboolean value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    self->isInAir = value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1getTireContactActor(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    return (jlong) self->tireContactActor;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setTireContactActor(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    self->tireContactActor = (physx::PxActor*) value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1getTireContactShape(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    return (jlong) self->tireContactShape;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setTireContactShape(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    self->tireContactShape = (physx::PxShape*) value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1getTireSurfaceMaterial(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    return (jlong) self->tireSurfaceMaterial;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setTireSurfaceMaterial(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    self->tireSurfaceMaterial = (physx::PxMaterial*) value;
}
JNIEXPORT jint JNICALL Java_physx_vehicle_PxWheelQueryResult__1getTireSurfaceType(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    return (jint) self->tireSurfaceType;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setTireSurfaceType(JNIEnv* env, jclass, jlong address, jint value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    self->tireSurfaceType = value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1getTireContactPoint(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    return (jlong) &self->tireContactPoint;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setTireContactPoint(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    self->tireContactPoint = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1getTireContactNormal(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    return (jlong) &self->tireContactNormal;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setTireContactNormal(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    self->tireContactNormal = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxWheelQueryResult__1getTireFriction(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    return (jfloat) self->tireFriction;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setTireFriction(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    self->tireFriction = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxWheelQueryResult__1getSuspJounce(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    return (jfloat) self->suspJounce;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setSuspJounce(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    self->suspJounce = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxWheelQueryResult__1getSuspSpringForce(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    return (jfloat) self->suspSpringForce;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setSuspSpringForce(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    self->suspSpringForce = value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1getTireLongitudinalDir(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    return (jlong) &self->tireLongitudinalDir;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setTireLongitudinalDir(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    self->tireLongitudinalDir = *((physx::PxVec3*) value);
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1getTireLateralDir(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    return (jlong) &self->tireLateralDir;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setTireLateralDir(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    self->tireLateralDir = *((physx::PxVec3*) value);
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxWheelQueryResult__1getLongitudinalSlip(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    return (jfloat) self->longitudinalSlip;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setLongitudinalSlip(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    self->longitudinalSlip = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxWheelQueryResult__1getLateralSlip(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    return (jfloat) self->lateralSlip;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setLateralSlip(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    self->lateralSlip = value;
}
JNIEXPORT jfloat JNICALL Java_physx_vehicle_PxWheelQueryResult__1getSteerAngle(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    return (jfloat) self->steerAngle;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setSteerAngle(JNIEnv* env, jclass, jlong address, jfloat value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    self->steerAngle = value;
}
JNIEXPORT jlong JNICALL Java_physx_vehicle_PxWheelQueryResult__1getLocalPose(JNIEnv* env, jclass, jlong address) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    return (jlong) &self->localPose;
}
JNIEXPORT void JNICALL Java_physx_vehicle_PxWheelQueryResult__1setLocalPose(JNIEnv* env, jclass, jlong address, jlong value) {
    (void) env;    // avoid unused parameter warning / error
    physx::PxWheelQueryResult* self = (physx::PxWheelQueryResult*) address;
    self->localPose = *((physx::PxTransform*) value);
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
