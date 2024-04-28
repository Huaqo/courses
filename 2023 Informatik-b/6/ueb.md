# 1. Aussagen zu $\Omega$ 
Zeigen Sie, dass die Folgenden Aussagen gelten, geben Sie jeweils ein $n_0$ und $c$ an.

# (a) Wenn $a \cdot f(n) \in \Omega(b \cdot f(n))$ für beliebige Konstanten $a,b$.

Die Definition von $\Omega$ besagt, dass $f(n) \in \Omega(g(n))$, wenn es Konstanten $c>0$ und $n_0$ gibt, so dass $f(n) \geq c \cdot g(n)$ für alle $n \geq n_0$.

In diesem Fall ist $g(n)=b \cdot f(n)$, also muss $a \cdot f(n) \geq c \cdot b \cdot f(n)$ für alle $n \geq n_0$. 

Wenn wir beide Seiten durch $f(n)$ teilen (vorausgesetzt, $f(n) \neq 0$ ), erhalten wir $a \geq c \cdot b$. 

Da $a$ und $b$ Konstanten sind, können wir $c=a / b$ wählen, und die Aussage gilt für alle $n$, also ist $n_0=0$.

# (b) Für $0 \leq b \leq a$ gilt $n^a \in \Omega\left(n^b\right)$.

Die Aussage, dass $n^a \in \Omega\left(n^b\right)$ für $0 \leq b \leq a$, bedeutet, dass es eine Konstante $c>0$ und ein $n_0 \geq 1$ gibt, so dass für alle $n \geq n_0$ gilt, dass $n^a \geq c \cdot n^b$.

Da $b \leq a$, können wir $c=1$ wählen. Dann gilt für alle $n \geq 1$, dass $n^a \geq 1 \cdot n^b$, da das Erhöhen der Potenz einer Zahl (mit einer Basis größer als 1) zu einer größeren Zahl führt.

Also können wir $n_0=1$ und $c=1$ wählen, um die Aussage zu beweisen.

# (c) Wenn $f_1(n) \in \Omega\left(g_1(n)\right)$ und $f_2(n) \in \Omega\left(g_2(n)\right)$ dann ist auch $f_1(n) \cdot f_2(n) \in$ $\Omega\left(g_1(n) \cdot g_2(n)\right)$.

Da $f_1(n) \in \Omega\left(g_1(n)\right)$, gibt es Konstanten $c_1>0$ und $n_{01}$, so dass $f_1(n) \geq c_1$. $g_1(n)$ für alle $n \geq n_{01}$. 

Ähnlich gibt es für $f_2(n) \in \Omega\left(g_2(n)\right)$ Konstanten $c_2>0$ und $n_{02}$ so dass $f_2(n) \geq c_2 \cdot g_2(n)$ für alle $n \geq n_{02}$. 

Wenn wir diese beiden Ungleichungen multiplizieren, erhalten wir $f_1(n) \cdot f_2(n) \geq c_1 \cdot c_2 \cdot g_1(n) \cdot g_2(n)$ für alle $n \geq$ $\max \left(n_{01}, n_{02}\right)$. 

Daher ist $f_1(n) \cdot f_2(n) \in \Omega\left(g_1(n) \cdot g_2(n)\right)$ mit $c=c_1 \cdot c_2$ und $n_0=$ $\max \left(n_{01}, n_{02}\right)$

# (d) Wenn $f_1(n) \in \Omega\left(g_1(n)\right)$ und $f_2(n) \in \Omega\left(g_2(n)\right)$ dann ist auch $f_1(n)+f_2(n) \in$ $\Omega\left(g_1(n)+g_2(n)\right)$

Da $f_1(n) \in \Omega\left(g_1(n)\right)$, gibt es Konstanten $c_1>0$ und $n_{01}$, so dass $f_1(n) \geq c_1$. $g_1(n)$ für alle $n \geq n_{01}$. 

Ähnlich gibt es für $f_2(n) \in \Omega\left(g_2(n)\right)$ Konstanten $c_2>0$ und $n_{02}$, so dass $f_2(n) \geq c_2 \cdot g_2(n)$ für alle $n \geq n_{02}$. 

Wenn wir diese beiden Ungleichungen addieren, erhalten wir $f_1(n)+f_2(n) \geq c_1 \cdot g_1(n)+c_2 \cdot g_2(n)$ für alle $n \geq$ $\max \left(n_{01}, n_{02}\right)$. 

