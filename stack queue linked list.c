#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Queue {
    struct Node *front, *rear;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue underflow\n");
        return -1;
    }
    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Push to Stack\n");
    printf("2. Pop from Stack\n");
    printf("3. Enqueue to Queue\n");
    printf("4. Dequeue from Queue\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Stack stack;
    stack.top = NULL;

    struct Queue queue;
    queue.front = queue.rear = NULL;

    int choice, data;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push to stack: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                printf("Popped from stack: %d\n", pop(&stack));
                break;
            case 3:
                printf("Enter data to enqueue to queue: ");
                scanf("%d", &data);
                enqueue(&queue, data);
                break;
            case 4:
                printf("Dequeued from queue: %d\n", dequeue(&queue));
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}