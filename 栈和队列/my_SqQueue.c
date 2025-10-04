// 这个源文件，尝试顺序队的表示和相关操作

#define MAXSIZE 100
#define OK 1
#define ERROR -1
#define OVERFLOW -2

typedef int Status;

typedef struct {
    int id;
    char name[10];
} QElemType;

typedef struct {
    QElemType *base;
    int front;
    int rear;
} SqQueue;

Status InitQueue(SqQueue *Q) {
// 初始化顺序队列
    Q->base = (QElemType *)malloc(MAXSIZE * sizeof(QElemType));
    if (!Q->base) return OVERFLOW;
    Q->front = Q->rear = 0;
    return OK;
}

Status DestroyQueue(SqQueue *Q) {
// 求队列长度
    return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

Status ClearQueue(SqQueue *Q, QElemType e) {
// 入队
    if (Q->rear = (Q->rear + 1) % MAXSIZE)
        return ERROR;

    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return OK;
}






