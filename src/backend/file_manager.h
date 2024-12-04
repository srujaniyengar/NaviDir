#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <filesystem>
#include <variant>
#include <vector>
#include <string>

using namespace std::filesystem;
using namespace std;

class FileManager {
private:
  path currentPath;
  vector<directory_entry> children;

  path selectedPath;
  int selected;

  variant<vector<directory_entry>, string> selectedData;

  void updateChildren(vector<directory_entry>*, path path);

  void updateSelectedData();

public:
  FileManager(); //constructor, initializes at current directory
  FileManager(path); //constructor, initializes at given directory

  path getCurrentPath(); //gets the current directory program is in

  vector<directory_entry> getChildren(); //gets children of current directory
  
  directory_entry getSelectedItem(); //gets selected item

  path getSelectedPath(); //gets the selected path by user
  bool selectPath(path, bool); //selelcts the given file
  bool selectPath(); //updates the selected file (selectedPath) based on index (selected)
  bool selectPath(int); //updates the index (selected) and updates the selected file (selectedPath)
  bool incrementSelected(bool); //selects next file in the current directory
  bool decrementSelected(bool); //selects previous file in the current directory
  bool selectParentDir(); //selects the parent directory
  
  variant<vector<directory_entry>, string> getSelectedData();

  path switchPath(path); //switchs to given directory
  path switchPath(); //switches to selected directory (selectedPath)
  path switchToParent(); //switches to parent directory

  ~FileManager(); //destructor, does nothing as of now
};

#endif
