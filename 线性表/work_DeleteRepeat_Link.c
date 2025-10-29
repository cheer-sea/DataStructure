#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 105

typedef struct {
    int address;
    int value;
    int next;
} ElemType;

typedef struct  {
    ElemType data[MAXSIZE];
    int length;
} SqList;

int main() {
    SqList L;
    int start, n;
    
    scanf("%d%d", &start, &n);
    for (int i = 0; i < n; i++) {
        int address, value, next, abs_value;
        scanf("%5d%d%5d", &address, &value, &next);

        L.data[i].address = address;
        L.data[i].value = value;
        L.data[i].next = next;
    }

    int front, new_start = start, count = 0, num = 0;
    int flag[100000] = {0}, finish[105] = {0};
    while (count < n) {
        for (int i = 0; i < n; i++) {
            if (finish[i]) 
                continue;
            if (L.data[i].address == new_start) {
                int abs_value = abs(L.data[i].value);

                num++;
                new_start = L.data[i].next;
                finish[i] = 1;
                count++;

                if (flag[abs_value]) {
                    num--;
                    L.data[i].address = -2;
                    L.data[front].next = new_start;
                }
                flag[abs_value] = 1;
                front = i;
            }
        }
    }
    printf("%d\n", num);

    int re_finish[105] = {0};
    new_start = start, count = 0;
    while (count < num) {
        for (int i = 0; i < n; i++) {
            if (L.data[i].address == new_start) {
                if (L.data[i].next == -1) {
                    printf("%05d %d %d\n", L.data[i].address, L.data[i].value, L.data[i].next);
                    break;
                }
                printf("%05d %d %05d\n", L.data[i].address, L.data[i].value, L.data[i].next);
                new_start = L.data[i].next;
            }
        }
        count++;
    }
    
    return 0;
}



