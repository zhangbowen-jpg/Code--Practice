/*************************************************************************
	> File Name: 150.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月29日 星期一 18时03分25秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n,m,flag;
    scanf("%d%d", &n, &m);
    int arr[n][m];
    for(int i = 0; i <= n-1; i++) {
        for(int j = 0; j <= m-1; j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i = m-1; i >= 0; i--) {
        flag = 0;
        for(int j = 0; j <= n-1; j++) {
            if(flag == 1){
                printf(" ");
            }
            printf("%d",arr[n-1-j][m-1-i]);
            flag = 1;
        }
        printf("\n");
    }
    return 0;
}

