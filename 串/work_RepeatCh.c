#include<stdio.h>
#include<string.h>

int main() {
    char ch[85];
    scanf("%s", ch);

    int T = 1, len = strlen(ch);
    while (1) {
        int flag = 1;
        for (int i = 0; i < len; i++) {
            if (ch[i] != ch[i+T]) {
                flag = 0;
            }
        }
        if (flag) {
            break;
        }
        else {
            T++;
        }
    }
    printf("%d", T);
    return 0;
}