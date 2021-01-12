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

FIND_PACKAGE(Python3)
SET(PYTHON ${Python3_EXECUTABLE} CACHE STRING "Python path")
SET(EMSCRIPTEN_ROOT $ENV{EMSDK}/upstream/emscripten CACHE STRING "Emscripten path")
SET(CMAKE_TOOLCHAIN_FILE ${EMSCRIPTEN_ROOT}/cmake/Modules/Platform/Emscripten.cmake)
SET(WEBIDL_BINDER_SCRIPT ${EMSCRIPTEN_ROOT}/tools/webidl_binder.py)


SET(WEB_SOURCE_DIR ${PHYSX_SOURCE_DIR}/physxwebbindings/src)
SET(PHYSXJS_INCLUDE_DIR ${PHYSX_ROOT_DIR}/include)
SET(PHYSXJS_HEADER_FILE ${WEB_SOURCE_DIR}/PhysXJs.h)
SET(PHYSXJS_IDL_FILE ${WEB_SOURCE_DIR}/PhysXJs.idl)
SET(PHYSXJS_FRONT_MATTER_FILE ${WEB_SOURCE_DIR}/front-matter.js)
SET(PHYSXJS_ONLOAD_FILE ${WEB_SOURCE_DIR}/onload.js)
SET(EMCC_WASM_ARGS
		--extern-pre-js ${PHYSXJS_FRONT_MATTER_FILE}
		--post-js glue.js
		--post-js ${PHYSXJS_ONLOAD_FILE}
		-s MODULARIZE=1
		-s EXPORT_NAME=PhysX
		-s WASM=1
		-s NO_EXIT_RUNTIME=1
		-s NO_FILESYSTEM=1
		-s ALLOW_TABLE_GROWTH=1
		-s ALLOW_MEMORY_GROWTH=0
		-s TOTAL_MEMORY=268435456
		--closure 1
		-s IGNORE_CLOSURE_COMPILER_ERRORS=1)

SET(EMCC_GLUE_ARGS
		-c
		-DNDEBUG
		-I${PHYSXJS_INCLUDE_DIR}
		-I${PHYSX_ROOT_DIR}/../pxshared/include
		-include${PHYSXJS_HEADER_FILE})

ADD_CUSTOM_COMMAND(
		OUTPUT glue.cpp glue.js
		BYPRODUCTS parser.out WebIDLGrammar.pkl
		COMMAND ${PYTHON} ${WEBIDL_BINDER_SCRIPT} ${PHYSXJS_IDL_FILE} glue
		DEPENDS ${PHYSXJS_IDL_FILE}
		COMMENT "Generating PhysX-js bindings"
		VERBATIM)
ADD_CUSTOM_COMMAND(
		OUTPUT glue.o
		COMMAND emcc glue.cpp ${EMCC_GLUE_ARGS} -o glue.o
		DEPENDS glue.cpp ${PHYSXJS_HEADER_FILE}
		COMMENT "Building PhysX-js bindings"
		VERBATIM)
ADD_CUSTOM_TARGET(physx-js-bindings ALL DEPENDS glue.js glue.o)

SET(PHYSX_TARGETS PhysX PhysXCharacterKinematic PhysXCommon PhysXCooking PhysXExtensions PhysXFoundation PhysXVehicle)
FOREACH(_TARGET ${PHYSX_TARGETS})
	LIST(APPEND PHYSX_LIBS $<TARGET_FILE:${_TARGET}>)
ENDFOREACH()

ADD_CUSTOM_COMMAND(
		OUTPUT physx-js.wasm.js physx-js.wasm.wasm
		COMMAND emcc glue.o ${PHYSX_LIBS} ${EMCC_WASM_ARGS} -o physx-js.wasm.js
		DEPENDS physx-js-bindings ${PHYSXJS_FRONT_MATTER_FILE} ${PHYSXJS_ONLOAD_FILE} ${PHYSX_TARGETS}
		COMMENT "Building PhysX-js webassembly"
		VERBATIM)
ADD_CUSTOM_TARGET(PhysXWebBindings ALL DEPENDS physx-js.wasm.js physx-js.wasm.wasm)

# Copy generated .js and .wasm file into top level build dir, where they are easier to locate
ADD_CUSTOM_COMMAND(TARGET PhysXWebBindings
		POST_BUILD
		COMMAND cp ${CMAKE_CURRENT_BINARY_DIR}/physx-js.wasm.js ${CMAKE_BINARY_DIR}
		COMMAND cp ${CMAKE_CURRENT_BINARY_DIR}/physx-js.wasm.wasm ${CMAKE_BINARY_DIR}
		VERBATIM)
