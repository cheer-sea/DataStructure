#include<stdio.h>
#include<stdlib.h>

int getMid(int key[], int low, int high) {
    int temp = key[low];
    while (low < high) {
        while (low < high && key[high] >= temp)
            high--;
        key[low] = key[high];
        while (low < high && key[low] <= temp)
            low++;
        key[high] = key[low];
    }
    key[low] = temp;
    return low;
}

void getPostOrder(int key[], int low, int high) {
    if (low <= high) {
        int mid = getMid(key, low, high);
    
        getPostOrder(key, low, mid-1);
        getPostOrder(key, mid+1, high);
        printf("%d ", key[mid]);
    }
    return;
}

int main () {
    int key[200], n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &key[i]);
    }

    getPostOrder(key, 0, n-1);
    return 0;
}