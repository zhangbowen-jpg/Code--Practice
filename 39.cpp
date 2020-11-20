/*************************************************************************
	> File Name: 39.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年01月15日 星期三 10时39分21秒
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
    int begin, n;
    scanf("%d%d", &begin, &n);
    if(begin < 0) {
        for(int i = 0; i < n; i++) {
            printf("%d\n", i * 2);
        }
    } else if(begin % 2 == 0) {
        for(int i = 0; i < n; i++) {
            printf("%d\n", begin + i * 2);
        }
    } else {
        for(int i = 1; i <= n; i++) {
            printf("%d\n", begin + i * 2 - 1);
        }
    }
    return 0;
}
