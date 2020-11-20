/*************************************************************************
	> File Name: 461.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年11月12日 星期四 15时37分35秒
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

struct Num {
    int data;
};

struct Chars {
    string level;
};

int main() {
    int n, ans1 = 0, ans2 = 0;
    char m;
    cin >> n;
    Chars a1[1005];
    Num a2[1005];
    for(int i = 0; i < n; i++) {
        cin >> m;
        if(m == 'C') {
            cin >> a1[ans1].level;
            ans1++;
        } else {
            cin >> a2[ans2].data;
            ans2++;
        }
    }
    int ans3 = 0;
    
    for(int i = 0; i < ans2; i++) {
        ans3 += a2[i].data;
    }
    ans3 /= ans2;

    cout << ans1 << ans3 << endl;

}


