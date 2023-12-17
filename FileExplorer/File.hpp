#pragma once
#include <string>
#include <unordered_map>

class File {
  File() = delete;
protected:
  std::string fileName_;
};

class Folder : public File {
private:
  std::unordered_map<std::string, File*> files;
public:

};