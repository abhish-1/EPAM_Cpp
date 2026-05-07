cmake_minimum_required(VERSION 3.14)

project("EpamLearningPath")

set(CMAKE_CXX_STANDARD 20)

# Find all .cpp files recursively
file(GLOB_RECURSE SOURCES "*.cpp")

foreach(sourcefile ${SOURCES})
    # Get a unique target name from the relative path (e.g., "module8_task1")
    file(RELATIVE_PATH relpath ${CMAKE_SOURCE_DIR} ${sourcefile})
    string(REPLACE "/" "_" name ${relpath})
    string(REPLACE "\\" "_" name ${name})
    string(REPLACE ".cpp" "" name ${name})
    string(REPLACE ".CPP" "" name ${name})
    # Sanitize invalid characters in target names
    string(REGEX REPLACE "[^a-zA-Z0-9_]" "_" name ${name})

    add_executable(${name} ${sourcefile})
endforeach()    