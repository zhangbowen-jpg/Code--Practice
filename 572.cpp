/*************************************************************************
	> File Name: 490.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月02日 星期六 14时08分57秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cstdio>
using namespace std;
#define MAX_N 400000

long long a[MAX_N + 5], b[MAX_N + 5];

struct Data {
    Data(long long val, long long i, long long j) : val(val), i(i), j(j) {}
    long long val, i, j;
    bool operator<(const Data &a) const {
        if(val - a.val) return val < a.val;
        if(i - a.i) return i < a.i;  //防止不同的点相同的值被去重
        return j < a.j;
    }
};

set<Data> s;

int  main() {
    int  n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%lld", a + i);
    for(int i = 0; i < n; i++) scanf("%lld", b + i);
    s.insert(Data(a[0] + b[0], 0, 0));
    for(int i = 0; i < n; i++) {
        long long val = s.begin()->val;
        long long x = s.begin()->i;
        long long y = s.begin()->j;
        s.erase(s.begin()); // 去重
        printf("%lld\n", val);
        if (x + 1 < n) s.insert(Data(a[x + 1] + b[y], x + 1, y));
        if (y + 1 < n) s.insert(Data(a[x] + b[y + 1], x, y + 1));
    }
    return 0;
}


