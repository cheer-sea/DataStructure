#include<stdio.h>
#include<stdlib.h>

typedef struct Tnode {
    char data;
    struct Tnode *Lchild;
    struct Tnode *Rchild;
} Tnode, *Tree;

Tree CreateTree() {
    char c;
    scanf(" %c", &c);
    if (c == '#') 
        return NULL;

    Tree root = (Tree)malloc(sizeof(Tnode));
    root->data = c;
    root->Lchild = CreateTree();
    root->Rchild = CreateTree();

    return root;
}

void TraverseT(Tree root) {
    if (root == NULL) {
        return ;
    }
    
    TraverseT(root->Lchild);
    printf("%c ", root->data);
    TraverseT(root->Rchild);
    return;
}

int main() {
    Tree T = CreateTree();
    TraverseT(T);
    return 0;
}