cmake_minimum_required(VERSION 3.0)

project(LibcamTests)

include_directories(../include)

IF(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fobjc-arc")
    set(CMAKE_EXE_LINKER_FLAGS "-framework AVFoundation -w")
ENDIF()

include(CTest)
add_executable(capture_utils_test capture_utils_test.cpp)
target_link_libraries(capture_utils_test libcam)

IF(CI)
    add_test(capture_utils capture_utils_test "ci")
ELSE()
    add_test(capture_utils capture_utils_test "device")
ENDIF()

set_tests_properties(capture_utils PROPERTIES TIMEOUT 1)

