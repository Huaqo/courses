#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node{
    int data;
    struct node* next;
} Node;

typedef Node* Linkedlist;

Node* createNode(int data);

void insertAtBeginning(LinkedList* head, int data);

void insertAtEnd(LinkedList* head, int data);

void deleteNode(LinkedList* head, int key);

void printList(LinkedList head);

#endif