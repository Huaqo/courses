#include <iostream>
#include <string>
#include <vector>

enum Abteilung {
    IT,
    FINANZ,
    MARKETING,
    PERSONAL,
    PRODUKTION
};

struct angestellter {
    std::string name;
    int personalnummer;
    Abteilung abteilung;
    double gehalt;
};

angestellter angestellter_eingeben();
std::vector<angestellter> abteilung_check(std::vector<angestellter> vec, Abteilung abt);

int main() {

    angestellter beispielAngestellter = angestellter_eingeben();

    std::cout << std::endl << "Angestellter:" << std::endl;
    std::cout << "Name: " << beispielAngestellter.name << std::endl;
    std::cout << "Personalnummer: " << beispielAngestellter.personalnummer << std::endl;
    std::cout << "Abteilung: " << beispielAngestellter.abteilung << std::endl;
    std::cout << "Gehalt: " << beispielAngestellter.gehalt << std::endl;

    angestellter kollege1 = {"Hans Wurst", 678, PRODUKTION, 3550.5};
    angestellter kollege2 = {"Scrooge McDough", 022, FINANZ, 4702};
    angestellter kollege3 = {"Ninja Scripter", 337, IT, 2500};
    angestellter kollege4 = {"Snake Oil", 888, MARKETING, 1800};
    angestellter kollege5 = {"Overlord", 007, PERSONAL, 5600};

    std::vector<angestellter> belegschaft = {kollege1, kollege2, kollege3, kollege4, kollege5};
    std::vector<angestellter> filtered = abteilung_check(belegschaft, beispielAngestellter.abteilung);

    // Display filtered employees or a message if no matching employees are found.
    if (!filtered.empty()) {
        for (const auto& ang : filtered) {
            std::cout << "Filtered employee: " << ang.name << std::endl;
        }
    } else {
        std::cout << "No matching employees found." << std::endl;
    }

    return 0;   
}

std::vector<angestellter> abteilung_check(std::vector<angestellter> vec, Abteilung abt) {
std::vector<angestellter> division;
    for (const auto &ang : vec) {
        if (ang.abteilung == abt) {
            division.push_back(ang);
        }
    }
    return division;
}

angestellter angestellter_eingeben() {
    angestellter neuerAngestellter;
    int abteilungWahl;
    std::cout << "Name: ";
    std::getline(std::cin, neuerAngestellter.name);
    std::cout << "Personalnummer: ";
    std::cin >> neuerAngestellter.personalnummer;

    std::cout << "Abteilung (0: IT, 1: FINANZ, 2: MARKETING, 3: PERSONAL, 4: PRODUKTION): ";
    std::cin >> abteilungWahl;
    neuerAngestellter.abteilung = static_cast<Abteilung>(abteilungWahl);

    std::cout << "Gehalt: ";
    std::cin >> neuerAngestellter.gehalt;
    std::cin.ignore();

    return neuerAngestellter;
}
