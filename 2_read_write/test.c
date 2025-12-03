#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <string.h>
#include <fcntl.h>
int main (){
char name_f[50];
printf("ten file :.. \n");
scanf("%49s",name_f);
printf("openning file : %s \n ",name_f);

char op[55] = "/dev/"	;
strcat(op,name_f);

int f = open(op,O_RDONLY);


if(f == -1){
printf("cannot open file: %s \n",op);
return -1;
}
printf("open success !");
	return 0;
}
