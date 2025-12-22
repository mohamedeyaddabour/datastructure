#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Modified struct with *prev
struct person {
    int pos;
    char name[10];
    struct person *next;
    struct person *prev; // Added for DLL
};

typedef struct person node;

node* create_node(int pos, char* name) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->pos = pos;
    strcpy(new_node->name, name);
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void add_end_dll(node **head, int pos, char *name) {
    node *new_node = create_node(pos, name);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL) temp = temp->next;
    
    temp->next = new_node;
    new_node->prev = temp;
}

// Insert New Node AFTER a specific node
void insert_after(node *prev_node, int pos, char *name) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    node *new_node = create_node(pos, name);

    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
}

void print_dll(node *head) {
    printf("DLL: ");
    while (head != NULL) {
        printf("<-[%s]-> ", head->name);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    node *head = NULL;
    add_end_dll(&head, 1, "Start");
    add_end_dll(&head, 3, "End");
    
    // Insert "Middle" after "Start"
    insert_after(head, 2, "Middle");
    
    print_dll(head);
    return 0;
}