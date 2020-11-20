/*************************************************************************
	> File Name: public.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月19日 星期三 18时47分00秒
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
    int x, y;
    int echo() {
         cout << "hello world" << endl;
         return 0;
    }
};  //默认权限位public
 
class B {
public:
    void set_xy(int x, int y) {
        cout << this << endl;
        this->x = x, this->y = y;
    }
    int echo() {
        cout << "hello world" << endl;
        cout << x << " " << y << endl;
        return 0;
    }
private:
    int x, y;
}; //默认位private

int main() { //主函数属于类外
    A a;
    B b;
    a.x = 3, a.y = 2;
    b.set_xy(3, 2);
    cout << &b << endl;
    cout << a.x << " " << a.y << endl;
    b.echo();
    return 0;
}

