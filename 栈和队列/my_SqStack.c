// 这个源文件，尝试顺序栈的表示和相关操作
// 相关操作包括：初始化一个空栈、入栈、出栈、获取栈顶元素

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define OK 1
#define ERROR -1
#define OVERFLOW -2

typedef int Status;

typedef struct {
    int num;
    char id[10];
} SElemType;

typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

Status InitStack(SqStack *s) {
// 初始化一个空栈
    s->base = (SElemType *)malloc(MAXSIZE * sizeof(SElemType));
    if (!s->base) exit (OVERFLOW);
    s->top = s->base;
    s->stacksize = MAXSIZE;
    return OK;
}

Status Push(SqStack *s, SElemType e) {
// 入栈
    if (s->top - s->base >= s->stacksize) {
        return ERROR; // 栈满
    }
    *s->top = e;
    s->top++;
    return OK;
}

Status Pop(SqStack *s, SElemType *e) {
// 出栈
    if (s->top == s->base) {
        return ERROR; // 栈空
    }
    s->top--;
    *e = *s->top;
    return OK;
}

SElemType GetTop(SqStack s) {
// 获取栈顶元素
    return *(s.top - 1);
}

