#include <stdio.h>

void change(int a[]);
int main(){
    int a[10];
    a[0] = 2;
    change(a);
    printf("%d", a[0]);

    return 0;
}

void change(int a[]) {
    a[0] = 5;
    return;
}