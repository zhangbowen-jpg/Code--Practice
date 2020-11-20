/*************************************************************************
	> File Name: 204.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年01月15日 星期三 12时55分37秒
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
    int n;
    scanf("%d", &n);
    int arr[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) printf("%d\n", arr[i][j]);
        }
    }
    return 0;
}

