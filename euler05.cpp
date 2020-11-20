/*************************************************************************
	> File Name: euler05.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 14时47分43秒
 ************************************************************************/

#include<stdio.h>

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b,a % b);
}

int main() {
    for (int i = 1; i <= 20; i++) {
        if (ans % i == 0) continue;
        ans = ans * i / gcd(ans, i);
    }
    printf("%d\n", ans);
    return 0;
}

