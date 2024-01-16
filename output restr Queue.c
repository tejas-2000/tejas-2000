#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Deque {
    int items[MAX_SIZE];
    int front, rear;
};

void initialize(struct Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
}

int isFull(struct Deque *deque) {
    return (deque->front == 0 && deque->rear == MAX_SIZE - 1) || (deque->front == deque->rear + 1);
}

int isEmpty(struct Deque *deque) {
    return (deque->front == -1);
}

void insertqfront(struct Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert %d at the front.\n", value);
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = MAX_SIZE - 1;
    } else {
        deque->front--;
    }

    deque->items[deque->front] = value;
    printf("Enqueued %d at the front of the queue.\n", value);
}

void insertqrear(struct Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert %d at the rear.\n", value);
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->rear == MAX_SIZE - 1) {
        deque->rear = 0;
    } else {
        deque->rear++;
    }

    deque->items[deque->rear] = value;
    printf("Enqueued %d at the rear of the queue.\n", value);
}

int remvleft(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Queue is empty. Cannot dequeue from the front.\n");
        return -1;
    }

    int dequeuedItem = deque->items[deque->front];

    if (deque->front == deque->rear) {
        // Only one element in the deque (queue)
        initialize(deque);
    } else {
        deque->front = (deque->front + 1) % MAX_SIZE;
    }

    printf("Dequeued %d from the front of the queue.\n", dequeuedItem);
    return dequeuedItem;
}

void displayq(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = deque->front;
    do {
        printf("%d ", deque->items[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (deque->rear + 1) % MAX_SIZE);

    printf("\n");
}

int main() {
    struct Deque deque;
    initialize(&deque);

    int choice, value;

    do {
        printf("\nQueue Operations using Deque:\n");
        printf("1. Enqueue at Front\n");
        printf("2. Enqueue at Rear\n");
        printf("3. Dequeue from Front\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue at the front: ");
                scanf("%d", &value);
                insertqfront(&deque, value);
                break;
            case 2:
                printf("Enter the value to enqueue at the rear: ");
                scanf("%d", &value);
                insertqrear(&deque, value);
                break;
            case 3:
                value = remvleft(&deque);
                if (value != -1) {
                    printf("Dequeued %d from the front of the queue.\n", value);
                }
                break;
            case 4:
                displayq(&deque);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
