/*************************************************************************
	> File Name: static_const_method.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月21日 星期五 18时43分42秒
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
    A(int x) {
        cout << "class A's constructor" << endl;
    }
};

class Point {
public:
    Point();
    Point(int x, int y); //如果定义了有参，再想创建无参对象必须重新定义,默认的会被删除
    int x() const;//为每个私有的成员添加提取方法,当然，生命和定义应该分开，否则链接时会发生重定义
    int y() const;
    int x_cnt() const; //用于处理被const和private固定了的__x_cnt()
    void set_x(int x); //在没有这个函数的时候，xy只读；
    void set_y(int y); //这样的方法可以避免直接修改私有成员值
    static int output_cnt();   //输出点类数量应该为类方法，不是对象的
    ~Point();
//成员属性一定先于类被构造。
private :
    static int point_cnt; //声明在这，但是定义必须额外定义
    int __x, __y;  //成员必须私有
    mutable int __x_cnt;  //可以在const类型进行修改
    A __a;
};

int Point::point_cnt = 0; //类属性的定义

int Point::output_cnt() {
    return Point::point_cnt;
}

Point::Point() : __x_cnt(0), __a(2) {    //初始化列表操作,相当于给一个整形对象赋值，并调用相关构造函数
    Point::point_cnt += 1;  //构造逻辑
}


Point::Point(int x, int y) : __x(x), __y(y), __x_cnt(0) , __a(4) {
    Point::point_cnt += 1;
}

Point::~Point() {
    Point::point_cnt -= 1;
}

int Point::x() const {
    this->__x_cnt += 1;
    return this->__x;
} 

int Point::y() const {
    return this->__y;
}

int Point::x_cnt() const {
    return this->__x_cnt;
}

void Point::set_x(int x) {
    this->__x = x;
}

void Point::set_y(int y) {
    this->__y = y;
}

void func() {
    Point c, d;
    cout << "func : " << Point::output_cnt() << endl;
    return ;
}

int main() {
    Point a(2, 3), b;
    const Point c(3, 4);  //const类型的对象只能使用const类型的方法，如果不是，则成员属性有可能改变
    cout << a.x() << " " << a.y() << endl;
    cout << c.x() << " " << c.y() << endl;
    cout << a.x_cnt() << " " << b.x_cnt() << " " << c.x_cnt() << endl;
    cout << "before func : " << Point::output_cnt() << endl;
    func();
    cout << "after func : " << Point::output_cnt() << endl;
    return 0;
}
