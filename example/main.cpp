#include <iostream>
#include <libcam/vcap.hpp>
#include <libcam/exception.hpp>

int main() {
    for (const auto &device : libcam::VideoCapture::list_devices()) {
        std::cout << '[' << device.index << ']' << " " << device.name << std::endl;
    }
    try {
		libcam::VideoCapture cap(0);
	    for (int i = 0; i < 10; ++i) {
	        std::cout << "Try capture..." << std::endl;
	        std::cout << (cap.read(1) ? "ok" : "timeout") << std::endl;
	    }
    } catch (libcam::Exception& exp) {
    	std::cerr << exp.what() << std::endl;
    	throw;
    }
    return 0;
}

