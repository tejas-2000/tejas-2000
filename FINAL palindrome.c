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

int is_palindrome(char str[]) {
    struct stack characters;
    initialize(&characters);

    int length = strlen(str);

    // Push the first half of the string onto the stack
    for (int i = 0; i < length / 2; i++) {
        push(&characters, str[i]);
    }

    // Check the second half of the string against the characters in the stack
    int start = (length + 1) / 2;  // Start index for the second half

    for (int i = start; i < length; i++) {
        if (isEmpty(&characters) || str[i] != pop(&characters)) {
            return 0;  // Not a palindrome
        }
    }

    return 1;  // Palindrome
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character from the input
    str[strcspn(str, "\n")] = '\0';

    if (is_palindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
