/*************************************************************************
	> File Name: 454.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年11月12日 星期四 14时14分41秒
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
#define MAX_N 100

int arr[MAX_N + 5] = {0};
int ans[MAX_N + 5] = {0};

bool cmp(int a, int b) {
    return a < b;
} 

int func(int a[],int n, int s) {
    int now = 0;
    for(int i = 0; i < n; i++) {
        if(now < arr[i]) {
            a[s] = arr[i];
            now = arr[i];
            s++;
        }
    }
    return s; 
}


int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr,arr + n,cmp);

    int s = func(ans, n, 0);
    
    cout << s << endl;

    for(int i = 0; i < s; i++) {
        if(i != s - 1) {
            cout << ans[i] << " ";
        } 
        else cout << ans[i] << endl;

    }

    return 0;
}


