#!/bin/sh
TARGET_DIR="$1"
BIN_DIR="$2"
IMG_PREFIX="$3"

version=`cat $TARGET_DIR/etc/openwrt_release|grep DISTRIB_DESCRIPTION|awk -F\' '{print $2}'`

cp $BIN_DIR/$IMG_PREFIX-ubi-root.bin $BIN_DIR/opensource-firmware-$version.bin
