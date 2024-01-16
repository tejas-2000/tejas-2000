#include <stdio.h>
#include <stdlib.h>

// Node structure for the Binary Search Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform an inorder traversal and print unique elements
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to remove duplicates from the list using BST
void removeDuplicates(int arr[], int n) {
    struct Node* root = NULL;

    for (int i = 0; i < n; i++) {
        // Insert the element into the BST
        root = insert(root, arr[i]);
    }

    // Perform an inorder traversal to print unique elements
    printf("Unique elements: ");
    inorderTraversal(root);

    // Free the memory used by the BST nodes (optional)
    // Note: This step is not strictly necessary for the program's functionality.
    // It is included here to demonstrate freeing the memory allocated for the BST.
    // You may choose to skip it depending on your specific use case.
    //free(root);
}

int main() {
    int n;

    // Input the number of elements in the list
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Remove duplicates and print unique elements
    removeDuplicates(arr, n);

    return 0;
}
