#pragma once

#include <AVFoundation/AVFoundation.h>

@interface CaptureDelegate : NSObject <AVCaptureVideoDataOutputSampleBufferDelegate> {
    NSCondition *frameAvailible;
@public
    dispatch_semaphore_t capture_started;
}

- (void)captureOutput:(AVCaptureOutput *)captureOutput
didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer
       fromConnection:(AVCaptureConnection *)connection;

- (bool)read:(NSDate *)waitUntil;

@end