#include <DX3D/Graphics/GraphicsEngine.h>
#include <DX3D/Graphics/RenderSystem.h>

dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc) : Base(desc.base)
{
	m_renderSystem = std::make_unique<RenderSystem>(RenderSystemDesc{desc.base});
}

dx3d::GraphicsEngine::~GraphicsEngine()
{
}
