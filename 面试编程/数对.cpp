/*************************************************************************
	> File Name: 数对.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月10日 星期一 16时29分47秒
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
    long long n, k, cnt = 0;
    cin >> n >> k;
    for(long long y = k + 1; y <= n; y++) {
        cnt += (y - k) * (n / y) + (n % y - k + 1 * (k != 0)) * (n % y >= k);
    }
    cout << cnt << endl;
    return 0;
}

