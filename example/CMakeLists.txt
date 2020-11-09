cmake_minimum_required(VERSION 3.0)

project(libcam_sample)

include_directories(../include)

set(SOURCE_FILES main.cpp)
add_executable(example ${SOURCE_FILES})

IF (APPLE)
    #set_target_properties(example PROPERTIES
    #    MACOSX_BUNDLE TRUE
    #    MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist
    #)
ENDIF ()

target_link_libraries(example libcam)