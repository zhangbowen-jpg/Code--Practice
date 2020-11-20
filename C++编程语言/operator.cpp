/*************************************************************************
	> File Name: operator.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月26日 星期三 18时56分14秒
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

struct Point {
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    Point(const Point &obj) : x(obj.x), y(obj.y) {
        cout << "copy constructor" << endl;
    }
    int operator()(int num) {
        return this->x + this->y + num;
    }
    int operator[](string str) {
        if(str == "x") return this->x;
        if(str == "y") return this->y;
        return 0;
    }
    Point operator-(const Point &a) {
        Point ret;
        ret.x = this->x - a.x;
        ret.y = this->y - a.y;
        return ret;
    }
    friend ostream &operator<<(ostream &out, const Point &a);
    friend Point operator+(const Point &, const Point &);  //友元函数指有一个类外的函数可以访问私有成员属性
private:
    int x, y;
};

 /*Point operator+(Point a, Point b) { //将重载的符号前面一定是operator,这么定义,传入的参数一定会直接调用拷贝构造函数
*/
/*Point operator(Point &a, Point &b) { //这么定义当产生连续的操作是，这个返回的是一个r-value(右值)，而传入必须为左值*/ 
Point operator+(const Point &a, const Point &b) {
    Point ret;
    ret.x = a.x + b.x;
    ret.y = a.y + b.y;
    return ret;
}

ostream &operator<<(ostream &out, const Point &a) {
    out << "<class Point> (" << a.x << ", " << a.y << ")";
    return out;
}

int main() {
    Point a(2, 4), b(5, 3);
    Point c = a + b;
    Point d = a + b + c;
    Point e = d - b; // 如果想要在类内部进行重载，那么C++会将其定义为d.operator - (b);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << a(5) << endl; //operator 在本质上重载的是(函数)对象
    cout << a["x"] << " " << a["y"] << endl;
    return 0;
}

