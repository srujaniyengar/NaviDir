add_subdirectory(frontend)
add_subdirectory(backend)

add_executable(NaviDir main.cpp)

target_link_libraries(NaviDir PRIVATE frontend backend ftxui)
