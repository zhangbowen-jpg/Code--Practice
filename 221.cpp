/*************************************************************************
	> File Name: 221.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: Wed Jul 15 18:51:48 2020
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

struct student {
    int num, h, ans;
};

bool cmp1(student a, student b) {
    return a.h < b.h;
}

bool cmp2(student a, student b) {
    return a.num < b.num;
}

int main() {
    int n, m;
    cin >> n >> m;
    student stu[100005];
    int height[100005];
    for(int i = 0; i < n; i++) {
        cin >> stu[i].h;
        stu[i].num = i;
        stu[i].ans = 0;
    }
    for(int i = 0; i < m; i++) {
        cin >> height[i];
    }
    sort(height,height + m);
    sort(stu, stu + n, cmp1);
    int index = 0;
    for(int i = 0; i < n; i++) {
        while(stu[i].h >= height[index] && index < m) {
            stu[i].ans++;
            index++;
        }
    }
    sort(stu, stu + n, cmp2);
    for(int i = 0; i < n; i++) {
        cout << stu[i].ans << endl;
    }
    return 0;
}

