// clear && g++ -std=c++14 -Wall -Wextra -Werror -pedantic ./w5/hilfsfunktionen.cpp ./w5/ultrasort.cpp -o ./bin/ultrasort && ./bin/ultrasort

#include "hilfsfunktionen.hpp"
#include <iostream>
#include <vector>
#include <limits>

bool isSorted(const std::vector<int>& vec);
void insertionSort(std::vector<int>& elems);
void merge(std::vector<int>& first_part, std::vector<int>& second_part, std::vector<int>& elems);
void ultraSort(std::vector<int>& elems);
void ultraSortParam(std::vector<int>& elems, double k);

int main() {

	srand(time(NULL)); 
	double time;
	std::vector<int> array;

	// Runtime (a)
	std::cout << "############ RUNTIME (ultraSort) ############ \n";
	for (int size = 10000; size <= 100000; size *= 10) {
		std::cout << "   " << size << " Elemente:" << std::endl;

		array = hf::zufalls_array(size);
      
		time = clock();
		ultraSort(array);
		time = clock() - time;

		std::cout << "      Zufällig: " << (time/CLOCKS_PER_SEC) << " Sekunden" << std::endl;

		array = hf::sortiertes_array(size, true);

		time = clock(); 
		ultraSort(array);
		time = clock() - time; 

		std::cout << "      Aufsteigend: " << (time/CLOCKS_PER_SEC) << " Sekunden" << std::endl;

		array = hf::sortiertes_array(size, false);

		time = clock(); 
		ultraSort(array);
		time = clock() - time;

		std::cout << "      Absteigend: " << (time/CLOCKS_PER_SEC) << " Sekunden" << std::endl;

		if (isSorted(array)) {
			std::cout << "      Array is sorted.\n";
		} else {
			std::cout << "      Array is not sorted.\n";
		}
		
	}

	// Optimal k
	std::cout << "############ OPTIMAL K ############ \n";
	std::vector<double> k_values = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
	double optimal_k = 0;
	double shortest_time = std::numeric_limits<double>::max();
	for (double k : k_values) {

		array = hf::zufalls_array(10000);
		time = clock();
		ultraSortParam(array, k);
		time = clock() - time;

		if (time < shortest_time) {
			shortest_time = time;
			optimal_k = k;
		}
	}
	std::cout << "   Optimal k is " << optimal_k << std::endl;

	// Runtime (b)
	std::cout << "############ RUNTIME (ultraSortParam) ############ \n";
	for (int size = 10000; size <= 100000; size *= 10) {
		std::cout << "   " << size << " Elemente:" << std::endl;

		array = hf::zufalls_array(size);
      
		time = clock();
		ultraSortParam(array, optimal_k);
		time = clock() - time;

		std::cout << "      Zufällig: " << (time/CLOCKS_PER_SEC) << " Sekunden" << std::endl;

		array = hf::sortiertes_array(size, true);

		time = clock(); 
		ultraSortParam(array, optimal_k);
		time = clock() - time; 

		std::cout << "      Aufsteigend: " << (time/CLOCKS_PER_SEC) << " Sekunden" << std::endl;

		array = hf::sortiertes_array(size, false);

		time = clock(); 
		ultraSortParam(array, optimal_k);
		time = clock() - time;

		std::cout << "      Absteigend: " << (time/CLOCKS_PER_SEC) << " Sekunden" << std::endl;

		if (isSorted(array)) {
			std::cout << "      Array is sorted.\n";
		} else {
			std::cout << "      Array is not sorted.\n";
		}
		
	}

	return 0;
}

bool isSorted(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        if (vec[i] > vec[i + 1]) {
            return false;
        }
    }
    return true;
}

void insertionSort(std::vector<int>& elems){
    int key=elems[0];
    unsigned shiftindex;
    for(unsigned i = 1; i<elems.size();i++){
        key=elems[i];
        for(shiftindex=i; shiftindex>0&&elems[shiftindex-1]>=key;shiftindex--){
            elems[shiftindex] = elems[shiftindex-1];
        }
        elems[shiftindex] = key;
    }
}

void merge(std::vector<int>& first_part, std::vector<int>& second_part, std::vector<int>& elems){
    unsigned i = 0;
    unsigned j = 0;
	unsigned begin = 0;
	unsigned end = elems.size();

    while(begin + i + j < end){
        if ( j >= second_part.size() || ((i<first_part.size()) && (first_part[i]<second_part[j]))){
            elems[begin+i+j] = first_part[i];
            i++;
        }
		else{
            elems[begin+i+j] = second_part[j];
            j++;
        }
    }
}

void ultraSort(std::vector<int>& elems){
    if (elems.size() <= 1) {
        return;
    }
    if (elems.size() < 10) {
        insertionSort(elems);
        return;
    }
    int groesse_erster_teil = elems.size() / 3;
    std::vector<int> erster_teil(elems.begin(), elems.begin() + groesse_erster_teil);
    std::vector<int> zweiter_teil(elems.begin() + groesse_erster_teil, elems.end());
    insertionSort(erster_teil);
    ultraSort(zweiter_teil);
    merge(erster_teil, zweiter_teil, elems);
}

void ultraSortParam(std::vector<int>& elems, double k){
    if (elems.size() <= 1) {
        return;
    }
    if (elems.size() < 10) {
        insertionSort(elems);
        return;
    }
    int groesse_erster_teil = static_cast<int>(k * elems.size());
    std::vector<int> erster_teil(elems.begin(), elems.begin() + groesse_erster_teil);
    std::vector<int> zweiter_teil(elems.begin() + groesse_erster_teil, elems.end());
    insertionSort(erster_teil);
    ultraSortParam(zweiter_teil, k);
    merge(erster_teil, zweiter_teil, elems);
}