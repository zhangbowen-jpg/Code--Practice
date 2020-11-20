/*************************************************************************
	> File Name: euler21-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月19日 星期一 14时56分18秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<map>
#include<vector>
using namespace std;
#define max_n 10000

int prime[max_n + 5] = {0};
int  f[max_n + 5] = {0};//记录因子数
int cnt[max_n + 5] = {0};//记录幂次
int fac[max_n + 5] = {0};//记录因子和

void init() {
    for (int i = 2; i <= max_n; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = 2;
            fac[i] = 1 + i;
            cnt[i] = 1;
        }
        for (int  j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) {
                fac[prime[j] * i] = fac[i] / (pow(prime[j], cnt[i] + 1) - 1) * (pow(prime[j], cnt[i] + 2) - 1);//因子和
                f[prime[j] * i] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);//因子数
                cnt[prime[j] * i] = cnt[i] + 1;//幂次
                break;
            } else {
                fac[prime[j] * i] = fac[prime[j]] * fac[i];
                f[prime[j] * i] = f[prime[j]] * f[i];
                cnt[prime[j] * i] = 1;
            }
        }
    }
    return ;
}

int main() {
    init();
   // for (int i = 2; i < max_n; i++) {
   //     printf("fac[%d] = %d\n", i, fac[i]);
   // }
    int sum = 0;
    for (int i = 2; i < max_n; i++) {
        fac[i] -= i;
    }
    for (int i = 2; i < max_n; i++) {
        if(fac[i] < max_n && fac[fac[i]] == i && fac[i] != i) sum += i;
    }
    cout << sum << endl;
    return 0;
}

