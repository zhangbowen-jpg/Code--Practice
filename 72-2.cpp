/*************************************************************************
	> File Name: 72-2.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月23日 星期六 18时29分55秒
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
#define MAX_N 10000

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for(int i = 1; i <= n; i++) {
            fa[i] = i;
            val[i] = 0;
        }
    }
    int get(int x) {
        if(x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 3;
        return fa[x] = root;
    } 
    void merge(int a, int b, ) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return ;
        fa[aa] = bb;
        val[aa] = (val[b] + 2 - val[a] + 3) % 3;
        return ;
    }
};

UnionSet u;

int main() {
    int n, m;
    cin >> n >> m;
    u.init(n);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        switch(a) {
            case 1 : u.merge(b, c); break;
            case 2 : {
                if(u.get(b) - u.get(c)) {
                    printf("Unknown\n");
                } else {
                   switch((u.val[b] - u.val[c] + 3) % 3) {
                        case 0 : printf("Tie\n"); break;
                        case 1 : printf("Loss\n"); break;
                        case 2 : printf("Win\n"); break;
                   }
                }
            }break;
        }
    }

    return 0;
}
