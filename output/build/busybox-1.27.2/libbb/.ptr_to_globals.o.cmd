cmd_libbb/ptr_to_globals.o := /media/panpan/tools/buildroot-2018.02.8/output/host/bin/arm-linux-gnueabihf-gcc -Wp,-MD,libbb/.ptr_to_globals.o.d   -std=gnu99 -Iinclude -Ilibbb  -include include/autoconf.h -D_GNU_SOURCE -DNDEBUG -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D"BB_VER=KBUILD_STR(1.27.2)" -DBB_BT=AUTOCONF_TIMESTAMP -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64  -Os  -Wall -Wshadow -Wwrite-strings -Wundef -Wstrict-prototypes -Wunused -Wunused-parameter -Wunused-function -Wunused-value -Wmissing-prototypes -Wmissing-declarations -Wno-format-security -Wdeclaration-after-statement -Wold-style-definition -fno-builtin-strlen -finline-limit=0 -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-guess-branch-probability -funsigned-char -static-libgcc -falign-functions=1 -falign-jumps=1 -falign-labels=1 -falign-loops=1 -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-builtin-printf -Os     -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(ptr_to_globals)"  -D"KBUILD_MODNAME=KBUILD_STR(ptr_to_globals)" -c -o libbb/ptr_to_globals.o libbb/ptr_to_globals.c

deps_libbb/ptr_to_globals.o := \
  libbb/ptr_to_globals.c \
  /media/panpan/tools/buildroot-2018.02.8/output/host/arm-buildroot-linux-gnueabihf/sysroot/usr/include/stdc-predef.h \
  /media/panpan/tools/buildroot-2018.02.8/output/host/arm-buildroot-linux-gnueabihf/sysroot/usr/include/errno.h \
  /media/panpan/tools/buildroot-2018.02.8/output/host/arm-buildroot-linux-gnueabihf/sysroot/usr/include/features.h \
  /media/panpan/tools/buildroot-2018.02.8/output/host/arm-buildroot-linux-gnueabihf/sysroot/usr/include/sys/cdefs.h \
  /media/panpan/tools/buildroot-2018.02.8/output/host/arm-buildroot-linux-gnueabihf/sysroot/usr/include/bits/wordsize.h \
  /media/panpan/tools/buildroot-2018.02.8/output/host/arm-buildroot-linux-gnueabihf/sysroot/usr/include/bits/long-double.h \
  /media/panpan/tools/buildroot-2018.02.8/output/host/arm-buildroot-linux-gnueabihf/sysroot/usr/include/gnu/stubs.h \
  /media/panpan/tools/buildroot-2018.02.8/output/host/arm-buildroot-linux-gnueabihf/sysroot/usr/include/gnu/stubs-hard.h \
  /media/panpan/tools/buildroot-2018.02.8/output/host/arm-buildroot-linux-gnueabihf/sysroot/usr/include/bits/errno.h \
  /media/panpan/tools/buildroot-2018.02.8/output/host/arm-buildroot-linux-gnueabihf/sysroot/usr/include/linux/errno.h \
  /media/panpan/tools/buildroot-2018.02.8/output/host/arm-buildroot-linux-gnueabihf/sysroot/usr/include/asm/errno.h \
  /media/panpan/tools/buildroot-2018.02.8/output/host/arm-buildroot-linux-gnueabihf/sysroot/usr/include/asm-generic/errno.h \
  /media/panpan/tools/buildroot-2018.02.8/output/host/arm-buildroot-linux-gnueabihf/sysroot/usr/include/asm-generic/errno-base.h \

libbb/ptr_to_globals.o: $(deps_libbb/ptr_to_globals.o)

$(deps_libbb/ptr_to_globals.o):
