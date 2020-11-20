/*************************************************************************
	> File Name: 205.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年01月15日 星期三 12时59分23秒
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
    double sum;
    scanf("%d%d", &n, &m);
    int arr[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        sum = 0;
        for(int j = 0; j < m; j++) {
            sum += arr[i][j];
        }
        printf("%.6f\n", sum / m);
    }
    return 0;
}


