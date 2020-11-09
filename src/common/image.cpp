#include <algorithm>
#include <libcam/image.hpp>

namespace libcam {

    RgbPixel::RgbPixel() noexcept: r(0), g(0), b(0) {}

    RgbPixel::RgbPixel(uint8_t r, uint8_t g, uint8_t b) noexcept: r(r), g(g), b(b) {}

    RgbImage::RgbImage() : m_width(0), m_height(0) {}

    RgbImage::RgbImage(RgbImage &&other) noexcept: m_width(0), m_height(0) {
        *this = other;
    }

    RgbImage::RgbImage(const RgbImage &other) : m_width(other.m_width), m_height(other.m_height),
                                                buffer(other.buffer) {}

    RgbImage::RgbImage(size_t width, size_t height) : m_width(width), m_height(height),
                                                      buffer(width * height) {}

    RgbImage::RgbImage(size_t width, size_t height, RgbPixel *buffer) : m_width(width), m_height(height),
                                                                        buffer(buffer, buffer + width * height) {}

    RgbImage &RgbImage::operator=(RgbImage &&other) noexcept {
        if (this == &other) { return *this; }
        std::swap(m_width, other.m_width);
        std::swap(m_height, other.m_height);
        std::swap(buffer, other.buffer);
        return *this;
    }

    RgbImage &RgbImage::operator=(const RgbImage &other) {
        if (this == &other) { return *this; }
        m_width = other.m_width;
        m_height = other.m_height;
        buffer = other.buffer;
        return *this;
    }

    std::pair<size_t, size_t> RgbImage::size() const noexcept {
        return std::pair(m_width, m_height);
    }

    size_t RgbImage::width() const noexcept { return m_width; }

    size_t RgbImage::height() const noexcept { return m_height; }

    void RgbImage::resize(size_t width, size_t height) {
        m_width = width;
        m_height = height;
        buffer.resize(width * height);
    }

    RgbPixel *RgbImage::data() noexcept {
        return buffer.data();
    }

    const RgbPixel *RgbImage::data() const noexcept {
        return buffer.data();
    }

    RgbImageRow RgbImage::operator[](size_t x) {
        assert(x < m_height);
        return buffer.data() + x * m_width;
    }

    RgbImageRowConst RgbImage::operator[](size_t x) const {
        assert(x < m_height);
        return buffer.data() + x * m_width;
    }

}