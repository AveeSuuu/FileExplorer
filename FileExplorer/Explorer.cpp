#include "Explorer.hpp"

Explorer::Explorer() {
  root_ = new Folder("home");
  path_ = new PathHandler();
  path_->addToPath(root_);
  operations_ = new OperationsHandler(path_);
}

void Explorer::run() {
  while (operations_->selectOperation());
}

