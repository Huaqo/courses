#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i;
    int *ptr = NULL;
    ptr = &i;
    i = 1;
    printf("Pointer Wert: \t\t\t %i\n", *ptr);
    printf("Pointer Adresse: \t\t %p\n", ptr);
    printf("Variablen Wert: \t\t %i\n", i);
    *ptr = 2;
    printf("Veraenderten Variablen Wert: \t %i\n", i);
    return EXIT_SUCCESS;
}
