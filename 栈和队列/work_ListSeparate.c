#include<stdio.h>

typedef struct Node {
    int number;
    struct Node *next;
} QNode;

typedef struct {
    QNode *front;
    QNode *rear;
} LinkQueue;

void EnterQueue(LinkQueue *Q, int number);
void 






// int main() {
//     int n, sum = 0;
//     int list[100], temp[100];
//     scanf("%d", &n);

//     for (int i = 0; i < n; i++) {
//         scanf("%d", list[i]);
//     }

//     for (int i = 0; i < n;) {
//         temp[sum] = list[i];
//         i += 2;
//         sum++;
//     }
//     for (int i = 0; i < n; ) {
//         temp[i+sum] = list[i+1];
//         i += 2;
//     }
//     for (int i = 0; i < n; i++) {
//         printf("%d ", temp[i]);
//     }
//     return 0;
// }

