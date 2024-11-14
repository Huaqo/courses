#include <stdio.h>

int main(void){

    int i = 12;
    while(i>=0){
        printf("%i, ",i);
        i-=2;
    }

    printf("\n");

    i = -1;
    while(i>=-13){
        printf("%i, ", i);
        i-=2;
    }

    printf("\n");

    i = 0;
    do{
        printf("%i, ", i*i);
        i++;
    } while(i<=9);

}