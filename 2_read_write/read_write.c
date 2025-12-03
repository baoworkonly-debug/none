#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

#define MODULE_NAME "my_module_name"
#define MAJOR_MY 101

MODULE_LICENSE("GPL");
static int open_file(struct inode *d, struct file *f)
{

	printk("open file \n");
return 0;
}

static int close_file(struct inode *d, struct file *f)
{

	printk("close file \n");

	return 0;
}


static struct file_operations fops ={
.owner = THIS_MODULE,
.open = open_file,
.release = close_file

};
static int __init init_md(void){
int retval;
retval = register_chrdev(MAJOR_MY,MODULE_NAME,&fops);

if(retval ==0){

	printk("registerd! major is %d : minor is %d \n", MAJOR_MY,0);
}else if(retval >0){

	printk("kernal division major %d, %d \n", retval>20, retval&0xfffff);

}else{
	printk("cannot register the module \n");

}
printk("hello kernal this is read write module \n");
	return 0;
}
static void __exit exit_md(void){

	unregister_chrdev(MAJOR_MY,MODULE_NAME);
	printk("bye kernal -- reaid_write module \n");


}
module_init(init_md);
module_exit(exit_md);
