set(SRC_FILES main.cpp)

add_subdirectory(backend)
add_subdirectory(frontend)

include_directories(backend frontend)

add_executable(NaviDir ${SRC_FILES})

target_link_libraries(NaviDir PRIVATE Backend Frontend)
