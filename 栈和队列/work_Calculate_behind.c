#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main() {
    int number[100];
    char operator[50], ch[200];
    
    int top1 = -1, top2 = -1;
    scanf("%[^\n]", ch);
    int len = strlen(ch);

    for (int i = 0; i < len; i++) {
        if (ch[i] >= '0' && ch[i] <= '9') {
            top1++;
            number[top1] = ch[i] - '0';
        }
        else {
            int temp1, temp2, new;
            temp2 = number[top1--];
            temp1 = number[top1--];
            switch (ch[i]) {
                case '+': 
                    new = temp1 + temp2;
                    break;
                case '-':
                    new = temp1 - temp2;
                    break;
                case '*':
                    new = temp1 * temp2;
                    break;
                case '/':
                    new = temp1 / temp2;
                    break;
            }
            top1++;
            number[top1] = new;
        }
    }


    printf("%d\n", number[top1]);
    return 0;
}