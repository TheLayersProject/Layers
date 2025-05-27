cmake_minimum_required(VERSION 3.22)

# Set the project name and version
project(Layers VERSION 0.18 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the include directories
include_directories(include)

# Collect all .cpp files in the src directory
file(GLOB SOURCES "src/*.cpp")

# Collect all .h/.hpp files in the include directory
file(GLOB HEADERS "include/Layers/*.h" "include/Layers/*.hpp")

# Create a shared library (including headers to show them in Qt Creator)
add_library(Layers SHARED ${SOURCES} ${HEADERS})
target_compile_definitions(Layers PRIVATE LAYERS_LIB)

# Specify the output directory for the library
set_target_properties(Layers PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
    ARCHIVE_OUTPUT_DIRECTORY  "${CMAKE_CURRENT_SOURCE_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY  "${CMAKE_CURRENT_SOURCE_DIR}/lib"
    DEBUG_POSTFIX "d"
)
