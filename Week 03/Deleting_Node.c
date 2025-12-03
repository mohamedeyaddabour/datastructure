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

node* deleteNode (node *head) {

    node *p, *q;
    int nodeP;

    printf("Enter the position of the node that you want to delete: ");
    scanf("%d", &nodeP);

    p = head;
    if(p != NULL && p->pos == nodeP) {
        head = p->next;
        free(p);
    } else {
        p = head;
        while(p->next != NULL && p->next->pos != nodeP) {
            p = p->next;
        }
        if(p->next->pos == nodeP) {
            q = p->next;
            p->next = p->next->next;
            free(q);
        } else if( p->next == NULL) {
            printf("The entered position does not have any value stored.");
        }
    }
    return head;
}