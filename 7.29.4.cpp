/*************************************************************************
	> File Name: 7.29.4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月29日 星期一 16时03分07秒
 ************************************************************************/
// C++版扩展欧几里得算法
#include <algorithm>
#include <iostream>
using namespace std;

int ex_gcd(int a, int b, int *x, int *y) {
    if (!b) {
        *x = 1, *y = 0;
        return a;
    }
    int ret = ex_gcd(b, a % b, y ,x);
    *y -= a / b * (*x);
    return ret;
}

int main() {
    int a, b, x, y;
    while (~scanf("%d%d", &a, &b)) {
        printf("gcd(%d,%d) = %d\n", a, b, ex_gcd(a, b, &x, &y));
        printf("%d * %d + %d * %d = %d\n", a, x, b, y, a * x + b * y);
    }
    return 0;
}

