#pragma once
#include "Folder.hpp"
#include "iostream"

class Operations{
  Folder* current = nullptr;
public:
  void setCurrent(Folder* folder);
  Folder* getCurrent();
  void listElements();
  void createFolder(const std::string& folderName);
  void removeFolder(const std::string& folderName);
  void enterFolder(const std::string& folderName);
  void leaveFolder();
  void clearTerminal();
  void quitExplorer();
};

