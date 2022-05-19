#pragma once

struct ImplementationWindow;
struct Window {
  ImplementationWindow* implementation;
  Window();
  unsigned width();
  unsigned height();
  void flip();
};
