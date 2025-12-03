#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


struct information {
    char name[16];
    struct information *next;
};


typedef struct information node;


node *head, *newNode, *prev, *toDelete;

node* duplicateList(node* head);
void createList();
void addNode();
void traverseList();
void deleteNode();
void search (char *name);


int main () {

    int operation;
    int c = 0;
    operation = 0;

    while (operation != 6) {
        printf("\n\n***********Main Menu***********\n");
        if(c == 0) printf("1. Create a List.\n");
        printf("2. Add a Name.\n");
        printf("3. Delete a Name.\n");
        printf("4. Read List.\n");
        printf("5. Clean List.\n");
        printf("6. Exit.\n");
        printf("*******************************\n");

        printf("\nSelect an operation: ");
        scanf(" %d", &operation);
        if (operation == 1) c++;
        
    switch (operation) {
        case 1:
            printf("Creating a list.....\n");
            createList();
            break;
        case 2:
            printf("Adding name.....\n");
            addNode();
            break;
        case 3:
            printf("Deleting name.....\n");
            deleteNode();
            break;
        case 4:
            printf("Printing list.....\n");
            traverseList();
            break;
        case 5:
            printf("Verifying List.....\n");
            head = duplicateList(head);
            break; 
    }
    }


    
    return 0;
}


void deleteNode() {

    char name[16];
    printf("Name to be deleted: ");
    scanf("%15s", name);

    search(name);
    if(prev == NULL) {
        printf("Name not in the list.");
    } else {
        toDelete = prev->next;
        if(toDelete == NULL) {
            printf("Name not in the list.");
        } else if (strcmp(toDelete->name, name) == 0) {
            prev->next = toDelete->next;
            free(toDelete);
            printf("Name deleted successfully.");
        } else printf("Name not in the list.");
    }

    printf("\n\nPress any key to continue......\n\n");
    getch();
    return;

}

void search (char *name) {
    node *p;
    p = head;
    prev = head;
    if(head == NULL) {
        prev = NULL;
        return;
    }
    while (p->next != NULL) {
        if(strcmp(p->next->name, name) >= 0) break;
        p = p->next;
    }
    prev = p;
    
}

node* duplicateList(node* head) {
    /* Remove duplicate nodes from a sorted singly-linked list.
       We assume the list is sorted in ascending order by name.
       head is a dummy node (list head), actual data starts at head->next.
    */
    node *p, *q;

    if(head == NULL) return head;

    p = head->next; /* first real node */
    while(p != NULL && p->next != NULL) {
        q = p->next;
        if(strcmp(p->name, q->name) == 0) {
            /* duplicate found: remove q */
            p->next = q->next;
            free(q);
            /* keep p the same to check for multiple duplicates */
        } else {
            p = p->next;
        }
    }

    return head;
}

void traverseList () {
    node *p;
    p = head;
    int c = 1;
    if(head == NULL) return;
    p = head->next;
    while(p != NULL) {
        printf("\n%d. %s", c, p->name);
        p = p->next;
        c++;
    }
    printf("\n\nPress any key to continue......\n\n");
    getch();
    return;
}

void addNode() {
    char name[16];

    newNode = (node *)malloc(sizeof(node));

    printf("Name to be added: ");
    scanf("%15s", name);

    strcpy(newNode->name, name);
    search(newNode->name);

    newNode->next = prev->next;
    prev->next = newNode;

    printf("\n\nPress any key to continue......\n\n");
    getch();
    return;
}

void createList() {

    head = (node *)malloc(sizeof(node));

    strcpy(head->name, "Top of the list");
    head->next = NULL;

    if(head->name != NULL) printf("\n\nList created successfully.\n\n");
    
    printf("\n\nPress any key to continue......\n\n");
    getch();
    return;
}
