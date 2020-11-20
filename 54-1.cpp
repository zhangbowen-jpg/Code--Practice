/*************************************************************************
	> File Name: 54-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月23日 星期五 17时59分40秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cinttypes>
#define max_n 1000000
using namespace std;

void f(int x);
int fac[max_n + 5];
int ans[max_n + 5];
void factorial(int x);

int main() {
    int x;
    while (~scanf("%d", &x)) {
        f(x);
        for (int i = ans[0]; i > 0; i--) printf("%d", ans[i]);
        printf("\n");
        /*
        printf("%d\n", fac[0]);
        for (int i = 1; i <= fac[0]; i++) {
            printf("%d", fac[i]);
        }
        */
    }
    return 0;
}

void factorial(int x) {
    memset(fac, 0, sizeof(fac));
    fac[0] = 1;
    fac[1] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= fac[0]; j++) fac[j] *= i;
        for (int j = 1; j <= fac[0]; j++) {
            if (fac[j] < 10) continue;
            fac[j + 1] += fac[j] / 10;
            fac[j] %= 10;
            fac[0] += (j == fac[0]);
        }
    }
    return;
}

void f(int x) {
    memset(ans, 0, sizeof(ans));
    ans[0] = 1;
    ans[1] = 1;
    factorial(x);
    for (int i = 1; i <= fac[0]; i++) {
        if (fac[i] == 0) continue;
        for (int j = 1; j <= ans[0]; j++) ans[j] *= fac[i];
        for (int j = 1; j <= ans[0]; j++) {
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (j == ans[0]);
        }
    }
    return;
}
