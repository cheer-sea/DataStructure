/* 这个源文件，用于实现线性表中的顺序存储结构的各方面内容
*/

# include <stdio.h>
# include <stdlib.h>
# define OK 1 // 函数正常执行状态
# define ERROR 0 // 函数执行出错状态
# define TRUE 1 // 逻辑真值
# define FALSE 0 // 逻辑假值
# define MAXSIZE 1000 // 顺序表的最大容量

/// 顺序存储结构的定义
typedef int ElemType; // 元素类型定义
typedef int Status; // 函数状态定义

// 结构体定义
typedef struct {
    ElemType data[MAXSIZE]; // 元素类型
    int length; // 容量
} SqList;

// 各种操作函数(初始化，检查非空，插入，删除)
Status InitList(SqList *L, int n) {
    // 初始化顺序表
    L = (SqList *)malloc(sizeof(SqList)); // 分配内存
    L->length = 0; // 初始长度 0
    if (L->data == NULL) { // 内存分配失败
        return ERROR;
    }
}
Status ListEmpty(SqList L) {
    // 检查顺序表是否为空
    if (L.length == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}
Status ListInsert(SqList *L, int i, ElemType e) {
    // 在第 i 个位置插入元素e
    if (i < 1 || i > L->length+1) { // 越界检查
        return ERROR;
    }

    for (int j = L->length - 1; j >= i-1; j--) { // 后移元素
        L->data[j + 1] = L->data[j];
    }
    L->data[i-1] = e; // 插入元素
    L->length++; // 容量加 1
    return OK;
}
Status ListDelete(SqList *L, int i, ElemType *e) {
    // 删除第 i 个位置的元素，并将其值存入e
    if (i < 1 || i > L->length - 1) { // 越界检查
        return ERROR;
    }

    *e = L->data[i-1]; // 保存要删除的元素的值
    for (int j = i; j < L->length; j++) { // 前移元素
        L->data[j] = L->data[j + 1];
    }
    L->length--; // 容量减 1
    return OK;
}


