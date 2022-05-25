#pragma once

#include <lo/lo.h>
#include <lo/lo_cpp.h>

#include "BCM.hpp"
#include "Window.hpp"

struct App : BCM, Window, lo::ServerThread {
  bool done{false};
  App();
  void end();
  void run();
  virtual void setup() = 0;
  virtual void draw() = 0;
};
