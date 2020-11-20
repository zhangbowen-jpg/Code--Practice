/*************************************************************************
	> File Name: 446.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月10日 星期四 15时39分19秒
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
    int a,x = 0;
    scanf("%d", &a);
    int arr[a][a];
    for(int j = 1; j <= (a + 1) / 2; j++) {
        for(int i = j - 1; i < a - x; i++) {
            arr[x][i] = j;
            arr[a - x - 1][i] = j;
            arr[i][x] = j;
            arr[i][a - x - 1] = j;
        }
        x++;
    }
    for(int i = 0; i < a; i++) {
        printf("%d", arr[i][0]);
        for(int j = 1; j < a; j++) {
            printf(" %d",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

