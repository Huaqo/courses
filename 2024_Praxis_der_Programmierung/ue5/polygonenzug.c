#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

//  Structs

typedef struct point {
    float x;
    float y;
} Point;

typedef struct Node {
    Point *pt;
    struct Node *next;
} Node;

typedef struct Polygonenzug {
    Node *head;    
} Polygonenzug;

//  Methods

Point *create_point(float a, float b){
    Point *pt = (Point *)malloc(sizeof(Point));
    if (pt == NULL) {
        fprintf(stderr, "Memory allocation failed for Point.\n");
        exit(EXIT_FAILURE);
    }
    pt->x=a;
    pt->y=b;
    return pt;
}

Polygonenzug* create_list() {
    Polygonenzug* pzug = (Polygonenzug*)malloc(sizeof(Polygonenzug));
    if (pzug == NULL) {
        fprintf(stderr, "Memory allocation failed for Polygonzug.\n");
        exit(EXIT_FAILURE);
    }
    pzug->head = NULL;
    return pzug;
}

void append(Polygonenzug *pzug, Point *pt){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed for new_node in append.\n");
        exit(EXIT_FAILURE);
    }
    new_node->pt = pt;
    new_node->next = NULL;

    if (pzug->head == NULL){
        pzug->head = new_node;
    } else {
        Node * temp = pzug->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void shorten(Polygonenzug *pzug){
    
    // Wenn Liste leer
    if (pzug->head == NULL){
        printf("The list is empty.\n");
        return;
    }
    
    // Wenn nur ein Knoten
    if (pzug->head->next == NULL){
        free(pzug->head->pt);
        pzug->head->pt = NULL;
        free(pzug->head);
        pzug->head = NULL;
        printf("Die Liste wurde geloescht.\n");
        return;
    }

    
    // Wenn mehrere Knoten
    Node * temp = pzug->head;
    while(temp->next && temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next->pt);
    free(temp->next);
    temp->next = NULL;
}

void insert(Polygonenzug *pzug, Point *pt, int index){
    
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed for new_node in insert.\n");
        exit(EXIT_FAILURE);
    }
    new_node->pt = pt;
    new_node->next = NULL;

    // Wenn index 0
    if(index == 0){
        new_node->next = pzug->head;
        pzug->head = new_node;
        return;
    }

    // Groesse der liste checken
    int i = 0;
    Node *temp = pzug->head;

    if(temp == NULL){
        printf("Cannot insert at index %d in an empty list.\n", index);
        free(new_node);
        return;
    }

    while(temp != NULL && i < index - 1){
        temp = temp->next;
        i++;
    }

    // Wenn index > 0
    if(temp != NULL){
        new_node->next = temp->next;
        temp->next = new_node;
    } else{
        printf("Index is outside the list bounds.\n");
        free(new_node);
        return;
    }
}

Polygonenzug *mirror(Polygonenzug *pzug){
    Polygonenzug *pzug2 = create_list();

    Node *temp = pzug->head;
    while(temp != NULL){
        Node * new_node = (Node*)malloc(sizeof(Node));
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation failed for new_node in mirror.\n");
            exit(EXIT_FAILURE);
        }
        Point *new_pt = create_point(temp->pt->x, temp->pt->y);
        new_node->pt = new_pt;
        new_node->next = pzug2->head;
        pzug2->head = new_node;
        temp = temp->next;
    }

    return pzug2;
}


void pretty_print(Polygonenzug *pzug){
    
    Node *index = pzug->head;
    
    while(index != NULL){
        printf("%f , %f\n", index->pt->x, index->pt->y);
        index = index->next;
    }
}

void free_list(Polygonenzug *pzug){
    Node *current = pzug->head;
    while(current != NULL){
        Node *next_node = current->next;
        free(current->pt);
        free(current);
        current = next_node;
    }
    free(pzug);
}


int main(){
    Point *p1 = create_point(3.0f,4.0f);
    Point *p2 = create_point(5.0f,6.0f);
    Point *p3 = create_point(8.0f, 9.0f);

    Polygonenzug *pzug = create_list();
    printf("Pzug after Append p1:\n");
    append(pzug, p1);
    pretty_print(pzug);
    
    printf("Pzug after Append p2:\n");
    append(pzug, p2);
    pretty_print(pzug);

    printf("Pzug after Insert p3:\n");
    insert(pzug, p3, 1);
    pretty_print(pzug);

    Polygonenzug *pzug2 = mirror(pzug);

    // Test shorten
    printf("Pzug after Shorten:\n");
    shorten(pzug);
    pretty_print(pzug);
    printf("Pzug after Shorten:\n");
    shorten(pzug);
    pretty_print(pzug);

    // Test shorten liste loeschen
    printf("Pzug after Shorten:\n");
    shorten(pzug);
    pretty_print(pzug);
    
    // Test shorten leer
    printf("Pzug after Shorten:\n");
    shorten(pzug);
    pretty_print(pzug);

    // Test mirror
    printf("Pzug2:\n");
    pretty_print(pzug2);

    free_list(pzug);
    free_list(pzug2);

    return 0;
}