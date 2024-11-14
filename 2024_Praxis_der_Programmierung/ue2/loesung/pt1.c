#include <stdio.h>

int main(){
    int i;
	int *ptr = &i;
	i = 1;
	printf("ptr = %p \n", ptr);  // ptr = 0x7fffc953d9f4
	printf("*ptr = %d \n", *ptr);  // *ptr = 1 
	printf("i = %d \n", i);
	*ptr = 2;
	printf("i = %d \n", i);
}
