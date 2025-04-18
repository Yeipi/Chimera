/************************************************************************/
/**
 * @file chGPUCommandBuffer.cpp
 * @author AccelMR
 * @date 2022/10/18
 *       GPU Command buffer. Used to send instructions to the gpu to be
 *            executed at the render pass.
 *   
 */
 /************************************************************************/

/************************************************************************/
/*
 * Includes
 */                                                                     
/************************************************************************/
#include "chGPUCommandBuffer.h"

#include "chGPUResourceDescriptors.h"

namespace chEngineSDK {
using namespace chGPUDesc;

/*
*/
void 
GPUCommandBuffer::begin() {
  _internalBegin();
}

/*
*/
void
GPUCommandBuffer::beginRenderPass(const SPtr<RenderPass>& renderPass, 
                                  const SPtr<Framebuffer>& frameBuffer,
                                  const Vector<LinearColor>& clearColors) {
  _internalBeginRenderPass(renderPass, frameBuffer, clearColors);
}

/*
*/
void
GPUCommandBuffer::setSubpassIndex(uint32 index) {
  _internalSetSubpassIndex(index);
}

/*
*/
void
GPUCommandBuffer::nextSubpass() {
  _internalNextSubpass();
}

/*
*/
void
GPUCommandBuffer::endRenderPass() {
  _internalEndRenderPass();
}

/*
*/
void
GPUCommandBuffer::reset(const SPtr<GPUPipelineState>& pipelineState) {
  _internalReset(pipelineState);
}

/*
*/
void
GPUCommandBuffer::setPipeLineState( const SPtr<GPUPipelineState> &pipelineState ) {
  _internalSetPipeLineState(pipelineState);
}

/*
*/
void
GPUCommandBuffer::close() {
  _internalClose();
}

/*
*/
void
GPUCommandBuffer::setGPUBuffer(const SPtr<GPUBuffer>& buff, uint32 slot) {
  _internalSetGPUBuffer(buff, slot);
}

/*
*/
void
GPUCommandBuffer::setGPUBuffers(const Vector<SPtr<GPUBuffer>>& buffs, uint32 slot) {
  _internalSetGPUBuffers(buffs, slot);
}

/*
*/
void
GPUCommandBuffer::setRect(const Box2D& rect) {
  _internalSetRect(rect);
}

/*
*/
void
GPUCommandBuffer::setScissorRect(const Box2D& rect) {
  _internalSetScissorRect(rect);
}

/*
*/
void
GPUCommandBuffer::setRenderTarget(const SPtr<Texture>& rt) {
  _internalSetRenderTarget(rt);
}

/*
*/
void
GPUCommandBuffer::setRenderTargets(const Vector<SPtr<Texture>>& rts) {
  _internalSetRenderTargets(rts);
}

/*
*/
void
GPUCommandBuffer::clearRenderTarget(const SPtr<Texture>& rt, 
                                    const LinearColor& color, 
                                    const bool bIsInRenderPass) {
  _internalClearRenderTarget(rt, color, bIsInRenderPass);
}

/*
*/
void
GPUCommandBuffer::clearRenderTargets(const Vector<SPtr<Texture>>& rts, 
                                     const LinearColor& color, 
                                     const bool bIsInRenderPass) {
  _internalClearRenderTargets(rts, color, bIsInRenderPass);
}

/*
*/
void
GPUCommandBuffer::setTopology(PRIMITIVE_TOPOLOGY_TYPE topology) {
  _internalSetTopology(topology);
}

/*
*/
void
GPUCommandBuffer::setVertexBuffer(uint32 startSlot, const SPtr<VertexBuffer>& vertexBuff) {
  _internalSetVertexBuffer(startSlot, vertexBuff);
}

/*
*/
void
GPUCommandBuffer::setVertexBuffers(uint32 startSlot, const Vector<SPtr<VertexBuffer>>& vertexBuffs) {
  _internalSetVertexBuffers(startSlot, vertexBuffs);
}

/*
*/
void
GPUCommandBuffer::setIndexBuffer( const SPtr<IndexBuffer> &indexBuff ) {
  _internalSetIndexBuffer(indexBuff);
}

/*
*/
void
GPUCommandBuffer::setBindingBufferGroup(const chGPUDesc::BindingGroup& bindingGroup) {
  _internalSetBindingBufferGroup(bindingGroup);
}

/*
*/
void
GPUCommandBuffer::drawInstanced(uint32 vertexCountPerInstance, 
                                uint32 instanceCount, 
                                uint32 startVertexLocation, 
                                uint32 startInstanceLocation) {
  _internalDrawInstanced(vertexCountPerInstance, 
                         instanceCount, 
                         startVertexLocation, 
                         startInstanceLocation);
}

/*
*/
void
GPUCommandBuffer::drawIndexed(uint32 indexCountPerInstance, 
                              uint32 instanceCount, 
                              uint32 startIndexLocation, 
                              int32 baseVertexLocation, 
                              uint32 startIstanceLocation) {
  _internalDrawIndexed(indexCountPerInstance, 
                       instanceCount, 
                       startIndexLocation,
                       baseVertexLocation, 
                       startIstanceLocation);
}

/*
*/
void
GPUCommandBuffer::resourceBarrier(const Vector<GPUBarrier>& barriers) {
  _internalResourceBarrier(barriers);
}

/*
*/
void
GPUCommandBuffer::resourceBarrierSwapChain(const chGPUDesc::GPUBarrier& barrier) {
 _internalResourceBarrierSwapChain(barrier);
}

/*
*/
bool
GPUCommandBuffer::present(int32 syncInterval, int32 flags) {
  return _internalPresent(syncInterval, flags);
}
} // namespace chEngineSDK


