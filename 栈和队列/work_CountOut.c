#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, sum, temp = 2;
    int flag[6000] = {0};
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        flag[i] = 1;
    }
    sum = n;

    while (sum > 3) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (flag[i]) {
                count++;
                if ((count % temp) == 0) {
                    flag[i] = 0;
                    sum--;
                }
            }
        }
        if (temp == 2) {
            temp = 3;
        }
        else {
            temp = 2;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (flag[i]) {
            printf("%d ", i+1);
        }
    }

    return 0;
}