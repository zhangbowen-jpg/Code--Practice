/*************************************************************************
	> File Name: euler07-2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 16时14分20秒
 ************************************************************************/

#include<stdio.h>
#define max_n 200000

int prime[max_n + 5] = {0};

int main() {
    for(int i = 2; i <= max_n; i++) {
        if(!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    printf("%d\n",prime[10001]);
    return 0;
}

