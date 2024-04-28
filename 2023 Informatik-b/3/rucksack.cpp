#include <iostream>
#include <vector>
#include <algorithm>

/*
Voraussetzung: keine
Effekt: Keiner
Ergebnis: Eine größtmögliche Auswahl von Elementen, deren Summe von Gewichten unter bound ist,
ist geliefert.
*/
std::vector<unsigned> rucksack_einfach(unsigned bound, std::vector<unsigned> gewichte);

/*
Voraussetzung: Der vector hat mindestens ein Element
Effekt: Die Elementen von vec im geschlossenen Intervall [start, end] werden ausgegeben
Ergebnis: keins
*/
void gebe_aus(std::vector<unsigned>& vec, unsigned start, unsigned end);

std::vector<unsigned> rucksack_einfach(unsigned bound, std::vector<unsigned> gewichte){
  std::vector<unsigned> rucksack_inhalt ={};
  std::sort(gewichte.begin(), gewichte.end());
  for(unsigned i = 0; i<gewichte.size() && bound >= gewichte[i]; i++){
    bound = bound - gewichte[i];
    rucksack_inhalt.push_back(gewichte[i]);
  }
  return rucksack_inhalt;
}

void gebe_aus(std::vector<unsigned>& vec, unsigned start, unsigned end){
  if(end>vec.size() || start >= end){
    std::cout << vec.size() << " " << end << std::endl;
    return;
  }
  std::cout << vec[start];
  for(unsigned k=start+1; k<end; k++){
    std::cout << ", " << vec[k];
  }
  std::cout << std::endl;
}

int main(){
  std::vector<unsigned> gewichte = {3,7,4,17,5,6};
  std::vector<unsigned> einfach_erg = rucksack_einfach(12, gewichte);
  gebe_aus(einfach_erg, 0, einfach_erg.size());

}
