/*************************************************************************
	> File Name: 218.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年01月21日 星期二 11时05分35秒
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
#define MAX_N 1000000

struct stu {
    int height, num;
};

bool cmp(stu a, stu b) {
    if(a.height == b. height) {   //同高度
        return a.num < b.num;
    }
    return a.height < b.height;
}

int main() {
    int n;
    cin >> n;
    stu student[MAX_N + 5];
    for(int i = 0; i < n; i++) {
        cin >> student[i].height;
        student[i].num = i + 1;
    }
    sort(student, student + n, cmp);
    for(int i = 0; i < n; i++) {
        if(i) {
            cout << " ";
        }
        cout << student[i].num;
    }
    return 0;
}


