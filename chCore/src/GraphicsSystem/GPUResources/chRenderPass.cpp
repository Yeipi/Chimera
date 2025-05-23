/************************************************************************/
/**
 * @file chRenderPass.cpp
 * @author AccelMR
 * @date 2025/02/02
 *  RenderPass interface.
 */
/************************************************************************/

/************************************************************************/
/*
 * Includes
 */
/************************************************************************/
#include "chRenderPass.h"

#include "chGPUResourceDescriptors.h"

namespace chEngineSDK {
/*
*/
void
RenderPass::init(const chGPUDesc::RenderPassDesc& desc) {
  _internalInit(desc);
}

/*
*/
uint32
RenderPass::getSubPassCount() const {
  return _internalGetSubPassCount();
}

/*
*/
bool
RenderPass::isValid() const {
  return _internalIsValid();
}

/*
*/
const chGPUDesc::SubpassDesc&
RenderPass::getSubpassDesc(uint32 index) const {
  return _internalGetSubpassDesc(index);
}

} // namespace chEngineSDK
