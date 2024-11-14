#include <stdio.h>
#include "stack.h"

int main() {

    stack_t* stack = stack_create(5);

    if(stack == NULL){
        printf("Failed to create stack\n");
        return 1;
    }

    if (stack_push(stack, 'A') != 0) {
        printf("Error: failed to push onto stack\n");
        stack_delete(stack);
        return 1;
    }

    if (stack_push(stack, 'B') != 0) {
        printf("Error: failed to push onto stack\n");
        stack_delete(stack);
        return 1;
    }
    
    if (stack_push(stack, 'C') != 0) {
        printf("Error: failed to push onto stack\n");
        stack_delete(stack);
        return 1;
    }

    printf("Stack length is %zu\n", stack_length(stack));

    char popped;
    if (stack_pop(stack, &popped) != 0){
        printf("Error: failed to pop from stack\n");
        stack_delete(stack);
        return 1;
    }
    
    printf("Popped element: %c\n", popped);

    if (stack_pop(stack, &popped) != 0){
        printf("Error: failed to pop from stack\n");
        stack_delete(stack);
        return 1;
    }

    printf("Popped element: %c\n", popped);

    printf("Stack length is %zu\n", stack_length(stack));

    stack_delete(stack);

    return 0;
}