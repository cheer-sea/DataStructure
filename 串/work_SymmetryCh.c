#include<stdio.h>

int main() {
    int n, flag = 0;
    char ch[105];
    scanf("%d", &n);
    scanf("%s", ch);

    for (int i = 0; i < (n-1) / 2; i++) {
        if (ch[i] != ch[n-1-i]) {
            flag = 0;
        }
    }

    if (flag) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
    return 0;
}