/*
Arbeiten mit Dateien in C++:
- Datei öffnen
- Datei lesen
- Datei schließen
Quelle: https://cplusplus.com/reference/fstream/

histogram() ist eine Funktion, die ein Histogramm der Buchstaben in einem String erstellt.
- Vorraussetzungen: str ist ein String
- Ergebnis: hist ist ein Vektor, der die Häufigkeit der Buchstaben in str enthält
- Seiteneffekte: keine
*/

#include <iostream>
#include <string>
#include <fstream> 
#include <vector>

std::vector<int> histogram(std::string str);

int main() {
    
    std::ifstream inputFile("moby.txt");

    std::string content, line;
    
    while (std::getline(inputFile, line)) {
        content += line;
    }

    std::vector<int> hist = histogram(content);
    
    for (unsigned i = 0; i < 26; i++) {
        if (hist[i] > 0) { 
            std::cout << static_cast<char>('a' + i) << ": " << hist[i] << ", ";
        }
    }
    
    for (unsigned i = 26; i < hist.size(); i++) { // Loop for uppercase letters
        if (hist[i] > 0) {
            std::cout << static_cast<char>('A' + i - 26) << ": " << hist[i] << ", ";
        }
    }

    std::cout << std::endl;

    inputFile.close();

    return 0;

}

std::vector<int> histogram(std::string str) {
    
    std::vector<int> hist(52, 0);
    
    for (unsigned i = 0; i < str.length(); i++) {
        
        if (str[i] >= 'a' && str[i] <= 'z') {
            hist[str[i] - 'a']++;
        } 

        else if (str[i] >= 'A' && str[i] <= 'Z') {
            hist[str[i] - 'A' + 26]++;
        }

    }

    return hist;
}
