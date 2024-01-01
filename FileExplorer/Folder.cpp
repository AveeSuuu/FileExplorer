#include "Folder.hpp"

Folder::Folder(const std::string& fileName) {
  this->fileName_ = fileName;
};

std::string Folder::getFolderName() const {
  return this->fileName_;
}

std::unordered_map<std::string, std::shared_ptr<Folder>>* Folder::getAccessToContainer() {
  return &files_;
}

