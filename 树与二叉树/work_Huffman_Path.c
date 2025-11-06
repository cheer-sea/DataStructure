#include<stdio.h>

#define MAXSIZE 70

void select(int w[], int n, int *l1, int *l2, int flag[]);

int main() {
    int n, sum = 0;
    int w[MAXSIZE];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    for (int k = 0; k < n-1; k++) {
        int idx1 = -1, idx2 = -2;
        int min1 = 10000, min2 = 10001;
        for (int i = 0; i < n+k; i++) {
            if (w[i] > 0 && w[i] < min1) {
                min1 = w[i];
                idx1 = i;
            }
        }
        for (int i = 0; i < n+k; i++) {
            if (w[i] > 0 && w[i] < min2 && i!= idx1) {
                min2 = w[i];
                idx2 = i;
            }
        }
        
        if (idx1 != -1) w[idx1] = -1;
        if (idx2 != -2) w[idx2] = -1;

        w[n+k] = min1 + min2;
        sum += w[n+k];
    }

    printf("%d\n", sum);
    return 0;
}


