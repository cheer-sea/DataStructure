#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char key;
    struct node *next;
} Node, *LinkList;

void ListReverse(LinkList L) {
    Node *p, *s;
    p = L->next;
    L->next = NULL;
    while (p) {
        s = p;
        p = p->next;
        s->next = L->next;
        L->next = s;
    }
}