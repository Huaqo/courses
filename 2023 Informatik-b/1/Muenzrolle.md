# Abwägen

## 1.
Wenn Sie nur jeweils eine Rolle gegen eine andere abwägen dürfen, dann ist die Methode der **binären Suche** das effizienteste Verfahren. Hier ist, wie Sie es tun könnten:

Vergleichen Sie die Rollen 1 und 2. Wenn sie gleich schwer sind, gehen Sie zur Rolle 3 und so weiter. Wenn sie unterschiedlich schwer sind, haben Sie das Falschgeld gefunden.
Wiederholen Sie diesen Vorgang, bis Sie das Falschgeld gefunden haben.

Im schlimmsten Fall müssten Sie 11 Vergleiche durchführen, um das Falschgeld zu finden (wenn das Falschgeld in der letzten Rolle ist).



## 2. 
    Wenn Sie mehrere Rollen gegeneinander wägen dürfen, dann können Sie das Problem mit nur 3 Vergleichen lösen. Hier ist ein möglicher Weg:

    - Vergleich 1: Nehmen Sie die ersten 4 Rollen (1-4) und wägen Sie sie gegen die nächsten 4 Rollen (5-8). Es gibt zwei Möglichkeiten:
        - Wenn sie gleich schwer sind, liegt das Falschgeld in den Rollen 9-12. Gehen Sie zu Vergleich 2a.
        - Wenn sie unterschiedlich schwer sind, liegt das Falschgeld in den Rollen 1-8. Gehen Sie zu Vergleich 2b.
    - Vergleich 2a: Wägen Sie die Rollen 9 und 10 gegen die Rollen 11 und 12. Hier finden Sie heraus, welche Rolle das Falschgeld enthält und ob es leichter oder schwerer ist.
    - Vergleich 2b: Wägen Sie drei der verdächtigen Rollen (zum Beispiel 1, 2, 3) gegen drei Rollen, von denen Sie wissen, dass sie echt sind (zum Beispiel 9, 10, 11). Es gibt zwei Möglichkeiten:
        - Wenn sie gleich schwer sind, liegt das Falschgeld in der verbliebenen verdächtigen Rolle (4). Sie wissen auch, dass das Falschgeld schwerer ist, weil die verdächtigen Rollen bei dem ersten Vergleich schwerer waren.
        - Wenn sie unterschiedlich schwer sind, liegt das Falschgeld in den drei verdächtigen Rollen (1, 2, 3). Gehen Sie zu Vergleich 3.
    - Vergleich 3: Wägen Sie zwei der verdächtigen Rollen (zum Beispiel 1 und 2) gegeneinander. Hier finden Sie heraus, welche Rolle das Falschgeld enthält und ob es leichter oder schwerer ist.
