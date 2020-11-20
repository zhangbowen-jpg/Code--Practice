/*************************************************************************
	> File Name: 443.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年01月15日 星期三 12时37分49秒
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
    int L, M, x, y, sum = 0;
    scanf("%d%d", &L, &M);
    int arr[L + 1];
    memset(arr, 1, sizeof(arr));
    for(int i = 0; i < M; i++) {
        scanf("%d%d", &x ,&y);
        for(int j = x; j <= y; j++) {
            arr[j] = 0;
        }
    }
    for(int i = 0; i <= L; i++) {
        if(arr[i]) sum += 1;
    }
    printf("%d\n", sum);
    return 0;
}

