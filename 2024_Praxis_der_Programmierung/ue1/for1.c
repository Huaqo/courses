#include <stdio.h>

int main(void){
    for(int i = 12; i >= 0; i-=2){
        printf("%i, ",i);
    }

    printf("\n");

    for(int i = -1; i >= -13; i-=2){
        printf("%i, ", i);
    }

    printf("\n");

    for(int i = 0; i <= 9; i++){
        printf("%i, ", i*i);
    }
}