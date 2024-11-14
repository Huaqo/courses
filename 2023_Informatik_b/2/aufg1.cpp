#include <iostream>
using namespace std;


int main(){
   int n1 = 10;
   int n2 = 20;
   int n3 = n1/n2;
   float f1 = 10;
   float f2 = f1 + 10;
   float f3 = f1/f2;

   cout << "n3: " << n3 << endl;
   cout << "f3: " << f3 << endl;

    f3 += 3;
    cout << "f3: " << f3++ << endl;
    cout << "f3: mit postincr " << f3++ << endl;
    cout << "f3: mit preincr " << ++f3 << endl;
  
    bool comp1 = 2*5+5*2 == n2;
    n2 = n2*2;
    bool comp2 = 2*5+5*2 == n2;
    bool comp3 = n3 < f3;

    bool comp4 = comp1 && comp3 || comp2;
    cout << "comp1, comp2, comp3, comp4: " << comp1 << ", " << comp2 << ", " << comp3 << ", "  << comp4 << endl;

}
