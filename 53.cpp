/*************************************************************************
	> File Name: 53.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月30日 星期二 19时17分00秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define max_n 1000000

int prime[max_n + 5] = {0};
int f[max_n + 5] = {0};
int cnt[max_n + 5] = {0};
int fac[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i; 
            fac[i] = 1 + i;
            cnt[i] = i * i;
        }
        for (int  j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) {
                fac[prime[j] * i] = fac[i] * (1 - cnt[i] * prime[j]) / (1 - cnt[i]);
                cnt[prime[j] * i] = prime[j] * cnt[i];//幂次
                break;
            } else {
                fac[prime[j] * i] = fac[prime[j]] * fac[i];
                cnt[prime[j] * i] = prime[j] * prime[j];
            }
        }
    }
    return ;
}


int main() {
    init();
    int sum = 0;
    for (int i = 1; i <= max_n; i++) {
        if(sum < fac[i]) sum = fac[i];
   }
    printf("%d",sum);
    return 0;
}

