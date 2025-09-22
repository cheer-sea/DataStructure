// 这个源文件，实现了删除有序数组中的重复项，并返回删除后数组的长度
// 已知数据是升序排列

#include <stdio.h>
#include <stdlib.h>

// 定义线性表结构体，这里为顺序存储
typedef int ElemType;
typedef struct {
    ElemType data;
    int length;
} SqList;

// 删除函数的实现
int Delete(SqList *list, int length) {
    if (length == 0)
        return 0;
    int fast, slow;
    fast = 1;
    slow = 1;
    while (fast < length) {
        if (list[fast].data != list[fast-1].data) {
            list[slow].data = list[fast].data;
            slow++;
        }
        fast++;
    }
    return slow;
}









