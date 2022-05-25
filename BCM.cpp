#include "bcm_host.h"  // bcm_host_init / bcm_host_deinit
#include "BCM.hpp"
BCM::BCM() { bcm_host_init(); }
BCM::~BCM() { bcm_host_deinit(); }
