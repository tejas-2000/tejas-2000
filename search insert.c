#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to search for an element in the linked list
int search(struct Node* head, int key) {
    int position = 0;
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == key) {
            return position; // Element found, return position
        }
        current = current->next;
        position++;
    }

    return -1; // Element not found
}

// Function to add an element to the end of the linked list
struct Node* addElement(struct Node* head, int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;

    if (head == NULL) {
        // If the list is empty, make the new node the head
        head = newNode;
    } else {
        // Otherwise, traverse the list to find the last node and add the new node
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    printf("Element added to the list.\n");
    return head;
}

// Function to display the elements of the linked list
void displayList(struct Node* head) {
    printf("List elements: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int element, position;

    // Input elements into the linked list
    printf("Enter the elements of the list (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &element);
        if (element == -1) {
            break;
        }
        head = addElement(head, element);
    }

    // Display the original linked list
    displayList(head);

    // Input the element to search or add
    printf("Enter the element to search or add: ");
    scanf("%d", &element);

    // Search for the element in the linked list
    position = search(head, element);

    if (position != -1) {
        printf("Element found at position %d.\n", position + 1);
    } else {
        // Element not found, add it to the linked list
        head = addElement(head, element);
        // Display the updated linked list
        displayList(head);
    }

    // Free the memory allocated for the linked list
    struct Node* current = head;
    while (current != NULL) {
        struct Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}
