#include "../inc/exp_sys.h"


struct Stack *createStack(unsigned cap) {
    struct  Stack* stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = cap;
    stack->top = -1;
    stack->array = (char *) malloc(stack->capacity * sizeof(char));
    return stack;
}

int     isFull(struct Stack* stack) {
    return (unsigned)stack->top == stack->capacity - 1;
}

int     isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

char    lastItem(struct Stack *stack) {
    if (isEmpty(stack))
        return CHAR_MIN;
    return (stack->array[stack->top]);
}

void push(struct Stack *stack, char item) {
    if (isFull(stack)) return ;
    stack->array[++stack->top] = item;
}

char    pop(struct Stack *stack) {
    if (isEmpty(stack))
        return CHAR_MIN;
    return (stack->array[stack->top--]);
}