#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int pos;
    char name[10];
    char surname[10];
    int age;
    struct { int day; int month; int year; } birth;
    struct person *next;
};

typedef struct person node;

// Helper to create a node
node* create_node(int pos, char* name) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->pos = pos;
    strcpy(new_node->name, name);
    new_node->next = NULL;
    return new_node;
}

void add_front(node **head, int pos, char *name) {
    node *new_node = create_node(pos, name);
    new_node->next = *head;
    *head = new_node;
}

void add_end(node **head, int pos, char *name) {
    node *new_node = create_node(pos, name);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = new_node;
}

void delete_front(node **head) {
    if (*head == NULL) return;
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Deleted front.\n");
}

void delete_end(node **head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    node *temp = *head;
    while (temp->next->next != NULL) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    printf("Deleted end.\n");
}

void print_list(node *head) {
    printf("List: ");
    while (head != NULL) {
        printf("[%s] -> ", head->name);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    node *head = NULL;
    add_end(&head, 1, "Ali");
    add_end(&head, 2, "Veli");
    add_front(&head, 0, "Ayse");
    print_list(head);

    delete_front(&head);
    delete_end(&head);
    print_list(head);
    return 0;
}