#include<stdio.h>

void BuildMaxHeap(int A[], int len) {
    for (int i = len/2; i > 0; i--) {
        M_HeapAdjust(A, i, len);
    }
}

void M_HeapAdjust(int A[], int k, int len) {
    A[0] = A[k];
    for (int i = 2*k; i <= len; i *= 2) {
        if (i+1 <= len && A[i] < A[i+1]) {
            i++;
        } 
        if (A[0] >= A[i]) {
            break;
        }
        else {
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}