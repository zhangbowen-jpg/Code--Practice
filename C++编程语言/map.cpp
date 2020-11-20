/*************************************************************************
	> File Name: map.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月19日 星期三 16时48分53秒
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

int main() {
    map<int, int> arr;
    arr[-100] = 36;
    arr[-90] = 50;
    arr[105] 37;
    arr[78] = 65; 
    for(auto iter = arr.begin(); iter != arr.end(); iter++) {
        cout << iter->first <<endl;
    }
    return 0;
}

