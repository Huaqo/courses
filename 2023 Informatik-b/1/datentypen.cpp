/* Informatik B - Sommersemester 2022
Vorlesung am 21.04.2022
Katharina Klost

Beispiele zu Datentypen
*/


#include <iostream>
#include <climits>

int main(){
  //Auf Grund der Wertsemantik wird nur der Inhalt von num 3 verändert
  int num2 = 20;
  int num3 = num2;
  std::cout << "num 2: " << num2 << std::endl;
  std::cout << "num 3: " << num3 << std::endl;
  num3 = num3 +1;
  std::cout << "num 2: " << num2 << std::endl;
  std::cout << "num 3: " << num3 << std::endl;

  /*Auch wenn in einem Bool allgeine Werte gespeichert werden können
  wird nur 0 für false und 1 für alle Werte != 0 ausgegeben*/
  bool b1 = 12;
  std::cout << "b1: " << b1 << std::endl;
  std::cout << "Größe von b1: " << sizeof(b1) << std::endl;

  //Da chars intern als Zahlen gespeichert werden, kann mit diesen auch
  //gerechnet werden
  char c1 = 'A';

  std::cout << "c1: " << c1 << std::endl;
  c1=c1+1;
  std::cout << "c1: " << c1 << std::endl;

  //Bei Integern kann es zu einem Überlauf kommen
  int n = INT_MAX;
  std::cout << n << std::endl;
  n= n+1;
  std::cout << n << std::endl;

  // Bei Floats kann es wegen Rundungsfehlern zu unerwartetem Verhalten kommen
  float x = 0;
  for (int i = 0; i < 10; i++){
	   x = x + 0.1;
	    std::cout << "x"<<i <<" :"<< x << std::endl;
    }

    std::cout <<"(x==1.0) " << (x==1.0) << std::endl;

  //Größen von verschiedenen Datentypen
short s1 = 123;
long l1 = 123;
long long ll1 = 123;
float f1 = 123.0;
double d1 = 123.0;
long double ld1 = 123.0;


// Größen der Datentypen (auf diesem System)
std::cout << "Größen verschiedener Datentypen in Byte" << std::endl;
std::cout << "bool: " << sizeof(b1) << std::endl;
std::cout << "char: " << sizeof(c1) << std::endl;
std::cout << "short: " << sizeof(s1) << std::endl;
std::cout << "int: " << sizeof(n) << std::endl;
std::cout << "long: " << sizeof(l1) << std::endl;
std::cout << "long long: " << sizeof(ll1) << std::endl;
std::cout << "float: " << sizeof(f1) << std::endl;
std::cout << "double: " << sizeof(d1) << std::endl;
std::cout << "long double: " << sizeof(ld1) << std::endl;

std::cout << "Größe eines Bytes in Bit: " << CHAR_BIT << std::endl;
}
