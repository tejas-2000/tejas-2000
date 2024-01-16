#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node with value x into an ordered linked list
void insertOrdered(struct Node** head, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = x;
    newNode->next = NULL;

    // If the list is empty or x is smaller than the head, insert at the beginning
    if (*head == NULL || x < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse the list to find the appropriate position to insert the node
    struct Node* current = *head;
    while (current->next != NULL && current->next->data < x) {
        current = current->next;
    }

    // Insert the new node
    newNode->next = current->next;
    current->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

// Driver program to test the functions
int main() {
    struct Node* list = NULL;

    int n, data;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements for the ordered list:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertOrdered(&list, data);
    }

    // Printing the ordered linked list
    printf("Ordered List: ");
    printList(list);

    // Freeing the memory allocated for the list
    freeList(list);

    return 0;
}
