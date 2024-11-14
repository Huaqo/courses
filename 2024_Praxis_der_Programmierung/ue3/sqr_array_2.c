#include <stdio.h>
#include <stdlib.h>
#define NL printf("\n");
#define SIZE 10

void rev_print(int *ar, int size){
    for(int i = 0; i < size; i++){
        printf("%i ",ar[size - 1 - i]);
    }
    NL
}

int main(void){
    int ar[SIZE];

    for(int i = 0; i < SIZE; i++){
        ar[i] = (i+1) * (i+1);
        printf("%i ", ar[i]);
    }
    NL
    rev_print(ar, SIZE);
}