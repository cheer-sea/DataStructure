#include<stdio.h>
#define MVNum 100

typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
    int otherinfo;
} ArcNode;

typedef struct VexNode{
    char data;
    ArcNode *firstarc;

} VNode, AdjList[MVNum];

typedef struct{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;
