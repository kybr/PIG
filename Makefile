.SUFFIXES:

_: foo.bin

foo.o: foo.cpp
	arm-unknown-linux-gnueabihf/bin/arm-unknown-linux-gnueabihf-g++ -std=c++14 -mfpu=vfp -march=armv6zk -mtune=arm1176jzf-s -DSTANDALONE -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS -DTARGET_POSIX -D_LINUX -fPIC -DPIC -D_REENTRANT -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -U_FORTIFY_SOURCE -Wall -g -DHAVE_LIBOPENMAX=2 -DOMX -DOMX_SKIP64BIT -ftree-vectorize -pipe -DUSE_EXTERNAL_OMX -DHAVE_LIBBCM_HOST -DUSE_EXTERNAL_LIBBCM_HOST -DUSE_VCHIQ_ARM -Wno-psabi  -Isysroot/opt/vc/include/ -Isysroot/opt/vc/include/interface/vcos/pthreads -Isysroot/opt/vc/include/interface/vmcs_host/linux -I./ -Isysroot/opt/vc/src/hello_pi/libs/ilclient -Isysroot/opt/vc/src/hello_pi/libs/vgfont -Isysroot/opt/vc/src/hello_pi/libs/revision -Isysroot/usr/include -g -c foo.cpp -o foo.o -Wno-deprecated-declarations

Window.o: Window.hpp Window.cpp
	arm-unknown-linux-gnueabihf/bin/arm-unknown-linux-gnueabihf-g++ -std=c++14 -mfpu=vfp -march=armv6zk -mtune=arm1176jzf-s -DSTANDALONE -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS -DTARGET_POSIX -D_LINUX -fPIC -DPIC -D_REENTRANT -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -U_FORTIFY_SOURCE -Wall -g -DHAVE_LIBOPENMAX=2 -DOMX -DOMX_SKIP64BIT -ftree-vectorize -pipe -DUSE_EXTERNAL_OMX -DHAVE_LIBBCM_HOST -DUSE_EXTERNAL_LIBBCM_HOST -DUSE_VCHIQ_ARM -Wno-psabi  -Isysroot/opt/vc/include/ -Isysroot/opt/vc/include/interface/vcos/pthreads -Isysroot/opt/vc/include/interface/vmcs_host/linux -I./ -Isysroot/opt/vc/src/hello_pi/libs/ilclient -Isysroot/opt/vc/src/hello_pi/libs/vgfont -Isysroot/opt/vc/src/hello_pi/libs/revision -Isysroot/usr/include -g -c Window.cpp -o Window.o -Wno-deprecated-declarations

BCM.o: BCM.hpp BCM.cpp
	arm-unknown-linux-gnueabihf/bin/arm-unknown-linux-gnueabihf-g++ -std=c++14 -mfpu=vfp -march=armv6zk -mtune=arm1176jzf-s -DSTANDALONE -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS -DTARGET_POSIX -D_LINUX -fPIC -DPIC -D_REENTRANT -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -U_FORTIFY_SOURCE -Wall -g -DHAVE_LIBOPENMAX=2 -DOMX -DOMX_SKIP64BIT -ftree-vectorize -pipe -DUSE_EXTERNAL_OMX -DHAVE_LIBBCM_HOST -DUSE_EXTERNAL_LIBBCM_HOST -DUSE_VCHIQ_ARM -Wno-psabi  -Isysroot/opt/vc/include/ -Isysroot/opt/vc/include/interface/vcos/pthreads -Isysroot/opt/vc/include/interface/vmcs_host/linux -I./ -Isysroot/opt/vc/src/hello_pi/libs/ilclient -Isysroot/opt/vc/src/hello_pi/libs/vgfont -Isysroot/opt/vc/src/hello_pi/libs/revision -Isysroot/usr/include -g -c BCM.cpp -o BCM.o -Wno-deprecated-declarations

App.o: App.hpp App.cpp
	arm-unknown-linux-gnueabihf/bin/arm-unknown-linux-gnueabihf-g++ -std=c++14 -mfpu=vfp -march=armv6zk -mtune=arm1176jzf-s -DSTANDALONE -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS -DTARGET_POSIX -D_LINUX -fPIC -DPIC -D_REENTRANT -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -U_FORTIFY_SOURCE -Wall -g -DHAVE_LIBOPENMAX=2 -DOMX -DOMX_SKIP64BIT -ftree-vectorize -pipe -DUSE_EXTERNAL_OMX -DHAVE_LIBBCM_HOST -DUSE_EXTERNAL_LIBBCM_HOST -DUSE_VCHIQ_ARM -Wno-psabi  -Isysroot/opt/vc/include/ -Isysroot/opt/vc/include/interface/vcos/pthreads -Isysroot/opt/vc/include/interface/vmcs_host/linux -I./ -Isysroot/opt/vc/src/hello_pi/libs/ilclient -Isysroot/opt/vc/src/hello_pi/libs/vgfont -Isysroot/opt/vc/src/hello_pi/libs/revision -Isysroot/usr/include -g -c App.cpp -o App.o -Wno-deprecated-declarations

GL.o: GL.hpp GL.cpp
	arm-unknown-linux-gnueabihf/bin/arm-unknown-linux-gnueabihf-g++ -std=c++14 -mfpu=vfp -march=armv6zk -mtune=arm1176jzf-s -DSTANDALONE -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS -DTARGET_POSIX -D_LINUX -fPIC -DPIC -D_REENTRANT -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -U_FORTIFY_SOURCE -Wall -g -DHAVE_LIBOPENMAX=2 -DOMX -DOMX_SKIP64BIT -ftree-vectorize -pipe -DUSE_EXTERNAL_OMX -DHAVE_LIBBCM_HOST -DUSE_EXTERNAL_LIBBCM_HOST -DUSE_VCHIQ_ARM -Wno-psabi  -Isysroot/opt/vc/include/ -Isysroot/opt/vc/include/interface/vcos/pthreads -Isysroot/opt/vc/include/interface/vmcs_host/linux -I./ -Isysroot/opt/vc/src/hello_pi/libs/ilclient -Isysroot/opt/vc/src/hello_pi/libs/vgfont -Isysroot/opt/vc/src/hello_pi/libs/revision -Isysroot/usr/include -g -c GL.cpp -o GL.o -Wno-deprecated-declarations

foo.bin: BCM.o Window.o App.o GL.o foo.o
	arm-unknown-linux-gnueabihf/bin/arm-unknown-linux-gnueabihf-g++ -std=c++14 -mfpu=vfp -march=armv6zk -mtune=arm1176jzf-s -o foo.bin -Wl,--whole-archive foo.o Window.o BCM.o App.o GL.o -Lsysroot/usr/lib/arm-linux-gnueabihf -lrevision -llo -ldl  -Xlinker "--sysroot=sysroot" -Wl,-rpath=sysroot/opt/vc/lib -Lsysroot/opt/vc/lib/ -lbrcmGLESv2 -lbrcmEGL -lopenmaxil -lbcm_host -lvcos -lvchiq_arm -lpthread -lrt -lm -Lsysroot/opt/vc/src/hello_pi/libs/ilclient -Lsysroot/opt/vc/src/hello_pi/libs/vgfont -Lsysroot/opt/vc/src/hello_pi/libs/revision -Wl,--no-whole-archive -rdynamic

clean:
	rm -f GL.o BCM.o App.o Window.o foo.o foo.bin
