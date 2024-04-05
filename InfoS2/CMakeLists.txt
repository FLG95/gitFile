cmake_minimum_required(VERSION 3.27)
project(InfoS2 C)

set(CMAKE_C_STANDARD 11)

add_executable(InfoS2 main.c)

target_link_libraries(InfoS2 m)