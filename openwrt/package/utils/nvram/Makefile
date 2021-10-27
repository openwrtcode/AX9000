# copyright            : (C) by 2021 Lin kai 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 as         
# published by the Free Software Foundation                                
# You may obtain a copy of the License at                                   
# https://opensource.org/licenses/gpl-2.0.php 


include $(TOPDIR)/rules.mk
include $(TOPDIR)/.config

PKG_NAME:=nvram
PKG_VERSION:=1
PKG_RELEASE:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/nvram
  SECTION:=utils
  CATEGORY:=Base system
  TITLE:=Userspace API for manipulate uboot parameter
  MAINTAINER:=opensource Communications technology
  DEPENDS:=@TARGET_ipq806x||TARGET_ipq401x||TARGET_ar71xx||TARGET_ipq807x_64||TARGET_ipq60xx||TARGET_ipq
endef

define Package/$(PKG_NAME)/description
 This package contains an utility to manipulate uboot parameter from linux.
 It invoke kernel api to implement functions.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./files/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) \
		CC="$(TARGET_CC)" \
		CFLAGS="$(TARGET_CFLAGS) $(TARGET_CPPFLAGS) -Wall" \
		LDFLAGS="$(TARGET_LDFLAGS) $(TARGET_CPPFLAGS)"
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/usr/sbin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/nvram $(1)/usr/sbin/
endef

$(eval $(call BuildPackage,nvram))
