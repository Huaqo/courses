#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    // Static string
    char statS[50] = "Hallo PdP!";
    
    // Dynamic string
    char *dynS = malloc(11);
    strcpy(dynS, "Hallo PdP!");

    // Print
    printf("Static string [1]: %c \n", statS[1]);
    printf("Dynamic string [1]: %c \n", dynS[1]);

    // Neuzuweisung
    statS[1] = 'e';
    dynS[1] = 'e';

    // Print
    printf("Static string [1]: %c \n", statS[1]);
    printf("Dynamic string [1]: %c \n", dynS[1]);

    // Neuzuweisung 2
    strcpy(statS,"neuer String");
    dynS = "neuer String";

        // Print
    printf("Static string: %s \n", statS);
    printf("Dynamic string: %s \n", dynS);
}