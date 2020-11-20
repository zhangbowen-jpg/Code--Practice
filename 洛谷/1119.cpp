/*************************************************************************
	> File Name: 1119.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年06月10日 星期三 19时56分51秒
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

int n, m, q, ans[205][205], day[205], now;

int main() {
    memset(ans, 0x3F, sizeof(ans));
    cin >> n >> m; 
    for(int i = 1; i <= n; i++) {
        cin >> day[i];
        ans[i][i] = 0;
    }
    for(int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a++;
        b++;
        ans[a][b] = ans[b][a] = c;
    }
    cin >> q;
    for(int i = 1; i <= q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a++;
        b++;
        while(day[now] <= c && now <= n) {
            for(int j = 1; j <= n; j++) {
                for(int k = 1; k <= n; k++) {
                    ans[j][k] = min(ans[j][k], ans[j][now] + ans[now][k]);
                }
            }
            now++;
        }
        if(day[a] > c || day[b] > c || ans[a][b] == 0x3F3F3F3F) {
            cout << -1 << endl;
        } else {
            cout << ans[a][b] << endl;
        }
    }
    return 0;
}


