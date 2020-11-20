/*************************************************************************
	> File Name: euler02.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月31日 星期三 15时38分56秒
 ************************************************************************/

#include <stdio.h>
#define max_n 4000000
int fib[45];

int main() {
    fib[1] = 1,fib[2] = 2;
    int n = 2;
    while (fib[n - 1] + fib[n] < max_n) {
        n++;
        fib[n] = fib[n - 1] + fib[n - 2];
    }
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        if(fib[i] % 2) continue;
        sum += fib[i];
    }
    printf("%lld\n", sum);
    return 0;
}

