/*************************************************************************
	> File Name: 271.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月15日 星期二 18时49分58秒
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
#define MAX_N 300000
int arr[MAX_N + 5];
int q[MAX_N + 5], head, tail;


int main() {
    int n, k;
    cin >> n >> k;    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    head = tail = 0;
    for(int i = 0; i < n; i++) {
        while(tail - head && arr[i] < arr[q[tail - 1]]) tail--;
        q[tail++] = i;
        if(i + 1 < k) continue;
        if(i - q[head] == k) {
            head++; //维护区间长度，过期弹出队列
        }
        i + 1 == k || cout << " ";
        cout << arr[q[head]];
    } // 维护元素单调性递增（最小值）
    cout << endl;
    head = tail = 0;
    for(int i = 0; i < n; i++) {
        while(tail - head && arr[i] > arr[q[tail - 1]]) tail--;
        q[tail++] = i;
        if(i + 1 < k) continue;
        if(i - q[head] == k) {
            head++;
        }
        i + 1 == k || cout << " ";
        cout << arr[q[head]];
    } // 维护元素单调性递减（最大值）
    cout << endl;
    return 0;
}



