#pragma once
#include <vector>
#include <string>
#include "Folder.hpp"

class PathHandler{
public:
  void addToPath(std::shared_ptr<Folder> folder);
  void removeFromPath();
  std::string getPath() const;
  std::shared_ptr<Folder> getCurrentLocation();
private:
  std::vector<std::shared_ptr<Folder>> path_;
};

