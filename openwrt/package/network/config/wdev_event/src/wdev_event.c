#include <linux/module.h>
#include <linux/kernel.h>
#include <asm/page.h>
#include <linux/slab.h>
#include <linux/device.h>
#include <linux/notifier.h>
#include <linux/if.h>
#include <linux/netdevice.h>
#include <linux/nl80211.h>
#include <net/cfg80211.h>


//int g_var;
struct wdev_event_device {
	struct device dev;
};

#define to_wdev_dev(d) container_of(d, struct wdev_event_device, dev)

static struct class *g_wdev_class;
static struct wdev_event_device *g_wdev = NULL;


static void wdev_event_device_release(struct device *dev)
{
	kfree(to_wdev_dev(dev));	
}



static int wdev_notify(struct notifier_block *this, unsigned long event, void *ptr)
{
	struct net_device *dev = netdev_notifier_info_to_dev(ptr);
	struct wireless_dev *wdev = dev->ieee80211_ptr;
	char env_ifname[32];
	char *envp[] = {
		env_ifname,
		NULL
	};

	if (!wdev || (wdev->iftype != NL80211_IFTYPE_AP))
		return NOTIFY_DONE;

	switch (event) {
		case NETDEV_UP:
			if (dev->flags & IFF_SLAVE)
				break;
			snprintf(env_ifname, sizeof(env_ifname), "IFNAME=%s", dev->name);
			kobject_uevent_env(&g_wdev->dev.kobj, KOBJ_CHANGE, envp);
			return NOTIFY_OK;
		
		default:
			break;
	}
	return NOTIFY_DONE;
}

static struct notifier_block g_wdev_event_notf = {
	.notifier_call = wdev_notify,
}; 


int __init wdev_event_init(void)
{
	int ret;

	g_wdev_class = class_create(THIS_MODULE, "wdev_event");
	if (!g_wdev_class) 
		goto failed;

	g_wdev = kzalloc(sizeof(struct wdev_event_device), GFP_KERNEL);
	if (!g_wdev)
		goto destory_cls;

	g_wdev->dev.init_name = "wdev";
	g_wdev->dev.release = wdev_event_device_release;
	g_wdev->dev.class = g_wdev_class;

	ret = device_register(&g_wdev->dev);
	if (ret)
		goto put_dev;

	if (!register_netdevice_notifier(&g_wdev_event_notf))
		return 0;

put_dev:
	put_device(&g_wdev->dev);
	kfree(g_wdev);

destory_cls:
	class_destroy(g_wdev_class);

failed:
	return -1;
}

void __exit wdev_event_exit(void)
{
	device_unregister(&g_wdev->dev);
	class_destroy(g_wdev_class);
	unregister_netdevice_notifier(&g_wdev_event_notf);
}

module_init(wdev_event_init);
module_exit(wdev_event_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("xiaomi");
MODULE_DESCRIPTION("Wireless Dev Event");
