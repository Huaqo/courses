#include <stdio.h>

int main() {
  int i;
  printf("\n");


  // 12, 10, ... , 0
  for(i = 12; i >= 0; i = i - 2) {
    printf("%d", i);
    if (i > 0)
      printf(", ");
  }
  printf("\n\n");


  // -1, -3, ..., -13
  i = -1;
  while (i > -14) {
    printf("%d", i);
    if (i > -13)
      printf(", ");
    i = i-2;
  }
  printf("\n\n");


  // Quadratzahlen 0 ... 81
  do {
    printf("%d", i*i);
    if (i < 9)
      printf(", ");
    i++;  // Inkrementiere i
  } while(i<=9);
  printf("\n\n");

  return 0;
}
