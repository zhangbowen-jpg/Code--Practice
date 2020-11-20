/*************************************************************************
	> File Name: nullptr.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月12日 星期四 20时39分04秒
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

#ifdef CPP
#define NULL 0
#else 
#define NULL ((void *),0)  
#endif

void f(int x) {
    cout << x << endl;
    return ;
}

void f(int *p) {
    cout << p << endl;
    return ;
}

int main() {
    int n = 123;
    f(n);
    f(&n);
    /*f(NULL);   // 报错 ，NULL可以当成0，也可以成为空地址。*/
    f(nullptr); // 明确的空地址
    return 0;
}

