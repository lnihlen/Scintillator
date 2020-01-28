#ifndef SRC_SCINTHDEF_HPP_
#define SRC_SCINTHDEF_HPP_

#include <memory>

namespace scin {

namespace core {
class AbstractScinthDef;
}

namespace vk {
class Canvas;
class CommandPool;
class Device;
class HostBuffer;
class Pipeline;
class Shader;
class ShaderCompiler;
class UniformLayout;
}

class Scinth;

/*! A ScinthDef encapsulates all of the graphics state that can be reused across individual instances of Scinths.
 */
class ScinthDef {
public:
    ScinthDef(std::shared_ptr<vk::Device> device, std::shared_ptr<vk::Canvas> canvas,
              std::shared_ptr<vk::CommandPool> commandPool,
              std::shared_ptr<const core::AbstractScinthDef> abstractScinthDef);
    ~ScinthDef();

    /*! Given the AbstractScinthDef, build the Vulkan objects that can be re-used across all running Scinth instances
     * of this ScinthDef.
     *
     * \param A pointer to the ShaderCompiler.
     * \return true on success, false on error.
     */
    bool build(vk::ShaderCompiler* compiler);

    /*! Create a Scinth instance based from this ScinthDef.
     *
     * The Scinth needs a shared_ptr reference to the originating ScinthDef, so that the ScinthDef will remain allocated
     * until all referencing Scinths are themselves deleted. So this is a static method that provides that shared
     * pointer as the first argument.
     * TODO: this is totally a code smell.
     *
     * \param scinthDef The ScinthDef to build this Scinth from.
     * \param nodeID The unique ID to assign to the running Scinth.
     */
    static std::shared_ptr<Scinth> cue(std::shared_ptr<ScinthDef> scinthDef, int nodeID);

    std::shared_ptr<const core::AbstractScinthDef> abstract() const { return m_abstractScinthDef; }

private:
    bool buildVertexData();

    std::shared_ptr<vk::Device> m_device;
    std::shared_ptr<vk::Canvas> m_canvas;
    std::shared_ptr<vk::CommandPool> m_commandPool;
    std::shared_ptr<const core::AbstractScinthDef> m_abstractScinthDef;
    std::shared_ptr<vk::HostBuffer> m_vertexBuffer;
    std::shared_ptr<vk::HostBuffer> m_indexBuffer;
    std::shared_ptr<vk::Shader> m_vertexShader;
    std::shared_ptr<vk::Shader> m_fragmentShader;
    std::shared_ptr<vk::UniformLayout> m_uniformLayout;
    std::shared_ptr<vk::Pipeline> m_pipeline;
};

} // namespace scin

#endif // SRC_SCINTHDEF_HPP_