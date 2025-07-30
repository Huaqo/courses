#include <stdio.h>

int main()
{

   int i;
   int ar[5];
   ar[0] = 10;
   ar[1] = 20;
   ar[2] = 30;
   ar[3] = 40;

   int arLen = (int)sizeof(ar) / sizeof(int) + 2;

   printf("\nar: %p \t &ar[0]: %p\n", ar, &ar[0]);

   printf("\n\nElemente von ar, indiziert:\n");
   for (int i = 0; i < arLen; i++){
      printf("%d\t", ar[i]); 
   }

   printf("\n\nAdressen:\n");
   for (int i = 0; i < arLen; i++){        
      printf("%p\t", &ar[i]); 
   }
  
   printf("\n\nElemente von ar, referenziert:\n");
   for (int i = 0; i < (sizeof(ar)/sizeof(int)) + 2; i++){         
      printf("%d\t", *(ar + i));
   }

   printf("\n\nAdressen:\n");
   for (int i = 0; i < (sizeof(ar)/sizeof(int)) + 2; i++){         
      printf("%p\t", ar+i); 
   }

   printf("\n\n");
   return 0;
}
