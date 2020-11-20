/*************************************************************************
	> File Name: 310.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年09月29日 星期日 19时11分37秒
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
#define MAX_N 1000000

long long prime[MAX_N + 5] = {0}; 

int init_prime() {
    for(int i = 2; i <= MAX_N; i++) {
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; i++) {
            if(i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

int main() {
    init_prime();
    int n;
    cin >> n;
    for(int i = 1; i <= prime[0] && prime[i] <= n; i++) {
        long long cnt = 0;
        for(long long j = prime[i]; j <= n; j *= prime[i]) {
            cnt += n / j; 
            // 分别算 N/2 N/2^2 N/2^3...
// 6/2 = 3  1*2 = 2, 2 * 2 =4, 3 * 2 = 6;  4是2的平方 6/4 = 1; 3+1 = 4;  
        }
        cout << prime[i] << " " << cnt <<endl;
    }
}

