#include <iostream>
#include <string>

/*
- Voraussetzungen: str ist ein String, charToReplace und replacementChar sind Zeichen
- Ergebnis: str ist ein String, in dem alle Vorkommen von charToReplace durch replacementChar ersetzt wurden
- Seiteneffekte: keine

Der Rückgabetyp ist string, weil wir einen neuen String zurückgeben wollen, in dem alle Vorkommen von charToReplace durch replacementChar ersetzt wurden.
Die Parameter sind char, weil wir nur ein Zeichen ersetzen wollen.

*/
std::string repl(std::string str, char charToReplace, char replacementChar);

int main() {
    
    std::cout << "Bitte gebe einen String ein bei dem du die Zeichen ersetzen willst: ";
    std::string s;
    std::getline(std::cin, s);
    
    std::cout << "Bitte gebe das Zeichen ein, welches zu ersetzen möchtest: ";
    char a;
    std::cin >>  a;
    
    std::cout << "Bitte gebe das Zeichen ein, durch welches du ersetzen möchtest: ";
    char b;
    std::cin >> b;

    std::cout << "Dein neuer String ist: " << repl(s, a, b) << std::endl;

}

std::string repl(std::string str, char charToReplace, char replacementChar) {
    
    for (unsigned i = 0; i < str.length(); i++) {
        if (str[i] == charToReplace) {
            str[i] = replacementChar;
        }
    }

    return str;
    
}