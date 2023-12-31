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
  std::cout << path_->getPath() << ":: " << std::flush;
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
  switch (operationCommands[userInput]) {
  case OperationType::listElements:
    std::cout << "printing all elements\n";
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
    std::cout << "creating folder " << fileName << std::endl;
    return true;
  case OperationType::openFolder:
    std::cout << "opening folder " << fileName << std::endl;
    return true;
  case OperationType::closeFolder:
    std::cout << "closing folder " << fileName << std::endl;
    return true;
  case OperationType::deleteFolder:
    std::cout << "deleting folder " << fileName << std::endl;
    return true;
  case OperationType::clearTerminal:
    system("cls");
    return true;
  case OperationType::quitTerminal:
    std::cout << "quitting...\n";
    return false;
  default:
    return false;
  }
}