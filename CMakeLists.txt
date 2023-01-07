cmake_minimum_required(VERSION 3.21)

project(GuitarTrainer)

include_directories(/usr/include/mkl/)

enable_testing()
add_subdirectory(src)
add_subdirectory(test)
