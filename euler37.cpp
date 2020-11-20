/*************************************************************************
	> File Name: euler37.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月09日 星期五 18时43分28秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include<math.h>
#define MAX_RANGE 5000000
#define MAX_N 1000000

int32_t prime[MAX_RANGE + 5] = {0};
int32_t isPrime[MAX_RANGE + 5] = {0};

int32_t initPrime() {
    isPrime[0] = 1; isPrime[1] = 1;
    for(int32_t i = 2; i < MAX_RANGE ; i++) {
        if(!isPrime[i]) prime[++prime[0]] = i;
        for(int32_t j = 1 ; j <= prime[0]; j++) {
            if(prime[j] * i >= MAX_RANGE) break;
            isPrime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

int32_t isCriclePirime(int32_t x) {
    if(isPrime[x] != 0) return 0;
    int32_t temp = x;
    int32_t h;
    h = (int32_t)pow(10,floor(log10(x)));
    while(temp) {
        if(isPrime[temp] != 0) return 0;
        temp = temp % h;
        h /= 10;
    }
    temp = x;
    while(temp) {
        if(isPrime[temp] != 0) return 0;
        temp = temp / 10;
    }
    return 1;
}

int32_t solve() {
    int32_t many = 0, flag = 11;
    for(int32_t i = 1; i <= prime[0]; i++) {
        if(prime[i] < 10) continue;
        if(!isCriclePirime(prime[i])) continue;
        many += prime[i];
        if(!(--flag)) break;
    }
    return many;
}

int32_t main() {
    initPrime();
    int32_t ans = solve();
    printf("%d\n",ans);
    return 0;
}

