#include <stdio.h>

#define MAX_SIZE 10

int q[MAX_SIZE];

void initializeQueue() {
    q[0] = q[1] = 0; // Set front and rear to 0 to represent an empty queue
}

int isEmpty() {
    return q[0] == q[1]; // If front equals rear, the queue is empty
}

void enqueue(int data) {
    if (q[1] == MAX_SIZE - 1) {
        printf("Queue overflow\n");
        return;
    }

    q[++q[1]] = data; // Increment rear and add data to the new rear position
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return -1;
    }

    return q[++q[0]]; // Increment front and return the data at the new front position
}

int main() {
    initializeQueue();

    enqueue(1);
    enqueue(2);
    enqueue(3);

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    enqueue(4);
    enqueue(5);

    while (!isEmpty()) {
        printf("Dequeued: %d\n", dequeue());
    }

    return 0;
}