/* 
g++ -std=c++14 -Wall -Wextra -Werror -pedantic ./w4/hilfsfunktionen.cpp ./w4/selectionsort.cpp -o ./bin/selectionsort

Dieser Algorithmus durchläuft das Array und findet das kleinste Element, dann tauscht es dieses Element mit dem ersten Element des Arrays. 
Danach durchläuft es den restlichen Teil des Arrays, findet das kleinste Element und tauscht es mit dem zweiten Element des Arrays. 
Dieser Prozess wird so lange wiederholt, bis das gesamte Array sortiert ist. Im Hauptprogramm (main) wird der Selection Sort Algorithmus auf 
ein Testarray angewendet und das Array vor und nach der Sortierung ausgegeben.

*/

#include <vector>
#include "hilfsfunktionen.hpp"

void selectionSort(std::vector<int>& elems){
    for(unsigned i = 0; i < elems.size();i++){
        hf::swap(elems, i, hf::minimumIndex(elems, i, elems.size()));
    }
}

int main(){
    std::vector<int> test = {1,4,2,67,3,76,13,8,10,22,6,9,5,11,32,0};
    hf::gebe_aus(test, 0, test.size());
    selectionSort(test);
    hf::gebe_aus(test, 0, test.size());
}
