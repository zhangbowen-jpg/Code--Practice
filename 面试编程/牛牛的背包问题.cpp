/*************************************************************************
	> File Name: 牛牛的背包问题.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月10日 星期一 20时20分08秒
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

long long v[40];
int n;

long long ans = 0, w;

void dfs(int t, long long sum) {
    ans++;
    if(t == n - 1) {
        return ;
    }
    for(int i = t + 1; i < n; i++) {
        if(sum + v[i] <= w) {
            dfs(i, sum + v[i]);
        }
    }
}

int main() {
    cin >> n >> w;
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    if(sum <= w) {
        ans = 1 << n;
    }
    else {
        dfs(-1, 0);
    }
    cout << ans << endl;
    return 0;
}

