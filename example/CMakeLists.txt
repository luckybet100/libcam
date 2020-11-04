cmake_minimum_required(VERSION 3.0)

project(libcam_sample)

include_directories(../include)

set(SOURCE_FILES main.cpp)
add_executable(main ${SOURCE_FILES})

IF(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fobjc-arc")
    set(CMAKE_EXE_LINKER_FLAGS "-framework AVFoundation -w")
ENDIF()

target_link_libraries(main libcam)

