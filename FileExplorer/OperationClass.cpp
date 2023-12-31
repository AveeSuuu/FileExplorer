#include "OperationClass.hpp"

OperationClass::OperationClass() {
  operationCommands[(std::string)"ls"] = Operation::listElements;
  operationCommands[(std::string)"file+"] = Operation::newFile;
  operationCommands[(std::string)"file>"] = Operation::openFile;
  operationCommands[(std::string)"file-"] = Operation::deleteFile;
  operationCommands[(std::string)"folder+"] = Operation::newFolder;
  operationCommands[(std::string)"folder>"] = Operation::openFolder;
  operationCommands[(std::string)"folder<"] = Operation::closeFolder;
  operationCommands[(std::string)"folder-"] = Operation::deleteFolder;
  operationCommands[(std::string)"clear"] = Operation::clearTerminal;
  operationCommands[(std::string)"quit"] = Operation::quitTerminal;
}

bool OperationClass::getUserInput() {
  std::string input;
  std::cin.clear();
  std::cout << "[@]root/> " << std::flush;
  std::getline(std::cin, input);
  std::string fileName = getFileNameFromInput(input);
  return selectOperation(input, fileName);
}

std::string OperationClass::getFileNameFromInput(std::string& input) {
  std::string fileName = input;

  std::string::const_iterator spaceItr = getCharIterator(fileName, ' ');
  if (spaceItr != fileName.end()) {
    fileName.erase(fileName.begin(), ++spaceItr);
    input.erase(getCharIterator(input, ' '), input.end());
  }

  return fileName;
}

std::string::const_iterator OperationClass::getCharIterator(const std::string& s, char c) {
  for (std::string::const_iterator itr = s.begin(); itr != s.end(); ++itr) {
    if (*itr == c) return itr;
  }
  return s.end();
}

bool OperationClass::selectOperation(const std::string& userInput, const std::string& fileName) {
  if (!operationCommands.count(userInput)) {
    std::cerr << "command not found!\n";
    return true;
  }
  switch (operationCommands[userInput]) {
  case Operation::listElements:
    std::cout << "printing all elements\n";
    return true;
  case Operation::newFile:
    std::cout << "creating file " << fileName << std::endl;
    return true;
  case Operation::openFile:
    std::cout << "opening file " << fileName << std::endl;
    return true;
  case Operation::deleteFile:
    std::cout << "deleting file " << fileName << std::endl;
    return true;
  case Operation::newFolder:
    std::cout << "creating folder " << fileName << std::endl;
    return true;
  case Operation::openFolder:
    std::cout << "opening folder " << fileName << std::endl;
    return true;
  case Operation::closeFolder:
    std::cout << "closing folder " << fileName << std::endl;
    return true;
  case Operation::deleteFolder:
    std::cout << "deleting folder " << fileName << std::endl;
    return true;
  case Operation::clearTerminal:
    system("cls");
    return true;
  case Operation::quitTerminal:
    std::cout << "quitting...\n";
    return false;
  default:
    return false;
  }
}