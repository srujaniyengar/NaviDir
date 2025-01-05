cmake_minimum_required(VERSION 3.11)
project(frontend)

include(FetchContent)
FetchContent_Declare(ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
    GIT_TAG v3.0.0
)
FetchContent_MakeAvailable(ftxui)

add_library(frontend STATIC
    UI.cpp
)

target_link_libraries(frontend PRIVATE
    ftxui::screen
    ftxui::dom
    ftxui::component
)

target_include_directories(frontend PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(frontend_test
    localTest.cpp
)

target_link_libraries(frontend_test PRIVATE
    frontend
    ftxui::screen
    ftxui::dom
    ftxui::component
)
