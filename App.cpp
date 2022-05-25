#include <lo/lo.h>
#include <lo/lo_cpp.h>

//#include "BCM.hpp"
//#include "Window.hpp"
#include "App.hpp"


App::App() : lo::ServerThread("7770") {}
void App::end() { done = true; }
void App::run() {
  add_method("/quit", "", [this](lo_arg **argv, int) { end(); });
  add_method("/tv", "i", [this](lo_arg **argv, int) {
    if (argv[0]->i == 0)
      system("tvservice -o");
    else
      system("tvservice -p");
  });
  setup();
  lo::ServerThread::start();
  while (!done) draw();
}
