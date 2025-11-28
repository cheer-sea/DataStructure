#define MAXSIZE 20

int UPSets[MAXSIZE];

int Initial(int s[]) {
// 初始化并查集
    for (int i = 0; i < MAXSIZE; i++) {
        s[i] = -1;
    }    
}

int Find(int s[], int x) {
// 找到 x 所属集合
    while(s[x] >= 0) {
        x = s[x];
    }
}

void Union(int s[], int root1, int root2) {
// 合并两个集合
    if (root1 == root2) return;
    s[root2] = root1;
}


int Find_opti(int s[], int x) {
// 查操作的优化，“压缩路径”提高速度
    int root = x;
    while (s[root] > 0) root = s[root];
    while (x != root) {
        int t = s[x];
        s[x] = root;
        x = t;
    }
    return root;
}

void Union_opti(int s[], int root1, int root2) {
    if (root1 == root2) return;
    if (s[root2] > s[root1]) {
        s[root1] += s[root2];
        s[root2] = root1;
    }
    else {
        s[root2] += s[root1];
        s[root1] = root2;
    }
}