/* Informatik B - Sommersemester 2023
Vorlesung am 28.04.2023
Katharina Klost

Beispiele zu Strings
*/

#include <iostream>
#include <string>

int main(){
  std::string ein_string = "Hallo";
  char stelle2 = ein_string[2];
  std::cout << "An index 2 steht: " << stelle2 << std::endl;
  ein_string[2]= 'x';
  std::cout << "Stelle 2 verändert: " << ein_string << std::endl;
  ein_string = ein_string + " Welt!";
  std::cout << ein_string << std::endl;
  std::cout << ein_string + 'c' << std::endl;

  std::cout << "Der String \"" << ein_string << "\" hat " << ein_string.length() << " Zeichen" << std::endl;

}
