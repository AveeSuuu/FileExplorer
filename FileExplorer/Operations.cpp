#include "Operations.hpp"

void Operations::setCurrent(std::shared_ptr<Folder> folder) {
  this->current = folder;
}

std::shared_ptr<Folder> Operations::getCurrent() {
  return this->current;
}

void Operations::help() {
  std::cout
    << "= = = = = = = = = = Commands help = = = = = = = = = =\n"
    << "help\t\t|| shows commands info \n"
    << "ls\t\t|| list all files in current location \n"
    << "tree\t\t|| show all files in tree structure \n"
    << "folder+ {name}\t|| create new folder \n"
    << "folder- {name}\t|| delete folder \n"
    << "folder> {name}\t|| enter folder \n"
    << "folder<\t\t|| quit current folder \n"
    << "clear\t\t|| clear terminal \n"
    << "quit\t\t|| quit terminal \n"
    << "= = = = = = = = = = = = = = = = = = = = = = = = = = =\n";
}

void Operations::listElements() {
  auto container = current->getAccessToContainer();
  for (auto itr = container->begin(); itr != container->end(); ++itr) {
    std::cout << "   > " << itr->second->getFolderName() << "\n";
  }
}

void Operations::treeElements(std::shared_ptr<Folder> folder, int level) {

  auto currentContainer = folder->getAccessToContainer();

  std::string tab;

  for (int i = 0; i < level; i++) {
    tab += "  ";
  }

  for (auto itr = currentContainer->begin(); itr != currentContainer->end(); ++itr) {
    if (itr->second->getAccessToContainer()->size() > 1) {
      std::cout << tab << " v " << itr->second->getFolderName() << "\n";
    }
    else {
      std::cout << tab << " > " << itr->second->getFolderName() << "\n";
    }

    treeElements(itr->second, level + 1);
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
  current->getAccessToContainer()->erase(folderName);
}

void Operations::enterFolder(const std::string& folderName) {
  if (!checkIfFolderExists(folderName)) {
    std::cerr << "[!] Folder '" << folderName << "' doesn't exist!\n";
    return;
  }

  current = current->getAccessToContainer()->at(folderName);
}

void Operations::leaveFolder(std::shared_ptr<PathHandler> path) {

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