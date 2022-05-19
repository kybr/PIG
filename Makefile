OBJS = foo.o Window.o
BIN = foo.bin
SDKSTAGE = sysroot

LDFLAGS += -L$(SDKSTAGE)/usr/lib/arm-linux-gnueabihf
#LDFLAGS += -L$(SDKSTAGE)/lib/arm-linux-gnueabihf
LDFLAGS += -lrevision
LDFLAGS += -llo
LDFLAGS += -ldl # -lc
LDFLAGS += -Xlinker "--sysroot=sysroot"
LDFLAGS += -Wl,-rpath=sysroot/opt/vc/lib
#LDFLAGS += $(SDKSTAGE)/usr/lib/arm-linux-gnueabihf/libc_nonshared.a 
#LDFLAGS += $(SDKSTAGE)/usr/lib/arm-linux-gnueabihf/liblo.a

CC=
CC += arm-unknown-linux-gnueabihf/bin/arm-unknown-linux-gnueabihf-gcc
CC += -mfpu=vfp -march=armv6zk -mtune=arm1176jzf-s
CXX=
CXX += arm-unknown-linux-gnueabihf/bin/arm-unknown-linux-gnueabihf-g++
CXX += -std=c++14
CXX += -mfpu=vfp -march=armv6zk -mtune=arm1176jzf-s

AR=
AR += arm-unknown-linux-gnueabihf/bin/arm-unknown-linux-gnueabihf-ar

LD=
LD += arm-unknown-linux-gnueabihf/bin/arm-unknown-linux-gnueabihf-ld

include Makefile.include

# warning:  libbcm_host.so, needed by sysroot/opt/vc/lib/libbrcmEGL.so
# warning: libvchiq_arm.so, needed by sysroot/opt/vc/lib/libbrcmGLESv2.so
# warning:      libvcos.so, needed by sysroot/opt/vc/lib/libbrcmGLESv2.so
#
# not found (try using -rpath or -rpath-link)
#
# all in ... /opt/vc/lib/
