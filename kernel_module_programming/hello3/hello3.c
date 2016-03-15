/*
* hello−3.c − Illustrating the __init, __initdata and __exit macros.
*/
#include <linux/module.h>
/* Needed by all modules */
#include <linux/kernel.h>
/* Needed for KERN_INFO */
#include <linux/init.h>
/* Needed for the macros */
MODULE_LICENSE("Dual BSD/GPL");

/*
  * HW_Button Implementation
  *
  * Copyright (C) 2013-2014 Kopera Software Pvt. Ltd.
  *
  */
 #include <linux/kobject.h>
 #include <linux/string.h>
 #include <linux/sysfs.h>
 #include <linux/module.h>
 #include <linux/init.h>
 #include <linux/slab.h>
 
 /*
Kernel will create three virtual btn
    - issue recovery
    - issue reset
    - alarm silent
  */
 
 
 /*
  * This is our "object" that we will create a few of and register them with
  * sysfs.
  */
 struct hw_btn_obj {
         struct kobject kobj;
         int state;
 };
 #define to_hw_btn_obj(x) container_of(x, struct hw_btn_obj, kobj)
 
 
 /* a custom attribute that works just for a struct hw_btn_obj. */
 struct hw_btn_attribute {
         struct attribute attr;
         ssize_t (*show)(struct hw_btn_obj *hw_btn, struct hw_btn_attribute *attr, char *buf);
         ssize_t (*store)(struct hw_btn_obj *hw_btn, struct hw_btn_attribute *attr, const char *buf, size_t count);
 };
 #define to_hw_btn_attr(x) container_of(x, struct hw_btn_attribute, attr)
 

 
 
 /*
  * The default show function that must be passed to sysfs.  This will be
  * called by sysfs for whenever a show function is called by the user on a
  * sysfs file associated with the kobjects we have registered.  We need to
  * transpose back from a "default" kobject to our custom struct hw_btn_obj and
  * then call the show function for that specific object.
  */
 static ssize_t hw_btn_attr_show(struct kobject *kobj,
                              struct attribute *attr,
                              char *buf)
 {
         struct hw_btn_attribute *attribute;
         struct hw_btn_obj *hw_btn;
 
         attribute = to_hw_btn_attr(attr);
         hw_btn = to_hw_btn_obj(kobj);
 
         if (!attribute->show)
                 return -EIO;
 
         return attribute->show(hw_btn, attribute, buf);
 }
 
 /*
  * Just like the default show function above, but this one is for when the
  * sysfs "store" is requested (when a value is written to a file.)
  */
 static ssize_t hw_btn_attr_store(struct kobject *kobj,
                               struct attribute *attr,
                               const char *buf, size_t len)
 {
         struct hw_btn_attribute *attribute;
         struct hw_btn_obj *hw_btn;
 
         attribute = to_hw_btn_attr(attr);
         hw_btn = to_hw_btn_obj(kobj);
 
         if (!attribute->store)
                 return -EIO;
 
         return attribute->store(hw_btn, attribute, buf, len);
 }
 
 /* Our custom sysfs_ops that we will associate with our ktype later on */
 static struct sysfs_ops hw_btn_sysfs_ops = {
         .show = hw_btn_attr_show,
         .store = hw_btn_attr_store,
 };
 
 /*
  * The release function for our object.  This is REQUIRED by the kernel to
  * have.  We free the memory held in our object here.
  *
  * NEVER try to get away with just a "blank" release function to try to be
  * smarter than the kernel.  Turns out, no one ever is...
  */
 static void hw_btn_release(struct kobject *kobj)
 {
         struct hw_btn_obj *hw_btn;
 
         hw_btn = to_hw_btn_obj(kobj);
         kfree(hw_btn);
 }
 
 /*
  * The "hw_btn" file where the .hw_btn variable is read from and written to.
  */
 static ssize_t hw_btn_show(struct hw_btn_obj *hw_btn_obj, struct hw_btn_attribute *attr,
                         char *buf)
 {
         return sprintf(buf, "%d\n", hw_btn_obj->state);
 }
 
 static ssize_t hw_btn_store(struct hw_btn_obj *hw_btn_obj, struct hw_btn_attribute *attr,
                          const char *buf, size_t count)
 {
        printk(KERN_ERR "modified state\n");
        kobject_uevent(&hw_btn_obj->kobj, KOBJ_CHANGE);
         sscanf(buf, "%du", &hw_btn_obj->state);
         return count;
 }
 
 static struct hw_btn_attribute reset_attribute =
         __ATTR(state, 0666, hw_btn_show, hw_btn_store);
 

 /*
  * Create a group of attributes so that we can create and destory them all
  * at once.
  */
 static struct attribute *reset_default_attrs[] = {
         &reset_attribute.attr,
         NULL,   /* need to NULL terminate the list of attributes */
 };
 
 
 static struct hw_btn_attribute silent_alarm_attribute =
         __ATTR(state, 0666, hw_btn_show, hw_btn_store);
 

 /*
  * Create a group of attributes so that we can create and destory them all
  * at once.
  */
 static struct attribute *silent_alarm_default_attrs[] = {
         &silent_alarm_attribute.attr,
         NULL,   /* need to NULL terminate the list of attributes */
 };
 
 
  static struct hw_btn_attribute tamper_btn_attribute =
         __ATTR(state, 0666, hw_btn_show, hw_btn_store);

 

 /*
  * Create a group of attributes so that we can create and destory them all
  * at once.
  */
 static struct attribute *tamper_btn_default_attrs[] = {
         &tamper_btn_attribute.attr,
         NULL,   /* need to NULL terminate the list of attributes */
 };

 static struct hw_btn_attribute tamper_btn_history_attribute =
         __ATTR(state, 0666, hw_btn_show, hw_btn_store);
 
 /*
  * Create a group of attributes so that we can create and destory them all
  * at once.
  */
 static struct attribute *tamper_btn_history_default_attrs[] = {
         &tamper_btn_history_attribute.attr,
         NULL,   /* need to NULL terminate the list of attributes */
 };

 
  static struct hw_btn_attribute hw_id_attribute =
         __ATTR(state, 0666, hw_btn_show, hw_btn_store);
 
 /*
  * Create a group of attributes so that we can create and destory them all
  * at once.
  */
 static struct attribute *hw_id_default_attrs[] = {
         &hw_id_attribute.attr,
         NULL,   /* need to NULL terminate the list of attributes */
 };

 
 
 /*
  * Our own ktype for our kobjects.  Here we specify our sysfs ops, the
  * release function, and the set of default attributes we want created
  * whenever a kobject of this type is registered with the kernel.
  */
 static struct kobj_type reset_btn_ktype = {
         .sysfs_ops = &hw_btn_sysfs_ops,
         .release = hw_btn_release,
         .default_attrs = reset_default_attrs,
 };
 
  /*
  * Our own ktype for our kobjects.  Here we specify our sysfs ops, the
  * release function, and the set of default attributes we want created
  * whenever a kobject of this type is registered with the kernel.
  */
 static struct kobj_type alarm_silent_btn_ktype = {
         .sysfs_ops = &hw_btn_sysfs_ops,
         .release = hw_btn_release,
         .default_attrs = silent_alarm_default_attrs,
 };
 
   /*
  * Our own ktype for our kobjects.  Here we specify our sysfs ops, the
  * release function, and the set of default attributes we want created
  * whenever a kobject of this type is registered with the kernel.
  */
 static struct kobj_type tamper_btn_ktype = {
         .sysfs_ops = &hw_btn_sysfs_ops,
         .release = hw_btn_release,
         .default_attrs = tamper_btn_default_attrs,
 };

   /*
  * Our own ktype for our kobjects.  Here we specify our sysfs ops, the
  * release function, and the set of default attributes we want created
  * whenever a kobject of this type is registered with the kernel.
  */
 static struct kobj_type tamper_btn_history_ktype = {
         .sysfs_ops = &hw_btn_sysfs_ops,
         .release = hw_btn_release,
         .default_attrs = tamper_btn_history_default_attrs,
 };
 
 
 
  static struct kobj_type hw_id_ktype = {
         .sysfs_ops = &hw_btn_sysfs_ops,
         .release = hw_btn_release,
         .default_attrs = tamper_btn_history_default_attrs,
 };
 
 
 static struct kset *smartly_kset;
 static struct hw_btn_obj *reset_btn_obj;
 static struct hw_btn_obj *alarm_silent_btn_obj;
 static struct hw_btn_obj *tamper_obj;
 static struct hw_btn_obj *tamper_history_obj;
 static struct hw_btn_obj *hw_id_obj;
 
 static struct hw_btn_obj *create_hw_btn_obj(const char *name, struct kobj_type *kobj_type_obj)
 {
         struct hw_btn_obj *hw_btn;
         int retval;
 
         /* allocate the memory for the whole object */
         hw_btn = kzalloc(sizeof(*hw_btn), GFP_KERNEL);
         if (!hw_btn)
                 return NULL;
 
         /*
          * As we have a kset for this kobject, we need to set it before calling
          * the kobject core.
          */
         hw_btn->kobj.kset = smartly_kset;
 
         /*
          * Initialize and add the kobject to the kernel.  All the default files
          * will be created here.  As we have already specified a kset for this
          * kobject, we don't have to set a parent for the kobject, the kobject
          * will be placed beneath that kset automatically.
          */
         retval = kobject_init_and_add(&hw_btn->kobj, kobj_type_obj, NULL, "%s", name);
         if (retval) {
                 kobject_put(&hw_btn->kobj);
                 return NULL;
         }
 
         /*
          * We are always responsible for sending the uevent that the kobject
          * was added to the system.
          */
         kobject_uevent(&hw_btn->kobj, KOBJ_ADD);
 
         return hw_btn;
 }
 
 static void destroy_hw_btn_obj(struct hw_btn_obj *hw_btn)
 {
         kobject_put(&hw_btn->kobj);
 }
 
