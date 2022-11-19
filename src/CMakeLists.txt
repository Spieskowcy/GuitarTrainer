cmake_minimum_required(VERSION 3.21)

project(GuitarTrainer)

set(CMAKE_CXX_STANDARD 20)

set(BINARY ${CMAKE_PROJECT_NAME})
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

add_library(${BINARY}_lib STATIC ${SOURCES})
target_include_directories(${BINARY}_lib PUBLIC .)
