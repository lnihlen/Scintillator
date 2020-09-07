#ifndef SRC_COMP_CAMERA_HPP_
#define SRC_COMP_CAMERA_HPP_

#include <memory>
#include <vector>

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
    Camera(std::shared_ptr<vk::Device> device, int width, int height);
    ~Camera();

    bool create(size_t numberOfImages);
    void destroy();

    void setShouldClear(bool clear);
    bool shouldClear();

    void setClearColor(const glm::vec4& clearColor);
    const glm::vec4& clearColor() const { return m_clearColor; }

    VkExtent2D extent() const { return m_extent; }
    size_t numberOfImages() { return m_numberOfImages; }
    uint32_t width() const { return m_extent.width; }
    uint32_t height() const { return m_extent.height; }
    VkRenderPass renderPass() { return m_renderPass; }
    VkFramebuffer framebuffer(size_t index) { return m_framebuffers[index]; }
    glm::vec2 normPosScale() const { return m_normPosScale; }

private:
    std::shared_ptr<vk::Device> m_device;
    bool m_shouldClear;
    glm::vec4 m_clearColor;

    VkExtent2D m_extent;
    size_t m_numberOfImages;
    std::vector<std::shared_ptr<Image>> m_images;
    VkRenderPass m_renderPass;
    std::vector<VkFramebuffer> m_framebuffers;
    glm::vec2 m_normPosScale;
};

} // namespace comp
} // namespace scin

#endif  // SRC_COMP_CAMERA_HPP_
