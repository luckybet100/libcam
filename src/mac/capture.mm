#include <capture.hpp>
#include <AVFoundation/AVFoundation.h>
#include <utility>

namespace libcam {

    std::vector< CaptureDeviceInfo > get_capture_devices() {
        AVCaptureDeviceDiscoverySession *session = [AVCaptureDeviceDiscoverySession discoverySessionWithDeviceTypes:@[AVCaptureDeviceTypeBuiltInWideAngleCamera,AVCaptureDeviceTypeExternalUnknown]
            mediaType:AVMediaTypeVideo
            position: AVCaptureDevicePositionBack];
        std::vector< CaptureDeviceInfo > result(size_t(session.devices.count)); 
        for (size_t index = 0; index < result.size(); ++index) {
            result[index].index = index;
            result[index].name = std::string([session.devices[index].localizedName UTF8String]);
        }
        return result;;
    }   

}
