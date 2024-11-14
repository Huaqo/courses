#include <stdio.h>
#include <stdlib.h>
#define NL printf("\n");
#define LEN 1000

int main(void){
    int ar[LEN];
    for(int i = 0; i < LEN; i++){
        ar[i] = (i + 1) * (i + 1);
    }

    while(1){
        printf("Geben Sie eine ganze Zahl zwischen 1 und %i ein: ", LEN);
        int input;
        scanf("%i", &input);


        if(input == 0){
            break;
        } 
        else if(input < 1 || input > LEN) {
            continue;
        }

        printf("Quadrat von %i: %i", input, ar[input - 1]);

        NL
    }
}