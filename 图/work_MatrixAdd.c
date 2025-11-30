#include<stdio.h>
#include<stdlib.h>

int main() {
    int A[10000] = {0};
    int B[10000] = {0};
    int re[10000] = {0};
    int flag_a[100][100];
    int flag_b[100][100];
    int flag_re[100][100];

    int n, m, num_a = 0, num_b = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &flag_a[i][j]);
            if (flag_a[i][j]) {
                num_a++;
            }
        }
    }

    for (int k = 0; k < num_a; k++) {
        scanf("%d", &A[k]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &flag_b[i][j]);
            if (flag_b[i][j]) {
                num_b++;
            }
        }
    }
    for (int k = 0; k < num_b; k++) {
        scanf("%d", &B[k]);
    }

    int index_a = 0, index_b = 0, k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (flag_a[i][j] || flag_b[i][j]) {
                if (flag_a[i][j]) {
                    re[k] += A[index_a];
                    index_a++;
                }
                if (flag_b[i][j]) {
                    re[k] += B[index_b];
                    index_b++;
                }
                
                if (re[k]) {
                    flag_re[i][j] = 1;
                    k++;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", flag_re[i][j]);
        }
        printf("\n");
    }

    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (flag_re[i][j]) {
                printf("%d ", re[k++]);
            }
        }
    }
    return 0;
}



