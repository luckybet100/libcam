#include <libcam/utils.hpp>

namespace libcam {

    namespace utils {

        FormatException::FormatException()
                : Exception("Error during formatting strings") {}

        void release_assert(bool ok) {
            if (!ok) {
                std::cerr << "Assertion failed" << std::endl;
                exit(1);
            }
        }

    }

}

