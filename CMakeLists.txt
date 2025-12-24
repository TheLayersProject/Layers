cmake_minimum_required(VERSION 3.22)

# Set the project name and version
project(Layers VERSION 0.18 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Force output directories for all configurations
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/lib")

# Define the include directories
include_directories(include)

# Collect all .cpp files in the src directory
file(GLOB SOURCES "src/*.cpp")

# Collect all .h/.hpp files in the include directory
file(GLOB HEADERS "include/Layers/*.h" "include/Layers/*.hpp")

# Create a shared library (including headers to show them in Qt Creator)
add_library(Layers SHARED ${SOURCES} ${HEADERS})
target_compile_definitions(Layers PRIVATE LAYERS_LIB)

# Create executable for resource compiler
add_executable(LayersResourceCompiler LayersResourceCompiler/main.cpp)

target_link_libraries(LayersResourceCompiler PRIVATE Layers)
target_include_directories(LayersResourceCompiler PRIVATE include)

set_target_properties(Layers LayersResourceCompiler PROPERTIES
    PREFIX ""
    DEBUG_POSTFIX "d"
)
