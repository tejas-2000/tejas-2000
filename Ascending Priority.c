#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct AscendingPriorityQueue {
    int items[MAX_SIZE];
    int rear;
};

void initialize(struct AscendingPriorityQueue *queue) {
    queue->rear = -1;
}

int isFull(struct AscendingPriorityQueue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

int isEmpty(struct AscendingPriorityQueue *queue) {
    return (queue->rear == -1);
}

void insert(struct AscendingPriorityQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Ascending Priority Queue is full. Cannot insert %d.\n", value);
        return;
    }

    int i = queue->rear;

    while (i >= 0 && value < queue->items[i]) {
        queue->items[i + 1] = queue->items[i];
        i--;
    }

    queue->items[i + 1] = value;
    queue->rear++;

    printf("Inserted %d into the ascending priority queue.\n", value);
}

int delete(struct AscendingPriorityQueue *queue) {
    if (isEmpty(queue)) {
        printf("Ascending Priority Queue is empty. Cannot delete.\n");
        return -1;
    }

    int deletedItem = queue->items[queue->rear];
    queue->rear--;

    printf("Deleted %d from the ascending priority queue.\n", deletedItem);
    return deletedItem;
}

void display(struct AscendingPriorityQueue *queue) {
    if (isEmpty(queue)) {
        printf("Ascending Priority Queue is empty.\n");
        return;
    }

    printf("Ascending Priority Queue elements: ");
    for (int i = 0; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

int main() {
    struct AscendingPriorityQueue queue;
    initialize(&queue);

    int choice, value;

    do {
        printf("\nAscending Priority Queue Operations:\n");
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
                value = delete(&queue);
                if (value != -1) {
                    printf("Deleted %d from the ascending priority queue.\n", value);
                }
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