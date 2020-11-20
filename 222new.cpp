/*************************************************************************
	> File Name: 222new.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月08日 星期一 20时03分00秒
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
int arr[MAX_N + 5];

int tree[(MAX_N << 2) + 5];

void Up(int ind) {
    tree[ind] = max(tree[ind << 1], tree[ind << 1 | 1]);
}

void build(int *arr, int ind, int l, int r) {
    if (l == r) {
        tree[ind] = arr[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(arr, ind * 2, l, mid);
    build(arr, ind * 2 + 1, mid + 1, r);
    Up(ind);
    return ;
}

void modify(int ind, int i, int x, int l, int r) {
    if (l == r) {
        tree[ind] = x;
        return ;
    }
    int mid = (l + r) >> 1;
    if (i <= mid) modify(ind << 1, i, x, l, mid);
    else modify(ind << 1 | 1, i, x, mid + 1, r);
    Up(ind);
    return ;
}

int query(int ind, int x, int y, int l, int r) {
    if (x <= l && r <= y) {
        return tree[ind];
    }
    int mid = (l + r) >> 1;
    int ans = 0x80000000;
    if (x <= mid) {
        ans = max(ans, query(ind << 1, x, y, l, mid));
    }
    if (y > mid) {
        ans = max(ans, query(ind << 1 | 1, x, y, mid + 1, r));
    }
    return ans;
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(arr, 1, 1, n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        switch (a) {
            case 1: modify(1, b, c, 1, n); break;
            case 2: cout << query(1, b, c, 1, n) << endl; break;
        }
    }
    return 0;
}

