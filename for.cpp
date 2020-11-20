/*************************************************************************
	> File Name: for.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月11日 星期五 07时50分00秒
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

int re(int x) {
    if(x != 100) {
    return 1;
    }
}

int main() {
    for(int i = 0; i < 99; i++) {
        if(re(i)){
        printf("!");
        i = 0;
        }      
    }
    return 0;
}

