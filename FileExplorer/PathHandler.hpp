#pragma once
#include <vector>
#include <string>
#include "Folder.hpp"
class PathHandler{
public:
  void addToPath(Folder* folder);
  void removeFromPath();
  std::string getPath() const;
  Folder* getCurrentLocation();
private:
  std::vector<Folder*> path_;
};

