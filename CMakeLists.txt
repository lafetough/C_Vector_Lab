cmake_minimum_required(VERSION 3.25)
project(C_Vector_Lab C)

set(CMAKE_C_STANDARD 11)

add_subdirectory("libs/data_structures/vector" VectorLib)

add_executable(C_Vector_Lab main.c)
target_link_libraries(C_Vector_Lab data_structures)

