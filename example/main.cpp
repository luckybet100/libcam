#include <iostream>
#include <libcam/vcap.hpp>

int main() {
    for (const auto &device : libcam::VideoCapture::list_devices()) {
        std::cout << '[' << device.index << ']' << " " << device.name << std::endl;
    }
    libcam::VideoCapture vcap(0);
    auto tmp = std::move(vcap);
    return 0;
}

