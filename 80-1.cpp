/*************************************************************************
	> File Name: 80-1.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月11日 星期三 20时30分37秒
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
#define MAX_N 500

char arr[MAX_N + 5][MAX_N + 5]; 
int n, m, sx, sy;
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

int func(int x, int y) {  
    for(int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if(arr[x][y] == 'g') return 1;
        if(arr[tx][ty] == '.') {
            arr[tx][ty] = 0;
            if(func(tx, ty)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 's') {
                sx = i;
                sy = j;
            }
        }
    }
    if(func(sx, sy)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}


