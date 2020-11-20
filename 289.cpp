/*************************************************************************
	> File Name: 289.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月02日 星期六 15时34分26秒
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
#include<cmath>
using namespace std;
#define MAX_N 100000
long long arr[MAX_N + 5];

struct Node {
    long long val, id, f; // f记录字段有效值。
    long long pre, next; //元素下标
    bool operator<(const Node &a) const {
        if(abs(val) - abs(a.val)) return abs(val) < abs(a.val);
        return id < a.id;
    }
} list[MAX_N + 5];   //0号节点不用

void del(long long k) {
    if(list[k].f == 0) return ;
    if(list[k].pre) list[list[k].pre].next = list[k].next;
    if(list[k].next) list[list[k].next].pre = list[k].pre;
    list[k].f = 0;
    return ;
}  

int main() {
    long long n, m, cnt = 0, sum = 0; // sum记录正端和值
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0, k = 1; i < n; k++) {
        long long val = arr[i];
        list[k].val = 0;
        list[k].id = k;
        list[k].f = 1;
        while(i < n && arr[i] * val >= 0) {
            list[k].val += arr[i++];
        }
        if(k - 1) list[k - 1].next = k;
        list[k].pre = k - 1;
        list[k].next = 0;
        if(list[k].val > 0) cnt += 1, sum += list[k].val;
        s.insert(list[k]);
    }
    while(cnt > m) {
        long long k = s.begin()->id;
        s.erase(s.begin());
        if(listt[k].f == 0) continue;

        if(list[k].pre && list[k].next) {//节点不在边上
            sum -= abs(list[k].val);
            cnt -= 1
            list[k].val += list[list[k].pre].val;
            list[k].val += list[list[k].next].val;
            del(list[k].pre);
            del(list[k].next);
            s.insert(list[k]);
        } else {
            if(list[k].val > 0) sum -= list[k].val,cnt -= 1;
            del(k);
        }
    }
    cout << sum << endl;
    return 0;
} 

