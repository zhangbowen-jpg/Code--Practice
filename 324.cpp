/*************************************************************************
	> File Name: 324.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月23日 星期六 15时48分44秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<math.h>
#include<cstdio>
using namespace std;
#define MAX_N 500000

struct UnionSet {
    int fa[MAX_N + 5], size[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for(int i = 1; i <= n; i++) {
            fa[i] = i;
            size[i] = 1;
            val[i] = 0;
        }
    }
    int get(int x) {
        if(x == fa[x]) return x;    //x为根结点
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        return fa[x] = root;
    }
    void merge(int a, int b) {
        int aa = get(a), bb = get(b);
        if(aa == bb) return ;
        fa[aa] = bb;
        val[aa] = size[bb];
        size[bb] += size[aa];
        return ;
    }
};

UnionSet u;

int main() {
    int n, a, b;
    char op[10];
    scanf("%d", &n);
    u.init(n);
    for(int i = 0; i < n; i++) {
        scanf("%s%d%d", op, &a, &b);
        switch(op[0]) {
            case 'M':u.merge(a, b); break;
            case 'C': {
                if(u.get(a) - u.get(b)) {
                    printf("-1\n");
                } else {
                    printf("%d\n", abs(u.val[a] - u.val[b]) - 1);
                }
            }break;
        }
    }
    return 0;
}

