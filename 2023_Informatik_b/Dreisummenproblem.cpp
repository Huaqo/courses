#include <vector>
#include <iostream>

void bubbleSort(std::vector<int>& zahlen) {
    unsigned n = zahlen.size();
    for (unsigned i = 0; i < n - 1; ++i) {
        for (unsigned j = 0; j < n - i - 1; ++j) {
            if (zahlen[j] > zahlen[j + 1]) {
                std::swap(zahlen[j], zahlen[j + 1]);
            }
        }
    }
}

bool binareSuche(std::vector<int>& zahlen, int start, int ende, int ziel) {
    while (start <= ende) {
        int mitte = start + (ende - start) / 2;
        if (zahlen[mitte] == ziel) {
            return true;
        } else if (zahlen[mitte] < ziel) {
            start = mitte + 1;
        } else {
            ende = mitte - 1;
        }
    }
    return false;
}

/*
Funktion: sucheTriplets(std::vector<int>& X)
Voraussetzungen:
- Die Funktion nimmt als Argument einen Vektor von Ganzzahlen (std::vector<int>).
- Der Vektor kann leer sein oder eine beliebige Anzahl von Ganzzahlen enthalten.
- Die Zahlen im Vektor können positiv, negativ oder null sein.
- Es wird angenommen, dass die Größe des Vektors in einem Bereich liegt, der für die verfügbare Speicherkapazität und Rechenleistung des Systems handhabbar ist.

Ergebnis:
- Die Funktion gibt kein Ergebnis zurück (void Rückgabetyp).
- Die Funktion druckt alle Tripel von Zahlen in der Eingabesequenz aus, für die die Summe der ersten beiden Zahlen gleich der dritten Zahl ist. Jedes Tripel wird in der Form "(a, b, c)" ausgegeben, wobei "a + b = c" gilt.
- Wenn keine solchen Tripel existieren, gibt die Funktion nichts aus.

Effekte:
- Die Funktion sortiert den Eingabevektor. Daher wird der Zustand des Eingabevektors geändert: die Elemente werden in aufsteigender Reihenfolge angeordnet.
- Die Funktion hat keinen weiteren Seiteneffekt auf den Zustand des Programms. Sie ändert keine globalen Variablen und hat keine Auswirkungen auf den Zustand des Systems außerhalb des Programms.
- Die Funktion kann eine beträchtliche Menge an Ausgabe produzieren, wenn viele gültige Tripel existieren. Dies könnte die Leistung des Systems beeinträchtigen, wenn die Ausgabe in eine Datei umgeleitet wird oder wenn das System über begrenzte Ressourcen für die Ausgabeverwaltung verfügt.
- Die Funktion verwendet zusätzlichen Speicher für das unordered_set, das zur Speicherung der Elemente des Eingabevektors verwendet wird. Die Menge des benötigten Speichers ist proportional zur Größe des Eingabevektors.
*/

void findeTripel(std::vector<int>& zahlen) {
    bubbleSort(zahlen);

    for (unsigned i = 0; i < zahlen.size(); ++i) {
        for (unsigned j = i + 1; j < zahlen.size(); ++j) {
            int summe = zahlen[i] + zahlen[j];
            if (binareSuche(zahlen, 0, zahlen.size() - 1, summe)) {
                std::cout << "(" << zahlen[i] << ", " << zahlen[j] << ", " << summe << ")\n";
            }
        }
    }
}

int main() {
    std::vector<int> zahlen = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    findeTripel(zahlen);
    return 0;
}