/*************************************************************************
	> File Name: 166-1.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月19日 星期三 16时29分35秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;

int main() {
    string str1, str2;
    int n;
    cin >> str1 >> n >> str2;
    cout << min(str1.length(), (size_t)100) << endl;  //这里两个内容的类型必须一值
    str1.insert(n - 1, str2);
    cout << str1 << endl;
    cout << str1.length() - str1.rfind('x') << endl;
    return 0;
}

