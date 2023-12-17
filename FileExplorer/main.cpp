#include <iostream>
#include <string>
#include <unordered_map>

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

  void selectOperation(const std::string& userInput) {
    switch (operationCommands[userInput]) {
    case Operation::listElements:
      break;
    case Operation::newFile:
      break;
    case Operation::openFile:
      break;
    case Operation::deleteFile:
      break;
    case Operation::newFolder:
      break;
    case Operation::openFolder:
      break;
    case Operation::closeFolder:
      break;
    case Operation::deleteFolder:
      break;
    case Operation::quitTerminal:
      break;
    default:
      throw std::exception("No command found");
    }
  }
};
//Would be nice if current path was visible just like in normal terminal

int main() {



  return 0;
}