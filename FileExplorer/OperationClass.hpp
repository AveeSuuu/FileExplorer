#pragma once
#include <unordered_map>
#include <memory>
#include "file.hpp" 
#include <iostream>

enum class Operation {
  listElements,
  newFile, newFolder,
  openFile, openFolder,
  deleteFile, deleteFolder,
  closeFolder,
  quitTerminal, clearTerminal,
};

typedef std::unordered_map<std::string, Operation> operationsMap;

class OperationClass {
public:
  OperationClass();
  bool getUserInput();
private:
  operationsMap operationCommands;
  std::string getFileNameFromInput(std::string& input);
  std::string::const_iterator getCharIterator(const std::string& s, char c);
  bool selectOperation(const std::string& userInput, const std::string& fileName);
};

