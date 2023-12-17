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

enum class Operation{
  listElements, quitTerminal,
  newFile,     newFolder, 
  openFile,    openFolder, 
  deleteFile,  deleteFolder,
               closeFolder
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
    operationCommands[(std::string)"quit"] = Operation::quitTerminal;
  }

  bool getUserInput() {
    std::string input;
    std::cin.clear();
    std::cout << "[@]> " << std::flush;
    std::cin >> input;
    return selectOperation(input);
  }

  bool selectOperation(const std::string& userInput) {
    if (!operationCommands.count(userInput)) {
      std::cout << "command not found!\n";
      return true;
    }
    switch (operationCommands[userInput]) {
    case Operation::listElements:
      std::cout << "printing all elements\n";
      return true;
      break;
    case Operation::newFile:
      std::cout << "creating new file\n";
      return true;
      break;
    case Operation::openFile:
      std::cout << "opening file\n";
      return true;
      break;
    case Operation::deleteFile:
      std::cout << "deleting file\n";
      return true;
      break;
    case Operation::newFolder:
      std::cout << "creating new folder\n";
      return true;
      break;
    case Operation::openFolder:
      std::cout << "opening folder\n";
      return true;
      break;
    case Operation::closeFolder:
      std::cout << "closing folder\n";
      return true;
      break;
    case Operation::deleteFolder:
      std::cout << "deleting folder\n";
      return true;
      break;
    case Operation::quitTerminal:
      std::cout << "quitting...\n";
      return false;
      break;
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