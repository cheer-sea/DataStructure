#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int cof;
    int exp;
    struct LNode *next;
} LNode, *LinkList;

LinkList InitList(LinkList L);
void CreateList(LinkList L, int num);
void MergeList(LinkList List1, LinkList List2, LinkList List3, int flag);
void PrintList(LinkList L);

int main() {
    LinkList List1, List2, List3;
    int n, m, t;
    
    scanf("%d %d %d", &n, &m, &t);
    List1 = InitList(List1);
    List2 = InitList(List2);
    List3 = InitList(List3);
    
    CreateList(List1, n);
    CreateList(List2, m);
    MergeList(List1, List2, List3, t);
    PrintList(List3);

    return 0;
}

LinkList InitList(LinkList L) {

    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    return L;
}

void CreateList(LinkList L, int num) {

    LNode *s, *end;
    int cof, exp;
    end = L;

    for (int i = 0; i < num; i++) {
        s = (LNode *)malloc(sizeof(LNode));
        scanf("%d %d", &cof, &exp);
        s->cof = cof;
        s->exp = exp;
        s->next = NULL;
        end->next = s;
        end = s;
    }
}

void MergeList(LinkList List1, LinkList List2, LinkList List3, int flag) {

    LNode *L1, *L2, *p, *end;
    L1 = List1->next;
    L2 = List2->next;
    end = List3;

    while (L1 != NULL && L2 != NULL) {
        p = (LNode*)malloc(sizeof(LNode));
        p->next = NULL;
        if (L1->exp > L2->exp) {
            p->cof = L2->cof;
            p->exp = L2->exp;
            L2 = L2->next;
        }
        else if (L1->exp < L2->exp) {
            p->cof = L1->cof;
            p->exp = L1->exp;
            L1 = L1->next;
        }
        else {
            if (flag == 0) {
                p->cof = L1->cof + L2->cof;
                p->exp = L1->exp;
            }
            else {
                p->cof = L1->cof - L2->cof;
                p->exp = L1->exp;
            }
            L1 = L1->next;
            L2 = L2->next;
        }
        if (p->cof != 0) {
            end->next = p;
            end = p;
        } else {
            free(p);
        }
    }

    while (L1 != NULL) {
        p = (LNode*)malloc(sizeof(LNode));
        p->cof = L1->cof;
        p->exp = L1->exp;
        p->next = NULL;
        end->next = p;
        end = p;
        L1 = L1->next;
    }

    while (L2 != NULL) {
        p = (LNode*)malloc(sizeof(LNode));
        p->cof = (flag == 0) ? L2->cof : -L2->cof;
        p->exp = L2->exp;
        p->next = NULL;
        end->next = p;
        end = p;
        L2 = L2->next;
    }
}

void PrintList(LinkList L) {
    LNode *p;
    int fir = 1;
    p = L->next;
    
    if (p == NULL) {
        printf("0");
        return;
    }

    while (p != NULL) {
        if (p->cof == 0) {
            p = p->next;
            continue;
        }
        else if (p->cof > 0) {
            if (fir != 1)
                printf("+");
            if (p->cof != 1 || p->exp == 0)
                printf("%d", p->cof);
        }
        else {
            if (p->cof == -1 && p->exp != 0)
                printf("-");
            else
                printf("%d", p->cof);
        }

        if (p->exp != 0) {
            if (p->exp == 1) {
                printf("x");
            } else {
                printf("x^%d", p->exp);
            }
        }
        
        fir = 0;
        p = p->next;
    }
}




