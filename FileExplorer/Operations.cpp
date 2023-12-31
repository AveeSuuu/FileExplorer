#include "Operations.hpp"

void Operations::setCurrent(Folder* folder) {
  this->current = folder;
}

Folder* Operations::getCurrent() {
  return this->current;
}

void Operations::listElements() {

}

void Operations::createFolder(const std::string& folderName) {
  if (current->getAccessToContainer()->count(folderName)) {
    std::cerr << "[!] Folder '" << folderName << "' already exists!\n";
    return;
  }

  current
    ->getAccessToContainer()
    ->insert(
      std::make_pair<const std::string&, Folder*>(
        folderName,
        new Folder(folderName)
        )
    );
}

void Operations::removeFolder(const std::string& folderName) {

}

void Operations::enterFolder(const std::string& folderName) {
  if (!current->getAccessToContainer()->count(folderName)) {
    std::cerr << "[!] Folder '" << folderName << "' doesn't exist!\n";
    return;
  }

  current = current->getAccessToContainer()->at(folderName);
}

void Operations::leaveFolder() {

}

void Operations::clearTerminal() {

}
void Operations::quitExplorer() {

}
