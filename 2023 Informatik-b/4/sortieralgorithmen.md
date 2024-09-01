# 3. Sortieralgorithmen

## a)

Bubblesort ist ein einfacher Sortieralgorithmus, der wiederholt **benachbarte Elemente in einer Liste vergleicht** und sie bei Bedarf vertauscht, bis die gesamte Liste sortiert ist. Der Algorithmus erhält seinen Namen aufgrund der Art und Weise, wie die **größten (oder kleinsten) Elemente "nach oben blubbern"**, ähnlich wie Blasen in einem aufsteigenden Strom.

Der Ablauf des Bubblesort-Algorithmus kann wie folgt beschrieben werden:

1. Beginne mit einer ungeordneten Liste von Elementen.
2. Vergleiche jeweils benachbarte Elemente der Liste. Wenn das linke Element größer (oder kleiner, abhängig von der Sortierreihenfolge) ist als das rechte Element, vertausche sie.
3. Wiederhole diesen Schritt für jedes Paar benachbarter Elemente in der Liste, bis das größte (oder kleinste) Element an die letzte Position der Liste "blubbert".
4. Reduziere die Größe des zu sortierenden Bereichs um 1 und wiederhole Schritt 2 und 3, bis die Liste vollständig sortiert ist.

Der Bubblesort-Algorithmus hat eine Zeitkomplexität von $O(n^2)$, was bedeutet, dass die Anzahl der Vergleiche und Vertauschungen quadratisch mit der Größe der Liste wächst. Es ist daher nicht effizient für große Listen.

Quellen:

- GeeksforGeeks. "Bubble Sort." https://www.geeksforgeeks.org/bubble-sort/
- Wikipedia. "Bubble sort." https://en.wikipedia.org/wiki/Bubble_sort

## c)

Bogosort, auch bekannt als "Monkey Sort" oder "Random Sort", ist ein extrem **ineffizienter Sortieralgorithmus**, der auf dem **Zufall** basiert. Der Algorithmus folgt einem einfachen Prinzip: Überprüfe, ob die gegebene Liste sortiert ist. Wenn nicht, mische die Elemente zufällig und überprüfe erneut. Dieser Vorgang wird so lange wiederholt, bis die Liste tatsächlich sortiert ist.

1. Der Ablauf des Bogosort-Algorithmus kann wie folgt beschrieben werden:
2. Überprüfe, ob die Liste sortiert ist. Wenn ja, beende den Algorithmus.
3. Falls die Liste nicht sortiert ist, mische die Elemente zufällig.
4. Überprüfe erneut, ob die Liste sortiert ist. Wenn nicht, gehe zu Schritt 2.

Der Bogosort-Algorithmus hat keine feste Zeitkomplexität. In der schlechtesten Fallannahme kann es jedoch eine unendliche Anzahl von Mischungen erfordern, um eine sortierte Liste zu erhalten. Das bedeutet, dass die Laufzeit des Algorithmus im schlimmsten Fall unbegrenzt ist.

Aufgrund dieser extremen Ineffizienz wird der Bogosort-Algorithmus nicht für die praktische Sortierung verwendet.

Quellen:

- GeeksforGeeks. "Bogosort." https://www.geeksforgeeks.org/bogosort-permutation-sort/
- Wikipedia. "Bogosort." https://de.wikipedia.org/wiki/Bogosort

Warum sollte man den Algorithmus nicht mit langen Listen testen?

Da der Bogosort-Algorithmus zufällige Mischungen verwendet, um die Sortierung zu erreichen, kann die Laufzeit des Algorithmus sehr lange dauern. Mit zunehmender Größe der Liste steigt die Anzahl der möglichen Permutationen exponentiell an. Das bedeutet, dass die Wahrscheinlichkeit, dass der Algorithmus eine sortierte Liste findet, mit zunehmender Listenlänge sehr gering wird. Für längere Listen ist der Algorithmus praktisch nutzlos und unpraktikabel. Es ist viel effizienter, andere Sortieralgorithmen zu verwenden, die eine bessere Leistungsgarantie bieten.