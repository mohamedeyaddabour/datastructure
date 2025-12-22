/*
 * Description: Circular Linked List - Traversal.
 * Uses a do-while loop to ensure we visit the head once and stop when we return to it.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traverse(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) return;

    printf("Circular List Elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    // Create 5 -> 6 -> (Head)
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* tail = (struct Node*)malloc(sizeof(struct Node));

    head->data = 5;
    head->next = tail;
    tail->data = 6;
    tail->next = head; // Link back to head

    traverse(head);
    return 0;
}