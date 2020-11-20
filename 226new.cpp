/*************************************************************************
	> File Name: 226new.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年09月29日 星期日 18时53分15秒
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

long long quick_mod(long long a, long long b, long long p) {
    long long temp = a, ans = 1;
    while(b) {
        if(b & 1)   ans = ans * temp % p;//看现在这位是否为1
        temp = temp * temp % p;
        b >>= 1;
    }
    return ans % p;
}

int main() {
    long long a, b, p;
    cin >> a >> b >> p;
    cout << quick_mod(a, b, p) << endl;
    return 0;
}

