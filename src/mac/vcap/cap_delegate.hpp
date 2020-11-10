#pragma once

#include <AVFoundation/AVFoundation.h>
#include <libcam/image.hpp>

@interface CaptureDelegate : NSObject <AVCaptureVideoDataOutputSampleBufferDelegate> {
    NSCondition *frame_available;
@public
    dispatch_semaphore_t capture_started;
    CVImageBufferRef captured_buffer;
}

- (void)captureOutput:(AVCaptureOutput *)captureOutput
didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer
       fromConnection:(AVCaptureConnection *)connection;

- (bool)read:(NSDate *)waitUntil
      result:(libcam::RgbImage *) result;

@end