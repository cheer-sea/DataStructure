#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Tnode {
    char data;
    struct Tnode *Lchild;
    struct Tnode *Rchild;
} Tnode, *Tree;

void Postorder(char* pre, char* in, int n) {
    if (n <= 0) 
        return;

    char root = pre[0];
    int i;

    for (i = 0; i < n; i++) {
        if (in[i] == root) break;
    }
    Postorder(pre + 1, in, i);
    Postorder(pre + i + 1, in + i + 1, n - i - 1);
    printf("%c", root);
    return;
}

int main () {
    char s1[30], s2[30];
    scanf("%s", s1);
    scanf("%s", s2);

    int len = strlen(s1);
    Postorder(s1, s2, len);
    return 0;

}
