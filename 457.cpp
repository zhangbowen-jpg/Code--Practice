/*************************************************************************
	> File Name: 457.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年10月22日 星期四 16时59分31秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;

bool cmp(int a, int b) {
    return a < b;
}

int main() {
    int n, arr[1005], ans[1005] = {0}, x = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i < n; i++) {
        int c = abs(arr[i] - arr[i - 1]);
        ans[c] = 1;
    }

    for(int j = 1; j < n; j++) {
        if(ans[j] != 1) {
            x = 1;
            break;
        }
    }
    
    if(x == 1) {
        cout << "Not jolly" << endl;
    } else {
        cout << "Jolly" << endl;
    }

    return 0;
}


