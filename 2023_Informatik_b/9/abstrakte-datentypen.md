# Übung 9

## 2. Abstrakte Datentypen

### (a) Linked List

Eine Queue kann mit Hilfe einer verketteten Liste implementiert werden, indem wir zwei Zeiger verwenden, die auf das vorderste (Front) und das hinterste Element (Rear) der Liste zeigen. Die Knoten der verketteten Liste müssen einen Zeiger auf den nächsten Knoten in der Liste sowie den eigentlichen Wert speichern.

```
is_empty():
    Überprüfe, ob der Front Zeiger auf null zeigt. Wenn ja, ist die Queue leer und die Methode gibt true zurück. Andernfalls gibt die Methode false zurück.

dequeue():
    // Überprüfe zuerst, ob die Queue leer ist.
    if is_empty(): 
        // Wenn ja, werfe eine Exception oder gebe eine Fehlermeldung aus.
        raise Exception("Queue is empty")
    else:
        // Wenn die Queue nicht leer ist, speichere den Wert des Front Knotens.
        temp = front.value
        // Verschiebe den Front Zeiger auf den nächsten Knoten in der Liste.
        front = front.next
        // Wenn Front jetzt null ist (die Queue ist leer), setze Rear auch auf null.
        if front is null: 
        rear = null
        // Gib den gespeicherten Wert zurück.
        return temp    

front():
    Überprüfe, ob die Queue leer ist. Wenn ja, werfe eine Exception oder gebe eine Fehlermeldung aus.
    Wenn die Queue nicht leer ist, gebe einfach den Wert des Front Knotens zurück.
    
enqueue(x):
    // Erstelle einen neuen Knoten mit dem Wert x.
    newNode = new Node(x)
    
    // Überprüfe, ob die Queue leer ist.
    if is_empty(): 
        // Wenn die Queue leer ist, setze Front und Rear auf den neuen Knoten.
        front = newNode
        rear = newNode
    else:
        // Wenn die Queue nicht leer ist, hänge den neuen Knoten an das Ende der Liste an.
        rear.next = newNode
        // Aktualisiere den Rear Zeiger auf den neuen Knoten.
        rear = newNode
```

### (b) Dynamisches Array

Das Konzept des Wrap-Arounds bedeutet, dass das Ende der Warteschlange mit dem Anfang des Arrays verbunden wird, um den begrenzten Speicherplatz optimal zu nutzen.

```
enqueue(x):
  // Überprüfe, ob die Queue voll ist. Dies ist der Fall, wenn das nächste Element nach "rear" der "front"-Index ist.
  if (rear + 1) % size == front:
    // Wenn die Queue voll ist, erweitere das Array oder gebe eine Fehlermeldung aus.
    raise Exception("Queue is full")
  else:
    // Wenn die Queue nicht voll ist, füge das Element an der "rear"-Position ein.
    array[rear] = x
    // Aktualisiere den "rear"-Index mit einem Wrap-Around.
    rear = (rear + 1) % size

dequeue():
  // Überprüfe zuerst, ob die Queue leer ist. Dies ist der Fall, wenn "front" und "rear" gleich sind.
  if front == rear:
    // Wenn ja, werfe eine Exception oder gebe eine Fehlermeldung aus.
    raise Exception("Queue is empty")
  else:
    // Wenn die Queue nicht leer ist, speichere den Wert an der "front"-Position.
    temp = array[front]
    // Aktualisiere den "front"-Index mit einem Wrap-Around.
    front = (front + 1) % size
    // Gib den gespeicherten Wert zurück.
    return temp

front():
  // Überprüfe, ob die Queue leer ist.
  if front == rear:
    // Wenn ja, werfe eine Exception oder gebe eine Fehlermeldung aus.
    raise Exception("Queue is empty")
  else:
    // Wenn die Queue nicht leer ist, gebe einfach den Wert an der "front"-Position zurück.
    return array[front]

is_empty():
  // Überprüfe, ob der "front"- und "rear"-Index gleich sind. Wenn ja, ist die Queue leer und die Methode gibt true zurück.
  return front == rear
```

## 3. ADT Wörterbuch

### (b)

#### (i)

```
Funktion Bereichsabfrage(Array, a, b):
    IndexA = binäreSuche(Array, a)
    IndexB = binäreSuche(Array, b)
    
    wenn IndexA ist nicht gefunden oder IndexB ist nicht gefunden:
        Rückgabe 'Elemente nicht gefunden'
    
    für i = IndexA bis IndexB:
        print Array[i]
```

#### (ii)

```
Beginnen Sie bei der Wurzel des Baums.
Wenn der Schlüssel des aktuellen Knotens kleiner als a ist, suchen Sie im rechten Unterbaum.
Wenn der Schlüssel des aktuellen Knotens größer als b ist, suchen Sie im linken Unterbaum.
Wenn der Schlüssel des aktuellen Knotens zwischen a und b liegt, dann fügen Sie den Knoten in die Ergebnisliste ein und suchen Sie sowohl im linken als auch im rechten Unterbaum.
```

Diese Suche kann rekursiv durchgeführt werden und gibt alle Elemente zurück, die zwischen a und b liegen.

## 4. Move

### (a)

Der Move-Konstruktor und der Move-Assignment Operator sind Funktionen in C++, die Teil des Konzepts des "Ressourcenausnahmeprinzips" (Resource Acquisition Is Initialization, RAII) sind. Sie ermöglichen die effiziente Übertragung von Ressourcen, wie beispielsweise dynamisch alloziertem Speicher, von einem Objekt auf ein anderes, ohne dass eine unnötige Kopie der Ressourcen erfolgt.

In C++ wird dies durch die Verwendung von sogenannten Rvalue-Referenzen ermöglicht, die mit dem sogenannten "Move-Semantik" verbunden sind. Die Rvalue-Referenz wird durch das "&&" -Symbol gekennzeichnet. Der Move-Konstruktor wird verwendet, um ein Objekt aus einem temporären (Rvalue-) Objekt zu konstruieren, während der Move-Assignment Operator verwendet wird, um einem bereits vorhandenen Objekt die Ressourcen eines temporären Objekts zuzuweisen.

```cpp
// Move-Konstruktor
class MyClass {
public:
    MyClass(MyClass&& other) {

    }
};
```

```cpp
// Move-Assignment Operator
class MyClass {
public:
    MyClass& operator=(MyClass&& other) {
        if (this != &other) {
        }
        return *this;
    }
};
```
