/* typengroesse.c
 * 
 * Bestimmung der Groesse der einfachen typen mit sizeof
 */

#include <stdio.h>

int main() {
  char c = 127;
  unsigned char uc = 255;

  printf("\n");
  printf("char: \t\t%2d\n", (int) sizeof c);
  printf("short: \t\t%2d\n", (int) sizeof (short));
  printf("int: \t\t%2d\n", (int) sizeof (int));
  printf("long: \t\t%2d\n", (int) sizeof (long));
  printf("long long: \t%2d\n", (int) sizeof (long long));
  printf("float: \t\t%2d\n", (int) sizeof (float));
  printf("double: \t%2d\n", (int) sizeof (double));
  printf("long double: \t%2d\n", (int) sizeof (long double));
  printf("_Bool: \t\t%2d\n", (int) sizeof (_Bool));
  printf("\n");

  return 0;
}
