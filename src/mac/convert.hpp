#pragma once

#include <AVFoundation/AVFoundation.h>
#import <libcam/image.hpp>

namespace libcam {
    const unsigned int supported_pixel_formats[] = {
            kCVPixelFormatType_32BGRA,
            0
    };

    bool pixel_format_is_supported(unsigned int format);

    void
    convertToRgb(void *base_address, libcam::RgbImage *result, size_t width, size_t height, unsigned int pixel_format);
}
