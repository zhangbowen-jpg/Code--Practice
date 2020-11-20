/*************************************************************************
	> File Name: 455.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年11月12日 星期四 14时41分37秒
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

int gcd(int a, int b) {
    int temp;
    while(a != 0) {
        temp = b % a;
        b = a;
        a = temp;
    }
    return b;
}

bool cmp(int a, int b) {
    return a < b;
}

int main() {
    int arr[5] = {0};
    for(int i = 0; i < 3; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + 3, cmp);

    int x = gcd(arr[0], arr[2]);

    cout << arr[0] / x << "/" << arr[2] / x << endl;

    return 0;
}

