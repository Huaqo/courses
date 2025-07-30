#include <iostream>

// Fibonacci numbers

int main() {

    int x;
    std::cout << "x-th Fibonacci number?: ";
    std::cin >> x;

    int prev = 0;
    int curr = 1;
    int tmp;

    for (int i = 2; i <= x; ++i) {
        tmp = curr;
        curr = prev + curr;
        prev = tmp;
    }

}
