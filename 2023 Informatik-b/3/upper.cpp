#include <iostream>
#include <string>

/*
- Voraussetzungen: str ist ein String
- Ergebnis: str ist ein String, der nur aus Großbuchstaben besteht
- Seiteneffekte: keine

Der Rückgabetyp ist string, weil wir einen neuen String zurückgeben wollen, der nur aus Großbuchstaben besteht.
Der Parameter ist string, weil wir einen String übergeben wollen, bei dem wir die Buchstaben in Großbuchstaben umwandeln wollen.

*/
std::string upper(std::string str);

int main() {

    std::cout << "Bitte gebe einen String ein der groß geschrieben werden soll: ";
    std::string s;
    std::getline(std::cin, s);
    std::cout << "Hier ist dein neuer String: " << upper(s) << std::endl;

}

std::string upper(std::string str) {
    for (unsigned i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }

    return str;

}
