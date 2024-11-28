#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]){
    
    double value;
    double cubic_value;
    char *endptr;

    if (argc != 2){
        printf("Nur einen Parameter eingeben\n");
        return 1;
    }

    errno = 0;

    value = strtod(argv[1], &endptr);

    if (errno == ERANGE) {
        printf("Der Wert ist außerhalb des darstellbaren Bereichs.\n");
        return EXIT_FAILURE;
    }

    if (endptr == argv[1]) {
        printf("Keine gültige Zahl gefunden.\n");
        return EXIT_FAILURE;
    }

    cubic_value = value * value * value;

    printf("Value: %f\n", value);
    printf("Cubic Value: %f\n", cubic_value);

    return EXIT_SUCCESS;

}