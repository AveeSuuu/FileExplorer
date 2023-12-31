#pragma once
#include <string>
#include <unordered_map>

class File {
protected:
  std::string fileName_;
public:
  File(const std::string& fileName) {
    fileName_ = fileName;
  }
};

class Folder : public File {
private:
  std::string fileName_;
  std::unordered_map<std::string, File*> files_;
public:
  Folder(const std::string& fileName): File(fileName) {
    this->fileName_ = fileName;
  };
};
