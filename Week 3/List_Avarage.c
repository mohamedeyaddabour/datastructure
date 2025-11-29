#include <stdio.h>
#include <stdlib.h>


struct data
{
    int grade;
    struct data *next;
};

typedef struct data node;


node* cleaning(node* head) {

    int c = 0;
    node *p, *q, *toDelete;
    p = head;
    while(p != NULL) {
        c++;
        p = p->next;
    }

    p = head;
    int n = c;
    int sum = 0, avg;
    while(p != NULL) {
        sum += p->grade;
        p = p->next;
        n--;
    }
    avg = sum/c;

    p = head;
    while (p != NULL)
    {
        if(p->grade < avg) {
            toDelete = p;
            if(toDelete == head) {
                head = toDelete->next;
                p = head;
            } else {
                q->next = p->next;
                p = p->next;
            }
            free(toDelete);
        } else {
            q = p;
            p = p->next;   
        }
    }
    return head;
}


int main () {

}
