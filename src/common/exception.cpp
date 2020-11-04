#include <libcam/exception.hpp>

namespace libcam {
    
    Exception::Exception(const std::string& message)
        : message(message) {

    }
    
    std::string Exception::what() const {
        return message;
    }

    Exception::~Exception() {}
    
}
