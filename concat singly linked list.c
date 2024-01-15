#include <stdio.h>
#include <stdlib.h>

// Node structure for a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of a linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to concatenate two linked lists
struct Node* concatenateLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) {
        return list2;
    }

    struct Node* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2;

    return list1;
}

// Function to display a linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int n, data;

    // Input for the first list
    printf("Enter the number of elements for List 1: ");
    scanf("%d", &n);
    printf("Enter the elements for List 1:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &data);
        insertEnd(&list1, data);
    }

    // Input for the second list
    printf("Enter the number of elements for List 2: ");
    scanf("%d", &n);
    printf("Enter the elements for List 2:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &data);
        insertEnd(&list2, data);
    }

    printf("List 1: ");
    displayList(list1);

    printf("List 2: ");
    displayList(list2);

    struct Node* concatenatedList = concatenateLists(list1, list2);

    printf("Concatenated List: ");
    displayList(concatenatedList);

    return 0;
}
