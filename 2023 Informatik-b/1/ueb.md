# 1. Zahlenraten
In dieser Aufgabe schauen wir uns ein einfaches Spiel für zwei Spieler:innen an. Nennen wir die Spieler:innen Alice und Bob. Alice denkt sich eine Zahl zwischen 0 und 1022 aus und Bob versucht die Zahl zu erraten. Bob darf eine Zahl nennen, und Alice gibt dann die Antwort kleiner, größer oder richtig, je nach dem ob die von Bob genannte Zahl kleiner, größer oder gleich der Zahl von Alice ist.

## (a) 
> Geben Sie eine Strategie an, mit der Bob mit maximal 1022 Versuchen die Zahl errät. Argumen- tieren Sie in einem Satz, warum jede Strategie, die 1023 oder mehr Versuche braucht unnötige Fragen verwendet.

Eine Strategie wäre es immer die in die Mitte der Zahlenkette zu raten und dann einen Teil zu verwerfen. Da die Zahlenkette immer halbiert wird, wird die Anzahl der Versuche immer kleiner. 

Eine Strategie mit mehr als 1023 Versuchen beinhaltet mehr Versuche als Zahlen in der Zahlenkette. Das heist selbst wenn man jede einzelne Zahl raten würde und die letzte die richtige Zahl ist, liegt man bei 1020 versuchen. Wenn man 1023 Versuche braucht fragt man also doppelt oder mehrmals nach Zahlen.

## (b) 
> Wie kann Bob einfach die Informationen, die er bis zu einem Zeitpunkt gesammelt hat verwenden, um sicher zu stellen, dass er keine Zahl rät, die nicht mehr die Lösung sein kann, da sie in einem Zahlenbereich liegt, der bereits ausgeschlossen wurde.

Nicht mehr die Zahlen raten die größer oder kleiner der genannten Zahl ist. Das ist abhängig von Alice Antwort.

## (c) 
> Nun ist eine Strategie gesucht, mit der das Spiel schneller vorbei ist. Bob behauptet, dass er immer maximal 10 Versuche braucht. Geben Sie eine Strategie an, die immer maximal 10 Versuche braucht. Überlegen Sie dafür, wie Sie in jedem Schritt möglichst viele Zahlen ausschließen können, unabhängig davon, welche Antwort Alice gibt. Argumentieren Sie, warum die Strategie maximal 10 Versuche braucht.

Mit der selben Strategie, die in (a) genannt wurde. Beweis:

1020/2 = 510
510/2 = 255
255/2 = 127
127/2 = 63
63/2 = 31
31/2 = 15
15/2 = 7
7/2 = 3
3/2 = 1

# 2. Lesen und Anpassen von C++ Code (0+6+2+2 Punkte)

## (a) 
> Betrachten Sie die Datei ueb1.cpp aus dem Whiteboard und kompilieren Sie diese mit 

```bash
g++ -std=c++14 -Wall -Wextra -Werror -pedantic ueb1.cpp -o ueb1
```

## (b) 
> Führen Sie das Programm mit ./ueb1 aus und erklären Sie den Ablauf anhand des Quellcodes.

```cpp
int main(){
```
Die main Funktion ist die Funktion die beim starten des Programms ausgeführt wird. Sie ist die erste Funktion die aufgerufen wird.

```cpp
  int x = 2;
  for (int i=0; i<32; i++){
    x=x*2;
  }
  std::cout << x << std::endl;
```

Die Variable x wird mit dem Wert 2 initialisiert. Die for Schleife wird 32 mal ausgeführt. In jeder Iteration wird x mit 2 multipliziert. Das Ergebnis sollte 4,294,967,296 sein. Da der Datentype int aber nur 32 bit hat und da die höchste Zahl 2,147,483,647 ist, kommt es zu einem Overflow. Der Wert von x wird zurückgesetz auf 0, was ausgegeben wird. 

```cpp
  int zahl = 50;
  std::cout << (3+5*9==zahl-2) << std::endl;
  std::cout << "Info B " << (40 * zahl + 23) << std::endl;
  std::cout << (true && (++zahl > 50)) << std::endl;
  std::cout << zahl << std::endl;
  std::cout << ((zahl <= 44) + 7) << std::endl;
```

Die Variable zahl wird mit dem Wert 50 initialisiert. Die zweite Zeile gibt 1 aus, da die Bedingung wahr ist. Die dritte Zeile berechnet den Wert 2023 und gibt diesen mit dem String "Info B" aus. Die vierte Zeile gibt 1 aus, da die Bedingung wahr ist. Die fünfte Zeile gibt 51 aus, da die Variable zahl in der vorherigen Zeile um 1 erhöht wurde. Die sechste Zeile gibt 7 aus, da die Bedingung falsch ist und 0 + 7 = 7 ist. 

