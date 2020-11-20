/*************************************************************************
	> File Name: 284.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月02日 星期六 15时20分25秒
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
#define MAX_N 10000

struct Data { 
    int d, p, id;   //d 过期日期 p 利润
    bool operator<(const Data &a) const {
        if(p - a.p) return p < a.p;
        if(d - a.d) return d < a.d;
        return id < a.id;
    }
} arr[MAX_N + 5];

set<Data> s;

bool cmp(const Data &a, const Data &b) {
    if(a.d - b.d) return a.d < b.d;
    if(a.p - b.p) return a.p < b.p;
    return a.id < b.id;
}

int main() {
    int n,ans = 0; 
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i].p >> arr[i].d, arr[i].id = i;
    sort(arr, arr + n, cmp);
    for(int i = 0; i < n; i++) {
        if(arr[i].d > s.size()) {
            s.insert(arr[i]);
        } else if (s.begin()->p < arr[i].p) {
            s.erase(s.begin());
            s.insert(arr[i]);
        }
    }
    for(auto iter = s.begin(); iter != s.end(); iter++) {
        ans += iter->p;
    }
    cout << ans << endl;
    return 0;
}

