/* Informatik B - Sommersemester 2022
Vorlesung am 21.04.2022
Katharina Klost

Beispiele zu arithmetischen Operationen
*/

#include <iostream>

int main(){
  /* Unterschiede zwische Post- und Preinkrement:

  Beim Postinkrement wird der Wert *erst* ausgewertet und dann erhöht,
  daher wird in der zweiten Zeile noch einmal 2 und erst in der dritten
  Zeile 3 ausgegeben.
  Bei Preinkrement wird erst erhöht und dann ausgegeben, daher wird in der
  vierten und fünften Zeile 4 ausgegeben.
  */
  int n =2;
  std::cout << "Vor Postinkrement " << n << std::endl;
  std::cout << "Postinkrement " << n++ << std::endl;
  std::cout << "Nach Postinkrement " << n << std::endl;
  std::cout << "Preinkrement " << ++n << std::endl;
  std::cout << "Nach Preinkrement " << n << std::endl;

  // += als vereinfachte Schreibweise für n = n + 3;
  n+=3;
  std::cout << n << std::endl;

  // k und k1 haben auf Grund der Bindunststärken den gleichen Wert
  int k1 = 7*4 + ++n/4;
  int k = (7*4)+ ((++n) / 4);
  std::cout << "k1: "  << k1 << ", k: " <<k << std::endl;

}
