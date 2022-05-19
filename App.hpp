#pragma once

#include <lo/lo.h>
#include <lo/lo_cpp.h>

#include "Window.hpp"
#include "BCM.hpp"

struct Domain {
  bool done{false};
  virtual void setup() = 0;
  virtual void draw() = 0;
  void end() { done = true; }
  void run() {
    setup();
    while (!done) draw();
  }
};

struct App : Domain, BCM, Window, lo::ServerThread {
  App() : lo::ServerThread("7770") { lo::ServerThread::start(); }
};
