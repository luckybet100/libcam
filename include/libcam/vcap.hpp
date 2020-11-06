#pragma once

#include <memory>
#include <vector>
#include <string>

#include "exception.hpp"

namespace libcam {

    class VideoCaptureBadDeviceIndex : public Exception {
     public:
        VideoCaptureBadDeviceIndex(size_t index);
        ~VideoCaptureBadDeviceIndex();
    };

    namespace internal {
        class IVideoCapture;
    }

    struct CaptureDeviceInfo {
        size_t index;
        std::string name;
    };

    class VideoCapture {
     private:
        std::unique_ptr<internal::IVideoCapture> icap;
     public:
        VideoCapture(size_t index);
        VideoCapture(const VideoCapture& other) = delete;
        VideoCapture(VideoCapture&& other);
        VideoCapture& operator = (const VideoCapture& other) = delete;
        static std::vector< CaptureDeviceInfo > list_devices();
        ~VideoCapture();
    };

}
