This project is a linux operating system targeting embedded devices,
comes from openwrt project and qualcomm's open source software.

## Requirements

To build your own firmware you need a Linux system.
you need the following tools to compile:

gcc binutils bzip2 flex python3 perl 
make find grep diff unzip gawk getopt
subversion libz-dev libc-dev rsync

## Build firmware
```
$ cd AX9000
$ cp .config.AX9000 .config
$ make defconfig
$ make -j1 V=s
```

This will download all sources, build the cross-compile toolchain and then 
cross-compile the Linux kernel & all chosen applications for your target system.

## Rom

The compiled firmware opensource-firmware-1.0.4.bin in the rom folder.
