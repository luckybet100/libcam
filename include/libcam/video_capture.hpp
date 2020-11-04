#pragma once

#include <memory>
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

    class VideoCapture {
     private:
        std::unique_ptr<internal::IVideoCapture> icap;
     public:
        VideoCapture(size_t index);
        VideoCapture(const VideoCapture& other) = delete;
        VideoCapture(VideoCapture&& other);
        VideoCapture& operator = (const VideoCapture& other) = delete;
        ~VideoCapture();
    };

}
