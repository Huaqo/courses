/*
clear && g++ -std=c++14 -Wall -Wextra -Werror -pedantic ./w5/turn_min.cpp -o ./bin/turn_min && ./bin/turn_min

Bei jedem Durchlauf halbieren wir die Größe der Eingabe (also n/2), 
und wir müssen alle Elemente betrachten, um das Minimum zu finden (also O(n))
Daraus folgt die Rekursionsgleichung: T(n) = T(n/2) + O(n) 

Da wir log(n) Runden benötigen und in jeder Runde O(n) Operationen durchführen 
beträgt die Gesamtlaufzeit des Algorithmus O(n log n) 
*/

#include <iostream>
#include <vector>

std::pair<int, int> TurnMin(std::vector<int>& vec);

int main() {
    std::vector<int> vec = {7, 3, 2, 5, 10, -5, 4, 6,2,2,3,4,4,5,6,76,7,78};
    auto ergebnis = TurnMin(vec);
    std::cout << "Die Gewinnerzahl, nach " << ergebnis.first << " Runden, ist: " << ergebnis.second << std::endl;
}

std::pair<int, int> TurnMin(std::vector<int>& vec) {
    int runde = 0;
    while (vec.size() > 1) {
       std::vector<int> gewinner; 
        for (unsigned i = 0; i < vec.size(); i += 2) {
                if (vec[i] < vec[i + 1]) {
                    gewinner.push_back(vec[i]);
                } 
                else {
                    gewinner.push_back(vec[i + 1]);
                }
        }
        vec = gewinner;
        runde++;
    }
    return {runde, vec[0]};
}