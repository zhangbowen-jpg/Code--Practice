/*************************************************************************
	> File Name: constexpr.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月12日 星期四 20时23分32秒
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

constexpr int func(int i) {  //这里表示该函数 可以 为编译期常量
    return 2 * i;
}

struct A {
    constexpr A(int x, int y) : x(x), y(y) {} //这里表示该函数 可以 为编译期常量,正常使用也没有问题
    int x, y;
};


int main() {
    int n;
    cin >> n;
    const int a = n + 3;  //const -> 不可修改(运行期常量) constexpr -> 编译期常量
    constexpr int b = func(123) + 567;  //这里会报错， 未加constexpr的func()在编译期不是常量
    cout << func(n) << endl;
    constexpr A c(2, 3);
    return 0;
}


