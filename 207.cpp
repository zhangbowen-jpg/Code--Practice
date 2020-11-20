/*************************************************************************
	> File Name: 207.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年01月16日 星期四 11时47分06秒
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
    int sum = 0;
    string name;
};

int main() {
    student stu[35];
    int n, max = 0, hs = 0, ls = 1000, score, l;
    cin >> n; 
    for(int i = 0; i < n; i++) {
        cin >> stu[i].name;
        for(int j = 0; j < 4; j++) {
            cin >> score;
            stu[i].sum += score;
            if(score > hs) hs = score; else if(score < ls) ls = score; else continue;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << stu[i].sum << endl;
        if(stu[i].sum > max) { 
            max = stu[i].sum;
            l = i;
        }
    }
    cout << stu[l].name << endl;
    cout << hs << " " << ls << endl;
    return 0;
}

