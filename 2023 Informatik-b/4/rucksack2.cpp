// g++ -std=c++14 -Wall -Wextra -Werror -pedantic ./w4/rucksack2.cpp -o ./bin/rucksack2

#include <iostream>
#include <vector>

struct Gegenstand {
    int gewicht;
    int wert;

    Gegenstand(int g, int w) : gewicht(g), wert(w) {}
};

int rucksackWert(const std::vector<Gegenstand>& gegenstaende, int kapazitaet, int index) {
    if (index < 0 || kapazitaet == 0) {
        return 0;
    }

    if (gegenstaende[index].gewicht > kapazitaet) {
        return rucksackWert(gegenstaende, kapazitaet, index - 1);
    } else {
        int wert1 = rucksackWert(gegenstaende, kapazitaet, index - 1);
        int wert2 = gegenstaende[index].wert + rucksackWert(gegenstaende, kapazitaet - gegenstaende[index].gewicht, index - 1);
        return (wert1 > wert2) ? wert1 : wert2;
    }
}

std::vector<Gegenstand> rucksackGegenstaende(const std::vector<Gegenstand>& gegenstaende, int kapazitaet, int index) {
    if (index < 0 || kapazitaet == 0) {
        return std::vector<Gegenstand>();
    }

    if (gegenstaende[index].gewicht > kapazitaet) {
        return rucksackGegenstaende(gegenstaende, kapazitaet, index - 1);
    } else {
        int wert1 = rucksackWert(gegenstaende, kapazitaet, index - 1);
        int wert2 = gegenstaende[index].wert + rucksackWert(gegenstaende, kapazitaet - gegenstaende[index].gewicht, index - 1);

        if (wert1 > wert2) {
            return rucksackGegenstaende(gegenstaende, kapazitaet, index - 1);
        } else {
            std::vector<Gegenstand> ausgewaehlteGegenstaende = rucksackGegenstaende(gegenstaende, kapazitaet - gegenstaende[index].gewicht, index - 1);
            ausgewaehlteGegenstaende.push_back(gegenstaende[index]);
            return ausgewaehlteGegenstaende;
        }
    }
}

int main() {
    std::vector<Gegenstand> gegenstaende;
    gegenstaende.push_back(Gegenstand(2, 10));
    gegenstaende.push_back(Gegenstand(3, 15));
    gegenstaende.push_back(Gegenstand(5, 20));
    gegenstaende.push_back(Gegenstand(7, 25));

    int kapazitaet = 10;

    int optimalerWert = rucksackWert(gegenstaende, kapazitaet, gegenstaende.size() - 1);
    std::cout << "Optimaler Wert: " << optimalerWert << std::endl;

    std::vector<Gegenstand> optimaleGegenstaende = rucksackGegenstaende(gegenstaende, kapazitaet, gegenstaende.size() - 1);
    std::cout << "Optimale Gegenstände: ";
    for (const auto& gegenstand : optimaleGegenstaende) {
        std::cout << "(" << gegenstand.gewicht << ", " << gegenstand.wert << ") ";
    }
    std::cout << std::endl;

    return 0;
}