Da $c_1 \cdot g_1(n)+c_2 \cdot g_2(n) \geq \min \left(c_1, c_2\right) \cdot\left(g_1(n)+g_2(n)\right)$, können wir $c=\min \left(c_1, c_2\right)$ wählen, und $f_1(n)+f_2(n) \in \Omega\left(g_1(n)+g_2(n)\right)$ mit $n_0=$ $\max \left(n_{01}, n_{02}\right)$

# 2. Rekursion und O-Notation
# (a) lösen Sie die folgenden Rekursionsgleichungen und geben Sie Ihren Lösungsweg an. Gehen Sie von T (0) = T (1) = O(1) aus.

## (i) $T(n)=3 T(n / 3)+3 n$

Wir verwenden das Master-Theorem, das für Rekursionen der Form $T(n)=a T(n / b)+f(n)$ gilt, wobei $a \geq 1, b>1$, und $f(n)$ eine positive Funktion ist. In diesem Fall haben wir $a=3$, $b=3$, und $f(n)=3 n$.

Nach dem Master-Theorem haben wir drei Fälle zu prüfen:

1. Wenn $f(n)=O\left(n^c\right)$, wobei $c<\log _b a$, dann ist $T(n)=$ $\Theta\left(n^{\log _b a}\right)$.
2. Wenn $f(n)=\Theta\left(n^c\right)$, wobei $c=\log _b a$, dann ist $T(n)=$ $\Theta\left(n^c \log n\right)$.
3. Wenn $f(n)=\Omega\left(n^c\right)$, wobei $c>\log _b a$, und wenn $a f(n / b) \leq k f(n)$ für ein $k<1$ und alle hinreichend großen $n$, dann ist $T(n)=\Theta(f(n))$.

In unserem Fall ist $f(n)=3 n=\Theta(n)$ und $\log _b a=\log _3 3=$ 1. Daher sind wir im zweiten Fall des Master-Theorems, und die Lösung ist $T(n)=\Theta(n \log n)$.

## (ii) $T(n)=T(n-1)+3$
Diese Rekursionsgleichung ist eine lineare Rekursion. Wir können sie lösen, indem wir sie mehrmals ausklappen:

$\begin{aligned} & T(n)=T(n-1)+3 \\ & =(T(n-2)+3)+3 \\ & =((T(n-3)+3)+3)+3 \\ & =\ldots \\ & =3 n+T(0)\end{aligned}$

$\operatorname{Da} T(0)=O(1)$, ist die Lösung $T(n)=\Theta(n)$.

## (iii) $T(n)=2 T\left(\frac{n}{3}\right)+3 n^2$

Wir können wieder das Master-Theorem verwenden. In diesem Fall haben wir $a=2, b=3$, und $f(n)=3 n^2$.

In unserem Fall ist $f(n)=3 n^2=\Omega\left(n^c\right)$ mit $c>\log _b a=$ $\log _3 2$, und die Bedingung $a f(n / b) \leq k f(n)$ für ein $k<1$ und alle hinreichend großen $n$ ist erfullt. Daher sind wir im dritten Fall des Master-Theorems, und die Lösung ist $T(n)=\Theta\left(n^2\right)$.

# (b) Sortieren Sie die Laufzeiten aufsteigend basierend auf der O-Notation.

1. $T(n)=\Theta(n)$
2. $T(n)=\Theta(n \log n)$
3. $T(n)=\Theta\left(n^2\right)$

# 3. Dreisummenproblem
Betrachten Sie das folgende Algorithmische Problem:
Gegeben: Eine Folge $X$ von Zahlen aus $\mathbb{Z}$.
Gesucht: Alle Tripel $a, b, c \in X$ von Zahlen mit mit $a+b=c$.
# (a) Beschreiben verbal oder mit Pseudocode einen naiven Algorithmus für dieses Problem. Was ist die Laufzeit Ihres Algorithmus?
```
für jedes Element a in X:
    für jedes Element b in X:
        für jedes Element c in X:
            wenn a + b == c:
                gib (a, b, c) aus
```

Die Laufzeit dieses Algorithmus ist $O\left(n^3\right)$, da wir drei verschachtelte Schleifen haben, die jeweils über die gesamte Sequenz iterieren.

