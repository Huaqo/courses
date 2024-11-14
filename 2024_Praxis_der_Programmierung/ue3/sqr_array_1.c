#include <stdio.h>
#include <stdlib.h>
#define NL printf("\n");
#define LEN 10

int main(void){
    int ar[LEN];

    for(int i = 0; i < sizeof(ar)/sizeof(int); i++){
        ar[i] = (i+1) * (i+1);
        printf("%i ", ar[i]);
    }
    NL

}