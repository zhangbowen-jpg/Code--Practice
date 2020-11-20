/*************************************************************************
	> File Name: 270.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月15日 星期二 19时12分39秒
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
#define MAX_N 300000
int s[MAX_N + 5]; //全局变量默认初始化为0
int q[MAX_N + 5], head, tail;

int main() {
    int n, m, ans;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> s[i], s[i] += s[i - 1];
    }
    head = tail = 0;
    q[tail++] = 0;
    ans = s[1]; //必须要有值，不能为0，有可能为负数
    for(int i = 1; i <= n; i++) {
        if(i - q[head] > m) head++; // 过期更新
        ans = max(ans, s[i] - s[q[head]]);
        while(tail - head && s[i] < s[q[head - 1]]) tail--;
        q[tail++] = i;
    }
    cout << ans << endl;
    return 0;
}



