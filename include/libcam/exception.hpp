#pragma once

#include <string>
#include <stdexcept>

namespace libcam {

    class Exception : public std::exception {
    private:
        std::string message;
    public:
        Exception(const std::string &message);

        virtual ~Exception() noexcept = default;

        const char *what() const noexcept;
    };

}
