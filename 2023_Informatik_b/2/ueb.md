# 3. Gültigkeitsbereich und Recherche (5+2+3 Punkte)
## (a) Betrachten Sie den folgenden C++-Code und geben Sie für alle Variablen den Gültigkeitsbereich
an.

```cpp  
#include <vector>
int main(){
   int v1 = 32;
   double i = 7.0;
   for(int i= 2; i< 30; i++){
      v1 *= i; }
   std::vector<std::vector<int>> vec = { 
      { 1, 2, 3 },
      { 4, 5, 6 },
      { 7, 8, 9, 4 } };
   for (i = 0; i<vec.size(); i++){
     int v1=20;
     for (unsigned int j=0; j<vec[i].size();j++){
       v1 = vec[i][j];
     }
    v1+=1; }
}
```

Die Variable v1 befindet sich in dem Gültigkeitsbereich von main() und auch in dem Gültigkeitsbereich der for-Schleife. 

Die Variable i befindet sich in dem Gültigkeitsbereich von main() und in dem Gültigkeitsbereich der ersten for-Schleife. Die Variable i aus dem Gültigkeitsbereich von main() wird  für die for-Schleife überschrieben.

Die Variable vec befindet sich in dem Gültigkeitsbereich von main() und in dem Gültigkeitsbereich der zweiten for-Schleife. 

Die Variable i aus dem Gültigkeitsbereich der ersten for-Schleife wird für die zweite for-Schleife überschrieben.

Die Variable j befindet sich in dem Gültigkeitsbereich der zweiten for-Schleife.

## (b) Es gibt in C++ noch eine weitere Schleifenart. Recherchieren Sie welche dies ist. Geben Sie die allgemeine Form an und beschreiben Sie die Funktionalität. Denken Sie daran Quellen anzugeben.

Die weitere Schleifenart ist die do-while-Schleife. Die allgemeine Form ist:

```cpp
do {
  <Anweisung>;
} while (<Bedingung>);
```

Sie verhält sich wie eine while-Schleife, mit dem Unterschied, dass die Bedingung nach der Ausführung der Anweisung anstatt davor ausgewertet wird. Dadurch wird garantiert, dass die Anweisung mindestens einmal ausgeführt wird, auch wenn die Bedingung niemals erfüllt ist.

[Quelle](https://www.cplusplus.com/doc/tutorial/control/#do_while)

## (c) Finden Sie je einen Anwendungsfall, in dem eine for, while und die weitere Schleife gegenüber den anderen Schleifenarten zu bevorzugen ist.

Die for-Schleife ist zu bevorzugen, wenn die **Anzahl der Durchläufe bekannt** ist. 

Die while-Schleife ist zu bevorzugen, wenn die **Anzahl der Durchläufe nicht bekannt** ist. 

Die do-while-Schleife ist zu bevorzugen, wenn die **Anweisung mindestens einmal ausgeführt werden soll**.

