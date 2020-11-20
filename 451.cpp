/*************************************************************************
	> File Name: 451.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年01月21日 星期二 10时57分54秒
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
#define MAX_N 100000

int main() {
    int n;
    int arr[MAX_N + 5];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    for(int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}

