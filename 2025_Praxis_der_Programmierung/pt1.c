#include <stdio.h>

int main(){
    int i;
    int *ptr;
    ptr = &i;
    i = 1;
    printf("%i\n", *ptr);
    printf("%p\n", ptr);
    printf("%i\n", i);
    *ptr = 2;
    printf("%i\n", i);
}


