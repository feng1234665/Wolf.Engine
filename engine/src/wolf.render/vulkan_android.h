/*
	Project			 : Wolf Engine. Copyright(c) Pooya Eimandar (http://PooyaEimandar.com) . All rights reserved.
	Source			 : Please direct any bug to https://github.com/PooyaEimandar/Wolf.Engine/issues
	Website			 : http://WolfSource.io
	Name			 : vulkan_android.h
	Description		 : The helper header for vulkan driver on android, Android API 23(Android 6) supports android, but libvulkan.so is 
						avaiable from API 24(Android 7)
	Comment          :
*/

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef __VULKAN_ANDROID_H__
#define __VULKAN_ANDROID_H__

#ifdef __ANDROID

#ifndef VK_USE_PLATFORM_ANDROID_KHR
#define VK_USE_PLATFORM_ANDROID_KHR
#endif

#include "vulkan/vulkan.h"

namespace android
{
	extern PFN_vkCreateInstance vkCreateInstance;
	extern PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr;
	extern PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;
	extern PFN_vkCreateDevice vkCreateDevice;
	extern PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices;
	extern PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties;
	extern PFN_vkEnumerateDeviceExtensionProperties vkEnumerateDeviceExtensionProperties;
	extern PFN_vkEnumerateDeviceLayerProperties vkEnumerateDeviceLayerProperties;
	extern PFN_vkGetPhysicalDeviceFormatProperties vkGetPhysicalDeviceFormatProperties;
	extern PFN_vkGetPhysicalDeviceFeatures vkGetPhysicalDeviceFeatures;
	extern PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties;
	extern PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties;
	extern PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties;
	extern PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;
	extern PFN_vkCmdPipelineBarrier vkCmdPipelineBarrier;
	extern PFN_vkCreateShaderModule vkCreateShaderModule;
	extern PFN_vkCreateBuffer vkCreateBuffer;
	extern PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements;
	extern PFN_vkMapMemory vkMapMemory;
	extern PFN_vkUnmapMemory vkUnmapMemory;
	extern PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges;
	extern PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges;
	extern PFN_vkBindBufferMemory vkBindBufferMemory;
	extern PFN_vkDestroyBuffer vkDestroyBuffer;
	extern PFN_vkAllocateMemory vkAllocateMemory;
	extern PFN_vkBindImageMemory vkBindImageMemory;
	extern PFN_vkGetImageSubresourceLayout vkGetImageSubresourceLayout;
	extern PFN_vkCmdCopyBuffer vkCmdCopyBuffer;
	extern PFN_vkCmdCopyBufferToImage vkCmdCopyBufferToImage;
	extern PFN_vkCmdCopyImage vkCmdCopyImage;
	extern PFN_vkCmdBlitImage vkCmdBlitImage;
	extern PFN_vkCmdClearAttachments vkCmdClearAttachments;
	extern PFN_vkCreateSampler vkCreateSampler;
	extern PFN_vkDestroySampler vkDestroySampler;
	extern PFN_vkDestroyImage vkDestroyImage;
	extern PFN_vkFreeMemory vkFreeMemory;
	extern PFN_vkCreateRenderPass vkCreateRenderPass;
	extern PFN_vkCmdBeginRenderPass vkCmdBeginRenderPass;
	extern PFN_vkCmdEndRenderPass vkCmdEndRenderPass;
	extern PFN_vkCmdExecuteCommands vkCmdExecuteCommands;
	extern PFN_vkCreateImage vkCreateImage;
	extern PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements;
	extern PFN_vkCreateImageView vkCreateImageView;
	extern PFN_vkDestroyImageView vkDestroyImageView;
	extern PFN_vkCreateSemaphore vkCreateSemaphore;
	extern PFN_vkDestroySemaphore vkDestroySemaphore;
	extern PFN_vkCreateFence vkCreateFence;
	extern PFN_vkDestroyFence vkDestroyFence;
	extern PFN_vkWaitForFences vkWaitForFences;
	extern PFN_vkResetFences vkResetFences;
	extern PFN_vkCreateCommandPool vkCreateCommandPool;
	extern PFN_vkDestroyCommandPool vkDestroyCommandPool;
	extern PFN_vkAllocateCommandBuffers vkAllocateCommandBuffers;
	extern PFN_vkBeginCommandBuffer vkBeginCommandBuffer;
	extern PFN_vkEndCommandBuffer vkEndCommandBuffer;
	extern PFN_vkGetDeviceQueue vkGetDeviceQueue;
	extern PFN_vkQueueSubmit vkQueueSubmit;
	extern PFN_vkQueueWaitIdle vkQueueWaitIdle;
	extern PFN_vkDeviceWaitIdle vkDeviceWaitIdle;
	extern PFN_vkCreateFramebuffer vkCreateFramebuffer;
	extern PFN_vkCreatePipelineCache vkCreatePipelineCache;
	extern PFN_vkCreatePipelineLayout vkCreatePipelineLayout;
	extern PFN_vkCreateGraphicsPipelines vkCreateGraphicsPipelines;
	extern PFN_vkCreateComputePipelines vkCreateComputePipelines;
	extern PFN_vkCreateDescriptorPool vkCreateDescriptorPool;
	extern PFN_vkCreateDescriptorSetLayout vkCreateDescriptorSetLayout;
	extern PFN_vkAllocateDescriptorSets vkAllocateDescriptorSets;
	extern PFN_vkUpdateDescriptorSets vkUpdateDescriptorSets;
	extern PFN_vkCmdBindDescriptorSets vkCmdBindDescriptorSets;
	extern PFN_vkCmdBindPipeline vkCmdBindPipeline;
	extern PFN_vkCmdBindVertexBuffers vkCmdBindVertexBuffers;
	extern PFN_vkCmdBindIndexBuffer vkCmdBindIndexBuffer;
	extern PFN_vkCmdSetViewport vkCmdSetViewport;
	extern PFN_vkCmdSetScissor vkCmdSetScissor;
	extern PFN_vkCmdSetLineWidth vkCmdSetLineWidth;
	extern PFN_vkCmdSetDepthBias vkCmdSetDepthBias;
	extern PFN_vkCmdPushConstants vkCmdPushConstants;
	extern PFN_vkCmdDrawIndexed vkCmdDrawIndexed;
	extern PFN_vkCmdDraw vkCmdDraw;
	extern PFN_vkCmdDrawIndexedIndirect vkCmdDrawIndexedIndirect;
	extern PFN_vkCmdDrawIndirect vkCmdDrawIndirect;
	extern PFN_vkCmdDispatch vkCmdDispatch;
	extern PFN_vkDestroyPipeline vkDestroyPipeline;
	extern PFN_vkDestroyPipelineLayout vkDestroyPipelineLayout;
	extern PFN_vkDestroyDescriptorSetLayout vkDestroyDescriptorSetLayout;
	extern PFN_vkDestroyDevice vkDestroyDevice;
	extern PFN_vkDestroyInstance vkDestroyInstance;
	extern PFN_vkDestroyDescriptorPool vkDestroyDescriptorPool;
	extern PFN_vkFreeCommandBuffers vkFreeCommandBuffers;
	extern PFN_vkDestroyRenderPass vkDestroyRenderPass;
	extern PFN_vkDestroyFramebuffer vkDestroyFramebuffer;
	extern PFN_vkDestroyShaderModule vkDestroyShaderModule;
	extern PFN_vkDestroyPipelineCache vkDestroyPipelineCache;
	extern PFN_vkCreateQueryPool vkCreateQueryPool;
	extern PFN_vkDestroyQueryPool vkDestroyQueryPool;
	extern PFN_vkGetQueryPoolResults vkGetQueryPoolResults;
	extern PFN_vkCmdBeginQuery vkCmdBeginQuery;
	extern PFN_vkCmdEndQuery vkCmdEndQuery;
	extern PFN_vkCmdResetQueryPool vkCmdResetQueryPool;
	extern PFN_vkCmdCopyQueryPoolResults vkCmdCopyQueryPoolResults;

