cmake_minimum_required(VERSION 3.22)

# Set the project name and language
project(Vulkan)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Set source files
set(SOURCES src/main.cpp)

# Define the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Define directory for stb
set(STB_INCLUDE_DIR ./include/core) # other loaction for stb: C:/msys64/mingw64/include/stb

# Define directory for tiny object loader
set(TINY_OBJ_INCLUDE_DIR ./include/core)

# Define the executable
add_executable(Vulkan ${SOURCES})

# Find Vulkan and GLFW3 packages
find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

# Link Vulkan and GLFW libraries to the executable
target_link_libraries(Vulkan PRIVATE ${Vulkan_LIBRARIES} glfw)

# Include Vulkan, GLFW and stb headers (target-scoped)
target_include_directories(Vulkan PRIVATE ${Vulkan_INCLUDE_DIRS})
target_include_directories(Vulkan PRIVATE ${GLFW_INCLUDE_DIRS})
target_include_directories(Vulkan PRIVATE ${STB_INCLUDE_DIR})
target_include_directories(Vulkan PRIVATE ${TINY_OBJ_INCLUDE_DIR})

# Set default build type if not specified
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()
