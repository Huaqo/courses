#include <stdio.h>
#include <string.h>
#define STRING_LENGHT 50

int main(){
    
    char s1[STRING_LENGHT];
    char s2[STRING_LENGHT];
    
    printf("Bitte geben Sie einen Vornamen ein: \n");
    scanf("%49s", s1);
    
    printf("Bitte geben Sie einen Nachnamen ein: \n");
    scanf("%49s", s2);
    
    if (strcmp(s1, s2))
    {
        printf("Vor- und Nachname sind verschieden\n");
    }
    else
    {
        printf("Vor- und Nachname sind gleich.\n");
    }

    for (int i = 0; s2[i] != '\0'; i++){
        if (s2[i] >= 'a' && s2[i] <= 'z'){
            s2[i] = s2[i] - ('a'-'A');
        }
    }

    char name[STRING_LENGHT * 2];
    strcat(name, s1);
    strcat(name, " ");
    strcat(name, s2);

    int name_laenge = (int)(strlen(s1) + strlen(s2));
    printf("name: %s, Laenge: %i\n", name, name_laenge);

}
