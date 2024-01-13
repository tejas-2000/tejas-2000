#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct CircularQueue {
    int front, rear;
    int items[MAX_SIZE];
};

void initialize(struct CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(struct CircularQueue *queue) {
    return (queue->front == (queue->rear + 1) % MAX_SIZE);
}

int isEmpty(struct CircularQueue *queue) {
    return (queue->front == -1);
}

void insert(struct CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot insert %d.\n", value);
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = value;

    printf("Inserted %d into the queue.\n", value);
}

void delete(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot delete.\n");
        return;
    }

    int deletedItem = queue->items[queue->front];

    if (queue->front == queue->rear) {
        // Last element in the queue is being deleted
        initialize(queue);
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    printf("Deleted %d from the queue.\n", deletedItem);
}

void display(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = queue->front;
    do {
        printf("%d ", queue->items[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);

    printf("\n");
}

int main() {
    struct CircularQueue queue;
    initialize(&queue);

    int choice, value;

    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(&queue, value);
                break;
            case 2:
                delete(&queue);
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
