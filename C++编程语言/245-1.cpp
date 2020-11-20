/*************************************************************************
	> File Name: 245-1.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月19日 星期三 16时06分08秒
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
int a[MAX_N + 5], ind[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    nth_element(a + 1, a + (n + 1) / 2, a + 1 + n); //只保证第二个参数位置的值是正确的，等与查找第k位的值,他的底层是快速选择算法
    int p = a[(n + 1) / 2], ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += abs(a[i] - p);
    }
    cout << ans << endl;
    return 0;
}

