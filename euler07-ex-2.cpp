/*************************************************************************
	> File Name: euler07-ex-2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月06日 星期二 11时12分20秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

#define MAX_RANGE 10000

int32_t prime[MAX_RANGE + 5] = {0};

int32_t main() {
    for(int32_t i = 2; i * i <= MAX_RANGE; i++) {
        if(!prime[i]) {
            for(int32_t j = i; j <= MAX_RANGE; j += i)
                prime[j] = i;
        }
    }
    int32_t n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n",prime[n]);
    }
    return 0;
}

