#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int n, next[10000] = {0};
    char str[10000];

    scanf("%d", &n);
    char c = getchar();
    for (int i = 0; i < n; i++) {
        scanf("%c", &str[i]);
        c = getchar();
    }

    next[0] = -1;
    int i = 0, j = -1;
    int len = strlen(str);

    while (i < n-1) {
        if (j == -1 || str[i] == str[j]) {
            next[++i] = ++j;
        }
        else {
            j = next[j];
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", next[i]);
    }
    return 0;
}