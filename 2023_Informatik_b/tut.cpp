#include <iostream>
#include <string>

int main() {

    // Aufgabe 1a

    int x;
    std::cin >> x;
    int y = 1;

    for (int i = x; i > 0; i--) {
        y = y * i;
    }

    std::cout << y << std::endl;

    // Aufgabe 1b

    int z = 1;
    int l = x;
    while (l > 1) {
        z = z * l;
        l--;   
    }

    std::cout << z << std::endl;

    // Aufgabe 2

    // 1 Load 7
    // 2 Write 6
    // 3 Add 7
    // 4 Jump 2
    // 5 Return
    // 6 0
    // 7 3

    // Aufgabe 3

    std::string artist;
    std::cout << "Wer ist dein Lieblingsartist?" << std::endl;
    std::cin >> artist;
    std::cout << "Dein Lieblingsartist ist " << artist << std::endl;
    
    std::string album;
    std::cout << "Was ist dein Lieblingsalbum?" << std::endl;
    std::cin >> album;
    std::cout << "Dein Lieblingsalbum ist " << album << std::endl;

    int zahl;
    std::cout << "Was ist deine Lieblingszahl?" << std::endl;
    std::cin >> zahl;
    int quad = zahl * zahl;
    std::cout << "Deine Lieblingszahl ist " << quad << std::endl;
    
}


