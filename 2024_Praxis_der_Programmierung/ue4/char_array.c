/* char_array.c
 * 
 * Entscheidung, ob eine Zeichenkette ein 'a' enthaelt
 */

#include <stdio.h>
#define MAX 40

int main() {
  int index;
  char eingabe [MAX];

  printf("Bitte String eingeben (max. %d Zeichen): ", MAX-1);
  fgets(eingabe, MAX, stdin);  

  printf("\nEingabe: %s", eingabe);

  for (index = 0; eingabe[index] != '\0'; index++)
    if (eingabe[index] == 'a')
      break;

  if (eingabe[index] == '\0')
    printf("Der String enthält kein ’a’.");
  else
    printf("Das erste 'a' ist an Position %d.\n", index + 1);

  return 0;
}