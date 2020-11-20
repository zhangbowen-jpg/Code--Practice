/*************************************************************************
	> File Name: 250.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 五  6/ 7 21:36:49 2019
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
#define MAX_N 1000000
long long arr[MAX_N + 5];
long long sum[MAX_N + 5];

int main() {
    int n;
    long long total = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i], total += arr[i];
    total /= n;
    sum[0] = arr[0] - total;
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + (arr[i] - total);
    }
    nth_element(sum, sum + n / 2, sum + n);
    long long c = sum[n / 2];
    total = 0;
    for (int i = 0; i < n; i++) {
        total += abs(sum[i] - c);
    }
    cout << total << endl;
    return 0;
}
