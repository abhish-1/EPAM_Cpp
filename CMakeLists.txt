cmake_minimum_required (VERSION 3.8)

project ("EpamLearningPath")

# COMMAND TO FIX: Use GLOB_RECURSE to find .cpp files in all subfolders
file(GLOB_RECURSE SOURCES "module*/*.cpp")

foreach(sourcefile ${SOURCES})
    # Get the file name (e.g., "poly1")
    get_filename_component(name ${sourcefile} NAME_WE)
    
    # Create a separate executable for every single file found
    add_executable(${name} ${sourcefile})
endforeach()    