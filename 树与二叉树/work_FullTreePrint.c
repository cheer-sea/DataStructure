#include<stdio.h>

int main() {
    int n, d, num[1050] = {0};
    scanf("%d", &n);

    while (n != 0) {
        int new;
        for (int i = 1; i <= n; i++) {
            scanf(" %d", &num[i]);
        }
        scanf("%d", &d);
        scanf("%d", &new);

        int end = 0, temp = 1;
        for (int i = 0; i < d; i++) {
            end += temp;
            temp *= 2;
        }
        int start = (end+1) / 2;

        int flag = 0;
        for (int i = start; i <= end && i <= n; i++) {
            if (num[i] != 0) {
                printf("%d ", num[i]);
                flag = 1;
            }
        }
        printf("\n");
        if (!flag) {
            printf("EMPTY\n");
        }
        n = new;
    }
    return 0;
}