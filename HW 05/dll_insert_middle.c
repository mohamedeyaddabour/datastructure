/*
 * Description: Double Linked List - Insertion in the Middle.
 * This code creates a basic DLL and inserts a new node *after* a specific position.
 * It handles the 'prev' and 'next' pointers carefully to avoid breaking the chain.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a node after a given previous_node
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    // Step 1: Set new node's next to prev's next
    new_node->next = prev_node->next;
    
    // Step 2: Set new node's prev to prev_node
    new_node->prev = prev_node;

    // Step 3: Update prev_node's next to new_node
    prev_node->next = new_node;

    // Step 4: If new_node's next is not NULL, update its prev to new_node
    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
    printf("Inserted %d.\n", new_data);
}

// Helper to print list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    // Manually create nodes for testing
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    
    head->data = 10;
    head->prev = NULL;
    head->next = second;
    
    second->data = 30;
    second->prev = head;
    second->next = NULL;

    printf("Original List:\n");
    printList(head);

    // Insert 20 between 10 and 30
    insertAfter(head, 20);

    printf("After Insertion:\n");
    printList(head);

    return 0;
}