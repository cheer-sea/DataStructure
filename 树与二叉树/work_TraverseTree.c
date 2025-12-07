#include<stdio.h>
#include<stdlib.h>

typedef struct Tnode {
    char data;
    int flag;
    struct Tnode *Lchild;
    struct Tnode *Rchild;
} Tnode, *Tree;

int InTree(Tree T);

int main () {
    char s1[30], s2[30];
    scanf("%s", s1);
    scanf("%s", s2);

    printf("%s\n", s1);
    printf("%s\n", s2);
    return 0;

}
