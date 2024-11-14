# 1. Gierige Algorithmen

## a)
Gegeben:

Eine Liste L von n Dateien. Jede Datei i hat eine Größe s_i und eine Zugriffswahrscheinlichkeit p_i. Da die Wahrscheinlichkeit für alle Dateien gleich ist, ist p_i = 1/n für alle i.

Ein Bandspeicher.

Gesucht:

Eine optimale Reihenfolge der Dateien auf dem Band, um die erwartete Zugriffszeit zu minimieren. Die Zugriffszeit auf eine Datei i ist gleich der Summe der Größen aller Dateien, die vor i auf dem Band stehen.

## b)

Eine einfache gierige Strategie zur Lösung dieses Problems wäre, die Dateien in aufsteigender Reihenfolge ihrer Größe auf das Band zu schreiben. Der gierige Algorithmus sortiert die Dateien nach ihrer Größe und schreibt sie in dieser Reihenfolge auf das Band.

1. Eingabe: Liste L von Dateien mit Größen s_i
2. Sortiere L in aufsteigender Reihenfolge nach s_i
3. Schreibe die Dateien in der sortierten Reihenfolge auf das Band

## c)
Angenommen, wir haben eine optimale Reihenfolge O und die gierige Reihenfolge G, und O unterscheidet sich von G. Wir können immer zwei benachbarte Dateien in O finden, die in umgekehrter Reihenfolge im Vergleich zu G angeordnet sind, d.h. eine größere Datei steht vor einer kleineren.

Wir nehmen diese beiden Dateien und tauschen sie. Dieser Tausch führt zu einer Reduzierung oder zumindest zu keiner Änderung der gesamten Zugriffszeit, da jede Zugriffsoperation auf die größere Datei jetzt weniger kostet. Dieser Tausch verletzt nicht die Ordnung der restlichen Dateien.

Indem wir dieses Verfahren wiederholen, können wir die Reihenfolge O allmählich in die Reihenfolge G umwandeln, ohne dass die Gesamtzugriffszeit steigt. Daher muss G mindestens genauso gut sein wie jede andere Reihenfolge, einschließlich O. Daher ist G optimal.

## d)
d4,d1,d3,d6,d2,d5

