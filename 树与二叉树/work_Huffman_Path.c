#include<stdio.h>

#define MAXSIZE 70

void select(int PathLength[], int n, int *l1, int *l2, int flag[]);

int main() {
    int n;
    int PathLength[MAXSIZE];
    int flag[MAXSIZE] = {0};

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &PathLength[i]);
    }

    int l1, l2, m = 2*n - 1;
    for (int i = n+1; i <= m; i++) {
        select(PathLength, i-1, &l1, &l2, flag);
        PathLength[i] = l1 + l2;
    }
    printf("%d", PathLength[m]);
    return 0;
}

void select(int PathLength[], int n, int *l1, int *l2, int flag[]) {
    int min1 = 10000, min2 = 10001;
    for (int i = 1; i <= n; i++) {
        if (!flag[i]) {
            if (min2 > PathLength[i]) {
                flag[i] = 1;
                if (min1 > PathLength[i]) { 
                    min1 = PathLength[i];
                    continue;
                }
                else 
                    min2 = PathLength[i];
            } 
        }
    }
    *l1 = min1;
    *l2 = min2;
}


