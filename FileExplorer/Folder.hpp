#pragma once
#include <string>
#include <unordered_map>

class Folder{
private:
  std::string fileName_;
  std::unordered_map<std::string, Folder*> files_;
public:
  Folder(const std::string& fileName);
  bool createFolder(const std::string& fileName);
  bool deleteFolder(const std::string& fileName);
  Folder* getFolder(const std::string& fileName);
  std::string getFolderName() const;
};
