#include <iostream>
#include <string>
#include <unordered_map>

enum class Operation{
  listElements
};

typedef std::unordered_map<std::string, Operation> operationsMap;

class OperationClass {
public:
  operationsMap operationCommands;

  OperationClass() {
    operationCommands[(std::string)"ls"] = Operation::listElements;
  }
};

int main() {
  OperationClass oc;
  std::cout << "[@]?: " << std::flush;
  std::string userInput;
  std::cin >> userInput;

  Operation operation = oc.operationCommands[userInput];

  switch (operation) {
  case Operation::listElements:
    for (int i = 0; i < 10; i++) {
      std::cout << "item " << i + 1 << std::endl;
    }
    break;
  default:
    break;
  }

  return 0;
}