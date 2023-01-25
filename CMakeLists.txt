cmake_minimum_required(VERSION 3.15)

project(GuitarTrainer)
set(MKL_DIR $ENV{MKLROOT}/lib/cmake/mkl)
find_package(MKL CONFIG REQUIRED)

enable_testing()
add_subdirectory(src)
add_subdirectory(test)
