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