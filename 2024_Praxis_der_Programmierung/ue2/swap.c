#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void){
    int x = 1;
    int y = 2;  
    printf("x: %i, y: %i\n",x,y);
    swap(&x, &y);
    printf("x: %i, y: %i\n",x,y);
}