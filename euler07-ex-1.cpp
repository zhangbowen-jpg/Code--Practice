/*************************************************************************
	> File Name: euler07-ex-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 16时02分12秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define max_n 10000

int prime[max_n + 5];

int main() {
    memset(prime, 0, sizeof(prime));
    for(int i = 2; i * i <= max_n; i++) {
        if(!prime[i]) {
            for(int j = i; j <= max_n; j += i) {
                if(!prime[j])
                    prime[j] = i;
            }
        }
    }
    int n;
    while(scanf("%d",&n) != EOF) {
        printf("%d",prime[n]);
    }
    return 0;
}
