#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){

	int dev = open("/dev/mydevice",O_RDONLY);
if (dev == -1)
{	printf(" cannot open file \n");
} else {
printf("open success \n ");
}
close(dev);
return 0;
}




