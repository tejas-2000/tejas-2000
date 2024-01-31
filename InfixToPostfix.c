#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Stack implementation
typedef struct {
    int top;
    char items[MAX_SIZE];
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, char item) {
    if (!isFull(stack)) {
        stack->items[++stack->top] = item;
    } else {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
}

char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
}

char peek(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top];
    } else {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char ch) {
    switch (ch) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack operators;
    initialize(&operators);

    int infixLength = strlen(infix);
    int postfixIndex = 0;

    for (int i = 0; i < infixLength; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            // Operand, append to the postfix expression
            postfix[postfixIndex++] = ch;
        } else if (ch == '(') {
            // Push '(' onto the stack
            push(&operators, ch);
        } else if (ch == ')') {
            // Pop operators from the stack and append to the postfix expression until '(' is encountered
            while (!isEmpty(&operators) && peek(&operators) != '(') {
                postfix[postfixIndex++] = pop(&operators);
            }
            // Pop the '(' from the stack
            pop(&operators);
        } else if (isOperator(ch)) {
            // Pop operators from the stack and append to the postfix expression until a lower precedence operator is encountered
            while (!isEmpty(&operators) && precedence(peek(&operators)) >= precedence(ch)) {
                postfix[postfixIndex++] = pop(&operators);
            }
            // Push the current operator onto the stack
            push(&operators, ch);
        }
    }

    // Pop any remaining operators from the stack and append to the postfix expression
    while (!isEmpty(&operators)) {
        postfix[postfixIndex++] = pop(&operators);
    }

    // Null-terminate the postfix expression
    postfix[postfixIndex] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
