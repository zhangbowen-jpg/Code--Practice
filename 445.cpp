/*************************************************************************
	> File Name: 445.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年01月17日 星期五 15时52分59秒
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
#define MAX_N 1000

int arr[MAX_N + 5];

int main() {
    int n, a = 0, b = 0, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[i]) a++;
        }
        for(int k = i + 1; k < n; k++) {
            if(arr[k] > arr[i]) b++;
        }
        if(a == b) sum++;
        a = 0;
        b = 0;
    }
    printf("%d\n", sum);
    return 0;
}

