#include<stdio.h>
#include<stdlib.h>
#define ElemType int

typedef struct {
    ElemType *elem;
    int TableLen;
} SSTable;

int Binary_Search(SSTable L, ElemType key) {
    int low = 0, high = L.TableLen-1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L.elem[mid] == key) {
            return mid;
        } 
        else if (L.elem[mid] < key) {
            low = mid+1;
        } 
        else {
            high = mid-1;
        }
    }
    return -1;
}