/*************************************************************************
	> File Name: 42-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 20时55分47秒
 ************************************************************************/

#include<stdio.h>
#define max_n 10000
#define max_N 20
int w[max_N + 5];
int f[max_n + 5];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++) {
        scanf("%d",&w[i]);
    }
    f[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = w[i]; j <= m; j++) {
            f[j] += f[j - w[i]];
            f[j] %= 9973;      
        }
    }
    printf("%d",f[m]);
    return 0;
}

