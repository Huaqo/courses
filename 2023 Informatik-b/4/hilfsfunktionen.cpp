/* Informatik B - Sommersemester 2023
Vorlesung am 12.05.2023
Katharina Klost

Hilfsfunktionen zum Sortieren, nur zusammen mit der sorting.cpp zu compilieren
*/
#include <iostream>
#include <vector>
#include "hilfsfunktionen.hpp"


namespace hf{

    void gebe_aus(std::vector<int>& vec, unsigned start, unsigned end){
        if(end>vec.size()){
            std::cout << vec.size() << " " << end << std::endl;
            return;
        }
    std::cout << vec[start];
    for(unsigned k=start+1; k<end; k++){
        std::cout << ", " << vec[k];
    }
    std::cout << std::endl;
}

    void swap(std::vector<int>& elems, unsigned i, unsigned j){
        if (i>=elems.size() || j >= elems.size()){
            return;
        }
        int tmp = elems[i];
        elems[i] = elems[j];
        elems[j] = tmp;
    }

    unsigned minimumIndex(std::vector<int>& elems, unsigned start, unsigned end){
        unsigned min = start;
        for(unsigned i = start; i<end; i++){
            if(elems[i] < elems[min]){
                min = i;
            }
        }
        return min;
    }

    std::vector<int> copy(std::vector<int>& elems, unsigned start, unsigned end){
        std::vector<int> returnVec;
        for(unsigned i= start; i<end; i++){
            returnVec.push_back(elems[i]);
        }
    return returnVec;
    }
}