#pragma once
#include <iostream>
#include "PathHandler.hpp"
#include "Folder.hpp"

class Operations {
public:
  void setCurrent(Folder* folder);
  Folder* getCurrent();
  void listElements();
  void treeElements(Folder* folder, int level);
  void createFolder(const std::string& folderName);
  void removeFolder(const std::string& folderName);
  void enterFolder(const std::string& folderName);
  void leaveFolder(PathHandler* path);
  void clearTerminal();
  void quitExplorer();
private:
  Folder* current = nullptr;
  bool checkIfFolderExists(const std::string& folderName);
};

