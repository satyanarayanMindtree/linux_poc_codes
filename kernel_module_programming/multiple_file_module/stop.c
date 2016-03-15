/*
* stop.c − Illustration of multi filed modules
*/
#include <linux/kernel.h>
#include <linux/module.h>

void cleanup_module()
{
    printk(KERN_INFO "Oh no!! I am dying :(\n");
    return;
}

