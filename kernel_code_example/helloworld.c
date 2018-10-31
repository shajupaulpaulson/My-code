#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Shaju");
MODULE_DESCRIPTION("A Simple Hello World module");

int init_module(void)
{
    printk(KERN_INFO "Hello world!\n");
    return 0;    // Non-zero return means that the module couldn't be loaded.
}

void cleanup_module(void)
{
    printk(KERN_INFO "Cleaning up module.\n");
}

