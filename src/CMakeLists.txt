add_subdirectory(backend)
add_subdirectory(frontend)

add_executable(NaviDir main.cpp)

target_link_libraries(NaviDir PRIVATE backend)
target_link_libraries(NaviDir PRIVATE frontend)

set_target_properties(NaviDir PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
