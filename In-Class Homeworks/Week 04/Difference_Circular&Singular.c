#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- THE STRUCT (Doubly Linked List Capable) ---
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
    struct person *prev; // Added prev to support DLL features
};

typedef struct person node;

// Global flag to track if list is currently Circular or Linear
int is_circular = 0; 

// --- HELPER: Create Node ---
node* create_node(int pos, char *name, int age) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->pos = pos;
    strcpy(new_node->name, name);
    strcpy(new_node->surname, "Doe"); // Default
    new_node->age = age;
    new_node->birth.day = 1; new_node->birth.month = 1; new_node->birth.year = 2000;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// --- HELPER: Swap Data (For Sorting) ---
void swap_data(node *a, node *b) {
    int temp_age = a->age; a->age = b->age; b->age = temp_age;
    
    int temp_pos = a->pos; a->pos = b->pos; b->pos = temp_pos;

    char temp_name[10];
    strcpy(temp_name, a->name); strcpy(a->name, b->name); strcpy(b->name, temp_name);
}

// ==========================================
// PART 1: ADD & DELETE (Standard Operations)
// ==========================================

void add_end(node **head, int pos, char *name, int age) {
    node *new_node = create_node(pos, name, age);
    
    if (*head == NULL) {
        *head = new_node;
        if (is_circular) {
            new_node->next = *head; // Point to self if circular
            new_node->prev = *head;
        }
        return;
    }

    // Traverse to last node
    node *temp = *head;
    if (is_circular) {
        while (temp->next != *head) temp = temp->next;
    } else {
        while (temp->next != NULL) temp = temp->next;
    }

    // Link
    temp->next = new_node;
    new_node->prev = temp;

    if (is_circular) {
        new_node->next = *head; // Close the circle
        (*head)->prev = new_node;
    }
}

void add_middle(node *head, int target_pos, int pos, char *name, int age) {
    if (head == NULL) return;
    node *temp = head;
    
    // Find target (Linear/Circular safe loop)
    do {
        if (temp->pos == target_pos) break;
        temp = temp->next;
    } while (temp != head && temp != NULL);

    if (temp == NULL || (is_circular && temp == head && temp->pos != target_pos)) {
        printf("Position %d not found.\n", target_pos);
        return;
    }

    node *new_node = create_node(pos, name, age);
    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next = new_node;

    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
    // If circular and we added at the very end, update head->prev handled by generic pointers mostly, 
    // but simplified here for brevity.
}

void delete_front(node **head) {
    if (*head == NULL) return;
    
    node *temp = *head;
    
    if (temp->next == NULL || (is_circular && temp->next == *head)) {
        // Only one node
        free(temp);
        *head = NULL;
        return;
    }

    if (is_circular) {
        // Find last node to update its next pointer
        node *last = *head;
        while (last->next != *head) last = last->next;
        
        *head = (*head)->next;
        last->next = *head;
        (*head)->prev = last;
    } else {
        *head = (*head)->next;
        if (*head) (*head)->prev = NULL;
    }
    free(temp);
}

// ==========================================
// PART 2: RECURSIVE DELETE
// ==========================================

void recursive_delete_logic(node *curr) {
    if (curr == NULL) return;
    recursive_delete_logic(curr->next);
    printf("Deleting: %s\n", curr->name);
    free(curr);
}

void delete_all(node **head) {
    if (*head == NULL) return;
    
    // SAFETY: If Circular, break the circle first to avoid infinite recursion
    if (is_circular) {
        node *temp = *head;
        while (temp->next != *head) temp = temp->next;
        temp->next = NULL; // Break the link
        is_circular = 0;   // Treat as linear now
    }

    recursive_delete_logic(*head);
    *head = NULL;
    printf("All nodes deleted recursively.\n");
}

// ==========================================
// PART 3: THE DIFFERENCE (SORTING)
// ==========================================

// Algorithm 1: LINEAR BUBBLE SORT (Stops at NULL)
void sort_linear(node *head) {
    if (head == NULL) return;
    int swapped;
    node *ptr1;
    node *lptr = NULL; 

    do {
        swapped = 0;
        ptr1 = head;
        // STOP CONDITION: ptr1->next != NULL
        while (ptr1->next != lptr) { 
            if (ptr1->age > ptr1->next->age) { 
                swap_data(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1; 
    } while (swapped);
    printf("Sorted using LINEAR logic.\n");
}

// Algorithm 2: CIRCULAR BUBBLE SORT (Stops at HEAD)
void sort_circular(node *head) {
    if (head == NULL) return;
    int swapped;
    node *ptr1;
    node *lptr = head; // End marker starts as head

    do {
        swapped = 0;
        ptr1 = head;
        // STOP CONDITION: ptr1->next != head
        // Also must check "lptr" to optimize sorted region
        do {
            if (ptr1->next == lptr && lptr != head) break; // Optimization break

            if (ptr1->age > ptr1->next->age) {
                swap_data(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        } while (ptr1->next != head && ptr1->next != lptr); // Crucial check

        lptr = ptr1;
    } while (swapped);
    printf("Sorted using CIRCULAR logic.\n");
}

// ==========================================
// PART 4: UTILS & MAIN
// ==========================================

void toggle_circular_mode(node **head) {
    if (*head == NULL) return;
    node *temp = *head;
    while (temp->next != NULL && temp->next != *head) temp = temp->next;

    if (is_circular) {
        // Break Circle
        temp->next = NULL;
        (*head)->prev = NULL;
        is_circular = 0;
        printf("Mode changed to: LINEAR Linked List.\n");
    } else {
        // Make Circle
        temp->next = *head;
        (*head)->prev = temp;
        is_circular = 1;
        printf("Mode changed to: CIRCULAR Linked List.\n");
    }
}

void print_list(node *head) {
    if (head == NULL) { printf("List is Empty\n"); return; }
    node *temp = head;
    printf("LIST (%s): ", is_circular ? "Circular" : "Linear");
    
    if (is_circular) {
        do {
            printf("[%s, %d] -> ", temp->name, temp->age);
            temp = temp->next;
        } while (temp != head);
        printf("(HEAD)\n");
    } else {
        while (temp != NULL) {
            printf("[%s, %d] -> ", temp->name, temp->age);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    node *head = NULL;
    int choice;
    
    // Pre-fill some data
    add_end(&head, 1, "Ali", 25);
    add_end(&head, 2, "Veli", 20);
    add_end(&head, 3, "Can", 30);

    while(1) {
        printf("\n1. Add Node\n2. Delete Front\n3. Insert Middle (After Pos 1)\n");
        printf("4. TOGGLE MODE (Linear <-> Circular)\n");
        printf("5. SORT (Auto-detects algorithm)\n");
        printf("6. Recursive Delete All & Exit\n");
        print_list(head);
        
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: add_end(&head, 99, "New", 18); break;
            case 2: delete_front(&head); break;
            case 3: add_middle(head, 1, 55, "Mid", 22); break;
            case 4: toggle_circular_mode(&head); break;
            case 5: 
                if (is_circular) sort_circular(head);
                else sort_linear(head);
                break;
            case 6: delete_all(&head); return 0;
        }
    }
}