#import <AVFoundation/AVFoundation.h>
#include <iostream>

#include "vcap.hpp"

namespace libcam {
    
    namespace internal {
        
        IVideoCapture::IVideoCapture(size_t index) {
            std::cout << "Internal init " << index << std::endl;
            throw VideoCaptureBadDeviceIndex(index);
        }

        IVideoCapture::~IVideoCapture() {
            std::cout << "Internal destroy" << std::endl;
        }
    }

    std::vector< CaptureDeviceInfo > VideoCapture::list_devices() {
        @autoreleasepool {
            AVCaptureDeviceDiscoverySession *session = [AVCaptureDeviceDiscoverySession discoverySessionWithDeviceTypes:@[AVCaptureDeviceTypeBuiltInWideAngleCamera,AVCaptureDeviceTypeExternalUnknown]
                                                                                                              mediaType:AVMediaTypeVideo
                                                                                                               position: AVCaptureDevicePositionBack ];
            std::vector< CaptureDeviceInfo > result(size_t(session.devices.count));
            for (size_t index = 0; index < result.size(); ++index) {
                result[index].index = index;
                result[index].name = [session.devices[index].localizedName UTF8String];
            }
            return result;
        }
    }
    
}
