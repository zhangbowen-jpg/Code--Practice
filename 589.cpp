/*************************************************************************
	> File Name: 589.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年05月06日 星期三 18时47分20秒
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

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n, k, id;
    cin >> n >> k >> id;
    if(n == k) {
        cout << "1/1" << endl;
    } else if (k == 0) {
        cout << "0/1" << endl; 
    } else {
        int t = gcd(n, k);
        cout << k / t << "/" << n / t << endl;
    }
    return 0;
}


