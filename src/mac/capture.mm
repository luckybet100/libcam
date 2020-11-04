#include <capture.hpp>
#include <AVFoundation/AVFoundation.h>

int get_video_device_count() {
    AVCaptureDeviceDiscoverySession *session = [AVCaptureDeviceDiscoverySession discoverySessionWithDeviceTypes:@[AVCaptureDeviceTypeBuiltInWideAngleCamera,AVCaptureDeviceTypeExternalUnknown]
        mediaType:AVMediaTypeVideo
        position: AVCaptureDevicePositionBack];;
    
    NSArray *devices = session.devices;
    return devices.count;
}

