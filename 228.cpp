/*************************************************************************
	> File Name: 228.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年09月29日 星期日 19时30分37秒
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

int f[1<<20][20];  //f[n][m] n用20位2进制数表示点的经过与否，m表示当前点最短路径长度

int Hamilton(int n, int w[20][20]) {
    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;//初始位置
    for(int i = 1; i < 1 << n; i++) {  //依次遍历每个位置，直到全部走过
        for(int j = 0; j < n; j++) {
            if(i >> j & 1) {  //如果j位是1，即刚走过的位置
                for(int k = 0; k < n; k++) { //k用来判断与没走过该点时且其他某个位置k为1时的长度加从k走到j的最小路径，与原f[i][j]比较，取两者最小值
                    if((i^1<<j) >> k & 1) {
                        f[i][j] = min(f[i][j], f[i^1<<j][k] + w[k][j]); 
                    }
                    
                }
            }
        }
    }
    return f[(1 << n) - 1][n - 1];  //返回最后一个点的路径长
}

int main() {
    int n;
    cin >> n;
    int weight[20][20];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> weight[i][j];
        }
    }
    cout << Hamilton(n, weight) << endl;
    return 0;
}

