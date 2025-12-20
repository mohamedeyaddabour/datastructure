// Pre-order: Root -> Left -> Right
void printPreOrder(struct Node* node) {
    if (node == NULL)
        return;

    // 1. Visit the Root
    printf("%d ", node->data);

    // 2. Go Left
    printPreOrder(node->left);

    // 3. Go Right
    printPreOrder(node->right);
}

// Example of how to call it in main:
// printPreOrder(root); 
// Output: 1 2 4 5 3 6 7