#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, next[10000] = {0};
    char str[10000];

    scanf("%d", &n);
    scanf("%s", str);

    next[0] = -1;
    for (int i = 1; i < n; i++) {
        if (str[i] == str[next[i-1]]) {
            next[i] = next[i-1] + 1;
        }
        else {
            int j = i-1;
            while (j != 0 || str[next[j]] != str[i]) {
                j = next[j];
            }
            next[i] = j;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", next[i]);
    }
    return 0;
}