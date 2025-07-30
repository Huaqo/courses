// hastable

#include<ctype.h>

typedef struct node {
    char *name;
    char *number;
    struct Node *next;
} Node ;

node *table[26];

unsigned int hash(const char *word){
    return toupper(word[0]) - 'A';
}


// tries

typedef struct node{
    struct node *children[26];
    char *number;
} Node;

node *trie;