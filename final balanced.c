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

int isOpeningBracket(char ch) {
    return (ch == '(' || ch == '[' || ch == '{');
}

int isClosingBracket(char ch) {
    return (ch == ')' || ch == ']' || ch == '}');
}

int isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

int Balance_infix_expression(struct stack *s, char infix[]) {
    initialize(s);

    int infixLength = strlen(infix);

    for (int i = 0; i < infixLength; i++) {
        char ch = infix[i];

        if (isOpeningBracket(ch)) {
            push(s, ch);
        } else if (isClosingBracket(ch)) {
            if (isEmpty(s) || !isMatchingPair(peek(s), ch)) {
                return 0;  // Not balanced
            }
            pop(s);
        }
    }

    return isEmpty(s);  // If the stack is empty, the expression is balanced
}

int main() {
    struct stack brackets;
    char infix[MAX_SIZE];

    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    if (Balance_infix_expression(&brackets, infix)) {
        printf("The infix expression is balanced.\n");
    } else {
        printf("The infix expression is not balanced.\n");
    }

    return 0;
}
