#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct PriorityQueues {
    int queue1[MAX_SIZE];
    int queue2[MAX_SIZE];
    int queue3[MAX_SIZE];
    int front1, rear1, front2, rear2, front3, rear3;
};

void initialize(struct PriorityQueues *pq) {
    pq->front1 = pq->rear1 = -1;
    pq->front2 = pq->rear2 = -1;
    pq->front3 = pq->rear3 = -1;
}

int isFull(struct PriorityQueues *pq) {
    return ((pq->rear1 == MAX_SIZE - 1) || (pq->rear2 == MAX_SIZE - 1) || (pq->rear3 == MAX_SIZE - 1));
}

int isEmpty(struct PriorityQueues *pq) {
    return ((pq->front1 == -1) && (pq->front2 == -1) && (pq->front3 == -1));
}

void insert(struct PriorityQueues *pq, int value) {
    if (isFull(pq)) {
        printf("Priority Queues are full. Cannot insert %d.\n", value);
        return;
    }

    int priority;

    printf("Enter the priority (1, 2, or 3) for %d: ", value);
    scanf("%d", &priority);

    switch (priority) {
        case 1:
            if (pq->rear1 == -1) {
                pq->front1 = pq->rear1 = 0;
            } else {
                pq->rear1++;
            }
            pq->queue1[pq->rear1] = value;
            break;
        case 2:
            if (pq->rear2 == -1) {
                pq->front2 = pq->rear2 = 0;
            } else {
                pq->rear2++;
            }
            pq->queue2[pq->rear2] = value;
            break;
        case 3:
            if (pq->rear3 == -1) {
                pq->front3 = pq->rear3 = 0;
            } else {
                pq->rear3++;
            }
            pq->queue3[pq->rear3] = value;
            break;
        default:
            printf("Invalid priority. Please enter 1, 2, or 3.\n");
            return;
    }

    printf("Inserted %d with priority %d into the priority queues.\n", value, priority);
}

int delete(struct PriorityQueues *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queues are empty. Cannot delete.\n");
        return -1;
    }

    if (pq->front1 != -1) {
        int deletedItem = pq->queue1[pq->front1];
        if (pq->front1 == pq->rear1) {
            pq->front1 = pq->rear1 = -1;
        } else {
            pq->front1++;
        }
        return deletedItem;
    } else if (pq->front2 != -1) {
        int deletedItem = pq->queue2[pq->front2];
        if (pq->front2 == pq->rear2) {
            pq->front2 = pq->rear2 = -1;
        } else {
            pq->front2++;
        }
        return deletedItem;
    } else {
        int deletedItem = pq->queue3[pq->front3];
        if (pq->front3 == pq->rear3) {
            pq->front3 = pq->rear3 = -1;
        } else {
            pq->front3++;
        }
        return deletedItem;
    }
}

void display(struct PriorityQueues *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queues are empty.\n");
        return;
    }

    printf("Priority Queue 1: ");
    for (int i = pq->front1; i <= pq->rear1; i++) {
        printf("%d ", pq->queue1[i]);
    }
    printf("\n");

    printf("Priority Queue 2: ");
    for (int i = pq->front2; i <= pq->rear2; i++) {
        printf("%d ", pq->queue2[i]);
    }
    printf("\n");

    printf("Priority Queue 3: ");
    for (int i = pq->front3; i <= pq->rear3; i++) {
        printf("%d ", pq->queue3[i]);
    }
    printf("\n");
}

int main() {
    struct PriorityQueues pq;
    initialize(&pq);

    int choice, value;

    do {
        printf("\nPriority Queue Operations:\n");
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
                insert(&pq, value);
                break;
            case 2:
                value = delete(&pq);
                if (value != -1) {
                    printf("Deleted %d from the priority queues.\n", value);
                }
                break;
            case 3:
                display(&pq);
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
