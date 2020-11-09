#include <libcam/utils.hpp>
#include <libcam/vcap.hpp>

namespace libcam {

    VideoCaptureBadDeviceIndex::VideoCaptureBadDeviceIndex(size_t index)
            : Exception(utils::format("Attempt to access device with invalid index. Index: %zu", index)) {}


    VideoCaptureConfigurationError::VideoCaptureConfigurationError(const std::string &text)
            : Exception(text) {}

    VideoCaptureReadFrameTimeout::VideoCaptureReadFrameTimeout()
            : Exception("Read frame timeout reached") {}

    VideoCaptureException::VideoCaptureException(const std::string &text)
            : Exception(text) {}

}
