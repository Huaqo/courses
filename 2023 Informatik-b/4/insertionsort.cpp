/*
g++ -std=c++14 -Wall -Wextra -Werror -pedantic ./w4/hilfsfunktionen.cpp ./w4/insertionsort.cpp -o ./bin/insertionsort

Insertion Sort funktioniert, indem es durch das Array läuft und jedes Element nach links verschiebt, 
bis es das erste Element findet, das kleiner ist. Dieser Prozess wird für jedes Element im Array wiederholt, 
bis das gesamte Array sortiert ist. Im Hauptprogramm (main) wird der Insertion Sort Algorithmus auf ein Testarray angewendet 
und das Array vor und nach der Sortierung ausgegeben.
*/

#include <vector>
#include "hilfsfunktionen.hpp"

void insertionSort(std::vector<int>& elems){
    // Der Schlüssel ist das Element, das wir gerade sortieren
    int key=elems[0];
    unsigned shiftindex;

    // Beginne mit dem zweiten Element (Index 1)
    for(unsigned i = 1; i<elems.size();i++){
        // Aktualisiere den Schlüssel auf das aktuelle Element
        key=elems[i];

        // Verschiebe jedes Element, das größer als der Schlüssel ist, um eine Position nach rechts
        for(shiftindex=i; shiftindex>0&&elems[shiftindex-1]>=key;shiftindex--){
            elems[shiftindex] = elems[shiftindex-1];
        }

        // Füge den Schlüssel an der richtigen Position ein
        elems[shiftindex] = key;
    }
}


int main(){
    std::vector<int> test = {1,4,2,67,3,76,13,8,10,22,6,9,5,11,32,0};
    hf::gebe_aus(test, 0, test.size());
    insertionSort(test);
    hf::gebe_aus(test, 0, test.size());
}