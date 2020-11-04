#pragma once

#include <vector>
#include <string>

namespace libcam {

    struct CaptureDeviceInfo {
        size_t index;
        std::string name;
    };

    std::vector< CaptureDeviceInfo > get_capture_devices();

}
