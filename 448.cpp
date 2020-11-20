/*************************************************************************
	> File Name: 448.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年01月15日 星期三 12时32分32秒
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
    int n, num;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &num);
    for(int i = 0; i < n; i++) {
        if(num == arr[i]) printf("%d\n", i + 1);
    }
    return 0;
}
