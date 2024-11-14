/* Informatik B - Sommersemester 2023
Vorlesung am 28.04.2023
Katharina Klost

Beispiele zu structs
*/

#include <iostream>
#include <vector>


struct studi{
  std::string name;
  int matrikelnummer;
  bool bachelor;
  std::string studienfach;
};

struct studi2{
   std::string name;
   int matrikelnummer;
   bool bachelor;
   std::string studienfach;
};

int main(){
  studi luca = {"Luca Muster", 42, true, "Informatik"};
  studi mo = {"Mo", 112, true, "Bioinformatik"};
  studi alex = {"Alex Müller", 4711, false, "Informatik"};

  //mit dem . kann auf ein Feld zugegriffen werden.
  std::cout << mo.name << std::endl;
  mo.bachelor = false;
  std::cout << mo.bachelor << std::endl;

  // wegen der Wertsemantik werden die Einträge beim zuweisen kopiert
  studi luca2 = luca;

  luca2.name = "Luca Mustermann";
  std::cout << luca2.name << std::endl;
  std::cout << luca.name << std::endl;
  studi2 luca3;
  //nur structs vom gleichen Typ können einander zugewiesen werden
  //luca3 = luca;

  //structs können auch in vectoren gespeichert werden
  std::vector<studi> tutorium ={luca,mo};
  tutorium.push_back(alex);
}
