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

    for (int i = len-1; i >= 0; i--) {
        if (ch[i] == ' ') {
            continue;
        }
        if (isdigit(ch[i])) {
            int num = 0, mul = 1;
            while (i >= 0 && isdigit(ch[i])) {
                num = num + (ch[i] - '0') * mul;
                mul *= 10;
                i--;
            }
            top1++;
            number[top1] = num;
        }
        else {
            int temp1, temp2, new;
            temp2 = number[top1--];
            temp1 = number[top1--];
            switch (ch[i]) {
                case '+': 
                    new = temp2 + temp1;
                    break;
                case '-':
                    new = temp2 - temp1;
                    break;
                case '*':
                    new = temp2 * temp1;
                    break;
                case '/':
                    new = temp2 / temp1;
                    break;
            }
            top1++;
            number[top1] = new;
        }
    }


    printf("%d\n", number[top1]);
    return 0;
}