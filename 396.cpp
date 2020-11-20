/*************************************************************************
	> File Name: 396.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月11日 星期三 18时43分56秒
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
#define MAX_N 30

int n, arr[MAX_N + 5][MAX_N + 5];

void dfs(int x, int y) { //将所有外部0修改
    if(x < 1 || x > n || y < 1 || y > n || arr[x][y] != 0) return ;  //碰到边缘 或者 不是0 回溯， 
    arr[x][y] = -1;  //标记为外部的位置
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= n; i++) { //这是从边框判断是否是1，是1则内部不受影响
        if(arr[i][1] != 1) dfs(i, 1);
        if(arr[i][n] != 1) dfs(i, n);
    }
    for(int i = 1; i <= n; i++) {
        if(arr[1][i] != 1) dfs(1, i);
        if(arr[n][i] != 1) dfs(n, i);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(j == n) {
                if(arr[i][j] == -1) {
                    cout << '0';
                } else if(arr[i][j] == 1) {
                    cout << '1';
                } else {
                    cout << '2';
                }
            }
            else {
                if(arr[i][j] == -1) {
                    cout << '0' << ' ';
                } else if(arr[i][j] == 1) {
                    cout << '1' << ' ';
                } else {
                    cout << '2' << ' ';
                }
            }
        }
        cout << endl;
    }
    return 0;
}

