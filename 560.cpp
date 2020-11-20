/*************************************************************************
	> File Name: 560.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年04月29日 星期三 19时23分04秒
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
#define max_n 25
#define max_m 30000

int t, m, mtime[max_n + 5], mval[max_n + 5], ans[max_m + 5];

int main() {
    cin >> t >> m;
    for(int i = 1; i <= m; i++) {
        cin >> mtime[i] >> mval[i];
    }
    for(int i = 1; i <= m; i++) {
        for(int j = t; j > 0; j--) {
            if(j < mtime[i]) {
                break;
            } else {
                ans[j] = max(ans[j], ans[j - mtime[i]] + mtime[i] * mval[i]);
            }
        }
    }
    cout << ans[t] << endl;
    return 0;
}
