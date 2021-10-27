# copyright            : (C) by 2021 Lin kai 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 as         
# published by the Free Software Foundation                                
# You may obtain a copy of the License at                                   
# https://opensource.org/licenses/gpl-2.0.php 

include $(TOPDIR)/rules.mk

PKG_NAME:=boot_check
PKG_VERSION:=1
PKG_RELEASE:=1.1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)


include $(INCLUDE_DIR)/package.mk

define Package/$(PKG_NAME)
  SECTION:=net
  CATEGORY:=Utilities
  TITLE:=check boot successfully?
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./files/* $(PKG_BUILD_DIR)
endef

define Build/Compile
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/usr/sbin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/boot_check $(1)/usr/sbin/
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/key_services_boot_check $(1)/etc/init.d/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/boot_check $(1)/etc/init.d/
endef

$(eval $(call BuildPackage,boot_check))

