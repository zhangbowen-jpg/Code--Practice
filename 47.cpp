/*************************************************************************
	> File Name: 47.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年04月22日 星期三 20时05分42秒
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

int all, n, w[105], v[105], ans[105][10005];

int main() {
    cin >> all >> n;
    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= all; j++) {
            if(j < w[i]) {
                ans[i][j] = ans[i - 1][j];
            } else {
                ans[i][j] = max(ans[i - 1][j], v[i] + ans[i - 1][j - w[i]]);
            }
        }
    }
    cout << ans[n][all] << endl;
    return 0;
}


