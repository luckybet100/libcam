#include <libcam/vcap.hpp>
#include <libcam/utils.hpp>
#include "cap_delegate.hpp"
#include "../convert/convert.hpp"

@implementation CaptureDelegate

- (id)init {
    self = [super init];
    capture_started = dispatch_semaphore_create(0);
    frame_available = [[NSCondition alloc] init];
    return self;
}

- (void)dealloc {}

- (bool)read:(NSDate *)waitUntil
      result:(libcam::RgbImage *)result {
    [frame_available lock];
    if ([frame_available waitUntilDate:waitUntil]) {
        auto error = CVPixelBufferLockBaseAddress(captured_buffer, 0);
        if (error != kCVReturnSuccess) {
            throw libcam::VideoCaptureException(
                    libcam::utils::format("Unable to lock base address: error %d", static_cast<int>(error)));
        }
        void *base_address = CVPixelBufferGetBaseAddress(captured_buffer);
        size_t width = CVPixelBufferGetWidth(captured_buffer);
        size_t height = CVPixelBufferGetHeight(captured_buffer);
        unsigned int pixel_format = CVPixelBufferGetPixelFormatType(captured_buffer);
        libcam::convertToRgb(base_address, result, width, height, pixel_format);
        CVPixelBufferUnlockBaseAddress(captured_buffer, 0);
        [frame_available unlock];
        return true;
    }
    [frame_available unlock];
    return false;
}

- (void)captureOutput:(AVCaptureOutput *)captureOutput
didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer
       fromConnection:(AVCaptureConnection *)connection {
    dispatch_semaphore_signal(capture_started);
    [frame_available lock];
    CVBufferRelease(captured_buffer);
    captured_buffer = CMSampleBufferGetImageBuffer(sampleBuffer);
    CVBufferRetain(captured_buffer);
    [frame_available signal];
    [frame_available unlock];
}

@end
