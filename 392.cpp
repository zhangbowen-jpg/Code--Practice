/*************************************************************************
	> File Name: 392.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年04月22日 星期三 19时06分30秒
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

int n, m , num[100005], mmax;

int check(int mid) {  //求出满足的瓶盖数
    int cnt = 1, now = 0;
    for(int i = 1; i < n; i++) {
        if(num[i] - num[now] >= mid) {
            cnt++;
            now = i;
        }
    }
    return cnt;
}

int func() {
    int l = 1, r = mmax;
    while(l != r) {   
        int mid = (l + r + 1) / 2;
        int cnt = check(mid);
        if(cnt >= m) { //比较瓶盖数量
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
    }
    sort(num, num + n);
    mmax = num[n - 1] - num[0]; //得到最大值
    cout << func() << endl;
    return 0;
}

