#include <linux/module.h>
#include <linux/init.h>

#include <linux/fs.h>
#define MJ 100
#define DEVICE_GPIO "init_device_gpioo"


MODULE_LICENSE("GPL");
static int driver_open(struct inode *device_file, struct file *instance){


printk("open was called \n");


return 0;

}

static int driver_close(struct inode *device_file, struct file *instance){

printk("close was called \n");


return 0;
}

static struct file_operations fops ={
	.owner = THIS_MODULE,
	.open = driver_open,
	.release = driver_close

};

static int __init gpio_init(void){
	printk("Start init gpio ! \n");

	int reval;
	reval = register_chrdev(MJ,DEVICE_GPIO,&fops);

	if (reval ==0){
		printk("egister sussess: major %d and minnor %d \n", MJ,0);

	} else if(reval>0){
		printk("register success: major is %d and minor is %d \n",reval>>20, reval&0xfffff);
	}else{
		printk("cannot register driver gpio %d \n",reval);
	}


	printk("init gpio complete ! \n");
	return 0;
} 

static void __exit gpio_exit(void){

	unregister_chrdev(MJ,DEVICE_GPIO);

	printk("gpio bey! \n");

	
}

module_init(gpio_init);
module_exit(gpio_exit);

