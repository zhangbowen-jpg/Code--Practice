/*************************************************************************
	> File Name: 210.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年01月16日 星期四 10时56分11秒
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
    int n;
    string fa[30];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> fa[i];
    }
    sort(fa, fa + n);
    for(int i = 0; i < n; i++) {
        if(i) {
            cout << " ";
        }
        cout << fa[i];
    }
    return 0;
}

