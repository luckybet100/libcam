#include <libcam/exception.hpp>

namespace libcam {

    Exception::Exception(const std::string &message)
            : message(message) {}

    const char *Exception::what() const noexcept {
        return message.c_str();
    }

}
