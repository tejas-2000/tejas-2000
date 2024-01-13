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

// Function to convert infix expression to postfix expression//
void infixToPostfix(char infix[], char postfix[]) {
    int i, j;
    char stack[MAX_SIZE];
    int top = -1;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        char currentChar = infix[i];

        if (isalnum(currentChar)) {
            // If the current character is an operand, add it to the postfix expression
            postfix[j++] = currentChar;
        } else if (currentChar == '(') {
            // If the current character is an opening parenthesis, push it onto the stack
            stack[++top] = currentChar;
        } else if (currentChar == ')') {
            // If the current character is a closing parenthesis, pop and add operators to postfix until '(' is encountered
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            // Pop the '(' from the stack
            top--;
        } else if (isOperator(currentChar)) {
            // If the current character is an operator, pop and add operators to postfix with higher or equal precedence
            while (top != -1 && getPrecedence(stack[top]) >= getPrecedence(currentChar)) {
                postfix[j++] = stack[top--];
            }
            // Push the current operator onto the stack
            stack[++top] = currentChar;
        }
    }

    // Pop any remaining operators from the stack and add them to the postfix expression
    while (top != -1) {
        postfix[j++] = stack[top--];
    }

    // Null-terminate the postfix expression
    postfix[j] = '\0';
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
