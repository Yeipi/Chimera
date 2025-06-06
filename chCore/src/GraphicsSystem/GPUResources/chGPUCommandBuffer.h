/************************************************************************/
/**
 * @file chGPUCommandBuffer.h
 * @author AccelMR
 * @date 2022/09/28
 * @brief GPU Command buffer. Used to send instructions to the gpu to be 
 *        executed at the render pass.
 */
 /************************************************************************/
#pragma once

/************************************************************************/
/*
 * Includes
 */                                                                     
/************************************************************************/
#include "chPrerequisitesCore.h"

#include <chBox2D.h>

#include "chPrerequisitesGraphics.h"

namespace chEngineSDK {
class CH_CORE_EXPORT GPUCommandBuffer
{
 public:
 /*
  *   Default constructor
  */
  GPUCommandBuffer() = default;

 /*
  *   Default destructor
  */
  virtual ~GPUCommandBuffer() = default;

  void
  begin();

  void
  beginRenderPass(const SPtr<RenderPass>& renderPass, 
                  const SPtr<Framebuffer>& frameBuffer,
                  const Vector<LinearColor>& clearColors);

  void
  setSubpassIndex(uint32 index);

  void
  nextSubpass();

  void
  endRenderPass();

  void
  reset(const SPtr<GPUPipelineState>& pipelineState);

  void
  setPipeLineState(const SPtr<GPUPipelineState>& pipelineState);

  void 
  close();

  void 
  setGPUBuffer(const SPtr<GPUBuffer>& buff, uint32 slot);
  
  void 
  setGPUBuffers(const Vector<SPtr<GPUBuffer>>& buff, uint32 slot);

  void 
  setRect(const Box2D& rect);

  void 
  setScissorRect(const Box2D& rect);

  void 
  setRenderTarget(const SPtr<Texture>& rt);

  void 
  setRenderTargets(const Vector<SPtr<Texture>>& rts);

  void
  clearRenderTarget(const SPtr<Texture>& rt, 
                    const LinearColor& color, 
                    const bool bIsInRenderPass = false);

  void
  clearRenderTargets(const Vector<SPtr<Texture>>& rts, 
                     const LinearColor& color, 
                     const bool bIsInRenderPass = false);

  void
  setTopology(chGPUDesc::PRIMITIVE_TOPOLOGY_TYPE topology);

  void
  setVertexBuffer(uint32 startSlot, const SPtr<VertexBuffer>& vertexBuff);

  void 
  setVertexBuffers(uint32 startSlot, const Vector<SPtr<VertexBuffer>>& vertexBuff);

  void
  setIndexBuffer(const SPtr<IndexBuffer>& indexBuff);

  void
  setBindingBufferGroup(const chGPUDesc::BindingGroup& bindingGroup);

  void
  drawInstanced(uint32 vertexCountPerInstance,
                uint32 instanceCount,
                uint32 startVertexLocation,
                uint32 startInstanceLocation);

  void
  drawIndexed(uint32 indexCountPerInstance,
              uint32 instanceCount,
              uint32 startIndexLocation,
              int32 baseVertexLocation,
              uint32 startIstanceLocation);

  void 
  resourceBarrier(const Vector<chGPUDesc::GPUBarrier>& barriers);

  void
  resourceBarrierSwapChain(const chGPUDesc::GPUBarrier& barriers);

  bool
  present(int32 syncInterval, int32 flags);

 protected:
 friend class GraphicsModule;
 
  virtual void
  _init(chGPUDesc::COMMAND_BUFFER_TYPES commandBufferType) = 0;


  virtual void
  _internalBegin() = 0;

    virtual void
  _internalBeginRenderPass(const SPtr<RenderPass>& renderPass, 
                           const SPtr<Framebuffer>& frameBuffer,
                           const Vector<LinearColor>& clearColors) = 0;

  virtual void
  _internalSetSubpassIndex(uint32 index) = 0;

  virtual void
  _internalNextSubpass() = 0;

  virtual void
  _internalEndRenderPass() = 0;

  virtual void
  _internalReset(const SPtr<GPUPipelineState>& pipelineState) = 0;

  virtual void 
  _internalClose() = 0;
  
  virtual void
  _internalSetPipeLineState(const SPtr<GPUPipelineState>& pipelineState) = 0;

  virtual void 
  _internalSetGPUBuffer(const SPtr<GPUBuffer>& buff, uint32 slot) = 0;
  
  virtual void 
  _internalSetGPUBuffers(const Vector<SPtr<GPUBuffer>>& buff, uint32 slot) = 0;

  virtual void 
  _internalSetRect(const Box2D& rect) = 0;

  virtual void 
  _internalSetScissorRect(const Box2D& rect) = 0;

  virtual void 
  _internalSetRenderTarget(const SPtr<Texture>& rt) = 0;

  virtual void 
  _internalSetRenderTargets(const Vector<SPtr<Texture>>& rts) = 0;

  virtual void
  _internalClearRenderTarget(const SPtr<Texture>& rt, const LinearColor& color, const bool bIsInRenderPass = false) = 0;

  virtual void
  _internalClearRenderTargets(const Vector<SPtr<Texture>>& rts, const LinearColor& color, const bool bIsInRenderPass = false) = 0;

  virtual void
  _internalSetTopology(chGPUDesc::PRIMITIVE_TOPOLOGY_TYPE topology) = 0;

  virtual void
  _internalSetVertexBuffer(uint32 startSlot, const SPtr<VertexBuffer>& vertexBuff) = 0;

  virtual void
  _internalSetVertexBuffers(uint32 startSlot, const Vector<SPtr<VertexBuffer>>& vertexBuff) = 0;

  virtual void
  _internalSetIndexBuffer(const SPtr<IndexBuffer>& indexBuff) = 0;

  virtual void
  _internalSetBindingBufferGroup(const chGPUDesc::BindingGroup& bindingGroup) = 0;

  virtual void
  _internalDrawInstanced(uint32 vertexCountPerInstance,
                         uint32 instanceCount,
                         uint32 startVertexLocation,
                         uint32 startInstanceLocation) = 0;

  virtual void
  _internalDrawIndexed(uint32 indexCountPerInstance,
                       uint32 instanceCount,
                       uint32 startIndexLocation,
                       int32 baseVertexLocation,
                       uint32 startIstanceLocation) = 0;

  virtual void
  _internalResourceBarrier(const Vector<chGPUDesc::GPUBarrier>& barriers) = 0;

  virtual void
  _internalResourceBarrierSwapChain(const chGPUDesc::GPUBarrier& barriers) = 0;

  virtual bool
  _internalPresent(int32 syncInterval, int32 flags) = 0;
};
}

