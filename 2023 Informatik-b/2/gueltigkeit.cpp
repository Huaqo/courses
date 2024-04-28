/* Informatik B - Sommersemester 2023
Vorlesung am 26.04.2023
Katharina Klost

Beispiele zu Gültigkeitsbereichen
*/

#include <iostream>

int main (){


  int variable1;
  std::cin >> variable1;

  float variable3;

  if (variable1 == 10){
    float varible2 = 9.1;
    std::cout << varible2 << std::endl;
  }
  else{
    // neue Deklaration von variable3, überschattet die andere variable3
    float variable3 = 10.1;
    std::cout << variable3 << std::endl;
  }
  /*
  variable2 ist nur in der ersten if-Bedingung definiert und kann daher
  hier nicht verwendet werden.
  */
  //std::cout << variable2 << std::endl;

  //Da diese variable3 nur deklariert aber nicht initialisiert wurde,
  // ist der Inhalt hier beliebig
  std::cout << variable3 << std::endl;

  variable3 = 1.1;


  while(variable1<10){
    //wird immer wieder neu deklariert
    int variable3 = variable1;
    std::cout << "variable3 in schleife: " << variable3 << std::endl;
    variable1++;
   }
   std::cout << "variable1 nach erster Schleife: " << variable1 << std::endl;
   std::cout << "variable3 nach erster Schleife: " << variable3 << std::endl;

}
