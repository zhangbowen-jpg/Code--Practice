/*************************************************************************
	> File Name: 程序自动分析.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月08日 星期一 08时36分14秒
 ************************************************************************/

//322题
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
#define MAX_N 2000000

struct UnionSet {
    int fa[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return (fa[x] = (x == fa[x] ? x : get(fa[x])));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
};
map<int, int> ind;
int cnt = 0;

UnionSet u;

struct Data {
    int a, b, c;
} arr[MAX_N + 5];

void solve() {
    int n;
    cin >> n;
    u.init(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
        if (ind[arr[i].a] == 0) ind[arr[i].a] = ++cnt;
        if (ind[arr[i].b] == 0) ind[arr[i].b] = ++cnt;
        arr[i].a = ind[arr[i].a];
        arr[i].b = ind[arr[i].b];
    }
    u.init(cnt);
    for (int i = 0; i < n; i++) {
        if (arr[i].c == 0) continue;
        u.merge(arr[i].a, arr[i].b);
    }        
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].c == 1) continue; 
        flag = flag || (u.get(arr[i].a) == u.get(arr[i].b));
    } 
    cout << (flag ? "NO" : "YES") << endl;
    return ;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
