#include <iostream>
#include <vector>

std::vector<int> reverseSortVector(std::vector<int> vec);

int main() {

    int input = -1;
    std::vector<int> vec;
    std::vector<int> vecnew;

    std::cout << "Geben Sie eine Zahlenfolge ein, mit 0 beenden Sie die Eingabe: " << std::endl;
    while (input != 0) {
        std::cin >> input;
        if (input != 0) {
            vec.push_back(input);
        }
    }

    vecnew = reverseSortVector(vec);

    std::cout << "Die Zahlenfolge in umgekehrter Reihenfolge: " << std::endl;
    for (unsigned i = 0; i < vecnew.size(); i++) {
        std::cout << vecnew[i] << std::endl;
    }
    
}

std::vector<int> reverseSortVector(std::vector<int> vec) {
    std::vector<int> vecnew;
    for (unsigned i = vec.size() - 1; i >= 0; i--) {
        vecnew.push_back(vec[i]);
    }
    return vecnew;
}