#include<stdio.h>
#define MAXLEN 100
typedef struct {
// 定长顺序串结构体定义
    char ch[MAXLEN];
    int len;
} SString;

int StrInsert(SString *s, int pos, SString *t); // 串插入函数
int StrCompart(SString s, SString t); // 串比较函数

int main() {
    SString s, t;

    int flag1 = StrInsert(&s, 1, &t);



}

int StrInsert(SString *s, int pos, SString *t) {
// 串插入函数实现，如被传入串内容按插入位置左右分为两部分 AB，待插入串内容为 C，则插入操作后变为 ACB
    if (pos < 0 || pos > s->len) 
        return 0;
    if (s->len + t->len < MAXLEN) {
    // 新串插入后没有超出最大存储个数
        for (int i = s->len + t->len - 1; i > pos + t->len - 1; i--) {
            s->ch[i] = s->ch[i-t->len];
        }
        for (int i = 0; i < t->len; t++) {
            s->ch[i+pos] = t->ch[i];
        }
        s->len += t->len;
    }
    else if (pos + t->len <= MAXLEN) {
    // 插入后新串仍在存储范围，但被插入串的部分内容无法再被存储
        for (int i = MAXLEN - 1; i > t->len + pos - 1; i--) {
            s->ch[i] = s->ch[i-t->len];
        }
        for (int i = 0; i < t->len; i++) {
            s->ch[i+pos] = t->ch[i];
        }
        s->len = MAXLEN;
    }
    else {
    // 插入后新串的部分内容也无法被存储
        for (int i = 0; i < MAXLEN-pos; i++) {
            s->ch[i+pos] = t->ch[i];
        }
        s->len = MAXLEN;
    }
    return 1;
}

int StrCompare(SString s, SString t) {
    for (int i = 0; i < s.len && i < t.len; i++) {
        if (s.ch[i] != t.ch[i]) 
            return (s.ch[i] - t.ch[i]);
    }
    return (s.len - t.len);
}