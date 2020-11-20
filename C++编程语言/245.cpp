/*************************************************************************
	> File Name: 245.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月19日 星期三 15时57分06秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<cstdio>
using namespace std;
#define MAX_N 100000
int a[MAX_N + 5];

int main() {
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);  //第二个参数是终止位置的后一位
    int p = a[(n + 1) / 2];
    for(int i = 1; i <= n; i++) {
        ans += abs(a[i] - p);
    }
    cout << ans << endl;
    return 0;
}

