#include<stdio.h>
#include<stdlib.h>

typedef struct PolyNode {
// 多项式结点的链式结构
    int coef;
    int exp;
    struct PolyNode *next;
} PolyNode, *PolyList;

PolyList PolyCreate() {
// 尾插法创建多项式链表
    PolyNode *head, *p, *rear;
    int c, e;
    head = (PolyList)malloc(sizeof(PolyNode));
    rear = head;

    scanf("%d%d", &c, &e);
    while(c != 0) {
        p = (PolyNode *)malloc(sizeof(PolyNode));
        p->coef = c;
        p->exp = e;
        rear->next = p;
        rear = p;
    }
    rear -> next = NULL;
    return head;
}

void PolyAdd(PolyList LA, PolyList LB) {
    PolyNode *pa, *pb, *temp, *tail;
    pa = LA->next;
    pb = LB->next;
    tail = LA;
    while (pa != NULL && pb!= NULL) {
        if (pa->exp < pb->exp) {
            tail->next = pa;
            tail = pa;
            pa = pa->next;
        }
        else if (pb->exp < pa->exp) {
            tail->next = pb;
            tail = pb;
            pb = pb->next;
        }
        else {
            int sum = pa->coef + pb->coef;
            if (sum != 0) {
                temp = (PolyNode *)malloc(sizeof(PolyNode));
                temp->coef = sum;
                temp->exp = pa->exp;
                tail->next = temp;
                tail = temp;
            }
        }
    }
    if (pa != NULL) tail->next = pa;
    else tail->next = pb;
}
