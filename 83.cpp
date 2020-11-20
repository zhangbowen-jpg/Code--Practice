/*************************************************************************
	> File Name: 83.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年01月15日 星期三 11时23分11秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int dp[101][9];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i >= j) {
                dp[i][j] = dp[i - j][j] + dp[i - 1][j - 1];
            }
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}

