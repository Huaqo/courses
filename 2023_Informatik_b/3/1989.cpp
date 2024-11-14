#include <iostream>
#include <vector>
#include <string>

int main() {
    int vector_size;
    std::vector<int> vec;
    
    std::cout << "Bitte geben Sie die Größe des Vektors an: ";
    std::cin >> vector_size;

    std::cout << "Geben Sie die Werte des Vektors ein:" << std::endl;
    for (int i = 0; i < vector_size; ++i) {
        int input;
        std::cin >> input;
        vec.push_back(input);
    }

    int count_1 = 0;
    int count_3 = 0;
    bool found = false;

    for (int i = 0; i < vector_size; ++i) {
        if (vec[i] == 1) count_1++;
        if (vec[i] == 3) count_3++;

        if (i + 3 < vector_size) {
            if (vec[i] == 1 && vec[i + 1] == 9 && vec[i + 2] == 8 && vec[i + 3] == 9) {
                found = true;
            }
        }
    }

    std::cout << "Anzahl der 1en im Vektor: " << count_1 << std::endl;
    std::cout << "Anzahl der 3en im Vektor: " << count_3 << std::endl;

    if (found) {
        std::cout << "Das Album \"1989\" von Taylor Swift ist ein sehr gutes Album." << std::endl;
    } else {
        std::cout << "\"1989\" kommt nicht vor." << std::endl;
    }

    return 0;
}
