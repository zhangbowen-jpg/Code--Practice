/*************************************************************************
	> File Name: euler44-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 15时02分42秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

int64_t pentagonal(int64_t n) {
    return n * (3 * n - 1) / 2;
}

int64_t is_Pentagonal(int64_t x) {
    int64_t head = 1, tail = 10000, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (pentagonal(mid) == x) return 1;
        else if (pentagonal(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int32_t main() {
    int64_t i = 1, j = 1, ans = INT32_MAX;
    while (pentagonal(j + 1) - pentagonal(j) < ans) {
        j += 1;
        i = j - 1;
        for (int i = j - 1; i >= 1 && pentagonal(j) - pentagonal(i) < ans; i--){
            if (is_Pentagonal(pentagonal(j) + pentagonal(i))) continue;
            if(is_Pentagonal(pentagonal(j) - pentagonal(i))) continue;
            if (pentagonal(j) - pentagonal(i) > ans) continue;
            ans = pentagonal(j) - pentagonal(i);
        }
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
