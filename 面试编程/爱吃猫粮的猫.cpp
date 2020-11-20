/*************************************************************************
	> File Name: 爱吃猫粮的猫.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月17日 星期一 19时45分28秒
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
#define MAX_N 1000000

int arr[MAX_N + 5];
int n = 0, h;

int binary_search(int l, int r) {
    int p, q, s = 0;
    if(l == r) return l;
    int mid = (l + r) >> 1;
    for(int i = 0; i < n; i++) { 
        s += (arr[i] / mid) + (arr[i] % mid != 0);
    }
    q = (s <= h) ? 1 : 0;
    if(q) return binary_search(l, mid);
    return binary_search(mid + 1, r);
}

int main() {
    int Max = 0, ans;
    while(cin >> arr[n]) {
        n++;
    }
    h = arr[--n];
    for(int i = 0; i < n; i++) {
        Max = max(Max, arr[i]);
    }
    ans = binary_search(1, Max); //最大值是最多猫粮一组的猫粮数，最小是堆数
    cout << ans << endl;
    return 0;
}

