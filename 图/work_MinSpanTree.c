#include<stdio.h>

int main() {
    int Adj_G[35][35], visited[35] = {0};
    int i, j, weight, n, m, min = 99999, id_x, id_y;
    scanf("%d%d", &n, &m);

    for (i = 0; i < 35; i++) {
        for (j = 0; j < 35; j++) {
            Adj_G[i][j] = 99999;
        }
    }
    for (int k = 0; k < m; k++) {
        scanf("%d%d%d", &i, &j, &weight);
        Adj_G[i][j] = weight;
        Adj_G[j][i] = weight;
    }


    int k = 0;
    while (k < n-1) {
        min = 99999;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (!(visited[i] && visited[j])) {
                    if (Adj_G[i][j] < min) {
                        min = Adj_G[i][j];
                        id_x = i;
                        id_y = j;
                    }
                }
            }
        }

        visited[id_x] = visited[id_y] = 1;
        printf("%d %d %d\n", id_x, id_y, Adj_G[id_x][id_y]);
        k++;
    }
    return 0;
}