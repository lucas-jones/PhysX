#include "PxPhysicsAPI.h"

namespace physx {

    class PxCudaBufferMemorySpace {
        public:
            enum Enum {
                T_GPU,
                T_PINNED_HOST,
                T_WRITE_COMBINED,
                T_HOST
            };
    };

    class PxCudaInteropMode {
        public:
            enum Enum {
                NO_INTEROP,
                D3D10_INTEROP,
                D3D11_INTEROP,
                OGL_INTEROP
            };
    };

    class PxCudaContextManager {
        public: 
            bool contextIsValid() { return false; }
            bool supportsArchSM10() { return false; }
            bool supportsArchSM11() { return false; }
            bool supportsArchSM12() { return false; }
            bool supportsArchSM13() { return false; }
            bool supportsArchSM20() { return false; }
            bool supportsArchSM30() { return false; }
            bool supportsArchSM35() { return false; }
            bool supportsArchSM50() { return false; }
            bool supportsArchSM52() { return false; }
            bool isIntegrated() { return false; }
            bool canMapHostMemory() { return false; }
            int getDriverVersion() { return 0; }
            size_t getDeviceTotalMemBytes() { return 0; }
            int getMultiprocessorCount() { return 0; }
            unsigned int getClockRate() { return 0; }
            int getSharedMemPerBlock() { return 0; }
            unsigned int getMaxThreadsPerBlock() { return 0; }
            const char* getDeviceName() { return "mock"; }
            PxCudaInteropMode::Enum getInteropMode() { return PxCudaInteropMode::Enum::NO_INTEROP; }
            void setUsingConcurrentStreams(bool flag) { }
            bool getUsingConcurrentStreams() { return false; }
            int usingDedicatedGPU() { return 0; }
            void release() { }
    };

    class PxCudaContextManagerDesc {
        public:
            void* graphicsDevice = NULL;
            PxCudaInteropMode::Enum interopMode = PxCudaInteropMode::Enum::NO_INTEROP;
            PxU32 maxMemorySize[1];
            PxU32 memoryBaseSize[1];
            PxU32 memoryPageSize[1];
    };
}