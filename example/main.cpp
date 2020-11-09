#include <iostream>
#include <fstream>
#include <libcam/vcap.hpp>
#include <libcam/exception.hpp>

int main() {
    for (const auto &device : libcam::VideoCapture::list_devices()) {
        std::cout << '[' << device.index << ']' << " " << device.name << std::endl;
    }
    try {
        libcam::VideoCapture cap(0);
        libcam::RgbImage result;
        cap.read(1, result);
        std::ofstream out_image("res.ppm");
        out_image << "P3\n";
        out_image << result.width() << " " << result.height() << '\n';
        std::cout << result.width() << " " << result.height() << std::endl;
        out_image << 255 << '\n';
        for (size_t i = 0; i < result.height(); ++i) {
            for (size_t j = 0; j < result.width(); ++j) {
                out_image << int(result[i][j].r) << ' ' << int(result[i][j].g) << ' ' << int(result[i][j].b) << '\n';
            }
        }
    } catch (libcam::Exception &exp) {
        std::cerr << exp.what() << std::endl;
        throw;
    }
    return 0;
}

