#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front of the doubly linked list
struct Node* insertAtFront(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to delete a node from the front of the doubly linked list
struct Node* deleteAtFront(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from front.\n");
        return NULL;
    }

    struct Node* temp = head;

    if (head->next != NULL) {
        head = head->next;
        head->prev = NULL;
    } else {
        head = NULL;
    }

    free(temp);
    printf("Node deleted from front successfully.\n");
    return head;
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Driver program
int main() {
    struct Node* head = NULL;
    int choice, value;

    do {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Delete at Front\n");
        printf("3. Display List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertAtFront(head, value);
                break;

            case 2:
                head = deleteAtFront(head);
                break;

            case 3:
                displayList(head);
                break;

            case 0:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
