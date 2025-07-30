#include <stdio.h>

void swap(int* value1, int* value2){
    int buffer = *value1;
    *value1 = *value2;
    *value2 = buffer;
}

int main(){
    int x = 4;
    int y = 5;
    printf("x:%i y:%i\n", x, y);
    swap(&x, &y);
    printf("swap!\n");
    printf("x:%i y:%i\n", x, y);
}