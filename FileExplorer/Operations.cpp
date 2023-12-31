#include "Operations.hpp"

void Operations::setCurrent(Folder* folder) {
  this->current = folder;
}

Folder* Operations::getCurrent() {
  return this->current;
}

void Operations::listElements() {
  auto container = current->getAccessToContainer();
  for (auto itr = container->begin(); itr != container->end(); ++itr) {
    std::cout << "   > " << itr->second->getFolderName() << "\n";
  }
}

void Operations::createFolder(const std::string& folderName) {
  if (checkIfFolderExists(folderName)) {
    std::cerr << "[!] Folder '" << folderName << "' already exists!\n";
    return;
  }

  if (folderName.length() == 0 || folderName == "folder+") {
    std::cerr << "[!] Incorrect folder name!\n";
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
  if (!checkIfFolderExists(folderName)) {
    std::cerr << "[!] Folder '" << folderName << "' doesn't exist!\n";
    return;
  }
  delete current->getAccessToContainer()->at(folderName);
  current->getAccessToContainer()->erase(folderName);
}

void Operations::enterFolder(const std::string& folderName) {
  if (!checkIfFolderExists(folderName)) {
    std::cerr << "[!] Folder '" << folderName << "' doesn't exist!\n";
    return;
  }

  current = current->getAccessToContainer()->at(folderName);
}

void Operations::leaveFolder(PathHandler* path) {

  if (current->getFolderName() == "home") {
    std::cerr << "[!] Can't leave root folder!\n";
    return;
  }

  path->removeFromPath();
}

void Operations::clearTerminal() {
  system("cls");
}

void Operations::quitExplorer() {
  std::cout << "[!] Quitting explorer...\n";
}

bool Operations::checkIfFolderExists(const std::string& folderName) {
  return current->getAccessToContainer()->count(folderName);
}