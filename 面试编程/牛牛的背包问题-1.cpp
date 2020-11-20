/*************************************************************************
	> File Name: 牛牛的背包问题-1.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月10日 星期一 20时42分40秒
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
//二进制枚举法

long long v1[35], v2[35];
int cntv1 = 0, cntv2 = 0;
long long s1[65536], s2[65536];
int cnts1 = 0, cnts2 = 0;

int main() {
    long long n, w;
    cin >> n >> w; 
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            cin >> v1[cntv1++];
        } else {
            cin >> v2[cntv2++];
        }
    }
    for (int t = 0, I = (1 << cntv1); t < I; t++) { //转2进制左移n位
        for (int i = 0; i < cntv1; i++) {
            if ((1 << i) & t) s1[cnts1] += v1[i];
        }
        cnts1++;
    }
    for (int t = 0, I = (1 << cntv2); t < I; t++) {
        for (int i = 0; i < cntv2; i++) {
            if ((1 << i) & t) s2[cnts2] += v2[i];
        }
        cnts2++;
    }
    sort(s1, s1 + cnts1);
    sort(s2, s2 + cnts2);
    long long p1 = 0, p2 = cnts2 - 1, ans = 0;
    while (p1 < cnts1) {
        while (p2 >= 0 && s2[p2] + s1[p1] > w) --p2;
        ans += p2 + 1;
        p1++;
    }
    cout << ans << endl;
    return 0;
}

