#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode{
    int value;
    struct Lnode *next;
} Lnode, *LinkList;

void CreateLink(LinkList L, int n);
void MergeLink(LinkList L1, LinkList L2);
void PrintResult(LinkList L);

int main() {
    int a, b;
    LinkList L1, L2;
    L1->next = NULL;
    L2->next = NULL;
    scanf("%d%d", &a, &b);

    CreateLink(L1, a);
    CreateLink(L2, b);
    MergeLink(L1, L2);
    PrintResult(L1);
    
    return 0;
}

void CreateLink(LinkList L, int n) {
    Lnode *p, *r;
    r = L;
    
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        p->value = value;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}
void MergeLink(LinkList L1, LinkList L2) {
    Lnode *p, *q, *pre, *temp;
    p = L1->next;
    q = L2->next;
    pre = L1;

    while (p != NULL && q != NULL) {
        if (p->value >= q->value) {
            temp = q;
            q = q->next;
            free(temp);
        } else {
            while (p->value < q->value) {
                pre = p;
                p = p->next;
            }
            if (p->value == q->value) {
                temp = q;
                q = q->next;
                free(q);
            } else {
                temp = q;
                q = q->next;
                temp->next = p;
                pre->next = temp;
            }
        }
    }
}

void PrintResult(LinkList L) {
    Lnode *p;
    p = L->next;
    while (p != NULL) {
        printf("%d", p->value);
    }
}

