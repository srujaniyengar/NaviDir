add_library(backend STATIC
    file_manager.cpp
    file_manager.h
)

target_include_directories(backend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

