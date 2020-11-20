/*************************************************************************
	> File Name: 240.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月11日 星期三 18时01分33秒
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

char ans[2200][2200];
int num[10] = {0, 1, 3, 9, 27, 81, 243, 729, 2187};  //记录数组的边长

void func(int x, int y, int n) {  //进行递归到最后一层输出X
    if(n == 1) {
        ans[x][y] = 'X'; 
        return ; 
    }
	//四个角位置的图案
    func(x, y, n - 1);
    func(x, y + num[n] / 3 * 2, n - 1);  //两个角之间间隔长度为总长度除3乘2
    func(x + num[n] / 3 * 2, y, n - 1);
    func(x + num[n] / 3 * 2, y + num[n] / 3 * 2, n - 1);
    func(x + num[n] / 3, y + num[n] / 3, n - 1);
}

int main() {
    func(1, 1, 7);  //先打印出整个图形 n <= 7;
    int n;
    while(cin >> n) {
        if(n == -1) break;
        for(int i = 1; i <= num[n]; i++) {
            for(int j = 1; j <= num[n]; j++) {
                if(ans[i][j] == 'X') cout << 'X';
                else cout << ' ';
            }
            cout << endl;
        }
        cout << "-" << endl;
    }
    return 0;
}