	extern PFN_vkCreateAndroidSurfaceKHR vkCreateAndroidSurfaceKHR;
	extern PFN_vkDestroySurfaceKHR vkDestroySurfaceKHR;

	extern PFN_vkDestroySwapchainKHR vkDestroySwapchainKHR;
	extern PFN_vkGetPhysicalDeviceSurfaceFormatsKHR vkGetPhysicalDeviceSurfaceFormatsKHR;
	extern PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
	extern PFN_vkGetPhysicalDeviceSurfacePresentModesKHR vkGetPhysicalDeviceSurfacePresentModesKHR;
	extern PFN_vkCreateSwapchainKHR vkCreateSwapchainKHR;
	extern PFN_vkGetSwapchainImagesKHR vkGetSwapchainImagesKHR;
	extern PFN_vkCmdClearColorImage vkCmdClearColorImage;
	extern PFN_vkAcquireNextImageKHR vkAcquireNextImageKHR;
	extern PFN_vkQueuePresentKHR vkQueuePresentKHR;

	extern PFN_vkGetPhysicalDeviceSurfaceSupportKHR vkGetPhysicalDeviceSurfaceSupportKHR;

	extern bool vk_load_library();
	extern void vk_load_functions_of_instance(VkInstance pInstance);
	extern void vk_load_functions_of_device(VkDevice pDevice);
	extern void vk_free_library();
}

#endif

#endif // VULKANANDROID_H
 