/*************************************************************************
	> File Name: 456.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年11月12日 星期四 14时51分46秒
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

int arr[MAX_N + 5] = {0};
int ans[MAX_N / 2 + 5] = {0};

bool cmp(int a, int b) {
    return a < b;
}

int func(int a[], int n) {
    int now = 0;
    for(int i = 0; i < n; i++) {
        if(now < arr[i]) {
            now = arr[i];
            ans[arr[i]] = 1;
        }
        else {
            ans[now]++;
        }
    }
    return MAX_N / 2 + 1; 
}

int main() {
    int n, s;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n, cmp);

    s = func(ans, n);

    for(int i = 0; i < s; i++) {
        if(ans[i] % 2 != 0) cout << i << endl;
    }

    return 0;
}



