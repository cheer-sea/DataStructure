
// 未优化写法一
void BubbleSort(int A[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = n-1; j > i; j--) {
            if (A[j-1] > A[j]) {
                int temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
            }
        }
    }
}

// 未优化写法二
void BubbleSort_Sec(int A[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (A[j] > A[j+1]) {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

// 优化写法
void BubbleSort_Plus(int A[], int n) {
    for (int i = 0; i < n-1; i++) {
        int flag = 0;
        for (int j = 0; j < n-1-i; j++) {
            if (A[j] > A[j+1]) {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                flag = 1;
            }
        }
        if (!flag) break;
    }
}