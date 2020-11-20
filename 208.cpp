/*************************************************************************
	> File Name: 208.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年01月16日 星期四 12时21分45秒
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
#define MAX_N 100

int main() {
    int m, n, num[MAX_N + 5] = {0};
    cin >> m;
    for(int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        num[temp]++;
    }
    cin >> n;
    for(int i = 100; i > 0; i--) {
        if(num[i] >= n) {
            cout << num[i] << endl;
            break;
        }
    }
    return 0;
}

