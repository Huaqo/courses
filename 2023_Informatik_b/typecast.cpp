/* Informatik B - Sommersemester 2023
Vorlesung am 26.04.2023
Katharina Klost

Beispiele zur Ein-und Ausgabe
*/

#include <iostream> // gibt Ein-und Ausgabe
#include <climits>  // gibt Minimal- und Maximalwerte für die Datentypen

int main(){

  /*Zuweisen einer Gleitkommazahl zu einer Ganzzahl schneidet die
  Nachkommastellen ab
  */
  int a = 3.5;
  std::cout << "a: " << a << std::endl;

  int n1 = SHRT_MAX;
  short n2 = SHRT_MAX;


  short n3 = n2 + n2; // overflow
  int n4 = n1 + n2; //der größere Datentyp gewinnt

  std::cout << "n3, n4: "<<n3 << ", " << n4<< std::endl;


  unsigned int n5 = 5;
  int n6 = -6;
  // Bei Kombination von unsigned und signed Typen gewinnt
  // der unsigned, der Inhalt der Speicherzelle wird dann
  // intern anders interpretiert
  std::cout << "n5+n6: "<< n5+6 <<std::endl;



// Bei der Kombination von Gleitkommazahlen und Ganzzahlen gewinnt
// die Gleitkommazahl
  double f1 = 0.4;
  std::cout << f1 + n6<< std::endl;


  int i1 = 18;
  int i2 = 16;

  //implizieter Typcast, es wird erst Ganzzahlig dividiert
  // (Nachkommastellen abgeschnitten) und dann umgewandelt
  double dv1 = i1 / i2;

  //werden Divisor und Divident erst umgewandelt, ist das Ergebnis die
  //erwartete Gleitkommazahl
  double dv2 = static_cast<double>(i1) / static_cast<double>(i2);

  // Wie weiter oben, erst wird geteilt (und abgeschnitten) und dann umgewandelt
  // und dann zugewiesen.
  double dv3 = static_cast<double>( i1 / i2 );
  std::cout << dv1 << ", " << dv2 << ", " << dv3 << std::endl;
}
