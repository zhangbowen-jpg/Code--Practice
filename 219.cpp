/*************************************************************************
	> File Name: 219.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年01月21日 星期二 11时23分36秒
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
#define MAX_N 10000

struct stu {
    int num;
};

bool cmp1(stu a, stu b) {
    return a.num < b.num;
}

bool cmp2(stu a, stu b) {
    return a.num > b.num;
}

int main() {
    int n, l1, r1, l2, r2;
    stu arr[MAX_N + 5];
    cin >> n >> l1 >> r1 >> l2 >> r2;
    for(int i = 0; i < n; i++) {
        cin >> arr[i].num;
    }
    sort(arr + l1 - 1, arr + r1, cmp1);
    sort(arr + l2 - 1, arr + r2, cmp2);
    for(int i = 0; i < n; i++) {
        if(i) {
            cout << " ";
        }
        cout << arr[i].num;
    }
    return 0;
}


