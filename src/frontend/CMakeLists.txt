add_library(frontend STATIC
    UI.cpp
    UI.h
)

target_include_directories(frontend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

