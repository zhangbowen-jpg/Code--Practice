/*************************************************************************
	> File Name: 264.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月15日 星期二 20时03分42秒
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
#define MAX_N 100000
int h[MAX_N + 5]; //木板
long long l[MAX_N + 5], r[MAX_N + 5];//左面单调栈，右面单调栈
int a[MAX_N + 5], top = -1;

int main() {
    int n;
    cin >> n;
    s[0] = s[n + 1] = -1; // 边界条件
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    s[++top] = 0;
    for(int i = 1; i <= n; i++) {
        while(h[i] <= h[s[top]]) --top;
        l[i] = s[top];
        s[++top] = i;
    }
    top = -1;
    s[++top] = n + 1;
    for(int i = n ; i >= 1; --i) {
        while(h[i] <= h[s[top]]) --top;
        r[i] = s[top];
        s[++top] = i;
    }
    long long ans = 0;
    for(int i = 1; i <= n ;i++) {
        ans = max(ans, h[i] * (r[i] - l[i] - 1)); //找所有木板的最大面积
    }
    cout << ans << endl;
    return 0;
}

