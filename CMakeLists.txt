cmake_minimum_required(VERSION 3.10)

# Set the project name
project(EPAM_Cpp_Training VERSION 1.0)

# Set the C++ standard to C++17 or C++20
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optional: Add compiler flags for better debugging and warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Identify all .cpp files in the directory
file(GLOB SOURCE_FILES "*.cpp")

# Loop through each file and create an individual executable
# This is ideal for training repos where each file is a standalone task
foreach(SOURCE_FILE ${SOURCE_FILES})
    # Get the filename without the extension to use as the executable name
    get_filename_component(EXE_NAME ${SOURCE_FILE} NAME_WE)
    
    add_executable(${EXE_NAME} ${SOURCE_FILE})
    
    message(STATUS "Added executable: ${EXE_NAME}")
endforeach()