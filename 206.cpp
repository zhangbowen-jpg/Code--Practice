/*************************************************************************
	> File Name: 206.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年01月15日 星期三 13时19分42秒
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

int main() {
    int n, m;
    int sum;
    scanf("%d%d", &n, &m);
    int arr[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 0; i < m; i++) {
        sum = 0;
        for(int j = 0; j < n; j++) {
            sum += arr[j][i];
        }
        printf("%d\n", sum);
    }
    return 0;
}

