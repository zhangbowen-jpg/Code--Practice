/*************************************************************************
	> File Name: add_template.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月14日 星期六 14时09分12秒
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

struct A {
    A() = delete;
    A(int x) : x(x) {} //转换类型构造函数
    double operator+(int x) { 
        return x + this->x + 0.001;
    }
    int x;
};


template<typename T, typename U> 
auto add(T a,U b) -> decltype(a + b) {  //使用构造函数是为了传入对象,使用返回值后置的办法
    return a + b;
}

template<typename T, typename U> 
auto add(T *a,U *b) -> decltype(add(*a, *b)) {  //如果传入的是二维指针
    return add(*a, *b);
}


auto func(int x) -> int { //等价于 int func(int x) {}
    return 2 * x;
}

int main() {
    cout << add(2, 3) << endl;
    cout << add(2.3, 3.5) << endl;
    cout << add(2, 3.5) << endl;
    int a = 12;
    double b = 45.7;
    decltype(a + b) c;    //自动判断a + b的类型
    cout << sizeof(c) << endl;
    A d(6);
    cout << add(d, 4) << endl;
    cout << func(4) << endl;
    cout << add(a, b) << endl;
    cout << add(&a, &b) << endl;
    return 0;
}

