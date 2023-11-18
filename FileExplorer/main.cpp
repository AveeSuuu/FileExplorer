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
  listElements, 
  newFile,     newFolder, 
  openFile,    openFolder, 
  deleteFile,  deleteFolder
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
    operationCommands[(std::string)"folder-"] = Operation::deleteFolder;
  }
};

int main() {



  return 0;
}