int  hw_btn_object_init(void)
 {
         /*
          * Create a kset with the name of "kset_example",
          * located under /sys/kernel/
          */
         smartly_kset = kset_create_and_add("smartly_1", NULL, kernel_kobj);
         if (!smartly_kset)
                 return -ENOMEM;
 
         /*
          * Create three objects and register them with our kset
          */
         reset_btn_obj = create_hw_btn_obj("reset_btn", &reset_btn_ktype);
         if (!reset_btn_obj)
                 goto rst_btn_error;
         
         alarm_silent_btn_obj = create_hw_btn_obj("silent_alarm_btn", &alarm_silent_btn_ktype);
         if (!alarm_silent_btn_obj)
                 goto alarm_btn_error;
         
         tamper_obj = create_hw_btn_obj("tamper", &tamper_btn_ktype);
         if (!tamper_obj)
                 goto tamper_btn_error;
 
         tamper_history_obj = create_hw_btn_obj("tamper_history", &tamper_btn_history_ktype);
         if (!tamper_obj)
                 goto tamper_history_error;
         
         hw_id_obj = create_hw_btn_obj("hw_id", &hw_id_ktype);
         if (!hw_id_obj)
                 goto hw_id_obj_error;
 
         return 0;
         
hw_id_obj_error:
        destroy_hw_btn_obj(tamper_history_obj);
        
tamper_history_error:      
        destroy_hw_btn_obj(tamper_obj);
        
tamper_btn_error:
        
         destroy_hw_btn_obj(alarm_silent_btn_obj);
alarm_btn_error:
          destroy_hw_btn_obj(reset_btn_obj);
          

    
 rst_btn_error:
         return -EINVAL;
 }

 
 
int  hw_btn_object_exit(void)
 {
         destroy_hw_btn_obj(reset_btn_obj);
         destroy_hw_btn_obj(alarm_silent_btn_obj);
         destroy_hw_btn_obj(tamper_obj);
         destroy_hw_btn_obj(tamper_history_obj);
         destroy_hw_btn_obj(hw_id_obj);
         kset_unregister(smartly_kset);
         return 0;
 }
 

static int hello3_data __initdata = 3;
static int __init hello_3_init(void)
{
    printk(KERN_ALERT "Hello, world %d\n", hello3_data);
    hw_btn_object_init();
    return 0;
}
static void __exit hello_3_exit(void)
{
	hw_btn_object_exit();
    printk(KERN_INFO "Goodbye, world 3\n");
}
module_init(hello_3_init);
module_exit(hello_3_exit);

