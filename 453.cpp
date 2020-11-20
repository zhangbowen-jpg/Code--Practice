/*************************************************************************
	> File Name: 453.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月26日 星期六 14时15分46秒
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

int arr[MAX_N + 5] = {0};

bool cmp(int a, int b) {
    return a < b;
} 

string func(int n, int k) {
    string x = "NO RESULT";
    int now = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        if(now < arr[i]) {
            now = arr[i];
            cnt++;
        }
        if(cnt == k) return to_string(now);
    }
    return x; 
}


int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr,arr + n,cmp);

    cout << func(n, k) << endl;

    return 0;
}


