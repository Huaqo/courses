// g++ -std=c++14 -Wall -Wextra -Werror -pedantic ./w7/call_by_reference_pointer.cpp -o ./bin/call_by_reference_pointer && ./bin/call_by_reference_pointer
#include <iostream>

/*
Voraussetzungen:
Ein gültiger Zeiger auf ein Integer-Objekt muss als Argument an die Funktion übergeben werden.
Der Zeiger darf nicht null und darf nicht auf Speicher zeigen, der nicht verändert werden darf (z.B. konstante Daten oder bereits freigegebener Speicher).

Ergebnis:
Die Funktion hat keinen Rückgabewert.

Effekt:
Die Funktion verändert den Wert der Integer-Variablen, auf die der übergebene Zeiger zeigt, zu 10.
*/

void aendern(int *ptr)
{
    *ptr = 10;
}

int main()
{
    int x = 5;
    std::cout << "Davor: " << x << std::endl;
    aendern(&x);
    std::cout << "Danach: " << x << std::endl;
}