/*************************************************************************
	> File Name: 326.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月23日 星期六 20时58分34秒
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
#define MAX_N 50000

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for(int i = 0; i < n; i++) {
            fa[i] = i;
            val[i] = 0;
        }
    }
    int get(int x) {
        if(fa[x] == x) return x;
        int temp = fa[x];
        fa[x] = get(fa[x]);
        val[x] = (val[x] + val[temp]) % 3;
        return fa[x];
    }
    void merge(int a, int b, int c) {
        int aa = get(a);
        int bb = get(b);
        fa[bb] = aa;
        val[bb] = (val[a] + 3 - val[b] + (c - 1)) % 3;
    }
};

UnionSet u;

int main() {
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    u.init(n);
    while(m--) {
        int d, x, y;
        scanf("%d%d%d", &d, &x, &y);
        if(x > n || y > n || (x == y && d == 2)) //无条件假话
            ans++;
        else if(u.get(x) == u.get(y)) {
            if(d == 1 && u.val[x] != u.val[y]) ans++; //冲突假话
            if(d == 2 && (u.val[x] + 1) % 3 != u.val[y]) ans++;  //捕食假话
        } else u.merge(x, y, d); 
    }
    printf("%d\n", ans); //所以这人有bing吧
    return 0;
}

