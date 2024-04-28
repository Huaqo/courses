// g++ -std=c++14 -Wall -Wextra -Werror -pedantic ./w7/primitive_arrays.cpp -o ./bin/primitive_arrays && ./bin/primitive_arrays

#include <iostream>

/*
Voraussetzungen:
Die Funktion sollte nur aufgerufen werden, wenn eine Eingabe vom Benutzer erwartet wird.
Es wird vorausgesetzt, dass der Benutzer ausschließlich positive Ganzzahlen eingibt.

Ergebnis:
Die Funktion gibt die Summe aller vom Benutzer eingegebenen Zahlen als Integer zurück.

Effekt:
Die Funktion reserviert und gibt dynamischen Speicher frei.
*/

int summeZahlen()
{
    int k;
    std::cout << "Geben Sie k an: ";
    std::cin >> k;

    int *arr = new int[k];

    for (int i = 0; i < k; ++i)
    {
        std::cout << "Geben Sie eine Zahl ein: ";
        std::cin >> arr[i];
    }

    int summe = 0;
    for (int i = 0; i < k; ++i)
    {
        summe += arr[i];
    }

    delete[] arr;

    return summe;
}

int main()
{
    int summe = summeZahlen();
    std::cout << "Die Summe ist: " << summe << std::endl;
}
