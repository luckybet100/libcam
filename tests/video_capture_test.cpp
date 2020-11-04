#include <iostream>
#include <libcam/video_capture.hpp>
#include <cassert>
#include <cstring>

void test_create_device_with_wrong_index() {
    std::cerr << "test_create_device_with_no_index()" << std::endl;
    bool exception_catched = false;
    try {
        libcam::VideoCapture capture(-1);
    } catch (...) {
        exception_catched = true;
    }
    assert(exception_catched);
}

int main(int argc,char** argv) {
    bool allow_no_devices = false;
    for (int i = 1; i < argc; ++i) {
         allow_no_devices = allow_no_devices || (strcmp(argv[i], "-allow_no_devices") == 0);
    }
    test_create_device_with_wrong_index();
    return 0;
}



