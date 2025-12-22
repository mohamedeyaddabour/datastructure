/*
 * Description: Circular Linked List - Delete.
 * Deletes a specific value. Handles the special case where the head itself
 * is deleted (pointers of last node need to update).
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;

    struct Node *curr = *head, *prev = NULL;

    // Check if head is the node to delete
    if (curr->data == key) {
        // Find last node first
        while (curr->next != *head) {
            curr = curr->next;
        }
        // If only one node
        if (*head == (*head)->next) {
            free(*head);
            *head = NULL;
        } else {
            curr->next = (*head)->next; // Last points to 2nd node
            free(*head);
            *head = curr->next; // Update head
        }
    } else {
        // Search for node
        while (curr->next != *head && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }
        // If found
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
        } else {
            printf("Node not found.\n");
        }
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("(Head)\n");
}

int main() {
    // Setup manual list: 10->20->30->(Head)
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    
    head->data = 10; head->next = node2;
    node2->data = 20; node2->next = node3;
    node3->data = 30; node3->next = head;

    printf("Before: "); printList(head);
    
    deleteNode(&head, 20);
    
    printf("After:  "); printList(head);
    return 0;
}