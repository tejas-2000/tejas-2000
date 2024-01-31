#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Stack implementation
struct stack {
    int top;
    char items[MAX_SIZE];
};

void initialize(struct stack *s) {
    s->top = -1;
}

int isEmpty(struct stack *s) {
    return s->top == -1;
}

int isFull(struct stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(struct stack *s, char item) {
    if (!isFull(s)) {
        s->items[++s->top] = item;
    } else {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
}

char pop(struct stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    } else {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
}

char peek(struct stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
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

void infixToPostfix(struct stack *s, char infix[], char postfix[]) {
    initialize(s);

    int infixLength = strlen(infix);
    int postfixIndex = 0;

    for (int i = 0; i < infixLength; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            // Operand, append to the postfix expression
            postfix[postfixIndex++] = ch;
        } else if (ch == '(') {
            // Push '(' onto the stack
            push(s, ch);
        } else if (ch == ')') {
            // Pop operators from the stack and append to the postfix expression until '(' is encountered
            while (!isEmpty(s) && peek(s) != '(') {
                postfix[postfixIndex++] = pop(s);
            }
            // Pop the '(' from the stack
            pop(s);
        } else if (isOperator(ch)) {
            // Pop operators from the stack and append to the postfix expression until a lower precedence operator is encountered
            while (!isEmpty(s) && precedence(peek(s)) >= precedence(ch)) {
                postfix[postfixIndex++] = pop(s);
            }
            // Push the current operator onto the stack
            push(s, ch);
        }
    }

    // Pop any remaining operators from the stack and append to the postfix expression
    while (!isEmpty(s)) {
        postfix[postfixIndex++] = pop(s);
    }

    // Null-terminate the postfix expression
    postfix[postfixIndex] = '\0';
}

int main() {
    struct stack operators;
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    infixToPostfix(&operators, infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
