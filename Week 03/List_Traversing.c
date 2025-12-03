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

void traverseList(node* head) {
    node *p;
    p = head;
    while (p != NULL) {
        printf("%d. %s %s, Age: %d, DOB: %02d/%02d/%04d.", p->pos, p->name, p->surname, p->age, p->birth.day, p->birth.month, p->birth.year);
        p = p->next;
    }

}