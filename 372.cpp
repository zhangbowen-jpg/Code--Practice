/*************************************************************************
	> File Name: 372.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月15日 星期二 20时25分37秒
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
#define MAX_N 500000
int a[MAX_N + 5], b[MAX_N + 5];//使用原存储空间来进行存储队列

int main() {
    int n; 
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int p = 1, top1 = 0, top2 = 0;//分别指向两个队列队尾位置
    while (p < n) {
        while(top1 != -1 && a[p] <= a[top1]) --top1; 
        while(top2 != -1 && b[p] <= b[top2]) --top2;
        if(top1 - top2) break;//如果对应位置的值不相同，退出循环返回p
        a[++top1] = a[p];
        b[++top2] = b[p];
        p++;
    }
    cout << p << endl;
    return 0;
}




