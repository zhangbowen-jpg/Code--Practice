/*************************************************************************
	> File Name: 安置路灯.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月10日 星期一 15时55分51秒
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
#define max_n 1000

int main() {
    int t;
    int n;
    char a[max_n + 5];
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d", &n);
        scanf("%s", a);
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(a[j] == 'X') continue;
            else {
                j += 2;
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}

