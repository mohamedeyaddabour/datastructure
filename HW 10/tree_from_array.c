/*
 * Description: Creates a Binary Tree from a given Array (Level Order).
 * It uses the standard logic:
 * - Left Child Index = 2*i + 1
 * - Right Child Index = 2*i + 2
 * I implemented a recursive function to link the nodes.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert nodes in level order
struct Node* insertLevelOrder(int arr[], int i, int n) {
    struct Node* root = NULL;

    // Base case for recursion
    if (i < n) {
        root = newNode(arr[i]);

        // insert left child
        root->left = insertLevelOrder(arr, 2 * i + 1, n);

        // insert right child
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

// InOrder traversal to verify the tree
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node* root = insertLevelOrder(arr, 0, n);

    printf("InOrder Traversal of constructed tree: ");
    inOrder(root);
    printf("\n");
    // Output should be sorted-ish order depending on tree structure: 4 2 5 1 6 3 66

    return 0;
}