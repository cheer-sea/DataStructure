#include <stdio.h>
#include <stdlib.h>

typedef struct Listnode{
    float exp;
    float value;
    struct Listnode *next;
} Lnode, *LinkList;

void initList(struct Listnode *L) {
    L = (struct Listnode *)malloc(sizeof(struct Listnode));
    L->next = NULL;
}
void createList(struct Listnode *L, float e, float v) {
    struct Listnode *s;
    s = (struct Listnode *)malloc(sizeof(struct Listnode));
    s->exp = e;
    s->value = v;
    findPosition(L, s);
}

void findPosition(struct Listnode *L, struct Listnode *s) {
    struct Listnode *pL, *pre;
    pre = L;
    pL = L->next;

    while (1) {
        if (pL == NULL || pL->exp > s->exp) {
            break;
        }
        
        if(pL->exp == s->exp) {
            s->value += pL->value;
            break;
        }
        pre = pL;
        pL = pL->next;
    }

    s->next = pL;
    pre->next = s;
}








