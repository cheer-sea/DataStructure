#include <stdio.h>

int judge(char a, char b);

int main() {
    int T;
    scanf("%d", &T);
    getchar();

    int flag[T];
    char match[T][31];
    for (int i = 0; i < T; i++) {
        int cnt = 0;

        while ((match[i][cnt] = getchar()) != '\n' && cnt < 30) {
            if (cnt > 0 && judge(match[i][cnt-1], match[i][cnt])) {
                cnt -= 1;
                continue;
            }
            cnt++;
        }
        if (cnt == 0) {
            flag[i] = 1;
        }
        else {
            flag[i] = 0;
        }
    }

    for (int i = 0; i < T; i++) {
        if (flag[i]) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }
    return 0;
}

int judge(char a, char b) {
    if (a == '{' && b == '}') {
        return 1;
    }
    if (a == '[' && b == ']') {
        return 1;
    }
    if (a == '(' && b == ')') {
        return 1;
    }
    return 0;
}

