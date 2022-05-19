#pragma once
#include "bcm_host.h"  // bcm_host_init / bcm_host_deinit
struct BCM {
  BCM() { bcm_host_init(); }
  ~BCM() { bcm_host_deinit(); }
};
