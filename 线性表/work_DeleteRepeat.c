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
        scanf("%d%d%d", &address, &value, &next);

        L.data[i].address = address;
        L.data[i].value = value;
        L.data[i].next = next;
    }

    int new_start = start, num = 0, delete = 0;
    int flag[10000] = {0};
    while (num + delete < L.length) {
        for (int i = 0; i < n; i++) {
            if (L.data[i].address == new_start) {
                int abs_value = abs(L.data[i].value);
                if (flag[abs_value]) {
                    delete++;
                    for (int j = 0; j < n; j++) {
                        if (L.data[j].next == L.data[i].address) {
                            L.data[j].next = L.data[i].next;
                            L.data[i].address = 0;
                            break;
                        }
                    }
                }
                flag[abs_value] = 1;
                num++;
                new_start = L.data[i].next;
            }
        }
    }

    new_start = start;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i].address == new_start) {
            printf("%05d %d %d\n", L.data[i].address, L.data[i].value, L.data[i].next);
            new_start = L.data[i].next;
        }
    }

    return 0;
}


