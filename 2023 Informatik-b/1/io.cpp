/* Informatik B - Sommersemester 2022
Vorlesung am 21.04.2022
Katharina Klost

Beispiele zur Ein-und Ausgabe
*/
#include <iostream>

int main(){
  float a;
  //Ohne std::endl gibt es keinen Zeilenumbruch
  std::cout << "Gebe eine Zahl ein: ";
  // mit std::cin wird ein Wert von der Konsole gelesen und wenn möglich
  // in die passende Variable geschrieben
  std::cin >> a;
  // Das Ergebnis von Ausdrücken kann auf der Konsole ausgegeben werden
  std::cout << "a: " << a << std::endl;
  std::cout << "a mal zwei: " << a*2 << std::endl;
}
