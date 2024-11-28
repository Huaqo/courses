#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 40

int main(){

    char s1 [MAX];
    char s2 [MAX];

    printf("Bitte Vorname eingeben (max. %d Zeichen): ", MAX-1);
    fgets(s1, MAX, stdin);  

    size_t len = strlen(s1);
    if (len > 0 && s1[len - 1] == '\n') {
        s1[len - 1] = '\0';
    }

    printf("Bitte Nachname eingeben (max. %d Zeichen): ", MAX-1);
    fgets(s2, MAX, stdin);  

    len = strlen(s2);
    if (len > 0 && s2[len - 1] == '\n') {
        s2[len - 1] = '\0';
    }

    if (strcmp(s1, s2) == 0) {
        printf("Vorname und Nachname sind gleich.\n");
    } else {
        printf("Vorname und Nachname sind nicht gleich.\n");
    }

    int index = 0;
    while(s2[index] != '\0'){        
        if (s2[index] >= 'a' && s2[index] <= 'z'){
            s2[index] -= 'a'-'A';
        }
        index++;
    }

    printf("Einzeln: %s %s \n", s1,s2);


    char *name = malloc( 80 * sizeof(char));
    if (name==NULL){
        printf("Konnte nicht reserviert werden");
        return 1;
    }

    strcpy(name, s1);
    strcat(name, " ");
    strcat(name, s2);


    printf("Zusammen: %s \n", name);
    printf("Laenge name: %zu\n", strlen(name));

    free(name);

    return 0;
}