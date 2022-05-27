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

  add_method("/system", "s", [this](lo_arg **argv, int) {
    printf("system(%s) exited with %d\n", &argv[0]->s, system(&argv[0]->s));
    fflush(stdout);
  });

  add_method("/say", "s", [this](lo_arg **argv, int) {
    printf("%s", &argv[0]->s);
  });
  add_method("/newline", "", [this](lo_arg **argv, int) {
    printf("\n");
  });
  add_method("/flush", "", [this](lo_arg **argv, int) {
    fflush(stdout);
  });

  setup();
  lo::ServerThread::start();
  while (!done) draw();
}
