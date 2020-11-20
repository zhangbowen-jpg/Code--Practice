/*************************************************************************
	> File Name: map1.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月19日 星期三 16时57分17秒
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
    string name;
    int n, age;
    map<int, string> arr;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> age >> name;
        arr[age] = name;
    }
    for(auto iter = arr.begin(); iter != arr.end(); iter++) {
        cout << iter->second << endl;
    }
    return 0;
}
