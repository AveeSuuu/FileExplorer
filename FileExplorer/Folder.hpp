#pragma once
#include <string>
#include <unordered_map>
#include <memory>

class Folder {
public:
  Folder(const std::string& fileName);
  std::string getFolderName() const;
  std::unordered_map<std::string, std::shared_ptr<Folder>>* getAccessToContainer();
private:
  std::string fileName_;
  std::unordered_map<std::string, std::shared_ptr<Folder>> files_;
};
