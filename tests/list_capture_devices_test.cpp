#include <iostream>
#include <libcam/capture_utils.hpp>
#include <cassert>
#include <cstring>

void test_list_capture_devices(bool allow_no_devices) {
    std::cerr << "test_list_capture_devices()" << std::endl;
    auto devices = libcam::list_capture_devices();
    assert(allow_no_devices || !devices.empty());
}

int main(int argc,char** argv) {
    bool allow_no_devices = false;
    for (int i = 1; i < argc; ++i) {
         allow_no_devices = allow_no_devices || (strcmp(argv[i], "-allow_no_devices") == 0);
    }
    test_list_capture_devices(allow_no_devices);
    return 0;
}

