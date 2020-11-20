/*************************************************************************
	> File Name: 452.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年11月12日 星期四 13时39分47秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#define MAX_N 10000
using namespace std;

int arr[MAX_N + 5];

int BubbleSort(int n) {
    int temp, ans = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                ans += 1;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << BubbleSort(n) << endl;

    return 0;
}


