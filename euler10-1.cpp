/*************************************************************************
	> File Name: euler10-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月31日 星期三 15时28分57秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#define max 10000000
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int32_t prime[max + 5] = {0};
    for(int i = 2; i <= max; i++) {
        if(!prime[i]) {prime[++prime[0]] = i; if(i >= a && i <= b) printf("%d\n", i)}
        for (int j = 1; j <= prime[0]; j++) {
            if(i * prime[j] > max) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return 0;
}
