/*************************************************************************
	> File Name: 387.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年04月08日 星期三 20时05分45秒
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
#define max_n 100000

struct node {
    int num, val;
};

node wm[max_n + 5];

bool cmp(node a, node b) {
    return a.val < b.val;
}

int main() {
    int m, n;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> wm[i].val;
        wm[i].num = i + 1;
    }
    sort(wm, wm + n, cmp);
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if(t > wm[n - 1].val) {
            cout << 0 << endl;
            continue;
        }
        int l = 0, r = n - 1;
        while(l != r) {
            int mid = (l + r) / 2;
            if(wm[mid].val >= t) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << wm[l].num << endl;
    }
    return 0;
}


