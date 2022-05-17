TARGET = 192.168.78.140
#SYSROOT = /Users/ky/cf/rpi-cross-compile/sysroot
SYSROOT = sysroot
BIN = foo
CC = arm-unknown-linux-gnueabihf/bin/arm-unknown-linux-gnueabihf-cc
#CC += --specs=nosys.specs 
CC += -mfpu=vfp -march=armv6zk -mtune=arm1176jzf-s
CC += --sysroot=$(SYSROOT)

#CC+= -pie
#CC += -shared
#CC += -flto
#CC += -ffreestanding
#CC += -nostdlib

INC =
#INC += -I $(SYSROOT)/usr/include/arm-linux-gnueabihf

LIB = 
LIB += -L $(SYSROOT)/usr/lib/arm-linux-gnueabihf
#LIB += -lrt
# LIB += -Wl,--no-whole-archive -rdynamic

_:
	$(CC) $(INC) $(LIB) foo.c -o $(BIN)
	@scp foo $(TARGET):
	@ssh $(TARGET) chmod 750 $(BIN)
	@ssh $(TARGET) ./$(BIN)
	@ssh $(TARGET) rm $(BIN)
	@rm $(BIN)

