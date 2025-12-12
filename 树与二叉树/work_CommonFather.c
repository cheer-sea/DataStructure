#include<stdio.h>


int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    while (x != 0 && y != 0) {
        int flag = 0, f_x = x, f_y = y;
        
        while (f_x != 0 && f_y != 0) {
            if (f_x == f_y) {
                flag = 1;
                break;
            }
            if (f_x > f_y) {
                f_x /= 2;
            } else {
                f_y /= 2;
            }
        }
        if (flag) {
            printf("%d\n", f_x);
        }
        scanf("%d%d", &x, &y);
    }
    return 0;
}