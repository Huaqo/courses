// typfehler.c
//
// Benutzereingaben mit Typfehler abfangen

#include <stdio.h>
#include <stdlib.h>

int main() {

  float zahl;
  int status;
  char c;


  while (1) {
		printf("Geben Sie eine Zahl ein: ");
		status = scanf("%f", &zahl); 
		if (status != 0){
			break;
		}
  do {
    // 
    c = getchar();
    }
    while (c != '\n');
    printf(" Typfehler bei Benutzeingabe");
  }

  printf("Die Zahl ist %f\n", zahl);
  return 0;
}
