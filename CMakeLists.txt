cmake_minimum_required(VERSION 3.0)

project(libcam)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Ofast")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

IF (APPLE)
    set(CMAKE_EXE_LINKER_FLAGS "-framework Foundation -framework AVFoundation -framework CoreVideo -framework CoreMedia -w")
ENDIF()

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(example)
