/*************************************************************************
	> File Name: 227new.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年09月29日 星期日 19时04分56秒
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

long long quick_mul(long long a, long long b, long long p) {
    long long tmp = a, ans = 0;
    while(b) {
        if(b & 1) ans = (ans + tmp) % p;
        tmp = tmp * 2 % p;
        b >>= 1;
    }
    return ans % ;p
}

int main() {
    long long a, b, p;
    cin >> a >> b >> p;
    cout << quick_mul(a, b, p) << endl;
    return 0;
}