```cpp
  int y = 3;
  int z = ++y + 2;
  std::cout << "z: " << z << std::endl;
  std::cout << "y: " << y << std::endl;
  z = y++ + 2;
  std::cout << "z: " << z << std::endl;
  std::cout << "y: " << y << std::endl;
```

Dieser Codeteil soll den Unterschied zwischen ++y und y++ zeigen. ++y erhöht y um 1 und wird dann verwendet. y++ wird zuerst verwendet und dann erhöht. 

Die Variable y wird mit dem Wert 3 initialisiert. In der zweiten Zeile wird z mit dem Wert 6 initialisiert. Da y um 1 erhöhrt wird und dann mit 2 addiert wird. y hat jetzt den Wert 4 und z den Wert 6 was ausgegeben wird. In der fünften Zeile wird z mit dem Wert 6 initialisiert. Da y immernoch den Wert 4 hat und mit 2 addiert wird. Nach dem Ausdruck wird y um 1 erhöht. y hat jetzt den Wert 5 und z den Wert 6 was ausgegeben wird. 

```cpp
  int a = 345;
  std::cout << "Groesse von a " << sizeof(a) << std::endl;
  std::cout << "Groesse von a+y " << sizeof(a+y) << std::endl;
```

Zeigt die Größe von a und a+y in Bytes an. 

```cpp
  std::cout << "Geben Sie eine Zahl ein: ";
  std::cin >> a;
  std::cout << "Ihre Zahl ist: " << a <<std::endl;
```

Fragt den Benutzer nach einer Zahl und gibt diese aus.

```cpp
  if(y++ == 6){
    std::cout << "Huhu" << std::endl;
  }
  std::cout << "y: " << y << std::endl;
  if(--y == 6){
    std::cout << "Hallo" << std::endl;
  }
  std::cout << "y: " << y << std::endl;

}
```

Gibt "Hallo" oder "Huhu" aus, je nachdem ob die Bedingung wahr oder falsch ist. Danach wird y ausgegeben.

## (c) 
> Passen Sie das Programm so an, dass beide if-Bedingungen zu wahr auswerten, ohne dass sich der Zustand der Variablen nach den if-Bedingungen ändert.

```cpp
if(++y == 6){
    std::cout << "Huhu" << std::endl;
  }
  std::cout << "y: " << y << std::endl;
  if(y-- == 6){
    std::cout << "Hallo" << std::endl;
  }
  std::cout << "y: " << y << std::endl;
```

## (d) 
> Das Programm führt keine adäquate Fehlerbehandlung aus. Finden Sie Eingaben, bei denen das Programm ein unerwünschtes Verhalten zeigt.

Todo!

# 3. Von-Neumann-Rechner (5+5 Punkte)

## (a)
> Schreiben Sie ein Programm für den Von-Neumann-Rechner, das solange eine Variable hochzählt, bis diese den gleichen Wert wie eine gelesene Eingabe hat. Kommentieren Sie die Bedeutung der Speicherzellen.

> Sie können die folgenden Befehle verwenden:

| Befehl   | Beschreibung                                                               |
|----------|----------------------------------------------------------------------------|
| READ     | Liest eine Eingabe ein.                                                    |
| WRITE X  | Schreibt den Inhalt des Rechenwerks in Zelle X.                            |
| LOAD X   | Liest den Inhalt von Zelle X und schreibt diesen ins Rechenwerk.           |
| CJUMP X  | Setzt den Befehlszähler auf X, wenn der Inhalt des Rechenwerks 0 
ist.      |
| GOTO X   | Setzt den Befehlszähler auf X.                                             |
| ADD X    | Addiert den Inhalt von Zelle X auf den Inhalt des Rechenwerks.             |
| SUB X    | Subtrahiert den Inhalt von Zelle X vom Inhalt des Rechenwerks.             |
| OUTP X   | Gibt den Inhalt von Zelle X aus.                                           |
| RETURN   | Beendet das Programm.                                                      |

```Von-Neumann-Rechner
1: READ
2: WRITE 10  
3: LOAD 11
4: ADD 12
5: STORE 11
6: SUB 10
7: CJUMP 9
8: JUMP 11
9: RETURN
10: 0
11: 0
12: 1
```

## (b)
> Beschreiben Sie, was das folgende Programm berechnet.

```
0: READ INP
1: WRITE 14
2: READ INP
4: WRITE 15
5: CJUMP 13
6: READ 16
7: ADD 14
8: WRITE 16
9: READ 15
10: SUB 17
11: WRITE 15
12: JUMP 5
13: OUTP 16
14:0
15:0
16:0
17:1
```

Liest zwei Zahlen ein. Die eine wird in einer Schleife verdoppelt, die andere wird um 1 reduziert. Wenn die zweite Zahl 0 erreicht, wird die mehrmals verdoppelte Zahl ausgegeben.

```
x = get()
y = get()

while y != 0:
  z = 0 
  z = z + x
  y = y - 1

print()
```
