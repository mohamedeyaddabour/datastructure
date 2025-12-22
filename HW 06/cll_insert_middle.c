/*
 * Description: Circular Linked List - Insert.
 * Inserts a node into a sorted Circular Linked List (or just standard insertion).
 * I used a simple "insert at end" logic but maintained circularity (last->next = head).
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Insert val into circular list
void insertEnd(struct Node** head_ref, int val) {
    struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));
    ptr1->data = val;
    ptr1->next = *head_ref; // Point new node to head

    // If list is empty
    if (*head_ref == NULL) {
        *head_ref = ptr1;
        ptr1->next = *head_ref; // Point to itself
    } else {
        // Find last node
        struct Node* temp = *head_ref;
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        temp->next = ptr1; // Last node points to new node
    }
    printf("Inserted %d.\n", val);
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
    struct Node* head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    
    printList(head);
    return 0;
}