// g++ -std=c++14 -Wall -Wextra -Werror -pedantic ./w4/bubblesort.cpp -o ./bin/bubblesort


#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr, bool ascending) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if ((arr[j] > arr[j + 1] && ascending) || (arr[j] < arr[j + 1] && !ascending)) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        
        if (!swapped) {
            break;
        }
    }
}

int main() {
    int arr[] = {30, 10, 25, 100, 5, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> numbers(arr, arr + n);
    bool ascending = true;

    // Ascending sort
    bubbleSort(numbers, ascending);

    std::cout << "Sorted list (ascending): ";
    for (unsigned i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // Descending sort
    ascending = false;
    bubbleSort(numbers, ascending);

    std::cout << "Sorted list (descending): ";
    for (unsigned i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
