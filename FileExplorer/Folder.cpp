#include "Folder.hpp"

Folder::Folder(const std::string& fileName) {
  this->fileName_ = fileName;
};

bool Folder::createFolder(const std::string& fileName) {
  if (files_.count(fileName)) {
    return false;
  }

  files_[fileName] = new Folder(fileName);
  return true;
}

bool Folder::deleteFolder(const std::string& fileName) {
  if (files_.count(fileName)) {
    return false;
  }

  delete files_[fileName];
  return true;
}

Folder* Folder::getFolder(const std::string& fileName) {
  if (files_.count(fileName)) {
    return nullptr;
  }

  return files_[fileName];
}

std::string Folder::getFolderName() const {
  return this->fileName_;
}

