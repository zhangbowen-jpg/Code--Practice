/*************************************************************************
	> File Name: 591.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年05月06日 星期三 20时34分30秒
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

int main() {
    int n, m;
    cin >> n >> m;
    if(n % 2 == 0) {
        int mid = n / 2;
        if(m <= mid) {
            cout << m + 1 << endl;
        } else {
            cout << m - 1 << endl;
        }
    } else {
        int mid = (n + 1) / 2;
        if(m < mid) cout << m + 1 << endl;
        else cout << m - 1 << endl;
    }
    return 0;
}


