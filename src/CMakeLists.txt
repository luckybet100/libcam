cmake_minimum_required(VERSION 3.0)

project(libcam)

set(COMMON_FILES
    common/video_capture.cpp
    common/exception.cpp
    common/utils.cpp
)

include_directories(../include)

IF(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fobjc-arc")
    set(CMAKE_EXE_LINKER_FLAGS "-framework AVFoundation -w")
    set(PLATFORM_FILES
        mac/list_capture_devices.mm
        mac/video_capture.mm
    )
ENDIF()

add_library(libcam ${COMMON_FILES} ${PLATFORM_FILES})
set_target_properties(libcam PROPERTIES PREFIX "")

