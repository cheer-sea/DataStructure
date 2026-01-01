#include <stdio.h>
#define INF 10000

int main() {
    int n, u, v;
    int dist[100][100], path[100][100];
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
            if(dist[i][j] == INF || i == j) 
                path[i][j] = -1;
            else 
                path[i][j] = i;
        }
    }
    
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    
    while(scanf("%d %d", &u, &v) && !(u == -1 && v == -1)) {
        if(dist[u][v] >= INF) {
            printf("NO\n");
            continue;
        }
        
        printf("%d\n", dist[u][v]);
        
        int route[100], cnt = 0, cur = v;
        while(cur != -1) {
            route[cnt++] = cur;
            cur = path[u][cur];
        }
        
        for(int i = cnt-1; i >= 0; i--)
            printf("%d ", route[i]);
        printf("\n");
    }
    
    return 0;
}