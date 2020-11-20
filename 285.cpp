/*************************************************************************
	> File Name: 285.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月06日 星期三 13时57分58秒
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
#define MAX_M 2000
#define MAX_N 100
using namespace std;
int a[MAX_M + 5], b[MAX_M + 5];
int ans[MAX_M + 5] = {0};

struct Data {
    Data(int val, int i) : val(val), i(i){}
    int val, i;
    bool operator<(const Data &a) const {
        if(val - a.val) return val < a.val;
        return i < a.i;
    }
};

multiset<Data> s;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
    }        
    sort(a + 1, a + m + 1);     
    n--;
    while(n--) {
        for(int i = 1; i <= m; i++) {
            scanf("%d", &b[i]);
        }
            for(int i = 1; i <= m; i++) {
                s.insert(Data(a[1] + b[i], 1));
            }
            int cnt = 1;
            while(cnt <= m) {
                int p = s.begin()->val;
                int q = s.begin()->i;
                s.erase(s.begin());
                ans[cnt++] = p;
                s.insert(Data(p - a[q] + a[q + 1], q + 1));
            }
            for(int j = 1; j <= m; j++) a[j] = ans[j];
            s.clear();
    }
    int flag = 1;
    for(int i = 1; i <= m; i++) {
        if(flag) {
            printf("%d", ans[i]);
            flag = 0;
            continue;
        }
        printf(" %d", ans[i]);
    }
    return 0;
}


