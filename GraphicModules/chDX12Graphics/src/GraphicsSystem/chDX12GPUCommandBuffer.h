/************************************************************************/
/**
 * @file chDX12GPUCommandBuffer.h
 * @author AccelMR
 * @date 2022/09/28
 * @brief  GPU Command buffer. Used to send instructions to the GPU to be
 *        executed at the render pass.
 * 
 * DirectX implementation specific.
 */
 /************************************************************************/
#pragma once

/************************************************************************/
/*
 * Includes
 */                                                                     
/************************************************************************/
#include "chPrerequisitesDX12.h"

#include <chGPUCommandBuffer.h>

class ID3D12CommandAllocator;
namespace chEngineSDK{
class GraphicsModuleDX12;

class DX12GPUCommandBuffer final: public GPUCommandBuffer {
 public:
 /*
  *   Default constructor
  */
  DX12GPUCommandBuffer() = default;

 /*
  *   Default destructor
  */
  ~DX12GPUCommandBuffer();


 protected:
 friend class GraphicsModuleDX12;

   void
  _init(chGPUDesc::COMMAND_BUFFER_TYPES commandBufferType,
        const SPtr<GPUPipelineState> & pipelineState) override;

  void 
  _internalReset(const SPtr<GPUPipelineState>& pipelineState) override;
  
  void 
  _internalclose() override;
  
  void 
  _internalsetGPUBuffer(const SPtr<GPUBuffer>& buff, uint32 slot) override;
  
  void 
  _internalsetGPUBuffers(const Vector<SPtr<GPUBuffer>>& buff, uint32 slot) override;
  
  void 
  _internalsetRect(const Box2D& rect) override;

  void
  _internalSetScissorRect(const Box2D& rect) override;
  
  void 
  _internalsetRenderTarget(const SPtr<Texture>& rt) override;
  
  void 
  _internalsetRenderTargets(const Vector<SPtr<Texture>>& rts) override;
  
  void 
  _internalclearRenderTarget(const SPtr<Texture>& rt, const LinearColor& color) override;
  
  void 
  _internalclearRenderTargets(const Vector<SPtr<Texture>>& rts, const LinearColor& color) override;
  
  void 
  _internalsetTopology(chGPUDesc::PRIMITIVE_TOPOLOGY_TYPE topology) override;
  
  void 
  _internalsetVertexBuffer(uint32 startSlot, 
                           uint32 numViews, 
                           const SPtr<VertexBuffer>& vertexBuff) override;

  void 
  _internaldrawInstanced(uint32 vertexCountPerInstance, 
                         uint32 instanceCount, 
                         uint32 startVertexLocation,
                         uint32 startInstanceLocation) override;
  
  
  void 
  _internalResourceBarrier(const Vector<chGPUDesc::GPUBarrier>& barriers) override;


  void 
  _internalClearSwapChainTexture(const LinearColor& color) override;


  void 
  _internalSetSwapChain() override;


  void
  _internalResourceBarrierSwapChain(const chGPUDesc::GPUBarrier& barriers) override;


  void 
  _internalSetPipeLineState(const SPtr<GPUPipelineState>& pipelineState) override;

  void 
  _internalSetBindingBufferGroup(const chGPUDesc::BindingGroup& bindingGroup) override;

  void 
  _internalSetIndexBuffer(const SPtr<IndexBuffer>& indexBuff) override;

  void 
  _internalDrawIndexed(uint32 indexCountPerInstance, 
                       uint32 instanceCount, 
                       uint32 startIndexLocation, 
                       int32 baseVertexLocation, 
                       uint32 startIstanceLocation) override;

private:
  ID3D12GraphicsCommandList* m_commandList{};
  GraphicsModuleDX12* rhiModule;
};
}

