cmake_minimum_required(VERSION 3.22)
project(VulkanLayers)

set(CMAKE_CXX_STANDARD 20)

# Source file
set(SOURCES list_layers.cpp)

add_executable(VulkanLayers ${SOURCES})

find_package(Vulkan REQUIRED)
target_link_libraries(VulkanLayers PRIVATE Vulkan::Vulkan)
