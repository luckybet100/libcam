#include <iostream>
#include <capture.hpp>

int main() {
    for (const auto& device : libcam::get_capture_devices()) {
        std::cout << device.name << std::endl;
    }    
    return 0;
}
