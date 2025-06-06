/************************************************************************/
/**
 * @file chVulkanIndexBuffer.h
 * @author AccelMR
 * @date 2025/01/27
 *   Index buffer implementation for Vulkan.
 */
/************************************************************************/
#pragma once

/************************************************************************/
/*
 * Includes
 */
/************************************************************************/
#include "chPrerequisitesVulkan.h"

#include "chIndexBuffer.h"

namespace chEngineSDK {
class VulkanIndexBuffer : public IndexBuffer
{
 public:
  VulkanIndexBuffer() = default;
  ~VulkanIndexBuffer() = default;
  void
  _internalUpdate(const chGPUDesc::IndexBufferDesc& desc, 
                  const IndexBufferData data) override;

  void
  _internalInit(const chGPUDesc::IndexBufferDesc& desc) override;

  FORCEINLINE VkBuffer
  getBuffer() const {
    return m_buffer;
  }

  FORCEINLINE VkIndexType
  getIndexType() const {
    return m_indexType;
  }

 private:
  VkBuffer m_buffer;
  VkDeviceMemory m_bufferMemory;
  VkDevice m_device;
  VkIndexType m_indexType = VK_INDEX_TYPE_UINT32;
};
} // namespace chEngineSDK
