#include<stdio.h>

int visit[105] = {0};

void dfs(int v, int n, int g[][100]) {
    printf("%d ", v);
    visit[v] = 1;
    for (int j = 1; j <= n; j++) {
        if (g[v][j] && !visit[j]) {
            dfs(j, n, g);
        }
    }
}
int g_DFS(int n, int g[][100]) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            dfs(i, n, g);
            sum++;
        }
    }
    return sum;
}


int main(){
    int n, g[100][100];
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    int sum = g_DFS(n, g);
    printf("\n%d\n", sum);
    return 0;
}