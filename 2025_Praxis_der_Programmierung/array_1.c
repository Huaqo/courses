#include <stdio.h>

int main()
{

   int i;
   int ar[4];
   ar[0] = 10;
   ar[1] = 20;
   ar[2] = 30;
   ar[3] = 40;
   int arLen = (int)sizeof(ar) / sizeof(int);

   printf("\nar: %p\t &ar[0]: %p", ar, &ar[0]);

   printf("\n\nElemente von ar, indiziert:\n");
   for (i = 0; i < arLen; i++){
      printf("%d\t", ar[i]); 
   }

   printf("\n\nAdressen:\n");
   for (i = 0; i < arLen; i++){
      printf("%p\t", &ar[i]);
   }

   printf("\n\nElemente von ar, referenziert:\n");
   for (i = 0; i < arLen; i++){
      printf("%d\t", *(ar + i));
   }

   printf("\n\nAdressen:\n");
   for (i = 0; i < arLen; i++){
      printf("%p\t", ar + i);
   }

   printf("\n\n");
   return 0;
}
