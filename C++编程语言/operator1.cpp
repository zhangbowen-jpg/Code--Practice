/*************************************************************************
	> File Name: operator1.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月10日 星期二 19时50分11秒
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

class Data {
public :
    Data(int x, int y) : x(x), y(y) {}
    int x, y;
}

class A {
public :
    A() {}
    A(Data *obj) : p(obj) {} //此时A为指针 
    Data *operator->() {
        return p;
    }
    Data &operator*() {
        return *p;
    }
private : 
    Data *p;
};

A func() {   //A func(A &a) RVO 返回值优化
    A a;
    return a;
}


int main() {
    A temp_a = func(); // ==>func(temp_a); RVO 返回值优化
    Data d(3, 4);
    A a = &d;
    cout << a->x << endl;
    cout << a->y << endl;
    cout << (*a).x << endl;
    cout << (*a).y << endl;
    return 0;
}


