#include <stdio.h>

void FindPath(int a[][100],int x1,int y1,int x2,int y2);

int d[5] = {0,1,2,3,4};
int cnt = 0,end = 0,t;

typedef struct num{
    int x;
    int y;
    int d;
}Num;
Num consult[1000];

int main(){
    int m,n,s1,s2,d1,d2;
    scanf("%d %d",&m,&n);
    scanf("%d %d %d %d",&s1,&s2,&d1,&d2);
    int num[m+2][100];
    for(int i = 0;i <= m+1;i++){
        for(int j = 0;j <= n+1;j++){
            if(i == 0 || j == 0 || i == m+1 || j == n+1){
                num[i][j] = 1;
            }else{
                scanf("%d",&num[i][j]);
            }
        }
    }

    FindPath(num,s1,s2,d1,d2);

    if(end == 1){
        for(int i = 0;i < t;i++){
            printf("(%d,%d,%d),",consult[i].x,consult[i].y,consult[i].d);
        }
        printf("(%d,%d,1)",d1,d2);
    }else{
        printf("no");
    }

    return 0;
}

void FindPath(int a[][100], int x1, int y1, int x2, int y2){
    if(x1 != x2 || y1 != y2){
        for(int i = 1; i <= 4; i++){
            if(end == 1){break;}
            switch (d[i]){
            case 1:
                if(a[x1][y1+1] != 1){
                    a[x1][y1+1] = 1;
                    consult[cnt].x = x1;
                    consult[cnt].y = y1;
                    consult[cnt].d = 1;
                    cnt++;
                    t = cnt;
                    FindPath(a, x1, y1+1, x2, y2);
                    cnt--;
                }
                break;
            case 2:
                if(a[x1+1][y1] != 1){
                    a[x1+1][y1] = 1;
                    consult[cnt].x = x1;
                    consult[cnt].y = y1;
                    consult[cnt].d = 2;
                    cnt++;
                    t = cnt;
                    FindPath(a, x1+1, y1, x2, y2);
                    cnt--;
                }
                break;
            case 3:
                if(a[x1][y1-1] != 1){
                    a[x1][y1-1] = 1;
                    consult[cnt].x = x1;
                    consult[cnt].y = y1;
                    consult[cnt].d = 3;
                    cnt++;
                    t = cnt;
                    FindPath(a, x1, y1-1, x2, y2);
                    cnt--;
                }
                break;
            case 4:
                if(a[x1-1][y1] != 1){
                    a[x1-1][y1] = 1;
                    consult[cnt].x = x1;
                    consult[cnt].y = y1;
                    consult[cnt].d = 4;
                    cnt++;
                    t = cnt;
                    FindPath(a, x1-1, y1, x2, y2);
                    cnt--;
                }
                break;
            default:
                break;
            }
        }
    }else{
        end = 1;
    }
    
    return;
}