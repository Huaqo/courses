cmake_minimum_required(VERSION 3.29)
project(uebung_0_stack C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(uebung_0_stack
    stack.c
    stack.h)
