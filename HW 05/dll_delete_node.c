/*
 * Description: Double Linked List - Deletion.
 * This code deletes a node with a specific value.
 * It checks if the node to be deleted is the head, the middle, or the tail
 * and updates pointers accordingly.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL) return;

    // If node to be deleted is head node
    if (*head_ref == del)
        *head_ref = del->next;

    // Change next only if node to be deleted is NOT the last node
    if (del->next != NULL)
        del->next->prev = del->prev;

    // Change prev only if node to be deleted is NOT the first node
    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
    printf("Node deleted.\n");
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    // Create 3 nodes: 10 <-> 20 <-> 30
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10; head->prev = NULL; head->next = second;
    second->data = 20; second->prev = head; second->next = third;
    third->data = 30; third->prev = second; third->next = NULL;

    printf("Original: ");
    printList(head);

    // Delete the middle node (20)
    deleteNode(&head, second);

    printf("Modified: ");
    printList(head);

    return 0;
}