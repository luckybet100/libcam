#include <iostream>
#include <libcam/capture_utils.hpp>
#include <libcam/video_capture.hpp>

int main() {
    for (const auto& device : libcam::list_capture_devices()) {
        std::cout << '[' << device.index << ']' << " " << device.name << std::endl;
    }    
    libcam::VideoCapture vcap(0);
    auto tmp = std::move(vcap);
    return 0;
}

