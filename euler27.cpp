/*************************************************************************
	> File Name: euler27.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月19日 星期一 19时48分20秒
 ************************************************************************/

 

#include <stdio.h>
#include <limits.h>
#include <inttypes.h>
#include <time.h>
#include <stdlib.h>
#define MAX_N 1000
#define MAX_M 2500
#define R_M_TEST_ROUND 30

 

int32_t prime[MAX_M + 5] = {0};

int32_t gcd(int32_t a, int32_t b) {
    if (!b) return a;
    return gcd(b, a % b);
}

bool R_M_TEST(int32_t x) {
    if (x <= 1) return false;
    int64_t a, m, ans;
    for (int32_t i = 0; i < R_M_TEST_ROUND; i++) {
        a = (rand() % (x - 1)) + 1;
        ans = 1;
        m = x - 1;
        while (m) {
            if (m % 2) ans = (ans * a) % x;
            a = (a * a) % x;
            m /= 2;
        }
        if (ans != 1) return false;
    }
    return true;
}

int32_t HowManyPrime(int32_t a, int32_t b) {
    int32_t i = 0;
    while (R_M_TEST(i * i + a * i + b)) ++i;
    return i;
}

int32_t main() {
    srand(time(0));
    prime[1] = INT_MAX;
    for (int32_t i = 2; i <= MAX_M; i++)
        if (!prime[i])
            for (int32_t j = i; j <= MAX_M; j += i)
                if (!prime[j]) prime[j] = i;
    int32_t maxNum = 40, tempNum, result = 0;
    for (int32_t a = 1 - MAX_N; a < MAX_N; a++) 
        for (int32_t b = (a < 0 ? -a + 1 : 2); b < MAX_N; b++) {
            if (prime[b] != b) continue;
            if (prime[b + a + 1] != b + a + 1) continue;
            if (a > 0 && b > 0 && prime[gcd(a, b)] <= maxNum) continue;
            tempNum = HowManyPrime(a, b);
            if (tempNum > maxNum) {
                result = a * b;
                maxNum = tempNum;
            }
        }
    printf("%d\n", result);
    return 0;
}

