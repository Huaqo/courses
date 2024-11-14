/*
g++ -std=c++14 -Wall -Wextra -Werror -pedantic ./w4/hilfsfunktionen.cpp ./w4/mergesort.cpp -o ./bin/mergesort


Dieser Algorithmus verwendet den Divide-and-Conquer-Ansatz, um das Array zu sortieren. Zuerst wird das Array in zwei Hälften geteilt. 
Diese Hälften werden dann rekursiv sortiert (mit mergeSortHelp). Danach werden die beiden sortierten Hälften mit der merge Funktion 
zusammengeführt. Dieser Prozess wird fortgesetzt, bis das gesamte Array sortiert ist. Im Hauptprogramm (main) wird der Merge Sort 
Algorithmus auf ein Testarray angewendet und das Array vor und nach der Sortierung ausgegeben.
*/

#include <vector>
#include "hilfsfunktionen.hpp"

void merge(std::vector<int>& elems, unsigned begin, unsigned mid, unsigned end){
    // Kopiere die erste und zweite Hälfte des zu sortierenden Bereichs in neue Vektoren
    std::vector<int> firstHalf = hf::copy(elems, begin, mid);
    std::vector<int> secondHalf = hf::copy(elems, mid, end);

    // Initialisiere Zähler für die beiden Hälften
    unsigned i = 0;
    unsigned j = 0;

    // Iteriere durch den zu sortierenden Bereich
    while(begin + i + j < end){
        // Wenn alle Elemente aus der zweiten Hälfte kopiert wurden oder das aktuelle Element der ersten Hälfte kleiner ist als das der zweiten Hälfte
        if ( j >= secondHalf.size() || ((i<firstHalf.size()) && (firstHalf[i]<secondHalf[j]))){
            // Kopiere das aktuelle Element der ersten Hälfte in den ursprünglichen Vektor
            elems[begin+i+j] = firstHalf[i];
            i++;
        }else{
            // Kopiere das aktuelle Element der zweiten Hälfte in den ursprünglichen Vektor
            elems[begin+i+j] = secondHalf[j];
            j++;
        }
    }
}


void mergeSortHelp(std::vector<int>& elems, unsigned start, unsigned end){
    if(start==end||start==end-1){
        return;
    }
    unsigned mid = (start+end)/2;
    mergeSortHelp(elems, start, mid);
    mergeSortHelp(elems, mid, end);
    merge(elems, start, mid, end);
}

void mergeSort(std::vector<int>& elems){
    mergeSortHelp(elems, 0, elems.size());
}

int main(){
    std::vector<int> test = {1,4,2,67,3,76,13,8,10,22,6,9,5,11,32,0};
    hf::gebe_aus(test, 0, test.size());
    mergeSort(test);
    hf::gebe_aus(test, 0, test.size());
}
