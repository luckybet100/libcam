cmake_minimum_required(VERSION 3.0)

project(LibcamTests)

include_directories(../include)

IF (APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fobjc-arc")
    set(CMAKE_EXE_LINKER_FLAGS "-framework Foundation -framework AVFoundation -w")
ENDIF ()

add_executable(video_capture_test video_capture_test.cpp)
target_link_libraries(video_capture_test libcam)

add_executable(utils_format_test utils_format_test.cpp)
target_link_libraries(utils_format_test libcam)

IF (ALLOW_NO_DEVICES)
    add_test(video_capture video_capture_test "-allow_no_devices")
ELSE ()
    add_test(video_capture video_capture_test)
ENDIF ()

add_test(utils_format utils_format_test)

set_tests_properties(video_capture PROPERTIES TIMEOUT 30)
set_tests_properties(utils_format PROPERTIES TIMEOUT 10)

