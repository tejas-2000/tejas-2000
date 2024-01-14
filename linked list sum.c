#include <stdio.h>

#define MAX_SIZE 100

// Function to search for an element in the list
int search(int list[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (list[i] == key) {
            return i; // Element found, return position
        }
    }
    return -1; // Element not found
}

// Function to add an element to the list
void addElement(int list[], int *size, int element) {
    if (*size < MAX_SIZE) {
        list[*size] = element;
        (*size)++;
        printf("Element added to the list.\n");
    } else {
        printf("List is full. Cannot add more elements.\n");
    }
}

int main() {
    int list[MAX_SIZE];
    int size = 0;
    int element, position;

    // Input elements into the list (you can modify this part as needed)
    printf("Enter the number of elements in the list: ");
    scanf("%d", &size);

    printf("Enter the elements of the list:\n");
    for (int i = 0; i < size; ++i) {
        scanf("%d", &list[i]);
    }

    // Input the element to search or add
    printf("Enter the element to search or add: ");
    scanf("%d", &element);

    // Search for the element in the list
    position = search(list, size, element);

    if (position != -1) {
        printf("Element found at position %d.\n", position + 1);
    } else {
        // Element not found, add it to the list
        addElement(list, &size, element);
    }

    return 0;
}
