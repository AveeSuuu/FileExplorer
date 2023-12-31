#include "OperationsHandler.hpp"

OperationsHandler::OperationsHandler(PathHandler* path) {
  operationCommands[(std::string)"ls"] = OperationType::listElements;
  operationCommands[(std::string)"file+"] = OperationType::newFile;
  operationCommands[(std::string)"file>"] = OperationType::openFile;
  operationCommands[(std::string)"file-"] = OperationType::deleteFile;
  operationCommands[(std::string)"folder+"] = OperationType::newFolder;
  operationCommands[(std::string)"folder>"] = OperationType::openFolder;
  operationCommands[(std::string)"folder<"] = OperationType::closeFolder;
  operationCommands[(std::string)"folder-"] = OperationType::deleteFolder;
  operationCommands[(std::string)"clear"] = OperationType::clearTerminal;
  operationCommands[(std::string)"quit"] = OperationType::quitTerminal;

  path_ = path;
}

bool OperationsHandler::selectOperation() {
  std::string input;
  std::cin.clear();
  std::cout << path_->getPath() << "::" << std::flush;
  std::getline(std::cin, input);
  std::string fileName = getFileNameFromInput(input);
  return getOperation(input, fileName);
}

std::string OperationsHandler::getFileNameFromInput(std::string& input) {
  std::string fileName = input;

  std::string::const_iterator spaceItr = getCharIterator(fileName, ' ');
  if (spaceItr != fileName.end()) {
    fileName.erase(fileName.begin(), ++spaceItr);
    input.erase(getCharIterator(input, ' '), input.end());
  }

  return fileName;
}

std::string::const_iterator OperationsHandler::getCharIterator(const std::string& s, char c) {
  for (std::string::const_iterator itr = s.begin(); itr != s.end(); ++itr) {
    if (*itr == c) return itr;
  }
  return s.end();
}

bool OperationsHandler::getOperation(const std::string& userInput, const std::string& fileName) {
  if (!operationCommands.count(userInput)) {
    std::cerr << "command not found!\n";
    return true;
  }

  operations.setCurrent(path_->getCurrentLocation());

  switch (operationCommands[userInput]) {
  case OperationType::listElements:
    operations.listElements();
    return true;
    /*
  case OperationType::newFile:
    std::cout << "creating file " << fileName << std::endl;
    return true;
  case OperationType::openFile:
    std::cout << "opening file " << fileName << std::endl;
    return true;
  case OperationType::deleteFile:
    std::cout << "deleting file " << fileName << std::endl;
    return true;
    */
  case OperationType::newFolder:
    operations.createFolder(fileName);
    return true;
  case OperationType::openFolder:
    operations.enterFolder(fileName);
    path_->addToPath(operations.getCurrent());
    return true;
  case OperationType::closeFolder:
    operations.leaveFolder();
    return true;
  case OperationType::deleteFolder:
    operations.removeFolder(fileName);
    return true;
  case OperationType::clearTerminal:
    operations.clearTerminal();
    return true;
  case OperationType::quitTerminal:
    operations.quitExplorer();
    return false;
  default:
    return false;
  }
}