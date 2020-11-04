#ifdef __APPLE__
#include "../mac/video_capture.hpp"
#endif

#include <libcam/utils.hpp>

namespace libcam {

    VideoCaptureBadDeviceIndex::VideoCaptureBadDeviceIndex(size_t index)
                : Exception(utils::format("Attemp to access device with invalid index. Index: %zu", index)) {
           
    }

    VideoCaptureBadDeviceIndex::~VideoCaptureBadDeviceIndex() {

    }

    VideoCapture::VideoCapture(size_t index) 
                : icap(new internal::IVideoCapture(index)) {
        
    }

    VideoCapture::VideoCapture(VideoCapture&& other)
                : icap(std::move(other.icap)) {

    }

    VideoCapture::~VideoCapture() {}

}
