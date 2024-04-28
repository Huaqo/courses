// g++ -std=c++14 -Wall -Wextra -Werror -pedantic ./w4/binarysearch.cpp -o ./bin/binarysearch
#include <iostream>
#include <vector>
int binarySearch(int query, std::vector<int> &elems)
{
    unsigned low = 0;
    unsigned high = elems.size() - 1;
    unsigned index = (low + high) / 2;
    while (low < high)
    {
        if (query == elems[index])
        {
            return elems[index];
        }
        if (query < elems[index])
        {
            high = index - 1;
        }
        else
        {
            low = index + 1;
        }
        index = (low + high) / 2;
    }
    return elems[index];
}
int main()
{
    std::vector<int> searchtest = {1, 4, 6, 12, 19, 22, 34, 36, 100};
    std::cout << "Binärsuche: " << binarySearch(36, searchtest) << std::endl;
    std::cout << "Binärsuche: " << binarySearch(1000, searchtest) << std::endl;
    std::cout << "Binärsuche: " << binarySearch(0, searchtest) << std::endl;
    std::cout << "Binärsuche: " << binarySearch(5, searchtest) << std::endl;
}