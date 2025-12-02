/*本源文件，尝试图中的邻接矩阵相关内容，操作包括结构体定义，创建矩阵，*/
#define MAX_VERTEX_NUM 20 // 最多顶点个数
#define INFINITY 32768 // 最大值

// 图的种类：DG有向图，DN有向网，UDG无向图，UDN无向网
typedef enum{DG, DN, UDG, UDN} GraphKind;
typedef char VertexData;
typedef int AdjType;
typedef struct ArcNode {
// 邻接矩阵中结点的定义
    AdjType adj; 
    char info;
} ArcNode;
typedef struct {
// 邻接矩阵的结构体定义
    VertexData vertex[MAX_VERTEX_NUM]; // 结点
    ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 邻接矩阵
    int vexnum, arcnum;
    GraphKind kind;
} AdjMatrix;

int LocateVertex(AdjMatrix *G, VertexData v) {
// 查找某一顶点位置
    int k, pos = -1;
    for (k = 0; k < G->vexnum; k++) {
        if(G->vertex == v) {
            pos = k;
            break;
        }
    }
    return pos;
}

int CreateDN(AdjMatrix *G) {
// 创建一个有向网
    int weight;
    VertexData v1, v2;
    scanf("%d,%d", &G->arcnum, &G->vexnum);
    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; j++) {
            G->arcs[i][j].adj = INFINITY;
        }
    }
    for (int i = 0; i < G->vexnum; i++) {
        scanf("%c", &G->vertex[i]);
    }
    for (int k = 0; k < G->arcnum; k++) {
        scanf("%c, %c, %d, %d", &v1, &v2, &weight);
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        G->arcs[i][j].adj = weight;
    }
    return 1;
}



