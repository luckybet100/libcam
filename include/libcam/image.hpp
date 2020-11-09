#pragma once

#include <vector>

namespace libcam {

    struct RgbPixel {

        uint8_t r;
        uint8_t g;
        uint8_t b;

        RgbPixel() noexcept;

        RgbPixel(uint8_t r, uint8_t g, uint8_t b) noexcept;
    };

    using RgbImageRow = RgbPixel *;
    using RgbImageRowConst = const RgbPixel *;

    class RgbImage {
    private:
        size_t m_width;
        size_t m_height;
        std::vector<RgbPixel> buffer;

    public:
        RgbImage();

        RgbImage(size_t width, size_t height);

        RgbImage(size_t width, size_t height, RgbPixel *buffer);

        RgbImage(const RgbImage &other);

        RgbImage(RgbImage &&other) noexcept;

        RgbImage &operator=(const RgbImage &other);

        RgbImage &operator=(RgbImage &&other) noexcept;

        RgbPixel *data() noexcept;

        const RgbPixel *data() const noexcept;

        RgbImageRow operator[](size_t x);

        RgbImageRowConst operator[](size_t x) const;

        void resize(size_t width, size_t height);

        std::pair<size_t, size_t> size() const noexcept;
        size_t width() const noexcept;
        size_t height() const noexcept;

        ~RgbImage() noexcept = default;
    };

}