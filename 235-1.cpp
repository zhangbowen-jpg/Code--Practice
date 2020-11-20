/*************************************************************************
	> File Name: 235-1.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月11日 星期三 19时06分33秒
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

int n, num[15], cnt;

void p() {
    for(int i = 0; i < cnt; i++) {
        if(i) cout << " ";
        cout << num[i];
    }
    cout << endl;
}

void func(int s) {
    for(int i = s; i <= n; i++) {
        num[cnt++] = i;
        p();
        func(i + 1);
        cnt--;
    }
}

int main() {
    cin >> n;
    func(n);
    return 0;
}

