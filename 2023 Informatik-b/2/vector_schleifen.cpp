/* Informatik B - Sommersemester 2023
Vorlesung am 28.04.2023
Katharina Klost

Beispiele zu vector und schleifen
*/

#include <iostream>
#include <vector>

int main(){
  std::vector<int> zahlen = {10,4,20,24,7,34,1,55,34,17,4};
  int sum = 0;

  //Schleife läuft durch alle Indizes des vector und summiert die Einträge auf
  for (unsigned int i = 0; i<zahlen.size(); i++){
    sum += zahlen[i];
  }

  std::cout << "Summe des vector: " << sum << std::endl;

  //Verschachtelte Schleife geht durch alle Paare i,j mit i<j und i,j < zahlen.size()
  std::cout << "Alle paare von Werten: "  << std::endl;
  for(unsigned i = 0; i< zahlen.size(); i++){
    for(unsigned j = i+1; j<zahlen.size(); j++){
      std::cout << "(" << zahlen[i] << ", " << zahlen[j] <<")" << std::endl;
    }
  }

}
