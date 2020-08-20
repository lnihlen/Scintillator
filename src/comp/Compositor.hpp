#ifndef SRC_COMP_COMPOSITOR_HPP_
#define SRC_COMP_COMPOSITOR_HPP_

namespace scin {

namespace vk {
class Device;
}

namespace comp {

/*! The Compositor owns all Cameras, schedules updates and rendering, maintains all globally shared objects (like Images
 * and Shapes), and handles the graphics for the update loop.
 */
class Compositor {
public:
    Compositor(std::shared_ptr<vk::Device> device);
    ~Compositor();

private:

};

} // namespace comp
} // namespace scin

#endif // SRC_COMP_COMPOSITOR_HPP_
