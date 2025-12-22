/*
 * Description: Double Linked List - Traversal.
 * Prints the list Forward (using next) and Backward (using prev).
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void traverse(struct Node* node) {
    struct Node* last;
    
    printf("\nTraversal in forward direction:\n");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node; // Store last node for backward traversal
        node = node->next;
    }

    printf("\nTraversal in reverse direction:\n");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

int main() {
    // Create 1 <-> 2 <-> 3
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1; head->prev = NULL; head->next = second;
    second->data = 2; second->prev = head; second->next = third;
    third->data = 3; third->prev = second; third->next = NULL;

    traverse(head);
    return 0;
}