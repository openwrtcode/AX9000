include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=wdev_event
PKG_RELEASE:=0

PKG_BUILD_DIR:=$(KERNEL_BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define KernelPackage/wdev_event
  CATEGORY:=Kernel modules
  TITLE:=Wireless Dev Event
  FILES:=$(PKG_BUILD_DIR)/wdev_event.ko
  AUTOLOAD:=$(call AutoLoad,78,wdev_event)
endef

define Package/wdev_event
  SECTION:=net
  CATEGORY:=Network
  TITLE:=Wireless Dev Uevent Hotplug Scripts
  DEPENDS:= +kmod-wdev_event
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) $(KERNEL_MAKEOPTS) M="$(PKG_BUILD_DIR)" modules
endef

define Package/wdev_event/install
	$(INSTALL_DIR) $(1)/etc/hotplug.d/wdev_event
	$(INSTALL_BIN) files/00-wdev_set_txpwr $(1)/etc/hotplug.d/wdev_event/00-wdev_set_txpwr
endef

$(eval $(call KernelPackage,wdev_event))
$(eval $(call BuildPackage,wdev_event))
