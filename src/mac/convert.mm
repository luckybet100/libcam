#include <libcam/vcap.hpp>
#include <libcam/utils.hpp>
#include "convert.hpp"

namespace libcam {

    bool pixel_format_is_supported(unsigned int format) {
        const unsigned int *it = supported_pixel_formats;
        do {
            if (format == *it)
                return true;
        } while ((*it++) != 0);
        return false;
    }

    void
    convertToRgb(void *base_address, libcam::RgbImage *result, size_t width, size_t height, unsigned int pixel_format) {
        if (result == nullptr) {
            throw libcam::VideoCaptureException("Null result buffer passed to convert");
        }
        if (pixel_format == kCVPixelFormatType_32BGRA) {
            uint8_t *base = reinterpret_cast<uint8_t *>(base_address);
            result->resize(width, height);
            for (size_t i = 0; i < height; ++i) {
                for (size_t j = 0; j < width; ++j) {
                    (*result)[i][j] = libcam::RgbPixel(*(base + 2), *(base + 1), *base);
                    base += 4;
                }
            }
        } else {
            throw libcam::VideoCaptureException(
                    libcam::utils::format("Unsupported capture format %u", pixel_format));
        }
    }

}

