#include <libcam/utils.hpp>
#include <string>
#include <cassert>

int main() {
    assert(libcam::utils::format("hello from %s", "libcam") == "hello from libcam");
    libcam::utils::release_assert(libcam::utils::format("hello from %s", "libcam") == "hello from libcam");
    assert(libcam::utils::format("%d %d %d", 1, 2, 3) == "1 2 3");
    libcam::utils::release_assert(libcam::utils::format("%d %d %d", 1, 2, 3) == "1 2 3");
    assert(libcam::utils::format("%s v%d%s%d", "libcam", 1, ".", 0) == "libcam v1.0");
    libcam::utils::release_assert(libcam::utils::format("%s v%d%s%d", "libcam", 1, ".", 0) == "libcam v1.0");
    return 0;
}
