/*************************************************************************
	> File Name: euler44.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月03日 星期六 13时24分00秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int64_t Pentagonal(int64_t n) {
    return n * (3 * n - 1) / 2;
}

bool isPentagonal(int64_t n) {
    int64_t mind = 1, maxd = n, mid;
    int64_t t;
    mid = (mind + maxd) >> 1;
    while (mind <= maxd) {
        t = Pentagonal(mid);
        if (t < n) {
            mind = mid + 1;
        } else if (t > n) {
            maxd = mid - 1;
        } else if (t == n) {
            return true;
        }
        mid = (mind + maxd) >> 1;
    }
    return false;
}

int32_t main() {
    int64_t miniNum = INT64_MAX;
    int64_t n = 1, m, p1, p2;
    while (true) {
        p1 = Pentagonal(n);
        p2 = Pentagonal(n - 1);
        if(p1 -p2 > miniNum) break;
        for(int32_t m = n - 1; m >= 1; m--) {
            p2 = Pentagonal(m);
            if(p1 - p2 >= miniNum) break;
            if(isPentagonal(p1 + p2) && isPentagonal(p1 - p2)) {
                miniNum = p1 - p2;
            }
        }
        ++n;
    }
    printf("%" PRId64 "\n", miniNum);
    return 0;
}

