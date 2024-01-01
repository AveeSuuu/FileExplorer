#pragma once
#include <unordered_map>
#include <iostream>
#include "Folder.hpp" 
#include "PathHandler.hpp"
#include "Operations.hpp"

enum class OperationType {
  help,
  listElements, treeElements,
  newFile,      newFolder,
  openFile,     openFolder,
  deleteFile,   deleteFolder,
                closeFolder,
  quitTerminal, clearTerminal,
};

typedef std::unordered_map<std::string, OperationType> operationsMap;

class OperationsHandler {
public:
  OperationsHandler(std::shared_ptr<PathHandler> path);
  bool selectOperation();
private:
  std::shared_ptr<PathHandler> path_;
  Operations operations;
  operationsMap operationCommands;
  bool getOperation(const std::string& userInput, const std::string& fileName);
  std::string getFileNameFromInput(std::string& input);
  std::string::const_iterator getCharIterator(const std::string& s, char c);
};

