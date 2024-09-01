/* Informatik B - Sommersemester 2023
Vorlesung am 26.04.2023
Katharina Klost

Beispiele zur Deklaration und Initialisierung von Variablen
*/

#include <iostream>

int main(){
  int num1;
  //num1 ist nur deklariert und nicht initialisiert und daher ist
  //der Inhalt hier nicht definiert (irgendein Wert)
  std::cout << num1 << std::endl;

  num1 = 10;
  
  std::cout << num1 << std::endl;
}
