#include <stdio.h>

int main(void){

    printf("\n Die geraden Zahlen von 12 bis 0: ");

    int i = 12;
    while(i>=0){
        printf("%i, ",i);
        i-=2;
    }

    printf("\n Die ungeraden Zahlen von -1 bis -13: ");

    i = -1;
    while(i>=-13){
        printf("%i, ", i);
        i-=2;
    }

    printf("\n Die ersten 10 Quadratzahlen: ");

    i = 0;
    do{
        printf("%i, ", i*i);
        i++;
    } while(i<=9);

}