/*************************************************************************
	> File Name: 48.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年04月22日 星期三 20时43分17秒
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

int all, n, w[10005], v[10005], ans[10005];

int main() {
    cin >> n >> all;
    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= all; j++) {
            if(j >= w[i]) { 
                ans[j] = max(ans[j], v[i] + ans[j - w[i]]);
            }
        }
    }
    cout << ans[all] << endl;
    return 0;
}

