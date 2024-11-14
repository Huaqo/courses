/* typengroesse.c
 * 
 * Bestimmung der Groesse der einfachen typen mit sizeof
 */

#include <stdio.h>

int main() {
  char c = 127;
  unsigned char uc = 255;

  printf("\n");

  //Ganzzahltypen
  printf("char: \t\t%2d\n", (int) sizeof c);
  printf("uns. char: \t%2d\n", (int) sizeof uc);

  printf("short: \t\t%2d\n", (int) sizeof (short));
  printf("uns. short: \t%2d\n", (int) sizeof (unsigned short));

  printf("int: \t\t%2d\n", (int) sizeof (int));
  printf("uns. int: \t%2d\n", (int) sizeof (unsigned int));

  printf("long: \t\t%2d \n", (int) sizeof (long));
  printf("uns. long: \t%2d \n", (int) sizeof (unsigned long));

  printf("long long: \t%2d \n", (int) sizeof (long long));
  printf("uns. long long: %2d \n", (int) sizeof (unsigned long long));

  // Gleitpunkttypen
  printf("float: \t\t%2d\n", (int) sizeof (float));
  printf("double: \t%2d\n", (int) sizeof (double));
  printf("long double: \t%2d\n", (int) sizeof (long double));


  printf("\n");

  return 0;
}
