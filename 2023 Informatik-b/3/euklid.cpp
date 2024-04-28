/* Informatik B - Sommersemester 2023
Vorlesung am 05.05.2023
Katharina Klost

Verschiedene Umsetzungen des euklidischen Algorithmus
*/

#include <iostream>

/*
Voraussetzung: keine
Effekt: Es werden Informationen zum Ablauf ausgegeben
Ergebnis: Der größte gemeinsame Teiler von a und b ist geliefert
*/
// Rekursive Umsetzung
unsigned euclid_rec(unsigned a, unsigned b);
//optimierte rekursive Umsetzung
unsigned euclid_rec_opt(unsigned a, unsigned b);
//iterative Umsetzung
unsigned euclid_it(unsigned a, unsigned b);


unsigned euclid_rec(unsigned a, unsigned b){
  std::cout << "ggT(" << a << ", " << b << ")" << std::endl;
  if (b>a){
    return euclid_rec(b,a);
  }
  if(b==0){
    return a;
  }
  return euclid_rec(a-b, b);
}

// statt immer wieder a-b zu rechnen, bis das Ergebnis kleiner als b ist,
// kann direkt modulu verwendet werden
unsigned euclid_rec_opt(unsigned a, unsigned b){
    std::cout << "ggTopt(" << a<< ", " << b << ")" << std::endl;
    if(b==0){
      return a;
    }
    return euclid_rec_opt(b, a%b);
}

//iterative Umsetzung des optimierten euklidischen Algorithmus
unsigned euclid_it(unsigned a, unsigned b){
  unsigned newb;
  while(b!=0){
    newb = a%b;
    a=b;
    b = newb;
  }
  return a;
}

int main(){
  int a= 12;
  int b= 136;
  std::cout << "===Rekursiv===" << std::endl;
  int ggT= euclid_rec(a , b);
  std::cout << "Der ggT von " << a << " und " << b << " ist " << ggT <<std::endl;
  std::cout << "===Rekursiv Optimiert ===" << std::endl;
  ggT= euclid_rec_opt(a , b);
  std::cout << "Der ggT von " << a << " und " << b << " ist " << ggT <<std::endl;

}
