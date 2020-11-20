/*************************************************************************
	> File Name: 73.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月23日 星期六 18时14分18秒
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
#define MAX_N 1000000

struct UnionSet {
    int fa[MAX_N + 5];
    void init(int n) {
        for(int i = 0; i <= n; i++) {
            fa[i] = i;
        }
    }
    int get(int x) {
        return (fa[x] = (x == fa[x] ? x : get(fa[x])));
    } 
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
};

UnionSet u;

char g[1005][1005];
int n, m;

//需要变成全局变量，否则爆栈

int ind(int i, int j) {
    return i * m + j + 1;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> g[i];
    u.init(n * m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
                if(g[i][j] - 'O') continue;
                if(j - 1 >= 0 && g[i][j - 1] == 'O') u.merge(ind(i,j), ind(i, j - 1));
                if(i - 1 >= 0 && g[i - 1][j] == 'O') u.merge(ind(i,j), ind(i - 1, j));
                if(i == 0 || i == n - 1) u.merge(ind(i, j), 0);
                if(j == 0 || j == m - 1) u.merge(ind(i, j), 0);
        }
        }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == 'X') continue;
            if (u.get(ind(i, j)) - u.get(0)) ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}

