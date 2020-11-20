/*************************************************************************
	> File Name: 389.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年04月08日 星期三 20时56分07秒
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
#define max_n 100000

int n, m, num[max_n + 5], mmax;

int func2(int len) {
    int cnt = 1, now = 0;
    for(int i = 1; i < n; i++) {
        if(num[i] - num[now] >= len) {
            cnt++;
            now = i;
        }
    }
    return cnt;
}

int func() {
    int l = 0, r = mmax;
    while(l != r) {
        int mid = (l + r + 1) / 2;
        int cnt = func2(mid);
        if(cnt >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        mmax = max(mmax, num[i]);
    }
    sort(num, num + n);
    cout << func() << endl;

    return 0;
}


