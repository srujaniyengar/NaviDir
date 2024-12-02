add_subdirectory(backend)

add_executable(NaviDir main.cpp)

target_link_libraries(NaviDir PRIVATE backend)

set_target_properties(NaviDir PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
