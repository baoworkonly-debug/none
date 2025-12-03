#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <string.h>
#include <fcntl.h>
int main (){

int f = open("/dev/read_write_mydevice",O_RDONLY);


if(f == -1){
printf("cannot open file: \n");
return -1;
}
printf("open success !\n");
	return 0;
}
