#include<stdio.h>
#include<stdlib.h>

int find(int x, int set[]) {
    if (x == set[x]) {
        return x;
    }
    set[x] = find(set[x], set);
    return set[x];
}

int main() {
    int m, n, set[1005] = {0}, high[1005] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        set[i] = i;
        high[i] = 1;
    }

    for (int j = 0; j < m; j++) {
        int city1, city2;
        scanf("%d %d", &city1, &city2);
        city1 = find(city1, set);
        city2 = find(city2, set);
        if (city1 == city2) {
            continue;
        }
        if (high[city1] <= high[city2]) {
            set[city1] = city2;
            high[city2]++;
        }
        else {
            set[city2] = city1;
            high[city1]++;
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i == set[i]) {
            sum++;
        }
    }
    printf("%d\n", sum-1);
    return 0;
}