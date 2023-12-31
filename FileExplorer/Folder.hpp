#pragma once
#include <string>
#include <unordered_map>

class Folder{
public:
  Folder(const std::string& fileName);
  std::string getFolderName() const;
  std::unordered_map<std::string, Folder*>* getAccessToContainer();
private:
  std::string fileName_;
  std::unordered_map<std::string, Folder*> files_;
};
