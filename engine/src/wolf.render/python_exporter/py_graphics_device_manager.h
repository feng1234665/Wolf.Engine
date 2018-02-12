/*
    Project          : Wolf Engine. Copyright(c) Pooya Eimandar (http://PooyaEimandar.com) . All rights reserved.
    Source           : Please direct any bug to https://github.com/PooyaEimandar/Wolf.Engine/issues
    Website          : http://WolfSource.io
    Name             : py_graphics_device_manager.h
    Description      : The python exporter for w_graphics_device_manager class and structs
    Comment          :
 */

#ifdef __PYTHON__

#ifndef __PY_GRAPHICS_DEVICE_MANAGER_H__
#define __PY_GRAPHICS_DEVICE_MANAGER_H__

#include <python_exporter/w_boost_python_helper.h>

namespace pywolf
{
	static void py_graphics_device_manager_export()
	{
		using namespace boost::python;
		using namespace wolf::graphics;

		//export w_graphics_device_manager_configs class
		class_<w_graphics_device_manager_configs>("w_graphics_device_manager_configs", init<>())
			.def_readwrite("debug_gpu", &w_graphics_device_manager_configs::debug_gpu, "debug_gpu")
			.def_readwrite("off_screen_mode", &w_graphics_device_manager_configs::off_screen_mode, "off_screen_mode")
			;

		//export w_viewport class
		class_<w_viewport>("w_viewport", init<>())
			.def_readwrite("x", &w_viewport::x, "x")
			.def_readwrite("y", &w_viewport::y, "y")
			.def_readwrite("width", &w_viewport::width, "width")
			.def_readwrite("height", &w_viewport::height, "height")
			.def_readwrite("minDepth", &w_viewport::minDepth, "minDepth")
			.def_readwrite("maxDepth", &w_viewport::maxDepth, "maxDepth")
			;

		//export w_viewport_scissor class
		class_<w_viewport_scissor>("w_viewport_scissor", init<>())
			.add_property("offset", &w_viewport_scissor::py_get_offset, &w_viewport_scissor::py_set_offset, "offset")
			.add_property("extent", &w_viewport_scissor::py_get_extent, &w_viewport_scissor::py_set_extent, "extent")
			;

		//export w_output_presentation_window class
		class_<w_output_presentation_window, boost::noncopyable>("w_output_presentation_window")
			.add_property("swap_chain_image_index", &w_output_presentation_window::swap_chain_image_index, "get swap chain image index")
			.add_property("swap_chain_image_is_available_semaphore", &w_output_presentation_window::swap_chain_image_is_available_semaphore, "semaphore for checking whether swap chain's image is available or not")
			.add_property("rendering_done_semaphore", &w_output_presentation_window::rendering_done_semaphore, "semaphore for signaling, when all rendering is done")
			.add_property("width", &w_output_presentation_window::width, "get width of presentation window")
			.add_property("height", &w_output_presentation_window::height, "get height of presentation window")
			.add_property("v_sync", &w_output_presentation_window::v_sync, "get status of v-sync")
			.add_property("cpu_access_to_swapchain_buffer", &w_output_presentation_window::cpu_access_to_swapchain_buffer, "get whether cpu allowed to access swap chain")
			.add_property("double_buffering", &w_output_presentation_window::double_buffering, "get statis of double buffering")
			;

		//export w_graphics_device class
		class_<w_graphics_device, boost::noncopyable>("w_graphics_device")
			.def("get_info", &w_graphics_device::get_info, "print graphics device information")
			.def("get_number_of_swap_chains", &w_graphics_device::get_number_of_swap_chains, "get number of swap chain buffers")
			.def("draw", &w_graphics_device::py_draw, "draw primitive(s) and instances using vertex & index buffer")
			.def("submit", &w_graphics_device::py_submit, "submit command buffer")
			.add_property("output_presentation_window", &w_graphics_device::py_get_output_presentation_window, "get shared pointer to the output presentation window structure")
			.add_property("graphics_queue", &w_graphics_device::vk_graphics_queue, "get graphics queue")
			.add_property("present_queue", &w_graphics_device::vk_present_queue, "get present queue")
			.add_property("compute_queue", &w_graphics_device::vk_compute_queue, "get compute queue")
			.add_property("transfer_queue", &w_graphics_device::vk_transfer_queue, "get transfer queue")
			.add_property("sparse_queue", &w_graphics_device::vk_sparse_queue, "get sparse queue")
			;

		//export w_push_constant_range class
		class_<w_push_constant_range, boost::noncopyable>("w_push_constant_range", init<>());

		//export w_descriptor_buffer_info class
		class_<w_descriptor_buffer_info, boost::noncopyable>("w_descriptor_buffer_info", init<>());

		//export w_descriptor_image_info class
		class_<w_descriptor_image_info, boost::noncopyable>("w_descriptor_image_info", init<>());

		//export w_pipeline_layout_create_info struct
		class_<w_pipeline_layout_create_info, boost::noncopyable>("w_pipeline_layout_create_info");

		//export w_pipeline_vertex_input_state_create_info struct
		class_<w_pipeline_vertex_input_state_create_info, boost::noncopyable>("w_pipeline_vertex_input_state_create_info");

		//export w_pipeline_input_assembly_state_create_info struct
		class_<w_pipeline_input_assembly_state_create_info, boost::noncopyable>("w_pipeline_input_assembly_state_create_info");

		//export w_pipeline_rasterization_state_create_info struct
		class_<w_pipeline_rasterization_state_create_info, boost::noncopyable>("w_pipeline_rasterization_state_create_info");

		//export w_pipeline_multisample_state_create_info struct
		class_<w_pipeline_multisample_state_create_info, boost::noncopyable>("w_pipeline_multisample_state_create_info");

		//export w_pipeline_color_blend_attachment_state struct
		class_<w_pipeline_color_blend_attachment_state, boost::noncopyable>("w_pipeline_color_blend_attachment_state");

		//define w_memory_property_flag_bits enum
		enum_<w_memory_property_flag_bits>("w_memory_property_flag_bits")
			.value("W_MEMORY_PROPERTY_DEVICE_LOCAL_BIT", w_memory_property_flag_bits::W_MEMORY_PROPERTY_DEVICE_LOCAL_BIT)
			.value("W_MEMORY_PROPERTY_HOST_VISIBLE_BIT", w_memory_property_flag_bits::W_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
			.value("W_MEMORY_PROPERTY_HOST_COHERENT_BIT", w_memory_property_flag_bits::W_MEMORY_PROPERTY_HOST_COHERENT_BIT)
			.value("W_MEMORY_PROPERTY_HOST_CACHED_BIT", w_memory_property_flag_bits::W_MEMORY_PROPERTY_HOST_CACHED_BIT)
			.value("W_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT", w_memory_property_flag_bits::W_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT)
			.value("W_MEMORY_PROPERTY_FLAG_BITS_MAX_ENUM", w_memory_property_flag_bits::W_MEMORY_PROPERTY_FLAG_BITS_MAX_ENUM)
			.export_values()
			;

		//define w_pipeline_stage_flag_bits enum
		enum_<w_pipeline_stage_flag_bits>("w_pipeline_stage_flag_bits")
			.value("W_PIPELINE_STAGE_TOP_OF_PIPE_BIT", w_pipeline_stage_flag_bits::W_PIPELINE_STAGE_TOP_OF_PIPE_BIT)
			.value("W_PIPELINE_STAGE_DRAW_INDIRECT_BIT", w_pipeline_stage_flag_bits::W_PIPELINE_STAGE_DRAW_INDIRECT_BIT)
			.value("W_PIPELINE_STAGE_VERTEX_INPUT_BIT", w_pipeline_stage_flag_bits::W_PIPELINE_STAGE_VERTEX_INPUT_BIT)
			.value("W_PIPELINE_STAGE_VERTEX_SHADER_BIT", w_pipeline_stage_flag_bits::W_PIPELINE_STAGE_VERTEX_SHADER_BIT)
			.value("W_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT", w_pipeline_stage_flag_bits::W_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT)
			.value("W_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT", w_pipeline_stage_flag_bits::W_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT)
			.value("W_PIPELINE_STAGE_GEOMETRY_SHADER_BIT", w_pipeline_stage_flag_bits::W_PIPELINE_STAGE_GEOMETRY_SHADER_BIT)
			.value("W_PIPELINE_STAGE_FRAGMENT_SHADER_BIT", w_pipeline_stage_flag_bits::W_PIPELINE_STAGE_FRAGMENT_SHADER_BIT)
			.value("W_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT", w_pipeline_stage_flag_bits::W_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT)
			.value("W_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT", w_pipeline_stage_flag_bits::W_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT)
			.value("W_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT", w_pipeline_stage_flag_bits::W_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT)
			.value("W_PIPELINE_STAGE_COMPUTE_SHADER_BIT", w_pipeline_stage_flag_bits::W_PIPELINE_STAGE_COMPUTE_SHADER_BIT)
			.value("W_PIPELINE_STAGE_TRANSFER_BIT", w_pipeline_stage_flag_bits::W_PIPELINE_STAGE_TRANSFER_BIT)
			.value("W_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT", w_pipeline_stage_flag_bits::W_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT)
			.value("W_PIPELINE_STAGE_HOST_BIT", w_pipeline_stage_flag_bits::W_PIPELINE_STAGE_HOST_BIT)
			.value("W_PIPELINE_STAGE_ALL_GRAPHICS_BIT", w_pipeline_stage_flag_bits::W_PIPELINE_STAGE_ALL_GRAPHICS_BIT)
			.value("W_PIPELINE_STAGE_ALL_COMMANDS_BIT", w_pipeline_stage_flag_bits::W_PIPELINE_STAGE_ALL_COMMANDS_BIT)
			.value("W_PIPELINE_STAGE_COMMAND_PROCESS_BIT_NVX", w_pipeline_stage_flag_bits::W_PIPELINE_STAGE_COMMAND_PROCESS_BIT_NVX)
			.value("W_PIPELINE_STAGE_FLAG_BITS_MAX_ENUM", w_pipeline_stage_flag_bits::W_PIPELINE_STAGE_FLAG_BITS_MAX_ENUM)
			.export_values()
			;

		//define w_dynamic_state enum
		enum_<w_dynamic_state>("w_dynamic_state")
			.value("W_DYNAMIC_STATE_VIEWPORT", w_dynamic_state::W_DYNAMIC_STATE_VIEWPORT)
			.value("W_DYNAMIC_STATE_SCISSOR", w_dynamic_state::W_DYNAMIC_STATE_SCISSOR)
			.value("W_DYNAMIC_STATE_LINE_WIDTH", w_dynamic_state::W_DYNAMIC_STATE_LINE_WIDTH)
			.value("W_DYNAMIC_STATE_DEPTH_BIAS", w_dynamic_state::W_DYNAMIC_STATE_DEPTH_BIAS)
			.value("W_DYNAMIC_STATE_BLEND_CONSTANTS", w_dynamic_state::W_DYNAMIC_STATE_BLEND_CONSTANTS)
			.value("W_DYNAMIC_STATE_DEPTH_BOUNDS", w_dynamic_state::W_DYNAMIC_STATE_DEPTH_BOUNDS)
			.value("W_DYNAMIC_STATE_STENCIL_COMPARE_MASK", w_dynamic_state::W_DYNAMIC_STATE_STENCIL_COMPARE_MASK)
			.value("W_DYNAMIC_STATE_STENCIL_WRITE_MASK", w_dynamic_state::W_DYNAMIC_STATE_STENCIL_WRITE_MASK)
			.value("W_DYNAMIC_STATE_STENCIL_REFERENCE", w_dynamic_state::W_DYNAMIC_STATE_STENCIL_REFERENCE)
			.value("W_DYNAMIC_STATE_VIEWPORT_W_SCALING_NV", w_dynamic_state::W_DYNAMIC_STATE_VIEWPORT_W_SCALING_NV)
			.value("W_DYNAMIC_STATE_DISCARD_RECTANGLE_EXT", w_dynamic_state::W_DYNAMIC_STATE_DISCARD_RECTANGLE_EXT)
			.value("W_DYNAMIC_STATE_SAMPLE_LOCATIONS_EXT", w_dynamic_state::W_DYNAMIC_STATE_SAMPLE_LOCATIONS_EXT)
			.value("W_DYNAMIC_STATE_BEGIN_RANGE", w_dynamic_state::W_DYNAMIC_STATE_BEGIN_RANGE)
			.value("W_DYNAMIC_STATE_END_RANGE", w_dynamic_state::W_DYNAMIC_STATE_END_RANGE)
			.value("W_DYNAMIC_STATE_RANGE_SIZE", w_dynamic_state::W_DYNAMIC_STATE_RANGE_SIZE)
			.value("W_DYNAMIC_STATE_MAX_ENUM", w_dynamic_state::W_DYNAMIC_STATE_MAX_ENUM)
			.export_values()
			;

		//define w_primitive_topology enum
		enum_<w_primitive_topology>("w_primitive_topology")
			.value("W_PRIMITIVE_TOPOLOGY_POINT_LIST", w_primitive_topology::W_PRIMITIVE_TOPOLOGY_POINT_LIST)
			.value("W_PRIMITIVE_TOPOLOGY_LINE_LIST", w_primitive_topology::W_PRIMITIVE_TOPOLOGY_LINE_LIST)
			.value("W_PRIMITIVE_TOPOLOGY_LINE_STRIP", w_primitive_topology::W_PRIMITIVE_TOPOLOGY_LINE_STRIP)
			.value("W_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST", w_primitive_topology::W_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST)
			.value("W_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP", w_primitive_topology::W_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP)
			.value("W_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN", w_primitive_topology::W_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN)
			.value("W_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY", w_primitive_topology::W_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY)
			.value("W_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY", w_primitive_topology::W_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY)
			.value("W_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY", w_primitive_topology::W_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY)
			.value("W_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY", w_primitive_topology::W_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY)
			.value("W_PRIMITIVE_TOPOLOGY_PATCH_LIST", w_primitive_topology::W_PRIMITIVE_TOPOLOGY_PATCH_LIST)
			.value("W_PRIMITIVE_TOPOLOGY_BEGIN_RANGE", w_primitive_topology::W_PRIMITIVE_TOPOLOGY_BEGIN_RANGE)
			.value("W_PRIMITIVE_TOPOLOGY_END_RANGE", w_primitive_topology::W_PRIMITIVE_TOPOLOGY_END_RANGE)
			.value("W_PRIMITIVE_TOPOLOGY_RANGE_SIZE", w_primitive_topology::W_PRIMITIVE_TOPOLOGY_RANGE_SIZE)
			.value("W_PRIMITIVE_TOPOLOGY_MAX_ENUM", w_primitive_topology::W_PRIMITIVE_TOPOLOGY_MAX_ENUM)
			.export_values()
			;

		//define w_format enum
		enum_<w_format>("w_format")
			.value("W_FORMAT_UNDEFINED", w_format::W_FORMAT_UNDEFINED)
			.value("W_FORMAT_R4G4_UNORM_PACK8", w_format::W_FORMAT_R4G4_UNORM_PACK8)
			.value("W_FORMAT_R4G4B4A4_UNORM_PACK16", w_format::W_FORMAT_R4G4B4A4_UNORM_PACK16)
			.value("W_FORMAT_B4G4R4A4_UNORM_PACK16", w_format::W_FORMAT_B4G4R4A4_UNORM_PACK16)
			.value("W_FORMAT_R5G6B5_UNORM_PACK16", w_format::W_FORMAT_R5G6B5_UNORM_PACK16)
			.value("W_FORMAT_B5G6R5_UNORM_PACK16", w_format::W_FORMAT_B5G6R5_UNORM_PACK16)
			.value("W_FORMAT_R5G5B5A1_UNORM_PACK16", w_format::W_FORMAT_R5G5B5A1_UNORM_PACK16)
			.value("W_FORMAT_B5G5R5A1_UNORM_PACK16", w_format::W_FORMAT_B5G5R5A1_UNORM_PACK16)
			.value("W_FORMAT_A1R5G5B5_UNORM_PACK16", w_format::W_FORMAT_A1R5G5B5_UNORM_PACK16)
			.value("W_FORMAT_R8_UNORM", w_format::W_FORMAT_R8_UNORM)
			.value("W_FORMAT_R8_SNORM", w_format::W_FORMAT_R8_SNORM)
			.value("W_FORMAT_R8_USCALED", w_format::W_FORMAT_R8_USCALED)
			.value("W_FORMAT_R8_SSCALED", w_format::W_FORMAT_R8_SSCALED)
			.value("W_FORMAT_R8_UINT", w_format::W_FORMAT_R8_UINT)
			.value("W_FORMAT_R8_SINT", w_format::W_FORMAT_R8_SINT)
			.value("W_FORMAT_R8_SRGB", w_format::W_FORMAT_R8_SRGB)
			.value("W_FORMAT_R8G8_UNORM", w_format::W_FORMAT_R8G8_UNORM)
			.value("W_FORMAT_R8G8_SNORM", w_format::W_FORMAT_R8G8_SNORM)
			.value("W_FORMAT_R8G8_USCALED", w_format::W_FORMAT_R8G8_USCALED)
			.value("W_FORMAT_R8G8_SSCALED", w_format::W_FORMAT_R8G8_SSCALED)
			.value("W_FORMAT_R8G8_UINT", w_format::W_FORMAT_R8G8_UINT)
			.value("W_FORMAT_R8G8_SINT", w_format::W_FORMAT_R8G8_SINT)
			.value("W_FORMAT_R8G8_SRGB", w_format::W_FORMAT_R8G8_SRGB)
			.value("W_FORMAT_R8G8B8_UNORM", w_format::W_FORMAT_R8G8B8_UNORM)
			.value("W_FORMAT_R8G8B8_SNORM", w_format::W_FORMAT_R8G8B8_SNORM)
			.value("W_FORMAT_R8G8B8_USCALED", w_format::W_FORMAT_R8G8B8_USCALED)
			.value("W_FORMAT_R8G8B8_SSCALED", w_format::W_FORMAT_R8G8B8_SSCALED)
			.value("W_FORMAT_R8G8B8_UINT", w_format::W_FORMAT_R8G8B8_UINT)
			.value("W_FORMAT_R8G8B8_SINT", w_format::W_FORMAT_R8G8B8_SINT)
			.value("W_FORMAT_R8G8B8_SRGB", w_format::W_FORMAT_R8G8B8_SRGB)
			.value("W_FORMAT_B8G8R8_UNORM", w_format::W_FORMAT_B8G8R8_UNORM)
			.value("W_FORMAT_B8G8R8_SNORM", w_format::W_FORMAT_B8G8R8_SNORM)
			.value("W_FORMAT_B8G8R8_USCALED", w_format::W_FORMAT_B8G8R8_USCALED)
			.value("W_FORMAT_B8G8R8_SSCALED", w_format::W_FORMAT_B8G8R8_SSCALED)
			.value("W_FORMAT_B8G8R8_UINT", w_format::W_FORMAT_B8G8R8_UINT)
			.value("W_FORMAT_B8G8R8_SINT", w_format::W_FORMAT_B8G8R8_SINT)
			.value("W_FORMAT_B8G8R8_SRGB", w_format::W_FORMAT_B8G8R8_SRGB)
			.value("W_FORMAT_R8G8B8A8_UNORM", w_format::W_FORMAT_R8G8B8A8_UNORM)
			.value("W_FORMAT_R8G8B8A8_SNORM", w_format::W_FORMAT_R8G8B8A8_SNORM)
			.value("W_FORMAT_R8G8B8A8_USCALED", w_format::W_FORMAT_R8G8B8A8_USCALED)
			.value("W_FORMAT_R8G8B8A8_SSCALED", w_format::W_FORMAT_R8G8B8A8_SSCALED)
			.value("W_FORMAT_R8G8B8A8_UINT", w_format::W_FORMAT_R8G8B8A8_UINT)
			.value("W_FORMAT_R8G8B8A8_SINT", w_format::W_FORMAT_R8G8B8A8_SINT)
			.value("W_FORMAT_R8G8B8A8_SRGB", w_format::W_FORMAT_R8G8B8A8_SRGB)
			.value("W_FORMAT_B8G8R8A8_UNORM", w_format::W_FORMAT_B8G8R8A8_UNORM)
			.value("W_FORMAT_B8G8R8A8_SNORM", w_format::W_FORMAT_B8G8R8A8_SNORM)
			.value("W_FORMAT_B8G8R8A8_USCALED", w_format::W_FORMAT_B8G8R8A8_USCALED)
			.value("W_FORMAT_B8G8R8A8_SSCALED", w_format::W_FORMAT_B8G8R8A8_SSCALED)
			.value("W_FORMAT_B8G8R8A8_UINT", w_format::W_FORMAT_B8G8R8A8_UINT)
			.value("W_FORMAT_B8G8R8A8_SINT", w_format::W_FORMAT_B8G8R8A8_SINT)
			.value("W_FORMAT_B8G8R8A8_SRGB", w_format::W_FORMAT_B8G8R8A8_SRGB)
			.value("W_FORMAT_A8B8G8R8_UNORM_PACK32", w_format::W_FORMAT_A8B8G8R8_UNORM_PACK32)
			.value("W_FORMAT_A8B8G8R8_SNORM_PACK32", w_format::W_FORMAT_A8B8G8R8_SNORM_PACK32)
			.value("W_FORMAT_A8B8G8R8_USCALED_PACK32", w_format::W_FORMAT_A8B8G8R8_USCALED_PACK32)
			.value("W_FORMAT_A8B8G8R8_SSCALED_PACK32", w_format::W_FORMAT_A8B8G8R8_SSCALED_PACK32)
			.value("W_FORMAT_A8B8G8R8_UINT_PACK32", w_format::W_FORMAT_A8B8G8R8_UINT_PACK32)
			.value("W_FORMAT_A8B8G8R8_SINT_PACK32", w_format::W_FORMAT_A8B8G8R8_SINT_PACK32)
			.value("W_FORMAT_A8B8G8R8_SRGB_PACK32", w_format::W_FORMAT_A8B8G8R8_SRGB_PACK32)
			.value("W_FORMAT_A2R10G10B10_UNORM_PACK32", w_format::W_FORMAT_A2R10G10B10_UNORM_PACK32)
			.value("W_FORMAT_A2R10G10B10_SNORM_PACK32", w_format::W_FORMAT_A2R10G10B10_SNORM_PACK32)
			.value("W_FORMAT_A2R10G10B10_USCALED_PACK32", w_format::W_FORMAT_A2R10G10B10_USCALED_PACK32)
			.value("W_FORMAT_A2R10G10B10_SSCALED_PACK32", w_format::W_FORMAT_A2R10G10B10_SSCALED_PACK32)
			.value("W_FORMAT_A2R10G10B10_UINT_PACK32", w_format::W_FORMAT_A2R10G10B10_UINT_PACK32)
			.value("W_FORMAT_A2R10G10B10_SINT_PACK32", w_format::W_FORMAT_A2R10G10B10_SINT_PACK32)
			.value("W_FORMAT_A2B10G10R10_UNORM_PACK32", w_format::W_FORMAT_A2B10G10R10_UNORM_PACK32)
			.value("W_FORMAT_A2B10G10R10_SNORM_PACK32", w_format::W_FORMAT_A2B10G10R10_SNORM_PACK32)
			.value("W_FORMAT_A2B10G10R10_USCALED_PACK32", w_format::W_FORMAT_A2B10G10R10_USCALED_PACK32)
			.value("W_FORMAT_A2B10G10R10_SSCALED_PACK32", w_format::W_FORMAT_A2B10G10R10_SSCALED_PACK32)
			.value("W_FORMAT_A2B10G10R10_UINT_PACK32", w_format::W_FORMAT_A2B10G10R10_UINT_PACK32)
			.value("W_FORMAT_A2B10G10R10_SINT_PACK32", w_format::W_FORMAT_A2B10G10R10_SINT_PACK32)
			.value("W_FORMAT_R16_UNORM", w_format::W_FORMAT_R16_UNORM)
			.value("W_FORMAT_R16_SNORM", w_format::W_FORMAT_R16_SNORM)
			.value("W_FORMAT_R16_USCALED", w_format::W_FORMAT_R16_USCALED)
			.value("W_FORMAT_R16_SSCALED", w_format::W_FORMAT_R16_SSCALED)
			.value("W_FORMAT_R16_UINT", w_format::W_FORMAT_R16_UINT)
			.value("W_FORMAT_R16_SINT", w_format::W_FORMAT_R16_SINT)
			.value("W_FORMAT_R16_SFLOAT", w_format::W_FORMAT_R16_SFLOAT)
			.value("W_FORMAT_R16G16_UNORM", w_format::W_FORMAT_R16G16_UNORM)
			.value("W_FORMAT_R16G16_SNORM", w_format::W_FORMAT_R16G16_SNORM)
			.value("W_FORMAT_R16G16_USCALED", w_format::W_FORMAT_R16G16_USCALED)
			.value("W_FORMAT_R16G16_SSCALED", w_format::W_FORMAT_R16G16_SSCALED)
			.value("W_FORMAT_R16G16_UINT", w_format::W_FORMAT_R16G16_UINT)
			.value("W_FORMAT_R16G16_SINT", w_format::W_FORMAT_R16G16_SINT)
			.value("W_FORMAT_R16G16_SFLOAT", w_format::W_FORMAT_R16G16_SFLOAT)
			.value("W_FORMAT_R16G16B16_UNORM", w_format::W_FORMAT_R16G16B16_UNORM)
			.value("W_FORMAT_R16G16B16_SNORM", w_format::W_FORMAT_R16G16B16_SNORM)
			.value("W_FORMAT_R16G16B16_USCALED", w_format::W_FORMAT_R16G16B16_USCALED)
			.value("W_FORMAT_R16G16B16_SSCALED", w_format::W_FORMAT_R16G16B16_SSCALED)
			.value("W_FORMAT_R16G16B16_UINT", w_format::W_FORMAT_R16G16B16_UINT)
			.value("W_FORMAT_R16G16B16_SINT", w_format::W_FORMAT_R16G16B16_SINT)
			.value("W_FORMAT_R16G16B16_SFLOAT", w_format::W_FORMAT_R16G16B16_SFLOAT)
			.value("W_FORMAT_R16G16B16A16_UNORM", w_format::W_FORMAT_R16G16B16A16_UNORM)
			.value("W_FORMAT_R16G16B16A16_SNORM", w_format::W_FORMAT_R16G16B16A16_SNORM)
			.value("W_FORMAT_R16G16B16A16_USCALED", w_format::W_FORMAT_R16G16B16A16_USCALED)
			.value("W_FORMAT_R16G16B16A16_SSCALED", w_format::W_FORMAT_R16G16B16A16_SSCALED)
			.value("W_FORMAT_R16G16B16A16_UINT", w_format::W_FORMAT_R16G16B16A16_UINT)
			.value("W_FORMAT_R16G16B16A16_SINT", w_format::W_FORMAT_R16G16B16A16_SINT)
			.value("W_FORMAT_R16G16B16A16_SFLOAT", w_format::W_FORMAT_R16G16B16A16_SFLOAT)
			.value("W_FORMAT_R32_UINT", w_format::W_FORMAT_R32_UINT)
			.value("W_FORMAT_R32_SINT", w_format::W_FORMAT_R32_SINT)
			.value("W_FORMAT_R32_SFLOAT", w_format::W_FORMAT_R32_SFLOAT)
			.value("W_FORMAT_R32G32_UINT", w_format::W_FORMAT_R32G32_UINT)
			.value("W_FORMAT_R32G32_SINT", w_format::W_FORMAT_R32G32_SINT)
			.value("W_FORMAT_R32G32_SFLOAT", w_format::W_FORMAT_R32G32_SFLOAT)
			.value("W_FORMAT_R32G32B32_UINT", w_format::W_FORMAT_R32G32B32_UINT)
			.value("W_FORMAT_R32G32B32_SINT", w_format::W_FORMAT_R32G32B32_SINT)
			.value("W_FORMAT_R32G32B32_SFLOAT", w_format::W_FORMAT_R32G32B32_SFLOAT)
			.value("W_FORMAT_R32G32B32A32_UINT", w_format::W_FORMAT_R32G32B32A32_UINT)
			.value("W_FORMAT_R32G32B32A32_SINT", w_format::W_FORMAT_R32G32B32A32_SINT)
			.value("W_FORMAT_R32G32B32A32_SFLOAT", w_format::W_FORMAT_R32G32B32A32_SFLOAT)
			.value("W_FORMAT_R64_UINT", w_format::W_FORMAT_R64_UINT)
			.value("W_FORMAT_R64_SINT", w_format::W_FORMAT_R64_SINT)
			.value("W_FORMAT_R64_SFLOAT", w_format::W_FORMAT_R64_SFLOAT)
			.value("W_FORMAT_R64G64_UINT", w_format::W_FORMAT_R64G64_UINT)
			.value("W_FORMAT_R64G64_SINT", w_format::W_FORMAT_R64G64_SINT)
			.value("W_FORMAT_R64G64_SFLOAT", w_format::W_FORMAT_R64G64_SFLOAT)
			.value("W_FORMAT_R64G64B64_UINT", w_format::W_FORMAT_R64G64B64_UINT)
			.value("W_FORMAT_R64G64B64_SINT", w_format::W_FORMAT_R64G64B64_SINT)
			.value("W_FORMAT_R64G64B64_SFLOAT", w_format::W_FORMAT_R64G64B64_SFLOAT)
			.value("W_FORMAT_R64G64B64A64_UINT", w_format::W_FORMAT_R64G64B64A64_UINT)
			.value("W_FORMAT_R64G64B64A64_SINT", w_format::W_FORMAT_R64G64B64A64_SINT)
			.value("W_FORMAT_R64G64B64A64_SFLOAT", w_format::W_FORMAT_R64G64B64A64_SFLOAT)
			.value("W_FORMAT_B10G11R11_UFLOAT_PACK32", w_format::W_FORMAT_B10G11R11_UFLOAT_PACK32)
			.value("W_FORMAT_E5B9G9R9_UFLOAT_PACK32", w_format::W_FORMAT_E5B9G9R9_UFLOAT_PACK32)
			.value("W_FORMAT_D16_UNORM", w_format::W_FORMAT_D16_UNORM)
			.value("W_FORMAT_X8_D24_UNORM_PACK32", w_format::W_FORMAT_X8_D24_UNORM_PACK32)
			.value("W_FORMAT_D32_SFLOAT", w_format::W_FORMAT_D32_SFLOAT)
			.value("W_FORMAT_S8_UINT", w_format::W_FORMAT_S8_UINT)
			.value("W_FORMAT_D16_UNORM_S8_UINT", w_format::W_FORMAT_D16_UNORM_S8_UINT)
			.value("W_FORMAT_D24_UNORM_S8_UINT", w_format::W_FORMAT_D24_UNORM_S8_UINT)
			.value("W_FORMAT_D32_SFLOAT_S8_UINT", w_format::W_FORMAT_D32_SFLOAT_S8_UINT)
			.value("W_FORMAT_BC1_RGB_UNORM_BLOCK", w_format::W_FORMAT_BC1_RGB_UNORM_BLOCK)
			.value("W_FORMAT_BC1_RGB_SRGB_BLOCK", w_format::W_FORMAT_BC1_RGB_SRGB_BLOCK)
			.value("W_FORMAT_BC1_RGBA_UNORM_BLOCK", w_format::W_FORMAT_BC1_RGBA_UNORM_BLOCK)
			.value("W_FORMAT_BC1_RGBA_SRGB_BLOCK", w_format::W_FORMAT_BC1_RGBA_SRGB_BLOCK)
			.value("W_FORMAT_BC2_UNORM_BLOCK", w_format::W_FORMAT_BC2_UNORM_BLOCK)
			.value("W_FORMAT_BC2_SRGB_BLOCK", w_format::W_FORMAT_BC2_SRGB_BLOCK)
			.value("W_FORMAT_BC3_UNORM_BLOCK", w_format::W_FORMAT_BC3_UNORM_BLOCK)
			.value("W_FORMAT_BC3_SRGB_BLOCK", w_format::W_FORMAT_BC3_SRGB_BLOCK)
			.value("W_FORMAT_BC4_UNORM_BLOCK", w_format::W_FORMAT_BC4_UNORM_BLOCK)
			.value("W_FORMAT_BC5_UNORM_BLOCK", w_format::W_FORMAT_BC5_UNORM_BLOCK)
			.value("W_FORMAT_BC5_SNORM_BLOCK", w_format::W_FORMAT_BC5_SNORM_BLOCK)
			.value("W_FORMAT_BC6H_UFLOAT_BLOCK", w_format::W_FORMAT_BC6H_UFLOAT_BLOCK)
			.value("W_FORMAT_BC6H_SFLOAT_BLOCK", w_format::W_FORMAT_BC6H_SFLOAT_BLOCK)
			.value("W_FORMAT_BC7_UNORM_BLOCK", w_format::W_FORMAT_BC7_UNORM_BLOCK)
			.value("W_FORMAT_BC7_SRGB_BLOCK", w_format::W_FORMAT_BC7_SRGB_BLOCK)
			.value("W_FORMAT_ETC2_R8G8B8_UNORM_BLOCK", w_format::W_FORMAT_ETC2_R8G8B8_UNORM_BLOCK)
			.value("W_FORMAT_ETC2_R8G8B8_SRGB_BLOCK", w_format::W_FORMAT_ETC2_R8G8B8_SRGB_BLOCK)
			.value("W_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK", w_format::W_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK)
			.value("W_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK", w_format::W_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK)
			.value("W_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK", w_format::W_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK)
			.value("W_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK", w_format::W_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK)
			.value("W_FORMAT_EAC_R11_UNORM_BLOCK", w_format::W_FORMAT_EAC_R11_UNORM_BLOCK)
			.value("W_FORMAT_EAC_R11_SNORM_BLOCK", w_format::W_FORMAT_EAC_R11_SNORM_BLOCK)
			.value("W_FORMAT_EAC_R11G11_UNORM_BLOCK", w_format::W_FORMAT_EAC_R11G11_UNORM_BLOCK)
			.value("W_FORMAT_EAC_R11G11_SNORM_BLOCK", w_format::W_FORMAT_EAC_R11G11_SNORM_BLOCK)
			.value("W_FORMAT_ASTC_4x4_UNORM_BLOCK", w_format::W_FORMAT_ASTC_4x4_UNORM_BLOCK)
			.value("W_FORMAT_ASTC_4x4_SRGB_BLOCK", w_format::W_FORMAT_ASTC_4x4_SRGB_BLOCK)
			.value("W_FORMAT_ASTC_5x4_UNORM_BLOCK", w_format::W_FORMAT_ASTC_5x4_UNORM_BLOCK)
			.value("W_FORMAT_ASTC_5x4_SRGB_BLOCK", w_format::W_FORMAT_ASTC_5x4_SRGB_BLOCK)
			.value("W_FORMAT_ASTC_5x5_UNORM_BLOCK", w_format::W_FORMAT_ASTC_5x5_UNORM_BLOCK)
			.value("W_FORMAT_ASTC_5x5_SRGB_BLOCK", w_format::W_FORMAT_ASTC_5x5_SRGB_BLOCK)
			.value("W_FORMAT_ASTC_6x5_UNORM_BLOCK", w_format::W_FORMAT_ASTC_6x5_UNORM_BLOCK)
			.value("W_FORMAT_ASTC_6x5_SRGB_BLOCK", w_format::W_FORMAT_ASTC_6x5_SRGB_BLOCK)
			.value("W_FORMAT_ASTC_6x6_UNORM_BLOCK", w_format::W_FORMAT_ASTC_6x6_UNORM_BLOCK)
			.value("W_FORMAT_ASTC_6x6_SRGB_BLOCK", w_format::W_FORMAT_ASTC_6x6_SRGB_BLOCK)
			.value("W_FORMAT_ASTC_8x5_UNORM_BLOCK", w_format::W_FORMAT_ASTC_8x5_UNORM_BLOCK)
			.value("W_FORMAT_ASTC_8x5_SRGB_BLOCK", w_format::W_FORMAT_ASTC_8x5_SRGB_BLOCK)
			.value("W_FORMAT_ASTC_8x6_UNORM_BLOCK", w_format::W_FORMAT_ASTC_8x6_UNORM_BLOCK)
			.value("W_FORMAT_ASTC_8x6_SRGB_BLOCK", w_format::W_FORMAT_ASTC_8x6_SRGB_BLOCK)
			.value("W_FORMAT_ASTC_8x8_UNORM_BLOCK", w_format::W_FORMAT_ASTC_8x8_UNORM_BLOCK)
			.value("W_FORMAT_ASTC_8x8_SRGB_BLOCK", w_format::W_FORMAT_ASTC_8x8_SRGB_BLOCK)
			.value("W_FORMAT_ASTC_10x5_UNORM_BLOCK", w_format::W_FORMAT_ASTC_10x5_UNORM_BLOCK)
			.value("W_FORMAT_ASTC_10x5_SRGB_BLOCK", w_format::W_FORMAT_ASTC_10x5_SRGB_BLOCK)
			.value("W_FORMAT_ASTC_10x6_UNORM_BLOCK", w_format::W_FORMAT_ASTC_10x6_UNORM_BLOCK)
			.value("W_FORMAT_ASTC_10x6_SRGB_BLOCK", w_format::W_FORMAT_ASTC_10x6_SRGB_BLOCK)
			.value("W_FORMAT_ASTC_10x8_UNORM_BLOCK", w_format::W_FORMAT_ASTC_10x8_UNORM_BLOCK)
			.value("W_FORMAT_ASTC_10x8_SRGB_BLOCK", w_format::W_FORMAT_ASTC_10x8_SRGB_BLOCK)
			.value("W_FORMAT_ASTC_10x10_UNORM_BLOCK", w_format::W_FORMAT_ASTC_10x10_UNORM_BLOCK)
			.value("W_FORMAT_ASTC_10x10_SRGB_BLOCK", w_format::W_FORMAT_ASTC_10x10_SRGB_BLOCK)
			.value("W_FORMAT_ASTC_12x10_UNORM_BLOCK", w_format::W_FORMAT_ASTC_12x10_UNORM_BLOCK)
			.value("W_FORMAT_ASTC_12x10_SRGB_BLOCK", w_format::W_FORMAT_ASTC_12x10_SRGB_BLOCK)
			.value("W_FORMAT_ASTC_12x12_UNORM_BLOCK", w_format::W_FORMAT_ASTC_12x12_UNORM_BLOCK)
			.value("W_FORMAT_ASTC_12x12_SRGB_BLOCK", w_format::W_FORMAT_ASTC_12x12_SRGB_BLOCK)
			.value("W_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG", w_format::W_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG)
			.value("W_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG", w_format::W_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG)
			.value("W_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG", w_format::W_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG)
			.value("W_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG", w_format::W_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG)
			.value("W_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG", w_format::W_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG)
			.value("W_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG", w_format::W_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG)
			.value("W_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG", w_format::W_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG)
			.value("W_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG", w_format::W_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG)
			.value("W_FORMAT_G8B8G8R8_422_UNORM_KHR", w_format::W_FORMAT_G8B8G8R8_422_UNORM_KHR)
			.value("W_FORMAT_B8G8R8G8_422_UNORM_KHR", w_format::W_FORMAT_B8G8R8G8_422_UNORM_KHR)
			.value("W_FORMAT_G8_B8_R8_3PLANE_420_UNORM_KHR", w_format::W_FORMAT_G8_B8_R8_3PLANE_420_UNORM_KHR)
			.value("W_FORMAT_G8_B8R8_2PLANE_420_UNORM_KHR", w_format::W_FORMAT_G8_B8R8_2PLANE_420_UNORM_KHR)
			.value("W_FORMAT_G8_B8_R8_3PLANE_422_UNORM_KHR", w_format::W_FORMAT_G8_B8_R8_3PLANE_422_UNORM_KHR)
			.value("W_FORMAT_G8_B8R8_2PLANE_422_UNORM_KHR", w_format::W_FORMAT_G8_B8R8_2PLANE_422_UNORM_KHR)
			.value("W_FORMAT_G8_B8_R8_3PLANE_444_UNORM_KHR", w_format::W_FORMAT_G8_B8_R8_3PLANE_444_UNORM_KHR)
			.value("W_FORMAT_R10X6_UNORM_PACK16_KHR", w_format::W_FORMAT_R10X6_UNORM_PACK16_KHR)
			.value("W_FORMAT_R10X6G10X6_UNORM_2PACK16_KHR", w_format::W_FORMAT_R10X6G10X6_UNORM_2PACK16_KHR)
			.value("W_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16_KHR", w_format::W_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16_KHR)
			.value("W_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16_KHR", w_format::W_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16_KHR)
			.value("W_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16_KHR", w_format::W_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16_KHR)
			.value("W_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16_KHR", w_format::W_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16_KHR)
			.value("W_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16_KHR", w_format::W_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16_KHR)
			.value("W_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16_KHR", w_format::W_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16_KHR)
			.value("W_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16_KHR", w_format::W_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16_KHR)
			.value("W_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16_KHR", w_format::W_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16_KHR)
			.value("W_FORMAT_R12X4_UNORM_PACK16_KHR", w_format::W_FORMAT_R12X4_UNORM_PACK16_KHR)
			.value("W_FORMAT_R12X4G12X4_UNORM_2PACK16_KHR", w_format::W_FORMAT_R12X4G12X4_UNORM_2PACK16_KHR)
			.value("W_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16_KHR", w_format::W_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16_KHR)
			.value("W_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16_KHR", w_format::W_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16_KHR)
			.value("W_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16_KHR", w_format::W_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16_KHR)
			.value("W_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16_KHR", w_format::W_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16_KHR)
			.value("W_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16_KHR", w_format::W_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16_KHR)
			.value("W_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16_KHR", w_format::W_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16_KHR)
			.value("W_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16_KHR", w_format::W_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16_KHR)
			.value("W_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16_KHR", w_format::W_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16_KHR)
			.value("W_FORMAT_G16B16G16R16_422_UNORM_KHR", w_format::W_FORMAT_G16B16G16R16_422_UNORM_KHR)
			.value("W_FORMAT_B16G16R16G16_422_UNORM_KHR", w_format::W_FORMAT_B16G16R16G16_422_UNORM_KHR)
			.value("W_FORMAT_G16_B16_R16_3PLANE_420_UNORM_KHR", w_format::W_FORMAT_G16_B16_R16_3PLANE_420_UNORM_KHR)
			.value("W_FORMAT_G16_B16R16_2PLANE_420_UNORM_KHR", w_format::W_FORMAT_G16_B16R16_2PLANE_420_UNORM_KHR)
			.value("W_FORMAT_G16_B16_R16_3PLANE_422_UNORM_KHR", w_format::W_FORMAT_G16_B16_R16_3PLANE_422_UNORM_KHR)
			.value("W_FORMAT_G16_B16R16_2PLANE_422_UNORM_KHR", w_format::W_FORMAT_G16_B16R16_2PLANE_422_UNORM_KHR)
			.value("W_FORMAT_G16_B16_R16_3PLANE_444_UNORM_KHR", w_format::W_FORMAT_G16_B16_R16_3PLANE_444_UNORM_KHR)
			.export_values()
			;



			register_ptr_to_python< boost::shared_ptr<w_output_presentation_window>>();
	}
}

#endif//__PY_GRAPHICS_DEVICE_MANAGER_H__

#endif//__PYTHON__
