#pragma once

#include "OperationsHandler.hpp"
#include "PathHandler.hpp"
#include "Folder.hpp"

class Explorer{
public:
  Explorer() {
    
  }

  void run();
private:
  Folder* homeFolder = nullptr;
  PathHandler* path = nullptr;
  OperationsHandler* operations = nullptr;
};

