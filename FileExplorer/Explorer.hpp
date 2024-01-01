#pragma once

#include "OperationsHandler.hpp"
#include "PathHandler.hpp"
#include "Folder.hpp"

class Explorer{
public:
  Explorer();
  void run();
private:
  std::shared_ptr<Folder> root_ = nullptr;
  std::shared_ptr<PathHandler> path_ = nullptr;
  std::shared_ptr<OperationsHandler> operations_ = nullptr;
};

