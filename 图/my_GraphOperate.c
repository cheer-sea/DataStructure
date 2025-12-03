// 这个源文件，抽象定义图的遍历操作
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXSIZE 100

bool visited[MAXSIZE]; // 访问标记数组

typedef struct {
    char vertex;
    char arc;
    int vernum;
    int arcnum;
} Graph;

// 广度优先遍历
void BFS(Graph G, int v) {
// 从顶点v出发，广度优先遍历图G, Q 作为辅助栈，帮忙实现遍历操作
    visit(v);
    visited[v] = TRUE;
    Enqueue(Q, v);
    while (!isEmpty(Q)) {
        Dequeue(Q, v);
        for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
            if (!visited[w]) {
                visit(w);
                visited[w] = TRUE;
                Enqueue(Q, w);
            }
        }
    }
}

void BFSTraverse(Graph G) {
// 把整个图G进行广度优先遍历。可以实现找出有几个最大连通分量等目的, 下面的flag值即对应最大连通分量的个数。
    int flag = 0;
    for (int i = 0; i < G.vernum; i++) {
        visited[i] = false;
    }
    InitQueue(Q);
    for (int i = 0; i < G.vernum; i++) {
        if (!visited[i]) {
            BFS(G, i);
            flag++;
        }
    }
}