// 该程序实现主要算法，删除顺序表中值为 x 的元素。要求算法时间复杂度为 O(n)， 空间复杂度为 O(1)。

typedef int ElemType; // 元素类型定义
#define MAXSIZE 1000

typedef struct {
    ElemType data[MAXSIZE]; // 元素值
    int length; // 指向下一个元素的位置
} SqList;

void DeleteX(SqList *L, ElemType x) {
    int i = 0, j = 0;
    while (i < L->length) {
        if (L->data[j] != x) {
            L->data[i] = L->data[j];
            i++;
            j++;
        } 
        else j++;
    }
    L->length = i; // 更新为长度
}