#pragma once
#include <iostream>
#include "PathHandler.hpp"
#include "Folder.hpp"

class Operations {
public:
  void setCurrent(std::shared_ptr<Folder> folder);
  std::shared_ptr<Folder> getCurrent();
  void help();
  void listElements();
  void treeElements(std::shared_ptr<Folder> folder, int level);
  void createFolder(const std::string& folderName);
  void removeFolder(const std::string& folderName);
  void enterFolder(const std::string& folderName);
  void leaveFolder(std::shared_ptr<PathHandler> path);
  void clearTerminal();
  void quitExplorer();
private:
  std::shared_ptr<Folder> current = nullptr;
  bool checkIfFolderExists(const std::string& folderName);
};

