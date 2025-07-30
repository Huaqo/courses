/* typengroesse.c
 * 
 * Bestimmung der Groesse der einfachen typen mit sizeof
 */

 #include <stdio.h>

 int main() {
   char c = 127;
   unsigned char uc = 255;
 
   printf("\n");

   printf("char: \t\t\t%2d\n", (int) sizeof c);
   printf("unsigned char: \t\t%2d\n", (int) sizeof uc);

   printf("short: \t\t\t%2d\n", (int) sizeof(short));
   printf("unsigned short: \t%2d\n", (int) sizeof(unsigned short));
   printf("int: \t\t\t%2d\n", (int) sizeof(int));
   printf("unsigned int: \t\t%2d\n", (int) sizeof(unsigned int));

   printf("long: \t\t\t%2d\n", (int) sizeof(long));
   printf("unsigned long: \t\t%2d\n", (int) sizeof(unsigned long));
   printf("long long: \t\t%2d\n", (int) sizeof(long long));
   printf("unsigned long long: \t%2d\n", (int) sizeof(unsigned long long));
   
   printf("float: \t\t\t%2d\n", (int) sizeof(float));
   printf("double: \t\t%2d\n", (int) sizeof(double));
   printf("long double: \t\t%2d\n", (int) sizeof(long double));
   
   printf("_Bool: \t\t\t%2d\n", (int) sizeof(_Bool));  // C99-Boolescher Typ

   printf("\n");
 
   return 0;
 }
 