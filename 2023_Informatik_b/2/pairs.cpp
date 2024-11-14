/* Informatik B - Sommersemester 2023
Vorlesung am 28.04.2023
Katharina Klost

Beispiele zu pairs
*/

#include <iostream>

int main(){
  std::pair<std::string, int> mein_paar = {"Hallo", 1234};

  std::cout << "Erster Eintrag vom mein_paar: " <<  mein_paar.first << std::endl;
  std::cout << "Zweiter Eintrag vom mein_paar: " << mein_paar.second << std::endl;

  mein_paar.first = "Test";

  std::cout << "Neuer erster Eintrag: " << mein_paar.first << std::endl;
}
