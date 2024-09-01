/* Informatik B - Sommersemester 2023
Vorlesung am 28.04.2023
Katharina Klost

Beispiele zur Kombination von zusammengesetzen Datentypen
*/

#include <iostream>
#include <vector>
#include <string>

enum class wohnart{HAUS,WOHNUNG};

struct person{
  std::string name;
  wohnart wa;
  unsigned telefonnummer;
};

int main(){

  // eine person hat unter anderem einen enum als Feld und kann in einem
  // vector gespeichert werden
  std::vector<person> telefonbuch = {};

  for(unsigned i=0; i< 30; i++){
    person p = {"Name"+std::to_string(i) , static_cast<wohnart>((3*i-1)%2), (i*300+23+i/2)};
    telefonbuch.push_back(p);
}

person eintrag;
for(unsigned i= 0 ; i< telefonbuch.size(); i++){
  eintrag = telefonbuch[i];
  if(eintrag.wa == wohnart::HAUS){
    std::cout <<  eintrag.name << " wohnt in einem Haus" << std::endl;
  }
}

std::string query;
std::cout << "Welcher Name soll gesucht werden? " ;
std::cin >> query;
bool found = false;
for (unsigned i= 0; i< telefonbuch.size()&&!found; i++){
  eintrag = telefonbuch[i];
  if (eintrag.name == query){
    std::cout << eintrag.name << " hat Telefonnummer: "<< eintrag.telefonnummer << std::endl;
    found = true;
  }
}
if (!found){
  std::cout << query << " ist nicht im Telefonbuch enthalten" << std::endl;
}

}
