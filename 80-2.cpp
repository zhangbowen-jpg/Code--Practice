/*************************************************************************
	> File Name: 80-2.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月25日 星期三 20时36分48秒
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
//广搜

struct node {
    int x, y, step;
}; //记录了步数

int n, m;
char mmap[505][505];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
queue<node> que;

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if(mmap[i][j] == 's') {
                que.push({i, j, 0});
                /* 等价
                 * node temp;
                 * temp.x = i;
                 * temp.y = j;
                 * temp.step = 0;
                 * que.push(temp);
                 * */
            }
        }
    }
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        for(int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if(mmap[x][y] == 'g') {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if(mmap[x][y] == '.') {
                mmap[x][y] = 0;
                que.push({x, y, temp.step + 1});
            }
        }
    }
    cout << "No" << endl;
    return 0;
}


