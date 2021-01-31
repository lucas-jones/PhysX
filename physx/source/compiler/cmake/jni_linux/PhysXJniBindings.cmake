##
## Redistribution and use in source and binary forms, with or without
## modification, are permitted provided that the following conditions
## are met:
##  * Redistributions of source code must retain the above copyright
##    notice, this list of conditions and the following disclaimer.
##  * Redistributions in binary form must reproduce the above copyright
##    notice, this list of conditions and the following disclaimer in the
##    documentation and/or other materials provided with the distribution.
##  * Neither the name of NVIDIA CORPORATION nor the names of its
##    contributors may be used to endorse or promote products derived
##    from this software without specific prior written permission.
##
## THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
## EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
## IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
## PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
## CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
## EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
## PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
## PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
## OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
## (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
## OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
##
## Copyright (c) 2018-2019 NVIDIA Corporation. All rights reserved.

#
# Build JNI Bindings
#

FIND_PACKAGE(JNI REQUIRED)

SET(PHYSX_SOURCE_DIR ${PHYSX_ROOT_DIR}/source)
SET(LL_SOURCE_DIR ${PHYSX_SOURCE_DIR}/physxjnibindings/src)

SET(PHYSX_JNIBINDINGS_LIBTYPE SHARED)
SET(PXJNIBINDINGS_LIBTYPE_DEFS
	PX_PHYSX_FOUNDATION_EXPORTS;PX_PHYSX_COMMON_EXPORTS;PX_PHYSX_COOKING_EXPORTS;PX_PHYSX_LOADER_EXPORTS;PX_PHYSX_CORE_EXPORTS
)

SET(PHYSX_JNIBINDINGS_COMPILE_DEFS
	# Common to all configurations
	${PHYSX_LINUX_COMPILE_DEFS};PX_JNIBINDINGS;${PXJNIBINDINGS_LIBTYPE_DEFS}

	$<$<CONFIG:debug>:${PHYSX_LINUX_DEBUG_COMPILE_DEFS};>
	$<$<CONFIG:checked>:${PHYSX_LINUX_CHECKED_COMPILE_DEFS};>
	$<$<CONFIG:profile>:${PHYSX_LINUX_PROFILE_COMPILE_DEFS};>
	$<$<CONFIG:release>:${PHYSX_LINUX_RELEASE_COMPILE_DEFS};>
)

SET(PHYSX_JNIBINDINGS_LINK_FLAGS " ")
SET(PHYSX_JNIBINDINGS_LINK_FLAGS_DEBUG " ")
SET(PHYSX_JNIBINDINGS_LINK_FLAGS_CHECKED " ")
SET(PHYSX_JNIBINDINGS_LINK_FLAGS_PROFILE " ")
SET(PHYSX_JNIBINDINGS_LINK_FLAGS_RELEASE " ")


SET(PHYSX_JNIBINDINGS_HEADERS

)
SOURCE_GROUP(include FILES ${PHYSX_JNIBINDINGS_HEADERS})

SET(PHYSX_JNIBINDINGS_SOURCE
	${LL_SOURCE_DIR}/PhysXJni.cpp
)
SOURCE_GROUP(src FILES ${PHYSX_JNIBINDINGS_SOURCE})

ADD_LIBRARY(PhysXJniBindings ${PHYSX_JNIBINDINGS_LIBTYPE}
	${PHYSX_JNIBINDINGS_SOURCE}
	${PHYSX_JNIBINDINGS_HEADERS}
)

TARGET_INCLUDE_DIRECTORIES(PhysXJniBindings 
	PRIVATE ${JNI_INCLUDE_DIRS}
	PRIVATE ${PHYSX_JNIBINDINGS_PLATFORM_INCLUDES}

	PRIVATE ${PHYSX_ROOT_DIR}/include

	PRIVATE ${PHYSX_SOURCE_DIR}/common/include
	PRIVATE ${PHYSX_SOURCE_DIR}/common/src

	PRIVATE ${PHYSX_SOURCE_DIR}/physxvehicle/src
	PRIVATE ${PHYSX_SOURCE_DIR}/physxvehicle/src/physxmetadata/include

	PRIVATE ${PHYSX_SOURCE_DIR}/physxmetadata/extensions/include
	PRIVATE ${PHYSX_SOURCE_DIR}/physxmetadata/core/include

	PRIVATE ${PHYSX_SOURCE_DIR}/physxextensions/src/serialization/Xml

	PRIVATE ${PHYSX_SOURCE_DIR}/pvdsdk/src
	
	PRIVATE ${PHYSX_SOURCE_DIR}/pvd/include	
)

TARGET_LINK_LIBRARIES(PhysXJniBindings 
	PUBLIC PhysXCommon
	PUBLIC PhysXFoundation
	PUBLIC PhysXExtensions
	PUBLIC PhysXCooking
	PUBLIC PhysXVehicle
)

# Use generator expressions to set config specific preprocessor definitions
TARGET_COMPILE_DEFINITIONS(PhysXJniBindings 
	PRIVATE ${PHYSX_JNIBINDINGS_COMPILE_DEFS}
)

SET_TARGET_PROPERTIES(PhysXJniBindings PROPERTIES
	OUTPUT_NAME PhysXJniBindings
)
	

IF(NV_USE_GAMEWORKS_OUTPUT_DIRS AND PHYSX_JNIBINDINGS_LIBTYPE STREQUAL "STATIC")	
	SET_TARGET_PROPERTIES(PhysXJniBindings PROPERTIES 
		ARCHIVE_OUTPUT_NAME_DEBUG "PhysXJniBindings_static"
		ARCHIVE_OUTPUT_NAME_CHECKED "PhysXJniBindings_static"
		ARCHIVE_OUTPUT_NAME_PROFILE "PhysXJniBindings_static"
		ARCHIVE_OUTPUT_NAME_RELEASE "PhysXJniBindings_static"
	)
ENDIF()

TARGET_LINK_LIBRARIES(PhysXJniBindings
	PUBLIC ${PHYSX_JNIBINDINGS_PLATFORM_LINKED_LIBS} PhysXFoundation PhysXPvdSDK
)

SET_TARGET_PROPERTIES(PhysXJniBindings PROPERTIES 
	LINK_FLAGS ${PHYSX_JNIBINDINGS_LINK_FLAGS}
	LINK_FLAGS_DEBUG ${PHYSX_JNIBINDINGS_LINK_FLAGS_DEBUG}
	LINK_FLAGS_CHECKED ${PHYSX_JNIBINDINGS_LINK_FLAGS_CHECKED}
	LINK_FLAGS_PROFILE ${PHYSX_JNIBINDINGS_LINK_FLAGS_PROFILE}
	LINK_FLAGS_RELEASE ${PHYSX_JNIBINDINGS_LINK_FLAGS_RELEASE}
)

IF(PX_GENERATE_SOURCE_DISTRO)			
	LIST(APPEND SOURCE_DISTRO_FILE_LIST ${PHYSX_JNIBINDINGS_SOURCE})
	LIST(APPEND SOURCE_DISTRO_FILE_LIST ${PHYSX_JNIBINDINGS_HEADERS})
ENDIF()

# enable -fPIC so we can link static libs with the editor
SET_TARGET_PROPERTIES(PhysXJniBindings PROPERTIES POSITION_INDEPENDENT_CODE TRUE)
