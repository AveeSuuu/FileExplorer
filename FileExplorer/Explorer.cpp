#include "Explorer.hpp"

Explorer::Explorer() {
  root_ = std::make_shared<Folder>("home");
  path_ = std::make_shared<PathHandler>();
  path_->addToPath(root_);
  operations_ = std::make_shared<OperationsHandler>(path_);
}

void Explorer::run() {
  while (operations_->selectOperation());
}