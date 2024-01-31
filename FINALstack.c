#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Stack implementation
struct Stack {
    int top;
    int items[MAX_SIZE];
};

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int item) {
    if (!isFull(stack)) {
        stack->items[++stack->top] = item;
        printf("%d pushed to the stack\n", item);
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (!isEmpty(stack)) {
        int poppedItem = stack->items[stack->top--];
        printf("%d popped from the stack\n", poppedItem);
        return poppedItem;
    } else {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
}

// Function to peek at the top element of the stack without removing it
int peek(struct Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top];
    } else {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
}

// Function to display the elements of the stack
void display(struct Stack *stack) {
    if (!isEmpty(stack)) {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->items[i]);
        }
        printf("\n");
    } else {
        printf("Stack is empty\n");
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Top element of the stack: %d\n", peek(&stack));

    pop(&stack);
    pop(&stack);

    display(&stack);

    return 0;
}
