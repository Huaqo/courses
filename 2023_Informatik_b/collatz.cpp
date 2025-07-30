/* Informatik B - Sommersemester 2023
Vorlesung am 03.05.2023
Katharina Klost

Weiteres Beispiel zur Rekursion
*/

#include <iostream>

/*
Voraussetzung: n ist größer als 0
Ergebnis: Wenn Collatz mit n/2 terminiert ist true geliefert
Effekt: keiner
*/
bool c1(unsigned);


/*
Voraussetzung: n ist größer als 0
Ergebnis: Wenn Collatz mit 3*n+1 terminiert ist true geliefert
Effekt: keiner
*/
bool c2(unsigned);

/*
Voraussetzung: n ist größer als 0
Ergebnis: true, wenn die Collatzfolge von n aus terminiert
Effekt: gibt aktuellen Wert n aus
*/
bool collatz(unsigned);

bool c1(unsigned n){
  return collatz(n/2);
}

bool collatz(unsigned n){
  std::cout << n << std::endl;
  if (n==1){
    return true;
  }
  // !(n%2) ist true, wenn n gerade ist. Dies kann wie folgt gesehen werden:
  // für gerade n ist n%2 == 0. Das Anwenden von ! interpretiert die 0 dann als
  // false, dieses wird negiert und damit wird der Ausdruck zu true ausgewertet.
  // Etwas länger aber evtl besser zu lesen wär (n%2 == 0).
  if (!(n%2)){
    return c1(n);
  }else{ // n ungerade
    return c2(n);
  }
}

bool c2(unsigned n){
  return collatz(3*n+1);
}

int main(){
  int n;
  std::cout << "Gebe eine Zahl ein: ";
  std::cin >> n;
  collatz(n);
  std::cout << "terminated" << std::endl;
}
