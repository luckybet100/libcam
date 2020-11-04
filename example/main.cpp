#include <iostream>
#include <capture_utils.hpp>

int main() {
    for (const auto& device : libcam::list_capture_devices()) {
        std::cout << device.name << std::endl;
    }    
    return 0;
}

