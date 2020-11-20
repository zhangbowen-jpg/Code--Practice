/*************************************************************************
	> File Name: euler08.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月31日 星期三 14时28分14秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include "008.H"


int main() {
    int64_t p = 1, zero = 0, ans = 0;
    for (int i = 0; num[i]; i++) {
        if (num[i] == '0') {
            zero += 1;
        } else {
            p *= (num[i] - '0');
        }
        if (i >= 13) {
            if (num[i - 13] == '0') {
                zero -= 1;
            } else {
                p /= (num[i - 13] - '0');
            }
        }
        if (zero == 0 && p > ans) ans = p;
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}

