#include <stdio.h>
#define MAX 100

int main() {
    int n, f = 0, r = 0, cnt = 0;
    int g[MAX][MAX], v[MAX] = {0}, q[MAX];
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (!v[i]) {
            cnt++;
            q[r++] = i;
            v[i] = 1;
            
            while (f < r) {
                int cur = q[f++];
                printf("%d ", cur + 1);
                
                for (int j = 0; j < n; j++) {
                    if (g[cur][j] && !v[j]) {
                        v[j] = 1;
                        q[r++] = j;
                    }
                }
            }
        }
    }
    
    printf("\n%d\n", cnt);
    return 0;
}