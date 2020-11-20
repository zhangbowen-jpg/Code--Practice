/*************************************************************************
	> File Name: 449.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月21日 星期三 17时00分08秒
 ************************************************************************/

#include<stdio.h>

int yanghui[25][25] = {0};

int main() {
    int n,flag;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        yanghui[i][1] = 1; 
    }
    for(int i = 1; i <= n; i++) {
        flag = 0;
        for(int j = 1; j <= i; j++) {
            if(flag == 1) printf(" ");
            printf("%d", yanghui[i][j]);
            yanghui[i + 1][j + 1] = yanghui[i][j + 1] + yanghui[i][j];
            flag = 1;
        }
        printf("\n");
    }
}

