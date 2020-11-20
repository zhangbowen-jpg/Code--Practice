/*************************************************************************
	> File Name: 458.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年07月15日 星期三 19时19分07秒
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
    string name;
    string sex;
    int year;
    int month;
};

bool cmp(student a, student b) {
    if(a.year == b.year) return a.month > b.month;
    return a.year > b.year;
}

int main() {
    int n;
    cin >> n;
    student stu[105];
    for(int i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].sex >> stu[i].year >> stu[i].month;
    }

    sort(stu, stu + n, cmp);

    for(int i = 0; i < n; i++) {
        cout << stu[i].name << " " << stu[i].sex << " " << stu[i].year << " " << stu[i].month << endl;
    }
    
    return 0;
}

