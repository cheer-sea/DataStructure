#include<stdio.h>

int main() {
    int n, m, found = 0;
    int A[500][500];
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        int min = A[i][0];
        int min_col = 0;
        
        for (int j = 1; j < m; j++) {
            if (A[i][j] < min) {
                min_col = j;
                min = A[i][j];
            }
        }

        int flag = 1;
        for (int k = 0; k < n; k++) {
            if (A[k][min_col] > min) {
                flag = 0;
                break;
            }
        }

        if (flag) {
            found = 1;
            printf("%d %d %d\n", i + 1, min_col + 1, min);
        }

        for (int j = 0; j < m; j++) {
            if ((j != min_col) && (A[i][j] == min)) {
                flag = 1;
                for (int k = 0; k < n; k++) {
                    if (A[k][j] > min) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    found = 1;
                    printf("%d %d %d\n", i+1, j+1, min);
                }
            }
        }
    }

    if (!found) {
        printf("No\n");
    } 
    
    return 0;
}