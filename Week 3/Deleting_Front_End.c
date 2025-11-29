#include <stdio.h>
#include <stdlib.h>

struct person {
    int pos;
    char name[10];
    char surname[10];
    int age;
    struct {
        int day;
        int month;
        int year;
    } birth;
    struct person *next;
};

typedef struct person node;

// Function to delete the first node
void delete_front(node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *temp = *head;
    *head = (*head)->next;
    
    free(temp);
}

// Function to delete the last node
void delete_end(node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Special case: If there is only one node
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    // Traverse to the second to last node
    node *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // Free the last node
    free(temp->next);
    
    // Set the next of the new last node to NULL
    temp->next = NULL;
}