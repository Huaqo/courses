/* Informatik B - Sommersemester 2023
Vorlesung am 26.04.2023
Katharina Klost

Beispiele zu Kontrollstrukturen
*/

#include <iostream>



int main(){

  /*
  Beispiel für eine komplexere if-then-else Abfrage.
  */
  int num ;
  std::cout << "Gebe eine Zahl für den if test ein: " ;
  std::cin >> num;
  if (num == 2) {
   num = num*2;
  }
  else if (num > 1 && num <5) {
   num= num*3;
  }
  else if (num >=10){
   num = num*4;
  }
  else{
   num = num*5;
  }
  std::cout << num << std::endl;

  /*
  Beispiel für eine switch-case umgebeung
  Die einzelnen case Abschnitte sind keine Blöcke, daher gibt es ohne
  break einen fallthrough und es können keine Variablen deklariert werden.

  Bei modernen Compilern sollte es keine Unterschiede in der Performance
  von semantisch gleichen if-Bedingungen und switch-case Umgebungen geben
  */
  int num1;
  std::cout << "Gebe eine Zahl für den switch-case test ein: ";
  std::cin >> num1;
  switch(num1){
    case 1:
       std::cout << "num ist 1" << std::endl; //kein break -> fallthrough
    case 2:
       std::cout << "num ist 1 oder 2" << std::endl;
       break;
    case 3:
       std::cout << "num ist 3" << std::endl;
       break;
    case 4:
       std::cout << "num ist 4" << std::endl;
       break;
    default:
       std::cout << "num ist nicht 1,2,3 oder 4" << std::endl;
  }

/*
Beispiel für eine for-schleife, in <Anweisung3> und <Anweisung1> (vgl. Folien)
Können auch mehrere Anweisungen mit , getrennt stehen.
*/
int num_for = 3;
for (int counter=1; counter <=4; counter=counter+1, num_for ++) {
    num_for= num_for*num_for;
    std::cout << "num_for in iteration " << counter << ": "<< num_for << std::endl;
}
std::cout << "num_for nach Schleife: " << num_for << std::endl;

/*
Beispiel für eine while-schleife
*/
  int num_while = 2;
  int goal = 300;
  while (num_while < goal) {
     num_while = num_while * num_while;
     std::cout << "num_while after *: " << num_while << std::endl;
  }
  std::cout << num_while << std::endl;
}
