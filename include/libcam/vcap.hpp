#pragma once

#include <memory>
#include <vector>
#include <string>

#include "exception.hpp"

namespace libcam {

    class VideoCaptureBadDeviceIndex : public Exception {
    public:
        VideoCaptureBadDeviceIndex(size_t index);

        ~VideoCaptureBadDeviceIndex() noexcept = default;
    };

    class VideoCaptureConfigurationError : public Exception {
    public:
        VideoCaptureConfigurationError(const std::string &text);

        ~VideoCaptureConfigurationError() noexcept = default;
    };

    struct CaptureDeviceInfo {
        size_t index;
        std::string name;
    };

    class VideoCapture {
    private:
        void *data;
    public:
        VideoCapture(size_t index);

        VideoCapture(const VideoCapture &other) = delete;

        VideoCapture(VideoCapture &&other) = delete;

        VideoCapture &operator=(const VideoCapture &other) = delete;

        VideoCapture &operator=(VideoCapture &&other) = delete;

        static std::vector<CaptureDeviceInfo> list_devices();

        bool read(double timeout);

        ~VideoCapture();
    };

}
