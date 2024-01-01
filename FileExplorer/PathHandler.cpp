#include "PathHandler.hpp"

void PathHandler::addToPath(std::shared_ptr<Folder> folder) {
  path_.push_back(folder);
}

void PathHandler::removeFromPath() {
  path_.pop_back();
}

std::string PathHandler::getPath() const {
  std::string path;
  for (auto folder : path_) {
    path += folder->getFolderName();
    path += "\\";
  }

  return path;
}

std::shared_ptr<Folder> PathHandler::getCurrentLocation() {
  return path_.back();
}
