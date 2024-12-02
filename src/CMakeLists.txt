add_executable(NaviDir main.cpp)

set_target_properties(NaviDir PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

target_link_libraries(NaviDir PRIVATE backend)

