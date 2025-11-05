#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[15];
    int grade;
    int age;
} DataType;

typedef struct Node {
// 二叉树数据结构体
    DataType data;
    struct Node *LChild;
    struct Node *RChild;
} BiTNode, * BiTree;

void PreOrder(BiTree root) {
// 先序遍历二叉树，即按根左右顺序
    if (root != NULL) {
        printf("%s", root->data.name);
        PreOrder(root->LChild);
        PreOrder(root->RChild);
    }
}

void PrePrintLeaf(BiTree root) {
// 先序遍历二叉树，打印叶子节点
    if (root != NULL) {
        if (root->LChild == NULL && root->RChild == NULL) {
            printf("%s", root->data.name);
        }
        PrePrintLeaf(root->LChild);
        PrePrintLeaf(root->RChild);
    }
}

int count = 0;
void CountLear(BiTree root) {
// 计算二叉树中叶子节点的个数，采用后序遍历，count为全局变量
    if (root != NULL) {
        CountLear(root->LChild);
        CountLear(root->RChild);
        if (root->LChild == NULL && root->RChild == NULL) {
            count++;
        }
    }
}

