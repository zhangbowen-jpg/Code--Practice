/*************************************************************************
	> File Name: 587.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年05月06日 星期三 18时03分35秒
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

int N, a, b, c;

int main() {
    cin >> N >> a >> b >> c;
    if(a > b && b > c) cout << 0 << endl;
    if(a > b && b < c) {
        if(a > c) cout << 1 << endl;
        else cout << 0 << endl;
    }
    if(a < b && b < c) cout << 1 << endl;
    if(a < b && b > c) {
        if(a > c) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}



