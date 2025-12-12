#include<stdio.h>
#include<string.h>

int n;
int leaf[1050], leaf_num = 0;
int preorder[1050], pre_num = 0;
int postorder[1050], post_num = 0;

void operate(int *in, int in_start, int in_end, int *level) {
    if (in_start > in_end) {
        return;
    }
    int index = -1;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = in_start; j <= in_end; j++) {
            if (in[j] == level[i]) {
                index = j;
                found = 1;
                break;
            }
        }
        if (found) break;
    }
    if (index == -1) {
        return;
    }
    preorder[pre_num++] = in[index];

    if (in_start == in_end) {
        leaf[leaf_num++] = in[index];
    }

    operate(in, in_start, index-1, level);
    operate(in, index+1, in_end, level);
    postorder[post_num++] = in[index];
}

void printresult(int *re, int len){
    for (int k = 0; k < len; k++) {
        printf("%d ", re[k]);
    }
    printf("\n");
    return;
}

int main(){
    int level[1050], in[1050];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &level[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf(" %d", &in[i]);
    }

    operate(in, 0, n-1, level);
    printresult(leaf, leaf_num);
    printresult(preorder, pre_num);
    printresult(postorder, post_num);

    return 0;
}