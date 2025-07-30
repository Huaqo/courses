#include <stdio.h>

int main(void){

    printf("\n Die geraden Zahlen von 12 bis 0: ");

    for(int i = 12; i >= 0; i-=2){
        printf("%i, ",i);
    }

    printf("\n Die ungeraden Zahlen von -1 bis -13: ");

    for(int i = -1; i >= -13; i-=2){
        printf("%i, ", i);
    }

    printf("\n Die ersten 10 Quadratzahlen: ");

    for(int i = 0; i <= 9; i++){
        printf("%i, ", i*i);
    }

    printf("\n");

}