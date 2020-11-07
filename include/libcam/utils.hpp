#pragma once

#include <string>
#include <cstdio>
#include "exception.hpp"
#include <memory>


namespace libcam {

    namespace utils {

        class FormatException : public Exception {
        public:
            FormatException();
        };

        template<typename ... Args>
        std::string format(const std::string &format, Args ... args) {
            int size = snprintf(nullptr, 0, format.c_str(), args...) + 1;
            if (size <= 0) {
                throw FormatException();
            }
            std::unique_ptr<char[]> buf(new char[size]);
            snprintf(buf.get(), size, format.c_str(), args...);
            return std::string(buf.get(), buf.get() + size - 1);
        }

    }
}
