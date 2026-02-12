cmake_minimum_required(VERSION 3.16)

project(EPAM_CXX LANGUAGES CXX)

# -------------------------------
# C++ Standard
# -------------------------------
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_ROOT ${CMAKE_SOURCE_DIR})

# -------------------------------
# Optional helper library (notes)
# -------------------------------
set(NOTES_PATHS
    "${SRC_ROOT}/Module2/encapsulationAbstrctionInheritnace/notes.cpp"
    "${SRC_ROOT}/Module2/encapsulationAbstrctionInheritnace/Notes.cpp"
    "${SRC_ROOT}/encapsulationAbstrictionInheritance/notes.cpp"
    "${SRC_ROOT}/encapsulationAbstrictionInheritance/Notes.cpp"
)

set(NOTES_SOURCES "")
foreach(p IN LISTS NOTES_PATHS)
    if(EXISTS "${p}")
        list(APPEND NOTES_SOURCES "${p}")
    endif()
endforeach()

if(NOTES_SOURCES)
    add_library(notes STATIC ${NOTES_SOURCES})
    message(STATUS "Added optional library 'notes' from: ${NOTES_SOURCES}")
else()
    message(STATUS "No notes.cpp found; skipping 'notes' library")
endif()

# -------------------------------
# Helper: sanitize target name (replace illegal chars, avoid leading digits)
# -------------------------------
function(sanitize_target_name in out)
    string(REGEX REPLACE "[^A-Za-z0-9_]" "_" _tmp "${in}")
    string(REGEX MATCH "^[0-9]" _starts "${_tmp}")
    if(_starts)
        set(${out} "exe_${_tmp}" PARENT_SCOPE)
    else()
        set(${out} "${_tmp}" PARENT_SCOPE)
    endif()
endfunction()

# -------------------------------
# Discover .cpp sources under Module2 and Module3 only
# -------------------------------
file(GLOB_RECURSE MODULE2_SOURCES CONFIGURE_DEPENDS
    "${SRC_ROOT}/Module2/*.cpp"
)
file(GLOB_RECURSE MODULE3_SOURCES CONFIGURE_DEPENDS
    "${SRC_ROOT}/Module3/*.cpp"
)

message(STATUS "Module2 sources: ${MODULE2_SOURCES}")
message(STATUS "Module3 sources: ${MODULE3_SOURCES}")

# -------------------------------
# Create one executable per .cpp with sanitized (and unique) target names
# -------------------------------
foreach(src IN LISTS MODULE2_SOURCES MODULE3_SOURCES)
    get_filename_component(basename "${src}" NAME_WE)
    if(basename STREQUAL "notes")
        continue()
    endif()

    sanitize_target_name("${basename}" target_name)

    # disambiguate duplicates by using relative path if necessary
    if(TARGET "${target_name}")
        file(RELATIVE_PATH relpath "${SRC_ROOT}" "${src}")
        string(REGEX REPLACE "[/\\\\]" "_" relpath_s "${relpath}")
        sanitize_target_name("${relpath_s}" target_name)
    endif()

    add_executable("${target_name}" "${src}")

    if(TARGET notes)
        target_link_libraries("${target_name}" PRIVATE notes)
    endif()
endforeach()

message(STATUS "Total Module2/Module3 sources considered: ${MODULE2_SOURCES} ${MODULE3_SOURCES}")
