#include <stdio.h>

int main() {
    int t, n, f, r, cnt, sum;
    int g[100][100], in[100], q[100], flag[100] = {0};
    scanf("%d", &sum);
    
    for (t = 0; t < sum; t++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) 
            in[i] = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &g[i][j]);
                if (g[i][j]) 
                    in[j]++;
            }
        }
        
        f = 0; r = 0; cnt = 0;
        for (int i = 0; i < n; i++)
            if (in[i] == 0) q[r++] = i;
        
        while (f < r) {
            int v = q[f++];
            cnt++;
            for (int i = 0; i < n; i++)
                if (g[v][i] && --in[i] == 0) q[r++] = i;
        }
        
        if (cnt != n) {
            flag[t] = 1;
        }
    }
    
    for (int i = 0; i < sum; i++) {
        printf("%d", flag[i]);
    }
    return 0;
}