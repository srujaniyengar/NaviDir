find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(NaviDirTests test_main.cpp test_UI.cpp test_FileManager.cpp)

target_link_libraries(NaviDirTests PRIVATE GTest::GTest GTest::Main frontend backend)

add_test(NAME NaviDirTests COMMAND NaviDirTests)
