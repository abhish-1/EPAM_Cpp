cmake_minimum_required(VERSION 3.16)

project(EPAM_CXX LANGUAGES CXX)

# -------------------------------
# C++ Standard
# -------------------------------
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -------------------------------
# Shared helper library (NO main)
# -------------------------------
add_library(notes STATIC
    encapsulationAbstrictionInheritance/notes.cpp
)

# -------------------------------
# Encapsulation / Abstraction / Inheritance
# -------------------------------
add_executable(task3EAI
    "encapsulationAbstrictionInheritance/task3EAI.cpp"
    "encapsulationAbstrictionInheritance/main(task3).cpp"
)
target_link_libraries(task3EAI PRIVATE notes)

# -------------------------------
# OOP Tasks
# -------------------------------
add_executable(task3
    OOPTasks/task3.cpp
)
target_link_libraries(task3 PRIVATE notes)

add_executable(task4
    OOPTasks/TaskRepo/task4.cpp
)
target_link_libraries(task4 PRIVATE notes)

add_executable(task5
    OOPTasks/TaskRepo/task5.cpp
)
target_link_libraries(task5 PRIVATE notes)

add_executable(task5ii
    OOPTasks/TaskRepo/task5ii.cpp
)
target_link_libraries(task5ii PRIVATE notes)

add_executable(task7
    OOPTasks/TaskRepo/task7.cpp
)
target_link_libraries(task7 PRIVATE notes)

add_executable(task8
    OOPTasks/task8.cpp
)
target_link_libraries(task8 PRIVATE notes)

add_executable(task9
    OOPTasks/TaskRepo/task9.cpp
)
target_link_libraries(task9 PRIVATE notes)

# -------------------------------
# Memory Management Tasks
# -------------------------------
add_executable(task2MM
    Memory_Mgmt/task2MM.cpp
)
target_link_libraries(task2MM PRIVATE notes)

add_executable(task3MM
    Memory_Mgmt/task3MM.cpp
)
target_link_libraries(task3MM PRIVATE notes)

add_executable(task4MM
    Memory_Mgmt/task4MM.cpp
)
target_link_libraries(task4MM PRIVATE notes)

add_executable(task5MM
    Memory_Mgmt/task5MM.cpp
)
target_link_libraries(task5MM PRIVATE notes)