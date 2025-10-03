// 这个源文件，尝试链栈的表示和相关操作，
// 相关操作包括初始化链栈，入栈，出栈，取栈顶元素
// 链栈通常用单链表来表示

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR -1

typedef int Status;

typedef struct {
    int name;
    int age;
} ElemType;

typedef struct StackNode{
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStack;

Status InitStack(StackNode *S) {
// 初始化链栈
    S = NULL;
    return OK;
}

Status Push(StackNode *S, ElemType e) {
// 入栈
    StackNode *p;
    p = (StackNode *)malloc(sizeof(StackNode)); p = (StackNode *)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S;
    S = p;
    return OK;
}

Status Pop(StackNode *S, ElemType *e) {
// 出栈
    StackNode *p;

    if (S == NULL) {
        return ERROR;
    }
    *e = S->data;
    p = S;
    S = S->next;
    free(p);
    return OK;
}

ElemType GetTop(StackNode *S) {
    if (S != NULL) 
        return S->data;
}

