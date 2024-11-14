//g++ -std=c++14 -Wall -Wextra -Werror -pedantic ./w5/min.cpp -o ./bin/min && ./bin/min


#include <iostream>
#include <vector>

int min(const std::vector<int>& vec);

int main() {
    std::vector<int> testVec = {10, 20, 2, 0, 30};
    std::cout << "The minimum value in the vector is: " << min(testVec) << std::endl;
}

int min(const std::vector<int>& vec) {
    int minVal = vec[0];
    for (unsigned i = 1; i < vec.size(); ++i) {
        if (vec[i] < minVal) { 
            minVal = vec[i]; 
        }
    }
    return minVal; 
}