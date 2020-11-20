/*************************************************************************
	> File Name: 401.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年04月08日 星期三 18时31分53秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cstdio>
using namespace std;

struct node {
    int x, y, step;
};

int dir[12][2] = {
    1, 2, 1, -2, -1, 2, -1, -2, 
    2, 1, 2, -1, -2, 1, -2, -1,
    2, 2, 2, -2, -2, 2, -2, -2
};

int n, ans[505][505], check[505][505];

int main() {
    queue<node> que;
    que.push({1, 1, 0});
    check[1][1] = 1;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 12; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 1 || y < 1 || x > 500 || y > 500) continue;
            if (check[x][y] == 0) {
                check[x][y] = 1;
                ans[x][y] = temp.step + 1;
                que.push({x, y, ans[x][y]});
            }
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        cout << ans[x][y] << endl;
    }
    return 0;

}



