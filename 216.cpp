/*************************************************************************
	> File Name: 216.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年01月16日 星期四 12时45分48秒
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
    string name[105];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> name[i];
        name[i] = name[i].substr(3);
    }
    sort(name, name + n);
    for(int i = 0; i < n; i++) {
        cout << name[i] << endl;
    }
    return 0;
} 

