/*************************************************************************
	> File Name: 217.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年01月17日 星期五 13时12分32秒
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

int main() {
    int n, arr[MAX_N + 5] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        arr[temp]++;
    }
    int num = 0;
    for(int i = 100; i >= 0; i--) {
        num += arr[i];
        if(num * 2 >= n) {
            printf("%d %d\n", i, num);
            break;
        }
    }
    return 0;
}

