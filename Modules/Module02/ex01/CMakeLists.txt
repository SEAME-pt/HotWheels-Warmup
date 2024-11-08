# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name
project(CarProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(includes includes/engine)

# Collect all source files
file(GLOB SOURCES "sources/*.cpp" "sources/engine/*.cpp")

# Add the executable
add_executable(main ${SOURCES})
