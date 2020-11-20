/*************************************************************************
	> File Name: 564.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年09月23日 星期三 23时36分08秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;

//不能用struct 没法== 

int n, m;

pair<string,int> arr[100005];

int function(int d, int k) {
    for(int i = 1; i <= n; i++) {
        int x = arr[i].second >> d & 1;  //判断第d位是k的情况
        if(arr[i].first == 'AND') k &= x;
        else if(arr[i].first == 'OR') k |= x;
        else k ^= x;
    }
    return k;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string str, int x;
        cin >> str >> x;
        arr[i] = make_pair(str,x);
    }
    int val = 0, ans = 0;
    for(int k = 29; k >= 0; k--) {
        int r0 = function(k, 0); //k为是0的情况
        int r1 = function(k, 1); //k为是1的情况
        if(val + (1 << k) <= m && r0 < r1)  //只有1的值比较大且没有越界的情况下置一，否则b位置0
            val += 1 << k, ans += r1 << k;
        else :
            ans += r0 << k;
    }
    cout << ans << endl;
    return 0;
}


