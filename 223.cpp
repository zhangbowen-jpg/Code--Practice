/*************************************************************************
	> File Name: 223.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月08日 星期一 20时19分50秒
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
long long arr[MAX_N + 5];

struct Node {
    long long sum, tag, cnt;
} tree[(MAX_N << 2) + 5];

void addTag(int ind, long long val) {
    tree[ind].tag += val;
    tree[ind].sum += tree[ind].cnt * val;
    return ;
}

void Up(int ind) {
    tree[ind].sum = tree[ind << 1].sum + tree[ind << 1 | 1].sum;
    return ;
}

void Down(int ind) {
    if (tree[ind].tag == 0) return ;
    if (tree[ind].cnt == 1) return ;
    addTag(ind << 1, tree[ind].tag);
    addTag(ind << 1 | 1, tree[ind].tag);
    tree[ind].tag = 0;
    return ;
}

void build(long long *arr, int ind, int l, int r) {
    tree[ind].tag = 0;
    tree[ind].cnt = r - l + 1;
    if (l == r) {
        tree[ind].sum = arr[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(arr, ind << 1, l, mid);
    build(arr, ind << 1 | 1, mid + 1, r);
    Up(ind);
    return ;
}

void modify(int ind, int x, int y, long long val, int l, int r) {
    if (x <= l && r <= y) {
        addTag(ind, val);
    }
    return ;
}

long long query(int ind, int x, int y, int l, int r) {
    if (x <= l && r <= y) {
        return tree[ind].sum;
    }
    Down(ind);
    int mid = (l + r) >> 1;
    long long ans = 0;
    if (x <= mid) {
        ans += query(ind << 1, x, y, l, mid);
    }
    if (y > mid) {
        ans += query(ind << 1 | 1, x, y, mid + 1, r);
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(arr, 1, 1, n);
    for (int i = 0; i < m; i++) {
        long long a, b, c, d;
        cin >> a >> b >> c;
        switch (a) {
            case 1:
                cin >> d;
                modify(1, b, c, d, 1, n);
                break;
            case 2: cout << query(1, b, c, 1, n) << endl; break;
        }
    }
    return 0;
}

