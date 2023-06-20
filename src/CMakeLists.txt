cmake_minimum_required(VERSION 3.15)

project(GuitarTrainer)

set(CMAKE_CXX_STANDARD 20)

set(BINARY ${CMAKE_PROJECT_NAME})
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)
find_package(Protobuf REQUIRED)
add_subdirectory(proto)


add_library(${BINARY}_lib STATIC ${SOURCES})
target_compile_options(${BINARY}_lib PUBLIC $<TARGET_PROPERTY:MKL::MKL,INTERFACE_COMPILE_OPTIONS>)
target_include_directories(${BINARY}_lib PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/src/proto)
target_link_libraries(${BINARY}_lib $<LINK_ONLY:MKL::MKL> protobuf::libprotobuf track)
target_include_directories(${BINARY}_lib PUBLIC . $<TARGET_PROPERTY:MKL::MKL,INTERFACE_INCLUDE_DIRECTORIES>)

add_executable(${BINARY} main.cpp)
target_link_libraries(${BINARY} ${BINARY}_lib)
