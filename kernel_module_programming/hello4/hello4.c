/*
* hello−4.c − Demonstrates module documentation.
*/

/* Needed by all modules */
#include <linux/module.h>
/* Needed for KERN_INFO */
#include <linux/kernel.h>
/* Needed for the macros */
#include <linux/init.h>

#define DRIVER_AUTHOR "Amit"
#define DRIVER_DESC    "A sample driver"

static int __init init_hello_4(void)
{
    printk(KERN_INFO "Hello, world 4\n");
    return 0;
}

static void __exit cleanup_hello_4(void)
{
    printk(KERN_INFO "Goodbye, world 4\n");
}
module_init(init_hello_4);
module_exit(cleanup_hello_4);

/*
* You can use strings, like this:
*/
/*
* Get rid of taint message by declaring code as GPL.
*/
MODULE_LICENSE("GPL");

/*
* Or with defines, like this:
*/
MODULE_AUTHOR(DRIVER_AUTHOR);

/* Who wrote this module? */
MODULE_DESCRIPTION(DRIVER_DESC);
