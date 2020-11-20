/*************************************************************************
	> File Name: develop_return_value.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月21日 星期五 20时27分31秒
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

class A {
public:
    A() {
        cout << "constructor" << endl;
    };
    A(const A &obj) {
        cout << "copy constructor" << endl;
    }
};

A func() {
    A temp;
    return temp;  //return的时候会调用拷贝构造函数
};

int main() {
    A a(func());  //拷贝给a的时候调用拷贝构造函数
    return 0;
}

