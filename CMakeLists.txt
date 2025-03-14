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
set(STB_INCLUDE_DIR C:/msys64/mingw64/include/stb) # other loaction for stb: C:/msys64/mingw64/include/stb

# Define directory for tiny object loader
set(TINY_OBJ_INCLUDE_DIR ./include/core/tinyobjectloader)

# Define the executable
add_executable(Vulkan ${SOURCES})

# Find Vulkan and GLFW3 packages
find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

# Link Vulkan and GLFW libraries to the executable
target_link_libraries(Vulkan PRIVATE ${Vulkan_LIBRARIES} glfw)

# Include Vulkan, GLFW, stb and tinyobj headers (target-scoped)
target_include_directories(Vulkan PRIVATE ${Vulkan_INCLUDE_DIRS})
target_include_directories(Vulkan PRIVATE ${GLFW_INCLUDE_DIRS})
target_include_directories(Vulkan PRIVATE ${STB_INCLUDE_DIR})
target_include_directories(Vulkan PRIVATE
    ${CMAKE_SOURCE_DIR}/include  # Add the root include directory
    ${CMAKE_SOURCE_DIR}/include/core/tinyobjectloader
)
