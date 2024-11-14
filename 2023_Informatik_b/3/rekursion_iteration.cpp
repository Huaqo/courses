/* Informatik B - Sommersemester 2023
Vorlesung am 03.05.2023
Katharina Klost

Beispiele zu rekursion und iteration
*/
#include <iostream>

/*
Voraussetzung: keine
Ergebnis: Die Fakultät von n ist geliefert
Effekt: keiner
Rekursive Implementierung
*/
unsigned fak_rek(unsigned n);


/*
Voraussetzung: keine
Ergebnis: Die Fakultät von n ist geliefert
Effekt: keiner
Iterative Implementierung
*/
unsigned fak_iter(unsigned n);

//Da hier direkte rekursion verwendet wird, gibt es keine Optimierung.
// Bei Endrekursion und Verwendung des -O3 flags wird die Endrekursion optimiert
unsigned fak_rek(unsigned n){
  if (n==0){
    return 1;
  }
  return(fak_rek(n-1)*n);
}

unsigned fak_iter(unsigned n){
  unsigned res = 1;
  for (unsigned i = 1; i<=n; i++){
    res*=i;
  }
  return res;
}

int main(){

}
