#include "file_manager.h"
#include <cstdio>
#include <filesystem>
#include <vector>

using namespace std::filesystem;
using namespace std;

FileManager::FileManager() {
  FileManager(path("."));
}

FileManager::FileManager(path path) {
  switchPath(path);
}

path FileManager::getCurrentPath() {
  return currentPath;
}

path FileManager::getSelectedPath() {
  return selectedPath;
}

bool FileManager::selectPath(path path, bool skipCheck=false) {
  if (! skipCheck) {
    for (int i = 0; i < children.size(); i++) {
      if (children[i] == path) {
        return selectPath(i);
      }
    }
  }
  if (path == selectedPath || path.empty()) {
    return false;
  }
  selectedPath = path;
  selected = -1;
  return true;
}

bool FileManager::selectPath() {
  if (selected < 0 || selected >= children.size()) {
    return false;
  }
  selectedPath = children[selected].path();
  return true;
}

bool FileManager::selectPath(int index) {
  if (selected == -1) {
    selected = 0;
  }
  int oldIndex = selected;
  selected = index;
  if (! selectPath()) {
    selected = oldIndex;
    return false;
  }
  return true;
}

bool FileManager::incrementSelected(bool cycle=true) {
  if (selected == -1) {
    selected = 0;
  }
  if (selected + 1 >= children.size()) {
    return selectPath(0);
  }
  return selectPath(selected + 1);
}

bool FileManager::decrementSelected(bool cycle=true) {
  if (selected == -1) {
    selected = 0;
  }
  if (selected == 0) {
    if (children.size() == 0) {
      return false;
    }
    return selectPath(children.size() - 1);
  }
  return selectPath(selected - 1);
}

bool FileManager::selectParentDir() {
  if (selected == -1) {
    return selectedPath == currentPath.parent_path();
  }
  return selectPath(currentPath.parent_path(), true);
}

path FileManager::switchPath(path path) {
  if (selectPath(path, true)) {
    return switchPath();
  }
  return currentPath;
}

path FileManager::switchPath() {
  currentPath = selectedPath;
  children.clear();
  int selectedIndex = -1;
  for (const auto& entry : directory_iterator(currentPath)) {
    children.push_back(entry);
    if (entry.path() == selectedPath) {
      selectedIndex = children.size() - 1;
    }
  }

  selectedPath = NULL;
  selected = selectedIndex == -1 ? 0 : selectedIndex;
  selectPath();
  return currentPath;
}

path FileManager::switchToParent() {
  if (selectParentDir()) {
    return switchPath();
  }
  return currentPath;
}
