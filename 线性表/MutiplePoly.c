/*
    这个源文件，尝试稀疏多项式的运算
*/
# include<stdio.h>

// 一、定义数据类型结构体
typedef struct PNode
{
    float coef; // 系数
    int exp; // 指数
    struct PNode *next; // 指向下一个节点
} PNode, *Polynomial;

// 二、声明函数
void CreatePolyn(Polynomial p, int n); // 创建多项式
void AddPolyn(Polynomial p1, Polynomial p2); // 多项式加法



// 函数功能实现
// 1. 创建多项式
void CreatePolyn(Polynomial p, int n)
{
    Polynomial P; // 定义指针变量
    P = (Polynomial)malloc(n * sizeof(PNode)); // 分配内存

}
void AddPolyn(Polynomial p1, Polynomial p2);