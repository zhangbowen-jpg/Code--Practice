/*************************************************************************
	> File Name: 被3整除.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月10日 星期一 15时45分52秒
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

int f(int x) {
    return x - (x + 2) / 3;
} 

int main() {
    int l, r;
    cin >> l >> r;
    cout << f(r) - f(l - 1) << endl;
    return 0;
}

