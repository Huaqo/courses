/* array_1.c
 *
 * Adressierung von Array-Elementen
 * Indizes vs. Pointer
 */

// ACHTUNG: Datei enthaelt zu beseitigende Fehler!!!

#include <stdio.h>

int main()
{

   int i = 0;
   int ar[4];
   ar[0] = 10;
   ar[1] = 20;
   ar[2] = 30;
   ar[3] = 40;
   int len = (int) sizeof(ar)/sizeof(int);
   printf("%d \n", len);

   printf("\nar: %p\t &ar[0]: %p", ar, &ar[0]);

// i) Array-Syntax
   printf("\n\nElemente von ar, indiziert:\n");
   for (i=0; i<=(len-1)  ; i++){         // hier ergaenzen!!!
      printf("%d\t",ar[i] ); // hier ergaenzen!!!
   }

   printf("\n\nAdressen:\n");
   for (i=0; i<=(len-1); i++){         // hier ergaenzen!!!
      printf("%p\t",&ar[i] ); // hier ergaenzen!!!
   }
  
// ii) Pointer-Syntax
   printf("\n\nElemente von ar, referenziert:\n");
   for (i=0; i<=(len-1); i++){         // hier ergaenzen!!!
      printf("%d\t", *(ar+i) ); // hier ergaenzen!!!
   }

   printf("\n\nAdressen:\n");
   for (i=0; i<=(len-1); i++){         // hier ergaenzen!!!
      printf("%p\t", ar+i ); // hier ergaenzen!!!
   }

   printf("\n\n");
   return 0;
}
