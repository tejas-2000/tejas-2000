#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to check if a character is an operator //
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // Assuming '(' has the lowest precedence
}

// Stack structure
struct Stack {
    int top;
    char array[MAX_SIZE];
};

// Function prototypes for stack operations
void initializeStack(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, char item);
char pop(struct Stack* stack);
char peek(struct Stack* stack);

// Function to convert infix expression to postfix expression//
void infixToPostfix(char infix[], char postfix[]) {
    int i, j;
    struct Stack stack;
    initializeStack(&stack);

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        char currentChar = infix[i];

        if (isalnum(currentChar)) {
            // If the current character is an operand, add it to the postfix expression
            postfix[j++] = currentChar;
        } else if (currentChar == '(') {
            // If the current character is an opening parenthesis, push it onto the stack
            push(&stack, currentChar);
        } else if (currentChar == ')') {
            // If the current character is a closing parenthesis, pop and add operators to postfix until '(' is encountered
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            // Pop the '(' from the stack
            pop(&stack);
        } else if (isOperator(currentChar)) {
            // If the current character is an operator, pop and add operators to postfix with higher or equal precedence
            while (!isEmpty(&stack) && getPrecedence(peek(&stack)) >= getPrecedence(currentChar)) {
                postfix[j++] = pop(&stack);
            }
            // Push the current operator onto the stack
            push(&stack, currentChar);
        }
    }

    // Pop any remaining operators from the stack and add them to the postfix expression
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    // Null-terminate the postfix expression
    postfix[j] = '\0';
}

// Function to initialize the stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an item onto the stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return '$'; // '$' is used to indicate an empty stack
}

// Function to get the top item from the stack without popping it
char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    // Input infix expression
    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Convert infix to postfix
    infixToPostfix(infix, postfix);

    // Output the postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
