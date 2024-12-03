add_library(Frontend UI.cpp)

target_include_directories(Frontend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Frontend PRIVATE ftxui::dom ftxui::screen ftxui::component)
