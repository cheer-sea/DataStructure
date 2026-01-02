#include <stdio.h>
#include <string.h>

#define MAXN 100

int main() {
    int top = -1, n;
    int g[MAXN][MAXN], stk[MAXN], in[MAXN] = {0}, ear[MAXN] = {0};
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
            if(g[i][j] > 0) 
                in[j]++;
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(in[i] == 0) 
            stk[++top] = i;
    }
    
    int cnt = 0;
    while(top != -1) {
        int v = stk[top--];
        cnt++;
        for(int i = 0; i < n; i++)
            if(g[v][i] > 0) {
                if(ear[v] + g[v][i] > ear[i])  
                    ear[i] = ear[v] + g[v][i];
                if(--in[i] == 0) stk[++top] = i;
            }
    }
    
    if(cnt != n) 
        printf("NO\n");
    else 
        printf("%d\n", ear[n-1]);
    
    return 0;
}