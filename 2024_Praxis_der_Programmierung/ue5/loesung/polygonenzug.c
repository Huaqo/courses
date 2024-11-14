#include <stdio.h>
#include <stdlib.h>

// Definition eines Punktes
typedef struct Point {
    int x;
    int y;
    struct Point* next;
} Point;

// Funktion zum Erstellen eines neuen Punktes
Point* create_point(int x, int y) {
    Point* new_point = (Point*)malloc(sizeof(Point));
    if (new_point == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    new_point->x = x;
    new_point->y = y;
    new_point->next = NULL;
    return new_point;
}

// Funktion zum Anhängen eines Punktes an das Ende der Liste
void append(Point** head, int x, int y) {
    Point* new_point = create_point(x, y);
    if (*head == NULL) {
        *head = new_point;
        return;
    }
    Point* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_point;
}

// Funktion zum Entfernen des letzten Punktes aus der Liste
int shorten(Point** head) {
    if (*head == NULL) {
        return -1; // Liste ist leer
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return 0;
    }
    Point* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return 0;
}

// Funktion zum Ausgeben der Punkte in der Liste
void pretty_print(Point* head) {
    Point* temp = head;
    while (temp != NULL) {
        printf("(%d, %d) -> ", temp->x, temp->y);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Funktion zum Einfügen eines Punktes an einer bestimmten Position
int insert(Point** head, int pos, int x, int y) {
    if (pos < 0) {
        return -1; // Ungültige Position
    }
    Point* new_point = create_point(x, y);
    if (pos == 0) {
        new_point->next = *head;
        *head = new_point;
        return 0;
    }
    Point* temp = *head;
    for (int i = 0; i < pos - 1; i++) {
        if (temp == NULL) {
            free(new_point);
            return -1; // Position außerhalb der Liste
        }
        temp = temp->next;
    }
    new_point->next = temp->next;
    temp->next = new_point;
    return 0;
}

// Funktion zum Spiegeln der Liste
int mirror(Point** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return -1; // Leere Liste oder nur ein Element
    }
    Point* prev = NULL;
    Point* current = *head;
    Point* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    return 0;
}

// Hauptfunktion zum Testen der Implementierung
int main() {
    Point* head = NULL;

    // Testen der append-Funktion
    append(&head, 1, 2);
    append(&head, 3, 4);
    pretty_print(head);

    // Testen der shorten-Funktion
    shorten(&head);
    pretty_print(head);
    shorten(&head);
    pretty_print(head);
    shorten(&head); // Sollte -1 zurückgeben, da die Liste leer ist

    // Testen der insert-Funktion
    insert(&head, 0, 5, 6);
    insert(&head, 1, 7, 8);
    pretty_print(head);

    // Testen der mirror-Funktion
    mirror(&head);
    pretty_print(head);

    return 0;
}

/*

punkt (x,y)

shorten(input: head, output: int (-1 nihctvgekalppt (bei leerer Liste, 0 hat geklappt)
 free(speicherdresse von letztes element), vorletzten next auf null setzen,

next von next (übernächstes)
wenn liste nur noch ein element: head von nächstes auf null


insert: (input: head, pos, le), output: 0,-1(
-liste leer
-position außerhalb liste pos> len(head)
- erstes,
- insert: nur elemente an position einfügen, die zurzeit schin besetzsind
- nihct letzte Element+1 als position möglich keine verlängerung sondern nur zwischen vorhanden elementen! möglich muss zwischen elemente gepackt werden
- 

mirror: input:head, ouput: int (-1(leere liste),0)
randfalle (ranfälle als komentar: wenn nru ein element, oer leer kein mirror möglich)
1. leere liste -> -1
2. 1 element -> -1

nxt pointer auf vorherigr le setzen

pretty print 

*/

