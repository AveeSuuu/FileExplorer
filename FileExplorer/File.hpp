#pragma once
#include <string>
#include <unordered_map>

class File {
protected:
  std::string fileName_;
public:
  //File(const std::string& fileName) {
 //   fileName_ = fileName;
  //}
};

class Folder : public File {
private:
  std::unordered_map<std::string, File*> files;
public:
  Folder(const std::string& fileName) {
    this->fileName_ = fileName;
  };

  int foo() {
    return 1;
  }
};

class Document : public File {

};