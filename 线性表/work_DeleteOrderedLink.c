#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int address;
    int value;
    int follow;
} ElemType;

typedef struct Node {
    ElemType data;
    struct Node *next;
} LNode, *LinkList;

void InitList(LinkList L) {
    L->next = NULL;
}
void CreateList(LinkList L, int n) {
    for (int i = 0; i < n; i++) {
        int address, value, follow;
        scanf("%d%d%d", &address, &value, &follow);
        ElemType e = {address, value, follow};
        LNode *p = (LNode *)malloc(sizeof(LNode));
        p->data = e;
        p->next = L->next;
        L->next = p;
    }
}

void MergeList(LinkList L1, LinkList Res_L, int n, int finish[n]) {
    LNode *p = L1->next;
    int cnt = 0;
    while (cnt < n) {
        
    }
    


}

int main() {
    return 0;
}

