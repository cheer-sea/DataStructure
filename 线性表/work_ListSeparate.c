#include<stdio.h>

 int main() {
    int n, sum = 0;
    int list[100], temp[100];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    for (int i = 0; i < n; i++) {
        if ((i+1) % 2 != 0) {
            temp[sum] = list[i];
            sum++;
        }
    }
    for (int i = 0; i < n; i++) {
        if ((i+1) % 2 == 0) {
            temp[sum++] = list[i];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
    return 0;
}

