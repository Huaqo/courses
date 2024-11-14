#include "stack.h"
#include <stdlib.h>

stack_t *stack_create(size_t size) {
    stack_t* stack = (stack_t*) malloc(sizeof(stack_t));
    if (stack == NULL) {
        return NULL;
    }
    stack->array = (char*) malloc(size * sizeof(char));
    if (stack->array == NULL) {
        free(stack);
        return NULL;
    }
    stack->size = size;
    stack->length = 0;
    return stack;
}

void stack_delete(stack_t *stack) {
    if (stack != NULL) {
        free(stack->array);
        free(stack);
    }
}

size_t stack_length(stack_t *stack) {
    return stack->length; 
}

int stack_push(stack_t *stack, char c) {
    if (stack->length >= stack->size) {
        return -1;
    }
    stack->array[stack->length] = c;
    stack->length++;
    return 0;
}

int stack_pop(stack_t *stack, char *dest) {
    if (stack->length == 0) {
        return -1;
    }
    *dest = stack->array[stack->length - 1];
    stack->length--;
    return 0;
}