#include "video_capture.hpp"
#include "libcam/video_capture.hpp"
#include <iostream>

namespace libcam {
    
    namespace internal {
        
        IVideoCapture::IVideoCapture(size_t index) {
            throw VideoCaptureBadDeviceIndex(index);
            std::cout << "Internal init " << index << std::endl;
        }

        IVideoCapture::~IVideoCapture() {
            std::cout << "Internal destroy" << std::endl;
        }
    }
    
}
