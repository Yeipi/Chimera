//#include "chPrerequisitesDX12.h"

#include "chDebug.h"
#include "chVulkanGraphicsModule.h"
#include "chVulkanGPUResourceModule.h"
#include "chScreenModule.h"

using namespace chEngineSDK;

CH_EXTERN CH_PLUGIN_EXPORT void
loadPlugin() {
  LOG_INFO("Loading Vulkan Plugin");

  GraphicsModule::startUp<GraphicsModuleVulkan>();
  GPUResourceModule::startUp<VulkanResourceModule>();

  if(!GraphicsModule::instance().isStarted() || !GPUResourceModule::instance().isStarted()) {
    LOG_ERROR("Vulkan plugin failed to load.");
    return;
  }
  
  LOG_INFO("Vulkan plugin loaded.");
}