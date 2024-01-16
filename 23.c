#include <stdio.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 10

// Function to display the current status of the row
void displayRow(int row[], int front, int rear) {
    printf("Current row status: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", row[i]);
    }
    printf("\n");
}

// Function to add a customer to the row
void enqueue(int row[], int *rear, int customer) {
    if (*rear == MAX_CUSTOMERS - 1) {
        printf("Row is full. Customer %d cannot enter.\n", customer);
    } else {
        (*rear)++;
        row[*rear] = customer;
        printf("Customer %d entered the row and got token %d.\n", customer, customer);
        displayRow(row, 0, *rear);
    }
}

// Function to process a customer (remove from the row)
void processCustomer(int row[], int *front, int rear) {
    if (*front > rear) {
        printf("No customers in the row.\n");
    } else {
        printf("Customer %d is called for the transaction and leaves the chair.\n", row[*front]);
        (*front)++;
        displayRow(row, *front, rear);
    }
}

int main() {
    int row[MAX_CUSTOMERS];
    int front = 0, rear = -1;
    int choice, customer;

    do {
        printf("\n1. Add a customer\n2. Process a customer\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer number: ");
                scanf("%d", &customer);
                enqueue(row, &rear, customer);
                break;

            case 2:
                processCustomer(row, &front, rear);
                break;

            case 3:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}
