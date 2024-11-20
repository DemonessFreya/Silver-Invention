#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>

int main () {
    uint32_t layerCount = 0;

    // Query the number of instance layers
    VkResult result = vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
    if (result != VK_SUCCESS) {
        std::cerr << "Failed to enumerate Vulkan instance layers!" << std::endl;
        return EXIT_FAILURE;
    }

    // Retrieve the layer properties
    std::vector<VkLayerProperties> availableLayers(layerCount);
    result = vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());
    if (result != VK_SUCCESS) {
        std::cerr << "Failed to retrieve Vulkan instance layers!" << std::endl;
        return EXIT_FAILURE;
    }

    // Print the available layers
    std::cout << "Available Vulkan validation layers:" << std::endl;
    for (const auto& layer : availableLayers) {
        std::cout << "\t" << layer.layerName << ": " << layer.description << std::endl;
    }

    return EXIT_SUCCESS;
}
