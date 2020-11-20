/*************************************************************************
	> File Name: 198.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年01月15日 星期三 12时21分14秒
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
#define N 1000000007

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    arr[0] = arr[1] = 1;
    for(int i = 2; i < n; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % N;
    }
    printf("%d\n", arr[n - 1] % N);
    return 0;
}
