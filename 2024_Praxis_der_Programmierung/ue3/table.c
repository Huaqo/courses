#include <stdio.h>
#include <stdlib.h>

#define NL printf("\n");

int main(void){

    int ar[3][4] = {
        {0, 1, 2, 3},      
        {10, 11, 12}
    };

    for(int i = 0; i < sizeof(ar)/sizeof(ar[0]);i++){
        for(int j = 0; j < sizeof(ar[0])/sizeof(int);j++){
            printf("%i\t", ar[i][j]);
        }
        NL
    }

}