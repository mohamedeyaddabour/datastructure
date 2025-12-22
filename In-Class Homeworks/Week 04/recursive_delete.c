#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int pos;
    char name[10];
    struct person *next;
};
typedef struct person node;

void add(node **head, char *name) {
    node *new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->name, name);
    new_node->next = *head;
    *head = new_node;
}

// Recursive Deletion
void delete_all_recursive(node *head) {
    if (head == NULL) return;

    // Go to the end first
    delete_all_recursive(head->next);

    // Free on the way back
    printf("Freeing %s...\n", head->name);
    free(head);
}

int main() {
    node *head = NULL;
    add(&head, "Node1");
    add(&head, "Node2");
    add(&head, "Node3");

    printf("Starting Recursive Delete:\n");
    delete_all_recursive(head);
    head = NULL; // Important to set head to NULL after
    
    if(head == NULL) printf("List is clean.\n");
    return 0;
}