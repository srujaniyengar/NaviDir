cmake_minimum_required(VERSION 3.16)

project(NaviDir VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(lib)

set_target_properties(NaviDir PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
