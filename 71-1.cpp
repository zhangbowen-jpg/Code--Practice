/*************************************************************************
	> File Name: 71-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月16日 星期五 18时05分07秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
#define MAX_N 10000

struct Friendship {
    int fa[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return (fa[x] = (x == fa[x] ? x : get(fa[x])));//get(fa[x])指的是获取父结点的根结点编号
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }//增加朋友关系，相当于合并路径
};

Friendship f;

int main() {
    int n, m;
    cin >> n >> m;
    f.init(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        switch (a) {
            case 1: {
                f.merge(b, c);
            } break;
            case 2: {
                cout << (f.get(b) == f.get(c) ? "Yes" : "No") << endl;//判断b，c是否拥有相同根结点，以判断是否是朋友关系。 
            } break;
        }
    }
    return 0;
}

