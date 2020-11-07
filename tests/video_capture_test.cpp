#include <libcam/vcap.hpp>
#include <cassert>
#include <cstring>
#include <iostream>

void test_list_capture_devices(bool allow_no_devices) {
    std::cerr << "test_list_capture_devices()" << std::endl;
    auto devices = libcam::VideoCapture::list_devices();
    assert(allow_no_devices || !devices.empty());
}

void test_create_device_with_wrong_index() {
    std::cerr << "test_create_device_with_no_index()" << std::endl;
    bool exception_catched = false;
    try {
        libcam::VideoCapture capture(-1);
    } catch (libcam::VideoCaptureBadDeviceIndex &error) {
        exception_catched = true;
    } catch (libcam::Exception &exception) {
        std::cerr << exception.what() << std::endl;
        throw;
    }
    assert(exception_catched);
}

void test_create_device(bool allow_no_devices) {
    std::cerr << "test_create_device()" << std::endl;
    if (allow_no_devices) {
        std::cerr << "\t - skip" << std::endl;
    } else {
        try {
            libcam::VideoCapture capture(0);
        } catch (libcam::Exception &exception) {
            std::cerr << exception.what() << std::endl;
            throw;
        }
    }
}

void test_read_frames(bool allow_no_devices) {
    std::cerr << "test_read_frames()" << std::endl;
    if (allow_no_devices) {
        std::cerr << "\t - skip" << std::endl;
    } else {
        try {
            libcam::VideoCapture capture(0);
            for (int i = 0; i < 10; ++i) {
                capture.read(1);
            }
        } catch (libcam::Exception &exception) {
            std::cerr << exception.what() << std::endl;
            throw;
        }
    }
}

int main(int argc, char **argv) {
    bool allow_no_devices = false;
    for (int i = 1; i < argc; ++i) {
        allow_no_devices = allow_no_devices || (strcmp(argv[i], "-allow_no_devices") == 0);
    }
    test_list_capture_devices(allow_no_devices);
    test_create_device(allow_no_devices);
    test_read_frames(allow_no_devices);
    test_create_device_with_wrong_index();
    return 0;
}



