# Copyright (c) 2013 The Linux Foundation. All rights reserved.
#
include $(TOPDIR)/rules.mk

ARCH:=arm
BOARD:=ipq
BOARDNAME:=Qualcomm Atheros IPQ
FEATURES:=squashfs pcie usbgadget
CPU_TYPE:=cortex-a7
SUBTARGETS:=ipq806x ipq40xx ipq807x ipq807x_64 ipq60xx ipq60xx_64 ipq50xx ipq50xx_64
MAINTAINER:=John Crispin <blogic@openwrt.org>

KERNELNAME:=zImage Image dtbs

LINUX_VERSION:=4.4.60
override LINUX_SOURCE:=linux-$(LINUX_VERSION).tar.xz

include $(INCLUDE_DIR)/target.mk
DEFAULT_PACKAGES += \
	uboot-envtools kmod-leds-gpio kmod-gpio-button-hotplug kmod-button-hotplug \
	kmod-ata-core kmod-ata-ahci kmod-ata-ahci-platform kmod-usb2 kmod-usb3 \
	kmod-usb-f-qdss swconfig

$(eval $(call BuildTarget))
