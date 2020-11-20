/*************************************************************************
	> File Name: 211.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年01月16日 星期四 11时01分14秒
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
    cin >> n;
    string name[35];
    for(int i = 0; i < n; i++) {
        cin >> name[i];
        reverse(name[i].begin(), name[i].end());
    }
    sort(name, name + n);
    for(int i = 0; i < n; i++) {
        cout << name[i] << endl;
    }
    return 0;
}


