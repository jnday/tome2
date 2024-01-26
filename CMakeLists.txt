# Project definition.
CMAKE_MINIMUM_REQUIRED (VERSION 3.5)
PROJECT (tome2)

# no idea.
ADD_DEFINITIONS(-DUSE_PRECISE_CMOVIE)

# add location of vcpkg installed libs
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	if(ARCH STREQUAL "x64")
		set(VCPKG_CURRENT_BIN_DIR ${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows/debug/bin)
	elseif(ARCH STREQUAL "x86")
		set(VCPKG_CURRENT_BIN_DIR ${CMAKE_SOURCE_DIR}/vcpkg_installed/x86-windows/debug/bin)
	else()
		message(STATUS "unexpected Debug architecture: " ${ARCH})
	endif()
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
	if(ARCH STREQUAL "x64")
		set(VCPKG_CURRENT_BIN_DIR ${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows/bin)
	elseif(ARCH STREQUAL "x86")
		set(VCPKG_CURRENT_BIN_DIR ${CMAKE_SOURCE_DIR}/vcpkg_installed/x86-windows/bin)
	else()
		message(STATUS "unexpected Release architecture: " ${ARCH})
	endif()
else()
	message(STATUS "unexpected CMAKE_BUILD_TYPE: " ${CMAKE_BUILD_TYPE})
endif()
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${VCPKG_CURRENT_BIN_DIR})

# JSON support
FIND_PACKAGE(JANSSON CONFIG REQUIRED)
set(LIBS ${LIBS} jansson::jansson)

# SDL support
FIND_PACKAGE(SDL2 CONFIG REQUIRED)
FIND_PACKAGE(SDL2_image CONFIG REQUIRED)
FIND_PACKAGE(SDL2_ttf CONFIG REQUIRED)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIR})
set(LIBS ${LIBS} SDL2::SDL2 SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf)
ADD_DEFINITIONS(-DUSE_SDL)

# Windows support
SET(EXECUTABLE_OPTIONS WIN32)
SET(LIBS ${LIBS} winmm wsock32)

# Add the source subdirectory.
ADD_SUBDIRECTORY(src)

