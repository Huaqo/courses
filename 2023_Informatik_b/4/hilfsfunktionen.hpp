/* Informatik B - Sommersemester 2023
Vorlesung am 12.05.2023
Katharina Klost

Headerdatei zu den Hilfsfunktionen zum Sortieren
*/

#include <vector>
// #include "telefonbuch.hpp"

namespace hf{
/*
Voraussetzung: 0 <= start <= end < vec.elems()
Ergebnis:      Keins
Effekt:        Gibt die Elemente des Vektors im Intervall [start,end) aus
*/
void gebe_aus(std::vector<int>& elems, unsigned start, unsigned end);

/*
Voraussetzung: 0<=start<=end < vec.elems()
Ergebnis:      Ein vector, mit alle Elemente im Intervall [start, end)
Effekt:        Keiner
*/
std::vector<int> copy(std::vector<int>& elems, unsigned start, unsigned end);

/*
Voraussetzung: 0 <= i,j <= elems.size()
Ergebnis:      Keins
Effekt:        Tauscht die Einträge and Position i und j
*/
void swap(std::vector<int>& elems, unsigned i, unsigned j);




/*
Voraussetzung: Es gilt 0 <= start <= end < elems.size()
Effekt: Keiner
Ergebni: Index des kleinesten Elements zwischen start und end
*/
unsigned minimumIndex(std::vector<int>& elems, unsigned start, unsigned end);


/*
Voraussetzung: left < right
Ergebnis: Eine Zufallszahl zwischen left(inklusive) und right (exklusive)
Effekt: Keiner
*/
int zufall(int left, int right);


std::vector<int> sortiertes_array(unsigned size, bool aufsteigend);

std::vector<int> zufalls_array(unsigned size);

void test();
}
