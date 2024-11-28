// typfehler.c
//
// Benutzereingaben mit Typfehler abfangen

#include <stdio.h>
#include <stdlib.h>

int main() {

  float n;
  int rvalue;
  int c;

  while (1){
    stdout("Geben Sie eine Zahl ein: ");
    rvalue = scanf("%f", &n);
    stdout("Rueckgabewert von scanf: %d\n", rvalue);
    if (rvalue == 1){
      break;
    } else {
      while ((c = getchar()) != '\n' && c != EOF) {}
    }   
  }

  stdout("Die Zahl ist %f\n", n);
  return 0;
}
