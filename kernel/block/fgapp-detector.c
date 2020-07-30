#include <linux/kobject.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/mm.h>

int fgapp_uid;
EXPORT_SYMBOL(fgapp_uid);

static ssize_t fgapp_show(struct kobject *kobj, struct kobj_attribute *attr,
			char *buf)
{
	return sprintf(buf, "%d\n", fgapp_uid);
}

static ssize_t fgapp_store(struct kobject *kobj, struct kobj_attribute *attr,
			 const char *buf, size_t count)
{
	sscanf(buf, "%du", &fgapp_uid);
	return count;
}

static struct kobj_attribute fgapp_attribute =
	__ATTR(fgapp_uid, 0664, fgapp_show, fgapp_store);


static struct attribute *attrs[] = {
	&fgapp_attribute.attr,
	NULL,
};

static struct attribute_group attr_group = {
	.attrs = attrs,
};

static struct kobject *fgapp_kobj;

static int __init fgapp_init(void)
{
	int retval;
	fgapp_uid = 257;
	fgapp_kobj = kobject_create_and_add("fgApp_Uid", kernel_kobj);
	if (!fgapp_kobj)
		return -ENOMEM;

	retval = sysfs_create_group(fgapp_kobj, &attr_group);
	if (retval)
		kobject_put(fgapp_kobj);

	return retval;
}

static void __exit fgapp_exit(void)
{
	kobject_put(fgapp_kobj);
}

module_init(fgapp_init);
module_exit(fgapp_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Riwei Pan");
