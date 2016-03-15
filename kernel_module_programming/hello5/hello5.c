
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>


static int myint = 0;
static short myshort = 0;
// static int mystr_maxlen = 0;
static char *mystr = "hello";
static int myarr_element_cnt = 0;
static int myarr[] = {0, 1, 2, 3, 4, 5};

module_param(myint, int, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP);
MODULE_PARM_DESC(myint, "An integer");
module_param(myshort, short, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP);
MODULE_PARM_DESC(myshort, "A short integer");
module_param(mystr, charp, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP);
MODULE_PARM_DESC(mystr, "A string");
module_param_array(myarr, int, &myarr_element_cnt, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP);
MODULE_PARM_DESC(myarr, "An array of integers");


static int init_hello5(void)
{
    int i;

    printk(KERN_INFO "Hello world 5\n");

    printk(KERN_INFO "myint: %d\n", myint);
    printk(KERN_INFO "myshort: %hu\n", myshort); 
    // printk(KERN_INFO "mystr: %s strlen: %d\n", mystr_maxlen);

    printk(KERN_INFO "mystr: %s\n", mystr);

    printk(KERN_INFO "myarr_element_cnt: %d\n", myarr_element_cnt);
    for (i = 0; i < myarr_element_cnt; i++)
    {        
        printk(KERN_INFO "myarr[%d]: %d\n", i, myarr[i]);
    }

    return 0;
}

static void exit_hello5(void)
{   
    printk(KERN_INFO "Bye World\n");
}

module_init(init_hello5);
module_exit(exit_hello5);


