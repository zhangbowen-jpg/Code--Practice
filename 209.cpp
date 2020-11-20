/*************************************************************************
	> File Name: 209.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年01月15日 星期三 13时36分06秒
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
    int n;
    double num[MAX_N + 5];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    for(int i = 0; i < n; i++) {
        cout << num[i] << endl;
    }
    return 0;
}

