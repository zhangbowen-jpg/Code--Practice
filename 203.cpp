/*************************************************************************
	> File Name: 203.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年09月29日 星期日 16时55分23秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<cstdio>
using namespace std;
#define MAX_N 10

int main() {
    int n, m, num[MAX_N + 5][MAX_N + 5], num2[105], cnt = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> num[i][j];
            num2[cnt] = num[i][j];
            cnt++;
        }
    }
    for(int i = 0; i < m; i++) {
        int max = num[0][i];
        for(int j = 1; j < n; j++) {
            if(max < num[j][i]) {
                max = num[j][i];
            }
        }
        cout << max << endl;
    }
    sort(num2, num2 + cnt);
    int sum = 0;
    for(int i = cnt - 1; i >= 0; i--) {
        sum += num2[i];
        cout << num2[i];
        if(i) {
        cout << " ";
        }
    }
    cout << endl;
    int arg = round(1.0 * sum / cnt);
    cout << arg << endl;
    int ans = 0;
    for(int i = cnt - 1; i >= 0; i--) {
        if(num2[i] >= arg) {
            ans++;
        } else {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}



