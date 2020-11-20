/*************************************************************************
	> File Name: 346.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月14日 星期三 20时44分25秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<memory.h>
#include<map>
#include<vector>
using namespace std;
#define max_n 100 //数组需要开两倍，横纵坐标加和

//把整个数组放斜，一条斜线上点x+y相等
int arr[max_n + 5][max_n + 5];
int val[max_n + 5][max_n + 5][max_n + 5];//一维记录x+y，一维记录x，一维记录y

int main() {
    int n,m;
    cin >> n >> m;
    memset(val,-1,sizeof(val));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    val[2][1][1] = 0; 
    for (int a = 3; a < n + m; a++) { // a是第一维，也就是x+y
        for (int i = 1; i < m; i++) {
            for(int j = i + 1; j <= m; j++) {
                int big = max(val[a - 1][i][j],max(val[a-1][i-1][j],max(val[a-1][i][j-1],val[a-1][i-1][j-1]))); // 过一个点的最大路径一定在四个方向中一个
                if (big == -1) continue;
                val[a][i][j] = big + arr[a-i][i] + arr[a - j][j];
            }
        }
    }
    cout << val[m + n - 1][m - 1][m] << endl;; //最后的值应该在终点左侧(循环中i<j)
    return 0;
}  

