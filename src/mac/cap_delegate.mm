#include "cap_delegate.hpp"

@implementation CaptureDelegate

- (id)init {
    self = [super init];
    capture_started = dispatch_semaphore_create(0);
    frameAvailible = [[NSCondition alloc] init];
    return self;
}

- (void)dealloc {}

- (bool)read:(NSDate *)waitUntil {
    [frameAvailible lock];
    bool read_frame = [frameAvailible waitUntilDate:waitUntil];
    [frameAvailible unlock];
    return read_frame;
}

- (void)captureOutput:(AVCaptureOutput *)captureOutput
didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer
       fromConnection:(AVCaptureConnection *)connection {
    dispatch_semaphore_signal(capture_started);
    [frameAvailible lock];
    [frameAvailible signal];
    [frameAvailible unlock];
}

@end
