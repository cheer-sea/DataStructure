#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct {
    int valid;
    int key;
    int next;
} Link;

int main() {
    int start, n;
    int visit[10000] = {0};
    Link list[100000];

    scanf("%d%d", &start, &n);
    for (int i = 0; i < n; i++) {
        int address, key, next;
        scanf("%d%d%d", &address, &key, &next);
        list[address].valid = 1;
        list[address].key = key;
        list[address].next = next;
    }
    
    int current = start;
    int pre = -2;
    while (current != -1) {
        int key = abs(list[current].key);
        if (visit[key] == 0) {
            visit[key] = 1;
            pre = current;
            current = list[current].next;
        }
        else {
            list[current].valid = 0;
            list[pre].next = list[current].next;
            current = list[current].next;
        }
    }

    current = start;
    int length = 0;
    while (current != -1) {
        length++;
        current = list[current].next;
    }

    printf("%d\n", length);

    current = start;
    while (current != -1) {
        if (list[current].next != -1) {
            printf("%05d %d %05d\n", current, list[current].key, list[current].next);
        } else {
            printf("%05d %d -1\n", current, list[current].key);
        }
        current = list[current].next;
    }

    return 0;
}





