/*************************************************************************
	> File Name: euler25.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月07日 星期三 18时57分45秒
 ************************************************************************/

#include<stdio.h>

int fib[3][1005] = {{0,0}, {1,1}, {1,1}};

int main() {
    int n = 2;
    while (fib[n % 3][0] < 1000) {
        n += 1;
        for (int i = 3; i < fib[(n - 1) % 3][0]; i++) {
            fib[n % 3][i] = fib[(n - 1) % 3][i] + fib[(n - 2) % 3][i];
        }
        fib[n % 3][0] = fib[(n-1) % 3][0];
        for (int i = 1; i <= fib[n % 3][0]; i++) {
            fib[n % 3][i] += fib[(n - 1) % 3][i] + fib[(n - 2) % 3][i];
        }
        fib[n % 3][0] = fib[(n - 1) % 3][0];
        for(int i = 1; i <= fib[n % 3][0]; i++) {
            if(fib[n % 3][i] < 10) continue;
            fib[n % 3][i + 1] += fib[n % 3][i] / 10;
            fib[n % 3][i] %= 10;
            fib[n % 3][0] += (i == fib[n % 3][0]);
        }
    }
    printf("%d\n", n);
    return 0;
}

