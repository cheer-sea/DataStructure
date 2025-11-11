// 这个源文件，尝试线性表的顺序存储表示和相关操作

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define Status int
#define OK 1
#define ERROR -1
#define OVERFLOW -2

typedef struct {
    int money;
    char id[20];
} ElemType;

typedef struct {
    ElemType elem[MAXSIZE];
    int length;
} SqList;

int main() {
    SqList L;
}

Status InitList(SqList *L) {
// 初始化顺序表

    L->length = 0;
    return OK;
}

Status GetElem(SqList L, int i, ElemType *e) {
// 获取顺序表第i个元素
    if (i < 1 || i > L.length) {
        return ERROR;
    }

    *e = L.elem[i - 1];
    return OK;
}



