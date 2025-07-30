/* char_array.c
 * 
 * Entscheidung, ob eine Zeichenkette ein 'a' enthaelt
 */

#include <stdio.h>
#include <string.h>
#define MAX 40

int main() {
  int index;
  char eingabe [MAX];

  printf("Bitte String eingeben (max. %d Zeichen): ", MAX-1);
  fgets(eingabe, MAX, stdin);

  size_t eingabeLen = strlen(eingabe);
  for (int i = 0; i < eingabeLen; i++)
  {
    if (eingabe[i] == 'a'){
      printf("Position von 'a': %d\n", i);
    } else {
      printf("Der String enthält kein ’a’.\n");
      return 0;
    }
  }

    printf("\nEingabe: %s", eingabe);

  for (index = 0; eingabe[index] != '\0'; index++) 
    if (eingabe[index] == 'a') 
      break;


  return 0;
}
     
