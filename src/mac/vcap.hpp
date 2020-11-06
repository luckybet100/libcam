#include <libcam/vcap.hpp>

namespace libcam {

    namespace internal {

        class IVideoCapture {
         public:
            IVideoCapture(size_t index);
            IVideoCapture(const IVideoCapture& other) = delete;
            IVideoCapture& operator = (const IVideoCapture& other) = delete;
            ~IVideoCapture();
        };

    }

}
