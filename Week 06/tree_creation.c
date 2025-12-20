#include <stdio.h>
#include <stdlib.h>

// Define the Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // MANUAL CREATION OF YOUR DRAWING (Nodes 1-7)
    
    // Level 1 (Root)
    struct Node* root = createNode(1);
    
    // Level 2
    root->left = createNode(2);
    root->right = createNode(3);
    
    // Level 3 (Children of 2)
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    // Level 3 (Children of 3)
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    return 0;
}