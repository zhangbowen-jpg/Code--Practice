/*************************************************************************
	> File Name: test.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 五  6/ 7 20:53:07 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
#define MAX_N 100000
long long arr[MAX_N + 5];

bool check(long long *arr, long long n, long long m, long long a) {
    long long sj = 0, si = 0, pre_min = 0;
    for (long long i = 1; i <= n; i++) {
        si += arr[i] - a;
        if(i < m) continue;
        sj = min(sj, pre_min);
        if(si - sj >= 0) return true;
        pre_min += arr[i - m + 1] - a;
    }
    return false;
}

long long binary_search(long long *arr, long long n, long long m, long long l, long long r) {
    if (l == r) return l;
    long long mid = (l + r + 1) >> 1;
    if (check(arr, n, m, mid))
        return binary_search(arr, n, m, mid, r);
    return binary_search(arr, n, m, l, mid - 1);
}

int main() {
    long long n, m;
    long long num_min, num_max;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] *= 1000;
        if (i == 1) num_min = arr[i], num_max = arr[i];
        num_min = min(num_min, arr[i]);
        num_max = max(num_max, arr[i]);
        }
    cout << binary_search(arr, n, m, num_min, num_max) << endl;
    return 0;
}
