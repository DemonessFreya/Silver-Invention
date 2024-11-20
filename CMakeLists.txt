cmake_minimum_required(VERSION 3.22)

# Set the project name and language
project(Vulkan)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Set source files
set(SOURCES src/main.cpp)

# Define the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Define the executable
add_executable(Vulkan ${SOURCES})

# Find Vulkan and GLFW3 packages
find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

# Check if Vulkan and GLFW are found
if (NOT Vulkan_FOUND)
    message(FATAL_ERROR "Vulkan SDK not found! Please install the Vulkan SDK.")
endif()

if (NOT glfw3_FOUND)
    message(FATAL_ERROR "GLFW not found! Make sure it's installed or use a package manager.")
endif()

# Link Vulkan and GLFW libraries to the executable
target_link_libraries(Vulkan PRIVATE ${Vulkan_LIBRARIES} glfw)

# Include Vulkan and GLFW headers (target-scoped)
target_include_directories(Vulkan PRIVATE ${Vulkan_INCLUDE_DIRS})
target_include_directories(Vulkan PRIVATE ${GLFW_INCLUDE_DIRS})

# Set default build type if not specified
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()
