#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char statS[] = "Hallo, PdP!";

    char *dynS = malloc( 50 * sizeof(char));
    if (dynS == NULL){
        printf("Speicher konnte nicht reserviert werden");
        return 1;
    }
    strcpy(dynS, "Hallo, PdP!");

    printf("%s\n", statS);
    printf("%s\n", dynS);

    statS[1] = 'e';
    dynS[1] = 'e';
    printf("%s\n", statS);
    printf("%s\n", dynS);

    strcpy(statS, "neuer String");
    strcpy(dynS, "neuer String");

    printf("%s\n", statS);
    printf("%s\n", dynS);

    free(dynS);
    return 0;
}
