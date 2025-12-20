#include <stdio.h>
#include <stdlib.h>

// --- 1. Define the Node Structure ---
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// --- 2. Function to Create a New Node ---
struct Node* createNode(int data) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Assign data and set children to NULL
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

// --- 3. Pre-order Traversal (Root -> Left -> Right) ---
// This matches your specific request regarding the compiler AST
void printPreOrder(struct Node* node) {
    if (node == NULL)
        return;

    printf("%d ", node->data); // Visit Root
    printPreOrder(node->left); // Visit Left
    printPreOrder(node->right);// Visit Right
}

// --- 4. In-order Traversal (Left -> Root -> Right) ---
void printInOrder(struct Node* node) {
    if (node == NULL)
        return;

    printInOrder(node->left);  // Visit Left
    printf("%d ", node->data); // Visit Root
    printInOrder(node->right); // Visit Right
}

// --- 5. Post-order Traversal (Left -> Right -> Root) ---
void printPostOrder(struct Node* node) {
    if (node == NULL)
        return;

    printPostOrder(node->left);  // Visit Left
    printPostOrder(node->right); // Visit Right
    printf("%d ", node->data);   // Visit Root
}

// --- 6. Main Function (Execution Starts Here) ---
int main() {
    // A. Manually building the tree from your drawing
    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    */
    
    struct Node* root = createNode(1);      // Level 1
    
    root->left = createNode(2);             // Level 2
    root->right = createNode(3);
    
    root->left->left = createNode(4);       // Level 3 (Children of 2)
    root->left->right = createNode(5);
    
    root->right->left = createNode(6);      // Level 3 (Children of 3)
    root->right->right = createNode(7);

    // B. Printing the results
    printf("--- Tree Traversal Results ---\n");

    printf("\nPre-order (Root -> Left -> Right):\n");
    printPreOrder(root);
    // Expected Output: 1 2 4 5 3 6 7

    printf("\n\nIn-order  (Left -> Root -> Right):\n");
    printInOrder(root);
    // Expected Output: 4 2 5 1 6 3 7

    printf("\n\nPost-order (Left -> Right -> Root):\n");
    printPostOrder(root);
    // Expected Output: 4 5 2 6 7 3 1

    printf("\n");
    return 0;
}