#include<stdio.h>
#define MAXSIZE 15

int main() {
    int n, flag = 1, top = -1, index = 0;
    int NumberSeq[MAXSIZE];
    int PopSeq[MAXSIZE];
    int Stack[MAXSIZE];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        NumberSeq[i] = i+1;
        scanf("%d", &PopSeq[i]);
    }
    
    for (int i = 0; i < n; i++) {
        int current = PopSeq[i];

        while (top == -1 || Stack[top] != current) {
            if (index >= n) {
                flag = 0;
                break;
            }
            top++;
            Stack[top] = NumberSeq[index];
            index++;
        }
        top--;
    }

    if (flag) {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
    return 0;
}

