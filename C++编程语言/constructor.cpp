/*************************************************************************
	> File Name: constructor.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月19日 星期三 19时27分02秒
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
    A() : next(nullptr) {
        cout << << this << "default constructor" << endl;
    }
    A(A *obj) {
        this->next = obj;
        this->next->arr = new int[1000];
    }
    A(int n) : next(nullptr){
        cout << this << "an int constructor" << endl;
        x = n, y = n;
    }
    A(const A &obj) : next(nullptr) {
        cout << this << "copy constructor" << endl;
        this->x = obj.x, this->y = obj.y;
    }
    void output() {
        cout << this->x << " " << this->y << endl;
    }
    int x, y;
    int *arr;
    A *next;
    ~A() {
        if(this->next) {
            delete this->next->arr;         
        }
        cout << this << "destructor" << endl;
    }
};

void func(int &x) { //这里的&是引用， 引用相当于被引用变量的别名
    x += 5;
}

A aa;
A bb(&aa);
A cc(&bb); 

int main() {
    int n = 7;
    func(n);   //构造函数将会被放到系统栈中，顺序跟入栈顺序有关，所以输出时先c在b再a
    cout << n << endl;
    cout << "pre postition" << endl;
    A a;
    A b = 6;   //这里 = 6也可以， 相当于类型转换, 这里的 = 相当于匹配构造函数。
    A c(a);
    cout << "a = " << &a << endl;
    cout << "b = " << &b << endl;
    cout << "c = " << &c << endl;
    cout << "aa = " << &aa << endl;
    cout << "bb = " << &bb << endl;
    cout << "cc = " << &cc << endl;
    b.output();
    b = 6;
    b.output();
    cout << "next posistion" << endl;
    return 0;
}

