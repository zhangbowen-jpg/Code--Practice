/*************************************************************************
	> File Name: 535-1.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月25日 星期三 20时58分47秒
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
    int x, y;
};

int n, m, ans = 1;
char mmap[55][55];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
queue<node> que;

int main() {
    cin >> m >> n; 
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if(mmap[i][j] == '@') {
                que.push({i, j});
            }
        }
    }
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        for(int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if(mmap[x][y] == '.') {
                mmap[x][y] = 0;
                ans++;
                que.push({x, y});
            }
        }
    }
    cout << ans << endl;
    return 0;
}


