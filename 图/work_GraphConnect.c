#include<stdio.h>

int Dfs_WithCount(int G[][35], int vnum, int v);
int visited[35] = {0};

int main(){
    int Adj_G[35][35] = {0}, num[35] = {0};
    int n, m, sum = 0;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        Adj_G[v1][v2] = 1;
        Adj_G[v2][v1] = 1;
    }

    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int temp = Dfs_WithCount(Adj_G, n, i);
            sum++;
            num[k++] = temp;
        }
    }

    printf("%d\n", sum);
    
    for (int i = 0; i < sum - 1; i++) {
        for (int j = 0; j < sum - i - 1; j++) {
            if (num[j] > num[j + 1]) {
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
    
    for (int i = 0; i < sum; i++) {
        printf("%d ", num[i]);
    }
    
    return 0;
}

int Dfs_WithCount(int G[][35], int vnum, int v) {
    visited[v] = 1;
    int count = 1;
    
    for (int j = 1; j <= vnum; j++) {
        if (G[v][j] && !visited[j]) {
            count += Dfs_WithCount(G, vnum, j);
        }
    }
    
    return count;
}