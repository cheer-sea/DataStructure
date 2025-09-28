// 这个源文件实现了链表的旋转，即把每个结点向右移动k个位置，其中k是非负数。

#include <stdio.h>
#include <stdlib.h>

// 定义链表节点的数据类型
typedef struct {
    char name[20];
    int age;
} ElemType;

// 定义链表的指针类型
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// 链表反转函数的实现








