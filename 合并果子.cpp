/*************************************************************************
	> File Name: 合并果子.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月06日 星期三 17时18分01秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<set>
using namespace std;

struct Data {
    long long p;
    Data(long long x) {
        p = x;
    }
    bool operator<(const Data &a) const {
        return p < a.p;
    }
};

multiset<Data> s;

int main() {
    long long n, ans = 0, k;
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &k);
        s.insert(Data(k));
    }
    while(s.size() > 1) {
        long long a = s.begin()->p;
        s.erase(s.begin());
        long long b = s.begin()->p;
        s.erase(s.begin());
        s.insert(Data(a + b));
        ans += (a + b);
    }
    printf("%lld", ans);
    return 0;
}


