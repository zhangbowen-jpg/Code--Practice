/*************************************************************************
	> File Name: 344.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月26日 星期三 16时48分48秒
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
#define MAX_N 2000
#define INF 0x3f3f3f3f
int a[MAX_N + 5];
int c[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];
//数先必须确定，要构造的序列中的元素一定在原有的序列中，否则绝对值一定会偏大，首先将a序列排序，在从排序后的序列中找,dp[i][j]指已经到了a的第i位，和c中的j位，然后比较c的j-1位和当前的c的位置那个比较合适。

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], c[i] = a[i];
    sort(c + 1, c + 1 + n);
    for (int i = 1; i <= n; i++) {
        dp[i][0] = INF;
        for (int j = 1; j <= n; j++) {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j] + abs(c[j] - a[i]));
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}

