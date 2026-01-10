#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    scanf("%d %d", &n, &m);
    int a[n], flag[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        flag[i] = 1;
    }
    
    int i = 0, cnt = 0, sum = n;

    while (sum > 0) {
        if (flag[i] == 1) {
            cnt++;

            if (cnt == m) {
                flag[i] = 0;
                printf("%d ", i + 1);
                cnt = 0;
                m = a[i];
                sum--;
            }
        }

        i = (i + 1) % n;
    }
    return 0;
}
