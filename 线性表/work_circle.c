#include <stdio.h>
#include <stdlib.h>


int main() {
    int n, m, sum = 0, temp = 0;

    scanf("%d %d", &n, &m);

    int num[n], flag[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);;
        flag[i] = 1;
    }
    
    for (int i = 0; i < n; i++) {
        if (flag[i] == 0) {
            continue;
        } 
        else {
            temp++;
        }
        if (i == n -1) {
            i = 0;
        }

        if (temp == m) {
            sum++;
            temp = 0;
            m = num[i];
            printf("%d ", i);
            flag[i] = 0;
        }
        if (sum == n) {
            break;
        }
    }
    return 0;
}






