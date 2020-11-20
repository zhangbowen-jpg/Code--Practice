/*************************************************************************
	> File Name: euler35.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月09日 星期五 18时01分59秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

#define MAX_RANGE 9999999
#define MAX_N 1000000

int isPrime[MAX_RANGE + 5] = {0};
int prime[MAX_RANGE + 5] = {0};

void initPrime() {
    for(int i = 2; i <= MAX_RANGE; i++){
        if(!isPrime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > MAX_RANGE) break;
            isPrime[prime[j] * i] = i;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}

bool isCirclePrime(int n) {
    if (isPrime[n] != 0) return false;
    int x = n, h, j;
    h = (int)pow(10, floor(log10(n)));
    j = (int)(floor(log10(n))) + 1;
    for (int i = 0; i < j; i++) {
        x = x / 10 + (x % 10) * h;
        if (isPrime[x] != 0) return false;
    }
    return true;      
}

int solve() {
    int many = 0;
    for(int i = 1; i <= prime[0]; i++) {
        if(prime[i] > MAX_N) break;
        if(isCirclePrime(prime[i])) many++; 
    }
    return many;
}

int main() {
    initPrime();
    int many = solve();
    printf("%d\n", many);
    return 0;
}

