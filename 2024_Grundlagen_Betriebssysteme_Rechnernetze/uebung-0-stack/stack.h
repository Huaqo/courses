#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct stack{
    int size;
    char* array;
    int length;
} stack_t;

stack_t* stack_create(size_t size);

void stack_delete(stack_t* stack);

size_t stack_length(stack_t* stack);

int stack_push(stack_t* stack,char c);

int stack_pop(stack_t* stack, char* dest);

#endif 