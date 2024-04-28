/* Informatik B - Sommersemester 2023
Vorlesung am 28.04.2023
Katharina Klost

Beispiele zu enums
*/

#include <iostream>

//Ein enum für Wochentage
enum class Wochentag{
  Montag,
  Dienstag,
  Mittwoch,
  Donnerstag,
  Freitag,
  Samstag,
  Sonntag
};


//Ein enum für Farben
enum class Farbe {rot, gruen, blau, orange};

// Ein enum für die Zustände von Ampeln
enum class Ampel {gruen, gelb, rot, gelb_rot};

int main(){
  // der Name des enums muss immer angegeben werden, da es Felder mit
  // dem gleichen Namen in verschiedenen enums geben kann
  Ampel ampel1 = Ampel::gruen;
  //enums und switch-case sind eine beliebte Kombination
  switch(ampel1){
    case Ampel::gruen:
      std::cout << "Kann fahren" << std::endl;
      break;
    case Ampel::gelb:
      std::cout << "Achtung" << std::endl;
      break;
    case Ampel::rot:
      std::cout << "Stop" << std::endl;
      break;
    case Ampel::gelb_rot:
      std::cout << "Achtung" << std::endl;
      break;
    default:
      std::cout <<"Irgendwas anderes" << std::endl;
      break;
   }

  int number;
  std::cout << "Gebe einen Tag ein, (Montag=1,..., Sonntag =7)";
  std::cin >> number;
  // da enums intern mit Zahlen dargestellt werden, können Zahlen
  // explizit in eine enum umgewandelt werden
  Wochentag tag = static_cast<Wochentag>(number-1);

  // werden enums verglichen gilt die Reihenfolge in der Definition
  if (tag >= Wochentag::Samstag){
    std::cout << "Es ist Wochenende :)" << std::endl;
  }
  else{
    std::cout << "Es ist ein Arbeitstag :(" << std::endl;
  }

}
