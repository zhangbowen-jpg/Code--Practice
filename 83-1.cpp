/*************************************************************************
	> File Name: 83-1.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月11日 星期三 20时14分25秒
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

int num[10], cnt;

void p() {
    for(int i = 0; i < cnt; i++) {
        if(i) cout << "+";
        cout << i;
    }
    cout << endl; 
}

int func(int s, int left_num, int left_cnt) {
    if(left_cnt == 0) {
        if(left_num == 0) {
            p();
            return 1;
        }
        return 0;
    }
    int ans = 0;
    for(int i = s; i <= left_num; i++) {
        num[cnt] = i;
        cnt++;
        ans += func(i, left_num - i, left_cnt - 1);
        cnt--;
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << func(1, n, m) << endl;
    return 0;
}


