#include<stdio.h>
#include<stdlib.h>

int result[1050];
int SumAddTree(int *pre, int *in, int in_start, int in_end) {
    int root = pre[0], index = -1;
    if (in_start > in_end) 
        return 0;

    for (int i = in_start; i <= in_end; i++) {
        if (in[i] == root) {
            index = i;
        }
    }

    int left_size = index - in_start;
    int lchild_sum = SumAddTree(pre+1, in, in_start, index-1);
    int rchild_sum = SumAddTree(pre+left_size+1, in, index+1, in_end);

    result[index] = lchild_sum + rchild_sum;
    return lchild_sum + rchild_sum + root;
}



int main() {
    int n, pre[1050], in[1050];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }

    SumAddTree(pre, in, 0, n-1);
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}