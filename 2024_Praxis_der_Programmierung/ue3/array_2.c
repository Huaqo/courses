/* array_1.c
 *
 * Adressierung von Array-Elementen
 * Indizes vs. Pointer
 */

// ACHTUNG: Datei enthaelt zu beseitigende Fehler!!!

#include <stdio.h>

int main()
{

   int i;
   int ar[4];
   ar[0] = 10;
   ar[1] = 20;
   ar[2] = 30;

   printf("\nar: %p \t &ar[0]: %p\n", ar, &ar[0]);

// i) Array-Syntax
   printf("\n\nElemente von ar, indiziert:\n");
   for (int i = 0; i < (sizeof(ar)/sizeof(int)) + 2; i++){
      printf("%d\t\n", ar[i]); 
   }

   printf("\n\nAdressen:\n");
   for (int i = 0; i < (sizeof(ar)/sizeof(int)) + 2; i++){        
      printf("%p\t\n", &ar[i]); 
   }
  
// ii) Pointer-Syntax
   printf("\n\nElemente von ar, referenziert:\n");
   for (int i = 0; i < (sizeof(ar)/sizeof(int)) + 2; i++){         
      printf("%d\t\n", *(ar + i));
   }

   printf("\n\nAdressen:\n");
   for (int i = 0; i < (sizeof(ar)/sizeof(int)) + 2; i++){         
      printf("%p\t", ar+i); 
   }

   printf("\n\n");
   return 0;
}
