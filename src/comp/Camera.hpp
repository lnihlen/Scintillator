#ifndef SRC_COMP_CAMERA_HPP_
#define SRC_COMP_CAMERA_HPP_

#include <memory>

#include "glm/glm.hpp"

namespace scin {

namespace vk {
class Device;
class Image;
}

namespace comp {

/*! The Camera encapsulates all of the needed state to render an image to a framebuffer. This includes both Vulkan
 * book-keeping objects and Scintillator abstractions like Camera projection and transform matrices.
 */
class Camera {
public:
    Camera(std::shared_ptr<vk::Device> device);
    ~Camera();

    bool create(size_t numberOfImages);

    void setShouldClear(bool clear);
    bool shouldClear();

    void setClearColor(const glm::vec4& clearColor);
    const glm::vec4& clearColor() const { return m_clearColor; }

private:
    bool m_shouldClear;
    glm::vec4 m_clearColor;
};

} // namespace comp
} // namespace scin

#endif  // SRC_COMP_CAMERA_HPP_
