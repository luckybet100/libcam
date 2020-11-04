cmake_minimum_required(VERSION 3.0)

project(libcam)

#set(COMMON_FILES
#  main.cpp
#)

include_directories(../include)

IF(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fobjc-arc")
    set(CMAKE_EXE_LINKER_FLAGS "-framework AVFoundation -w")
    set(PLATFORM_FILES
        mac/capture_utils.mm
    )
ENDIF()

add_library(libcam ${PLATFORM_FILES})
set_target_properties(libcam PROPERTIES PREFIX "")

