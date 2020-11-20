/*************************************************************************
	> File Name: 535.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月11日 星期三 17时57分44秒
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

int n, m, sx, sy, ans = 1;
char mmap[55][55];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

void func(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if(mmap[tx][ty] == '.') {
            mmap[tx][ty] = 0;
            ans++;
            func(tx, ty);
        }
    }
}

int main() {
    cin >> m >> n;

    
    for(int i = 1; i <= n; i++) {
        cin >> (&mmap[i][1]); //取每行第一个位置输入
    }
    /*
    for(int i = 1; i <= n; i++) { //从一开始省去判断边界
        for(int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if(mmap[i][j] == '@') {
                sx = i;
                sy = j;
            }
        }
    }
    */
    func(sx, sy);
    cout << ans << endl;


    return 0;
}

