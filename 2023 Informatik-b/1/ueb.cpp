#include <iostream>

int main(){
  int x = 2;
  for (int i=0; i<32; i++){
    x=x*2;
  }
  std::cout << x << std::endl;

  int zahl = 50;
  std::cout << (3+5*9==zahl-2) << std::endl;
  std::cout << "Info B " << (40 * zahl + 23) << std::endl;
  std::cout << (true && (++zahl > 50)) << std::endl;
  std::cout << zahl << std::endl;
  std::cout << ((zahl <= 44) + 7) << std::endl;


  int y = 3;
  int z = ++y + 2;
  std::cout << "z: " << z << std::endl;
  std::cout << "y: " << y << std::endl;
  z = y++ + 2;
  std::cout << "z: " << z << std::endl;
  std::cout << "y: " << y << std::endl;


  short a = 345;
  std::cout << "Groesse von a " << sizeof(a) << std::endl;
  std::cout << "Groesse von a+y " << sizeof(a+y) << std::endl;

  std::cout << "Geben Sie eine Zahl ein: ";
  std::cin >> a;
  std::cout << "Ihre Zahl ist: " << a <<std::endl;

  if(++y == 6){
    std::cout << "Huhu" << std::endl;
  }
  std::cout << "y: " << y << std::endl;
  if(y-- == 6){
    std::cout << "Hallo" << std::endl;
  }
  std::cout << "y: " << y << std::endl;

}