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



node* createList(int n) {
    int i, c = 1;
    node *head = NULL, *p = NULL;

    for (i = 0; i < n; i++) {
        if (i == 0) {
            head = (node *)malloc(sizeof(node));
            p = head;
        } else {
            p->next = (node *)malloc(sizeof(node));
            p = p->next;
        }

        p->pos = c++;
        printf("Enter the name: ");
        scanf("%9s", p->name);
        printf("Enter the surname: ");
        scanf("%9s", p->surname);
        printf("Enter the age: ");
        scanf("%d", &p->age);

        printf("Enter the day of birth: ");
        scanf("%d", &p->birth.day);
        printf("Enter the month of birth: ");
        scanf("%d", &p->birth.month);
        printf("Enter the year of birth: ");
        scanf("%d", &p->birth.year);
    }

    p->next = NULL;
    return head;
}