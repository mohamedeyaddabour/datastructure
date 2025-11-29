#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Using the FULL structure with Prev pointer to handle all cases
struct person {
    int pos;
    char name[10];
    char surname[10];
    int age;
    struct person *next;
    struct person *prev; // Included for DLL logic
};

typedef struct person node;

// --- Helper: Create Node ---
node* create_node(int pos, char* name) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->pos = pos;
    strcpy(new_node->name, name);
    // Init default values
    strcpy(new_node->surname, "Default");
    new_node->age = 20;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// --- 1. Add Front ---
void add_front(node **head, int pos, char *name) {
    node *new_node = create_node(pos, name);
    if (*head == NULL) {
        *head = new_node;
    } else {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
    }
    printf("Added %s to front.\n", name);
}

// --- 2. Add End ---
void add_end(node **head, int pos, char *name) {
    node *new_node = create_node(pos, name);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL) temp = temp->next;
    
    temp->next = new_node;
    new_node->prev = temp;
    printf("Added %s to end.\n", name);
}

// --- 3. Insert Between (After a specific pos) ---
void insert_after_pos(node *head, int target_pos, int new_pos, char *name) {
    node *temp = head;
    while (temp != NULL && temp->pos != target_pos) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position %d not found.\n", target_pos);
        return;
    }
    
    // Found target, insert after 'temp'
    node *new_node = create_node(new_pos, name);
    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next = new_node;
    
    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
    printf("Inserted %s after position %d.\n", name, target_pos);
}

// --- 4. Delete Front ---
void delete_front(node **head) {
    if (*head == NULL) return;
    node *temp = *head;
    *head = (*head)->next;
    
    if (*head != NULL) (*head)->prev = NULL;
    
    free(temp);
    printf("Deleted front node.\n");
}

// --- 5. Delete End ---
void delete_end(node **head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL) temp = temp->next;
    
    temp->prev->next = NULL;
    free(temp);
    printf("Deleted last node.\n");
}

// --- 6. Recursive Delete All ---
void delete_all_recursive(node *current) {
    if (current == NULL) return;
    
    delete_all_recursive(current->next);
    
    printf("Recursively freeing node: %s\n", current->name);
    free(current);
}

// --- Print List ---
void print_list(node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("NULL <- ");
    while (head != NULL) {
        printf("[%d: %s] <-> ", head->pos, head->name);
        head = head->next;
    }
    printf("NULL\n");
}

// --- MAIN MENU ---
int main() {
    node *head = NULL;
    int choice, p, target;
    char n[10];

    while(1) {
        printf("\n--- LINKED LIST MASTER ---\n");
        printf("1. Add Front\n");
        printf("2. Add End\n");
        printf("3. Insert Between (After Pos)\n");
        printf("4. Delete Front\n");
        printf("5. Delete End\n");
        printf("6. Delete All (Recursive) & Exit\n");
        printf("7. Show List\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Pos and Name: ");
                scanf("%d %s", &p, n);
                add_front(&head, p, n);
                break;
            case 2:
                printf("Enter Pos and Name: ");
                scanf("%d %s", &p, n);
                add_end(&head, p, n);
                break;
            case 3:
                printf("Enter Target Pos to insert after: ");
                scanf("%d", &target);
                printf("Enter New Pos and Name: ");
                scanf("%d %s", &p, n);
                insert_after_pos(head, target, p, n);
                break;
            case 4:
                delete_front(&head);
                break;
            case 5:
                delete_end(&head);
                break;
            case 6:
                delete_all_recursive(head);
                head = NULL;
                printf("List cleared. Exiting.\n");
                return 0;
            case 7:
                print_list(head);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}