#include <linux/init.h>
#include <linux/module.h>

/* 
 * Another special macro (MODULE_LICENSE) is used to tell the kernel that this 
 * module bears a free license; without such a declaration, the kernel 
 * complains when the module is loaded.
 */
MODULE_LICENSE("Dual BSD/GPL");

/*
 * Module parameter
 */
static char *whom = "Josh";
module_param(whom, charp, S_IRUGO);

static int how_many = 1;
module_param(how_many, int, S_IRUGO);

static int int_array[6] = {1, 2, 3, 4, 5, 6};
static int int_array_num;
module_param_array(int_array, int, &int_array_num, S_IRUGO);

static int __init hello_init(void)
{
	int i;
	for (i=0; i < how_many; i++) {
		printk(KERN_ALERT "Hello %s\n", whom);
	}

	printk(KERN_ALERT "array element input from user: %d\n", int_array_num);

	for (i=0; i < 6; i++) {
		printk(KERN_ALERT "int_array[%d]: %d\n", i, int_array[i]);
	}
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye %s\n", whom);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("John LiuXin");
MODULE_DESCRIPTION("Example of kernel module");