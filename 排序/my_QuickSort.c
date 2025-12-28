// 快排中可以选择从数组的头、中、尾三个元素中，值位于中间的元素为枢轴元素，实现一定性能的优化，但本代码中选择默认待划分数组部分中第一个元素为枢轴元素


// 用第一个元素将排序序列划分成左右两个部分
int Partition(int A[], int low, int high) {
    int pivot = A[low];
    while (low < high) {
        while (low < high && A[high] >= pivot) {
            high--;
        }
        A[low] = A[high];
        while (low < high && A[low] <= pivot) {
            low++;
        }
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(int A[], int low, int high) {
    if (low < high) {
        int mid = Partition(A, low, high);
        QuickSort(A, low, mid-1);
        QuickSort(A, mid+1, high);
    }
}
