#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include "file.hpp" 

/*TODO
* before anything else:
* > PLAN MORE STUFF U DUMB FUCK
*
* Classes:
* > File, Folder, Operations, (for now to test things)
*
* must-have functions:
* > smth to separate command and parameters/names
* > function that makes use of separated strings above
*
* Tests:
* > add and remove functions (opening for later)
*/

enum class Operation {
  listElements,
  newFile,      newFolder,
  openFile,     openFolder,
  deleteFile,   deleteFolder,
                closeFolder,
  quitTerminal, clearTerminal,
};

typedef std::unordered_map<std::string, Operation> operationsMap;

class OperationClass {
public:
  operationsMap operationCommands;

  OperationClass() {
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

  bool getUserInput() {
    std::string input;
    std::cin.clear();
    std::cout << "[@]root/> " << std::flush;
    std::getline(std::cin, input);
    std::string fileName = getFileNameFromInput(input);
    return selectOperation(input, fileName);
  }

  std::string getFileNameFromInput(std::string& input) {
    std::string fileName = input;

    std::string::const_iterator spaceItr = getCharIterator(fileName, ' ');
    if (spaceItr != fileName.end()) {
      fileName.erase(fileName.begin(), ++spaceItr);
      input.erase(getCharIterator(input, ' '), input.end());
    }

    return fileName;
  }

  std::string::const_iterator getCharIterator(const std::string& s, char c) {
    for (std::string::const_iterator itr = s.begin(); itr != s.end(); ++itr) {
      if (*itr == c) return itr;
    }
    return s.end();
  }

  bool selectOperation(const std::string& userInput, const std::string& fileName) {
    if (!operationCommands.count(userInput)) {
      std::cout << "command not found!\n";
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
};
//Would be nice if current path was visible just like in normal terminal

int main() {

  OperationClass operations;
  File* root = new Folder("root");
  File* current = root;

  while (operations.getUserInput()) {

  }

  delete root;

  return 0;
}