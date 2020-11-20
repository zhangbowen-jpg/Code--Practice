/*************************************************************************
	> File Name: 323-1.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月24日 星期日 16时15分51秒
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

struct Data {
    int p, d;
}arr[MAX_N + 5];

void solve(int n) {
    for(int i = 0; i < n; i++) {
        cin >> arr[i].p >> arr[i].d;
    }
    sort(arr,arr + n, [](const Data &a, const Data &b) {
        return a.p > b.p; 
    });
    u.init(MAX_N);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int d = u.get(arr[i].d);
        if(d == 0) continue;
        ans += arr[i].p;
        u.merge(d, d - 1);
    }
    cout << ans << endl;
}

int main() {
    int n;
    while(cin >> n) {
        solve(n);
    }
    return 0;
}

