#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    char name[10];
    struct person *next;
};
typedef struct person node;

void add_circular(node **head, char *name) {
    node *new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->name, name);
    
    if (*head == NULL) {
        *head = new_node;
        new_node->next = *head; // Point to self
    } else {
        node *temp = *head;
        while (temp->next != *head) { // Loop until we find the node pointing to head
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = *head; // Close the circle
    }
}

void print_circular(node *head) {
    if (head == NULL) return;
    node *temp = head;
    
    printf("Circular List: ");
    do {
        printf("[%s] -> ", temp->name);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to Head)\n");
}

int main() {
    node *head = NULL;
    add_circular(&head, "A");
    add_circular(&head, "B");
    add_circular(&head, "C");
    
    print_circular(head);
    return 0;
}