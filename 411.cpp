/*************************************************************************
	> File Name: 411.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月18日 星期五 19时45分13秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>
#include<cstdio>
using namespace std;
#define MAX_N 2000

int cmn[MAX_N + 5][MAX_N + 5] = {0};
int num[MAX_N + 5][MAX_N + 5] = {0};

int main() {
    int t, k, n, m;
    cin >> t >> k;
    for(int i = 0; i <= MAX_N; i++) num[i][0] = 1;
    for(int i = 1; i <= MAX_N; i++) {
        for(int j = 1; j <= i; j++) {
            cmn[i][j] = (cmn[i - 1][j - 1] + cmn[i - 1][j]) % k; //打表，并使用递归思想，对下一位置的组合组数取模。
        }
    }
    for(int i = 1; i <= MAX_N; i++) {
        for(int j = 1; j <= i; j++) {
            num[i][j] = num[i - 1][j] + num[i][j - 1] - ans[i - 1][j - 1]; // 求前缀和，减去重复值。
            if(cmn[i][j] == 0) num[i][j]++;
        }
        num[i][i + 1] = num[i][i];
    }
    for(int i = 1; i <= t; i++){
        scanf("%d%d",&n, &m);
        if(n < m) m = n;
        printf("%d\n", num[n][m]);
    }
    return 0;
}

