#pragma once

#include <string>

namespace libcam {
    
    class Exception {
     private:
        std::string message;
     public:
        Exception(const std::string& message);
        std::string what() const;
        virtual ~Exception();
    };

}
