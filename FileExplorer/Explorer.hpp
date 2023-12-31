#pragma once

#include "OperationsHandler.hpp"
#include "PathHandler.hpp"
#include "Folder.hpp"

class Explorer{
public:
  Explorer();
  void run();
private:
  Folder* root_ = nullptr;
  PathHandler* path_ = nullptr;
  OperationsHandler* operations_ = nullptr;
};

