/* Informatik B - Sommersemester 2023
Vorlesung am 28.04.2023
Katharina Klost

Beispiele zu vector
*/

#include <iostream>
#include <vector>

int main(){

  std::vector<int> zahlen = {10,4,20,24,7,34,1,55,34,17,4};

//vector mit 10 Boolean einträgen, die alle 0 bzw false sind
  std::vector<bool> wahrheitswerte(10);

//vector mit 5 Einträgen, alle sind "Mo"
  std::vector<std::string> montage(5,"Mo");

std::cout << zahlen[3] << std::endl;

zahlen[3] = 100;

std::cout << zahlen[3] << std::endl;
std::cout << zahlen.size() << std::endl;
zahlen.push_back(1234);
std::cout << zahlen.size() << std::endl;


 //ACHTUNG! Kein Fehler, wenn wir auf Daten außerhalb des vector zugreifen
 std::cout << zahlen[zahlen.size()] << std::endl;


 //Wird auf einen Index größer oder gleich size() des vector
 // zugegriffen gibt es undefiniertes Verhalten.
 // Es kann ein Wert zurückgegeben werde, oder ein Speicherzugriffehler
 // ausgegeben werden.
 // Wird ein Wert außerhalb der Grenzen zugewiesen, wird die Größe
 // des vector nicht angepasst
 std::cout << zahlen[100000] << std::endl;
 std::cout << zahlen.size() << std::endl;
}
