// 这个源文件，尝试用显示栈的操作解决括号匹配问题，链式栈
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR -1

typedef int Status;
typedef char ElemType;
typedef struct StackNode {
    ElemType elem;
    struct StackNode *next;
} SNode, *LinkStack;

LinkStack InitStack();
ElemType GetTop(LinkStack S);
Status Push(LinkStack S, ElemType e);
Status Pop(LinkStack S);

int main() {

}

LinkStack InitStack()
{
    return NULL;
}
ElemType GetTop(LinkStack S)
{
    if (S == NULL) 
        return ERROR;    
    
    return S->elem;
}
Status Push(LinkStack S, ElemType e)
{
    SNode *p = (SNode *)malloc(sizeof(SNode));
    p->elem = e;
    p->next = S;
    S = p;

    return OK;
}
Status Push(LinkStack S, ElemType e);

Status Pop(LinkStack S);






