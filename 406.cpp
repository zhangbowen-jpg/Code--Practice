/*************************************************************************
	> File Name: 406.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月18日 星期三 19时06分48秒
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

int n, m, ans = 0;
char mmap[2005][2005];
int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1}; 

void func(int x, int y) {
    for(int i = 0; i < 8; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if(mmap[tx][ty] == '#') {
            mmap[tx][ty] = 0;
            func(tx, ty);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(mmap[i][j] == '#'){
                ans++;
                mmap[i][j] = 0;
                func(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

