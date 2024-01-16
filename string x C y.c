#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Function to initialize an empty stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

// Function to push a character onto the stack
void push(struct Stack *stack, char value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = value;
}

// Function to pop a character from the stack
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Function to determine if the input string is of the form "x C y"
int isFormXY(char input[]) {
    struct Stack stack;
    initialize(&stack);

    int len = strlen(input);

    // Push the characters of x onto the stack
    for (int i = 0; i < len / 2; i++) {
        push(&stack, input[i]);
    }

    // Compare the remaining characters with the characters popped from the stack
    for (int i = (len + 1) / 2; i < len; i++) {
        if (isEmpty(&stack) || input[i] != pop(&stack)) {
            return 0; // Not of the form "x C y"
        }
    }

    return 1; // It is of the form "x C y"
}

int main() {
    char input[MAX_SIZE];

    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    if (isFormXY(input)) {
        printf("The string is of the form 'x C y'\n");
    } else {
        printf("The string is not of the form 'x C y'\n");
    }

    return 0;
}
