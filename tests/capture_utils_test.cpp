#include <iostream>
#include <capture_utils.hpp>
#include <cassert>
#include <cstring>

int main(int argc,char** argv) {
    assert(argc == 2);
    bool is_device = (strcmp(argv[1], "device") == 0);
    bool is_ci = (strcmp(argv[1], "ci") == 0);
    assert(is_device || is_ci);
    auto devices = libcam::list_capture_devices();
    if (is_device) {
        assert(devices.size() != 0);
    }
    if (is_ci) {
        assert(devices.size() == 0);
    }
    return 0;
}
