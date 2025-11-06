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
void CountLeaf(BiTree root) {
// 计算二叉树中叶子节点的个数，采用后序遍历，count为全局变量
    if (root != NULL) {
        CountLeaf(root->LChild);
        CountLeaf(root->RChild);
        if (root->LChild == NULL && root->RChild == NULL) {
            count++;
        }
    }
}

int CountLeaf_2(BiTree root) {
/* 采用分治算法，如果是空树，返回0；如果只有一个结点，说明当前就是叶子结点，返回1；否则，递归计算左右子树的叶子结点个数，相加返回。 */
    int leafcount;
    if (root == NULL) leafcount = 0;
    else if (root->LChild == NULL || root->RChild == NULL)
        leafcount = 1;
    else {
        leafcount = CountLeaf_2(root->LChild) + CountLeaf_2(root->RChild);
    }
    return leafcount;
}

int PostTreeDepth(BiTree root) {
// 后序遍历二叉树，计算树的深度，采用递归算法
    int left, right, max;

    if (root == NULL)  
        return 0;
    else {
        left = PostTreeDepth(root->LChild);
        right = PostTreeDepth(root->RChild);
        max = (left > right)? (left) : (right);
    }
    return max+1;
}

int depth = 0, h = 1;
void PreTreeDepth(BiTree bt, int h) {
// 先序遍历二叉树，h 为bt指向结点的深度，初值为1, depth 为全局变量，记录树的深度
    if (bt != NULL) {
        if (h > depth) {
            depth = h;
        }
        PreTreeDepth(bt->LChild, h+1);
        PreTreeDepth(bt->RChild, h+1);
    }
}

