#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <filesystem>
#include <variant>
#include <vector>
#include <string>

class FileManager {
private:
  std::filesystem::path currentPath;
  std::vector<std::filesystem::directory_entry> children;

  std::filesystem::path selectedPath;
  int selected;

  std::variant<std::vector<std::filesystem::directory_entry>, std::string> selectedData;

  void updateSelectedData();

public:
  FileManager(); //constructor, initializes at current directory
  FileManager(std::filesystem::path); //constructor, initializes at given directory

  std::filesystem::path getCurrentPath(); //gets the current directory program is in

  std::vector<std::filesystem::directory_entry> getChildren(); //gets children of current directory
  
  std::filesystem::directory_entry getSelectedItem(); //gets selected item

  std::filesystem::path getSelectedPath(); //gets the selected path by user
  bool selectPath(std::filesystem::path, bool); //selelcts the given file
  bool selectPath(); //updates the selected file (selectedPath) based on index (selected)
  bool selectPath(int); //updates the index (selected) and updates the selected file (selectedPath)
  bool incrementSelected(bool); //selects next file in the current directory
  bool decrementSelected(bool); //selects previous file in the current directory
  bool selectParentDir(); //selects the parent directory
  
  std::variant<std::vector<std::filesystem::directory_entry>, std::string> getSelectedData();

  std::filesystem::path switchPath(std::filesystem::path); //switchs to given directory
  std::filesystem::path switchPath(); //switches to selected directory (selectedPath)
  std::filesystem::path switchToParent(); //switches to parent directory

  ~FileManager(); //destructor, does nothing as of now
};

#endif
