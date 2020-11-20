/*************************************************************************
	> File Name: 447.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年11月12日 星期四 13时09分59秒
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

int arr[15] = {4,7,44,47,74,77,444,777,447,774,474,747,744,477};
string func(int n) {
    string y = "YES";
    string x = "NO";
    for(int i = 0; i < 13; i++) {
        if(n % arr[i] == 0) return y;
        else continue;
    }
    return x;
}

int main() {
    int n;
    cin >> n;
    cout << func(n) << endl;
    return 0;
}


