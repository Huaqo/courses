#include <iostream>

// Definiere eine Vorlage für die Klasse QueueList.
// Diese Klasse implementiert eine Warteschlange mit einer verketteten Liste.
template <typename E>
class QueueList
{
private:
    // Definition eines Knotens, der einen Wert und einen Zeiger auf den nächsten Knoten hat.
    struct Node
    {
        E value;
        Node *next;
    };

    // Zeiger auf den Anfang und das Ende der Warteschlange und eine Zählvariable für die Größe.
    Node *head;
    Node *tail;
    int count;

public:
    // Konstruktor initialisiert Zeiger und Zähler mit Nullwerten.
    QueueList() : head(nullptr), tail(nullptr), count(0) {}

    // Destruktor löscht alle Elemente in der Warteschlange.
    // Voraussetzung: keine
    // Effekt: Alle Elemente in der Warteschlange werden gelöscht
    // Ergebnis: Keines
    ~QueueList()
    {
        while (!is_empty())
        {
            dequeue();
        }
    }

    // Überprüft, ob die Warteschlange leer ist.
    // Voraussetzung: keine
    // Effekt: Keiner
    // Ergebnis: Wenn die Warteschlange leer ist, ist 'true' geliefert, sonst ist 'false' geliefert
    bool is_empty() const
    {
        return count == 0;
    }

    // Gibt die Größe der Warteschlange zurück.
    // Voraussetzung: keine
    // Effekt: Keiner
    // Ergebnis: Die Anzahl der Elemente in der Warteschlange wird zurückgegeben
    unsigned size() const
    {
        return count;
    }

    // Gibt das erste Element der Warteschlange zurück.
    // Voraussetzung: Die Warteschlange ist nicht leer
    // Effekt: Keiner
    // Ergebnis: Das vorderste Element wird zurückgegeben
    E front() const
    {
        if (is_empty())
        {
            throw std::runtime_error("Queue is empty");
        }
        return this->head->value;
    }

    // Fügt ein Element am Ende der Warteschlange ein.
    // Voraussetzung: Keine
    // Effekt: Das übergebene Element wird hinten in die Warteschlange eingefügt
    // Ergebnis: Keines
    void enqueue(E x)
    {
        Node *newNode = new Node();
        newNode->value = x;
        newNode->next = nullptr;

        if (tail != nullptr)
        {
            tail->next = newNode;
        }

        tail = newNode;

        if (is_empty())
        {
            head = newNode;
        }

        count++;
    }

    // Entfernt das erste Element der Warteschlange und gibt seinen Wert zurück.
    // Voraussetzung: Die Warteschlange ist nicht leer
    // Effekt: Das vorderste Element wird aus der Warteschlange entfernt
    // Ergebnis: Das vorderste Element wird zurückgegeben
    E dequeue()
    {
        if (is_empty())
        {
            throw std::runtime_error("Queue is empty");
        }

        Node *tempNode = head;
        E value = head->value;

        head = head->next;

        if (head == nullptr)
        {
            tail = nullptr;
        }

        delete tempNode;
        count--;

        return value;
    }
};

int main()
{
    // Erstellt eine Warteschlange und fügt die Werte 3, 5 und 2 hinzu. Dann wird das vorderste Element angezeigt und zwei Elemente werden entfernt.
    // Überprüft schließlich, ob die Warteschlange leer ist.
    QueueList<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    std::cout << q.front() << std::endl;    // Erwartetes Ergebnis: 1
    std::cout << q.dequeue() << std::endl;  // Erwartetes Ergebnis: 1
    std::cout << q.dequeue() << std::endl;  // Erwartetes Ergebnis: 2
    std::cout << q.is_empty() << std::endl; // Erwartetes Ergebnis: 0
    std::cout << std::endl;
}
