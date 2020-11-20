/*************************************************************************
	> File Name: 438.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年01月16日 星期四 12时29分50秒
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
    double cost;
    scanf("%d", &n);
    if(n <= 240) {
        cost = n * 0.4783;
        printf("%.1f\n", cost);
    } else if(n > 240 && n <= 400) {
        cost = 240 * 0.4783 + (n - 240) * 0.5283;
        printf("%.1f\n", cost);
    } else {
        cost = 240 * 0.4783 + 160 * 0.5283 + (n - 400) * 0.7783;
        printf("%.1f\n", cost);
    }
    return 0;
}


