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
    struct person *prev;
};

typedef struct person node;

node* addList(node* head) {
    int nodeP;
    node *p, *q;
    node *newNode = (node *)malloc(sizeof(node));

    printf("Add before position: ");
    scanf("%d", &nodeP);

    {   
        printf("Enter the name: ");
        scanf("%9s", newNode->name);
        printf("Enter the surname: ");
        scanf("%9s", newNode->surname);
        printf("Enter the age: ");
        scanf("%d", &newNode->age);

        printf("Enter the day of birth: ");
        scanf("%d", &newNode->birth.day);
        printf("Enter the month of birth: ");
        scanf("%d", &newNode->birth.month);
        printf("Enter the year of birth: ");
        scanf("%d", &newNode->birth.year);
    }


    p = head;
    if(head->pos == nodeP) {
        newNode->next = head;
        head = newNode;
    } else {
        while (p != NULL && p->pos != nodeP) {
            q = p;
            p = p->next;
        }
        if(p->pos == nodeP) {
            q->next = newNode;
            newNode->next = p;
        } else if (p == NULL) {

            q->next = newNode;
            newNode->next = NULL;
        }
    }

    newNode->pos = nodeP;
    return head;





    p = head;

    if(head->pos == nodeP) {
        newNode->next = head;
        head = newNode;
    } else {
        while(p != NULL && p->pos != nodeP)  {
            q = p;
            p = p->next;
        }
        if(p->pos == nodeP) {
            q->next = newNode;
            newNode->next = p;
        } else if( p == NULL) {
            q->next = newNode;
            newNode->next = NULL;
        }
    }

    newNode -> pos = nodeP;
    return head;

}


