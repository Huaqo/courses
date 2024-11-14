/* fehler.c
 *  
 *  Ein Programm, dass Compilerfehler,
 *  Laufzeitfehler und logische Fehler demonstriert.
 */

#include <stdio.h>

int main() {

  int num1, num2;
  num1 = 0;
  num2 = 1;
  int temp;

  printf("Der Quotient der Variablen ist: "); //Sytnaxfehler ; einfügen
  printf("%d\n", num1/num2);
  printf("\n");		   //  Syntaxfehler: Anführungzeichen fehlten

  printf("Jetzt werden die Variablenwerte vertauscht.\n");

  // Dies muss korrigiert werden. (logischer Fehler!!!)
    temp = num1;
    num1 = num2;
    num2 = temp;

  printf("Der Quotient der Vaiablen ist nun: ");
  printf("%d\n", num1/num2);

  return 0;
}