# (b) Beschreiben verbal oder im Pseudocode Sie einen Algorithmus mit einer Laufzeit von $\Theta\left(n^2\right)$ für das Problem. Beweisen Sie, dass Ihr Algorithmus wirklich diese Laufzeit hat.
```
sortiere X
für jedes Element a in X:
    für jedes Element b in X:
        wenn a + b in X:
            gib (a, b, a+b) aus
```

Die Laufzeit dieses Algorithmus ist $O\left(n^2\right)$ für die beiden verschachtelten Schleifen, die über die Sequenz iterieren, plus $O(n \log n)$ für das Sortieren der Sequenz. Da $n^2$ größer ist als $n \log n$ für große $n$, dominiert der $n^2$-Teil die Laufzeit, und wir können sagen, dass die Laufzeit des Algorithmus $O\left(n^2\right)$ ist.

# (c) Implementieren Sie Ihren effizienten Algorithmus in `C++`.
```cpp
#include <vector>
#include <iostream>

void bubbleSort(std::vector<int>& zahlen) {
    unsigned n = zahlen.size();
    for (unsigned i = 0; i < n - 1; ++i) {
        for (unsigned j = 0; j < n - i - 1; ++j) {
            if (zahlen[j] > zahlen[j + 1]) {
                std::swap(zahlen[j], zahlen[j + 1]);
            }
        }
    }
}

bool binareSuche(std::vector<int>& zahlen, int start, int ende, int ziel) {
    while (start <= ende) {
        int mitte = start + (ende - start) / 2;
        if (zahlen[mitte] == ziel) {
            return true;
        } else if (zahlen[mitte] < ziel) {
            start = mitte + 1;
        } else {
            ende = mitte - 1;
        }
    }
    return false;
}

/*
Funktion: sucheTriplets(std::vector<int>& X)
Voraussetzungen:
- Die Funktion nimmt als Argument einen Vektor von Ganzzahlen (std::vector<int>).
- Der Vektor kann leer sein oder eine beliebige Anzahl von Ganzzahlen enthalten.
- Die Zahlen im Vektor können positiv, negativ oder null sein.
- Es wird angenommen, dass die Größe des Vektors in einem Bereich liegt, der für die verfügbare Speicherkapazität und Rechenleistung des Systems handhabbar ist.

Ergebnis:
- Die Funktion gibt kein Ergebnis zurück (void Rückgabetyp).
- Die Funktion druckt alle Tripel von Zahlen in der Eingabesequenz aus, für die die Summe der ersten beiden Zahlen gleich der dritten Zahl ist. Jedes Tripel wird in der Form "(a, b, c)" ausgegeben, wobei "a + b = c" gilt.
- Wenn keine solchen Tripel existieren, gibt die Funktion nichts aus.

Effekte:
- Die Funktion sortiert den Eingabevektor. Daher wird der Zustand des Eingabevektors geändert: die Elemente werden in aufsteigender Reihenfolge angeordnet.
- Die Funktion hat keinen weiteren Seiteneffekt auf den Zustand des Programms. Sie ändert keine globalen Variablen und hat keine Auswirkungen auf den Zustand des Systems außerhalb des Programms.
- Die Funktion kann eine beträchtliche Menge an Ausgabe produzieren, wenn viele gültige Tripel existieren. Dies könnte die Leistung des Systems beeinträchtigen, wenn die Ausgabe in eine Datei umgeleitet wird oder wenn das System über begrenzte Ressourcen für die Ausgabeverwaltung verfügt.
- Die Funktion verwendet zusätzlichen Speicher für das unordered_set, das zur Speicherung der Elemente des Eingabevektors verwendet wird. Die Menge des benötigten Speichers ist proportional zur Größe des Eingabevektors.
*/

void findeTripel(std::vector<int>& zahlen) {
    bubbleSort(zahlen);

    for (unsigned i = 0; i < zahlen.size(); ++i) {
        for (unsigned j = i + 1; j < zahlen.size(); ++j) {
            int summe = zahlen[i] + zahlen[j];
            if (binareSuche(zahlen, 0, zahlen.size() - 1, summe)) {
                std::cout << "(" << zahlen[i] << ", " << zahlen[j] << ", " << summe << ")\n";
            }
        }
    }
}

int main() {
    std::vector<int> zahlen = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    findeTripel(zahlen);
    return 0;
}
```
