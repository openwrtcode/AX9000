This project is a linux operating system targeting embedded devices,
comes from openwrt project and qualcomm's open source software.This project supports for xiaomi AX9000.

## Requirements

To build your own firmware you need a Linux system.
you need the following tools to compile:

zip unzip build-essential cmake subversion libncurses5-dev zlib1g-dev gawk gcc-multilib flex git-core gettext libssl-dev autoconf zlib1g:i386 libelf1:i386 libstdc++6:i386 libxml-parser-perl lzma libcurl4-openssl-dev libjson0 libjson0-dev libboost-all-dev libevent-dev uuid-dev libsqlite3-dev libjpeg-dev libpng-dev libudev-dev libboost-dev libboost-test-dev libboost-program-options-dev automake libtool bison pkg-config g++ libssl-dev lib32z1 lib32ncurses5 libbz2-1.0:i386

## Build firmware
```
$ cd AX9000
$ cp .config.AX9000 .config
$ make defconfig
$ make
```

This will download all sources, build the cross-compile toolchain and then 
cross-compile the Linux kernel & all chosen applications for your target system.

## Rom

The compiled firmware opensource-firmware-1.0.4.bin in AX9000/rom
