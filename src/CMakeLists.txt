cmake_minimum_required(VERSION 3.0)

project(libcam)

set(COMMON_FILES
        common/vcap.cpp
        common/exception.cpp
        common/utils.cpp
        common/image.cpp)

include_directories(../include)

IF (APPLE)
    set(PLATFORM_FILES mac/vcap/vcap.mm
            mac/vcap/cap_delegate.mm mac/convert/convert.mm)
    set_source_files_properties(${PLATFORM_FILES} PROPERTIES COMPILE_FLAGS -fobjc-arc)
ENDIF ()

add_library(libcam STATIC ${COMMON_FILES} ${PLATFORM_FILES})
set_target_properties(libcam PROPERTIES PREFIX "")

