#include <gtest/gtest.h>
#include "../src/backend/FileManager.h"

TEST(FileManagerTests, Initialization) {
    std::filesystem::path tempDir = std::filesystem::temp_directory_path() / "testDir";
    std::filesystem::create_directory(tempDir);

    FileManager fileManager(tempDir);
    EXPECT_EQ(fileManager.getCurrentPath(), tempDir);

    std::filesystem::remove_all(tempDir);
}
