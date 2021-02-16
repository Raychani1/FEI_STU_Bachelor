cmake_minimum_required(VERSION 3.17)
project(Project_2__Refactored_2021_ C)

set(CMAKE_C_STANDARD 11)

add_executable(Project_2__Refactored_2021_ main.c monster_hunt.c monster_hunt.h arena_visualization.c arena_visualization.h characters.c characters.h)
target_link_libraries(Project_2__Refactored_2021_ m)