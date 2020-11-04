#include <iostream>
#include <capture_utils.hpp>
#include <cassert>

int main() {
    auto devices = libcam::list_capture_devices();
    assert(devices.size() != 0);
    return 0;
}
