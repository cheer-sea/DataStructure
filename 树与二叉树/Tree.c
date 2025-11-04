typedef struct {
    char name[15];
    int grade;
    int age;
} DataType;

typedef struct Node {
    DataType data;
    struct Node *LChild;
    struct Node *RChild;
} BiTNode, * BiTree;
