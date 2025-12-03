#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void add_front(node **head, int pos, char *name, char *surname, int age, int day, int month, int year) {
    node *new_node = (node *)malloc(sizeof(node));

    new_node->pos = pos;
    strcpy(new_node->name, name);
    strcpy(new_node->surname, surname);
    new_node->age = age;
    new_node->birth.day = day;
    new_node->birth.month = month;
    new_node->birth.year = year;

    new_node->next = *head;
    *head = new_node;
}

void add_end(node **head, int pos, char *name, char *surname, int age, int day, int month, int year) {
    node *new_node = (node *)malloc(sizeof(node));

    new_node->pos = pos;
    strcpy(new_node->name, name);
    strcpy(new_node->surname, surname);
    new_node->age = age;
    new_node->birth.day = day;
    new_node->birth.month = month;
    new_node->birth.year = year;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}