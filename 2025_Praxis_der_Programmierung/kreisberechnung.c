#include <stdio.h>

int main() {
  double pi = 3.14159265359;
  int r;

  printf("Geben Sie den Radius ein: ");
  scanf("%d", &r);

  double f = pi * r * r;
  double u = 2 * pi * r;

  printf("Für einen Kreis mit Radius %d gilt:\n", (short)r);
  printf("Fläche: %f\n", f);
  printf("Umfang: %f\n", u);

  return 0;

}
