/*************************************************************************
	> File Name: 7.29.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月29日 星期一 14时41分52秒
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <inttypes.h>

int max_int(int n, ...) {
    if(n <= 0) return 0;
    va_list arg;
    va_start(arg, n);
    int32_t ans = INT32_MIN;
    for (int i = 0; i < n; i++) {
        int32_t temp = va_arg(arg, int);
        if (temp > ans) ans = temp;
    }
    return ans;
}

int main() {
    printf("%d\n", max_int(3, 1, 5, 3));
    printf("%d\n", max_int(3, 1, 5, 3, 7));
    printf("%d\n", max_int(2, 3, 7));
    return 0;
}

//输出位5 5 7，仔细考虑函数的意义。
