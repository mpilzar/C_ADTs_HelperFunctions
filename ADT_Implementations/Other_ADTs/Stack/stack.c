#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

typedef struct {
    int items[STACK_SIZE];
    int top;
} Stack;

void stack_initialize(Stack* stack) {
    stack->top = -1;
}

int stack_isempty(Stack* stack) {
    return stack->top == -1;
}

int stack_isfull(Stack* stack) {
    return stack->top == STACK_SIZE - 1;
}

void stack_push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->items[++stack->top] = value;
}

int stack_pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->items[stack->top--];
}

int stack_peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->items[stack->top];
}