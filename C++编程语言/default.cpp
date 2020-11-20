/*************************************************************************
	> File Name: default.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月10日 星期二 18时49分25秒
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
/*
class T {
public : 
    T() = delete; //删除默认构造函数
};
*/

class A {
public : 
    A() : z(0), w(x) {}
    A(int x, int y) : x(x), y(y), z(8), w(this->x) {}
    A(const A &a) = z(a.z),w(x) { //这是正常的初始化赋值，不报错
        this->x = a.x;
        this->y = a.y;
        //this->z = a.z;   报错，常值不可修改   这种不是严格意义初始化
    };
    void say() { cout << "hello world" << endl; }
    // T t;   代码报错
private : 
    int x, y;
    const int z;
    int &w;
};

int main() {
    A *p = new A();
    A a(3, 4);
    A b = a;
    return 0;
}

