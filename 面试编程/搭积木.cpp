/*************************************************************************
	> File Name: 搭积木.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月17日 星期一 17时57分25秒
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define MAX_N 1000000

struct Wood {
    int x;
    int y;
} arr[MAX_N + 5];

bool cmp(const Wood &a, const Wood &b) { //长和宽都要满足，小的在上
    if(a.x - b.x) return a.x < b.x;
    return a.y < b.y;
}

int main() {
    int dp[MAX_N + 5];
    int n, s = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr, arr + n, cmp);
    dp[s++] = arr[0].y;
    for(int i = 1; i < n; ++i) {
        if (arr[i].y >= dp[s-1]) {
            dp[s++] = arr[i].y;
            continue;
        }
        int l = 0;
        int r = s - 1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(dp[mid] <= arr[i].y) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        dp[l] = arr[i].y;
    }
    cout << s << endl;
    return 0;
}
