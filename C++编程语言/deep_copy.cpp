/*************************************************************************
	> File Name: deep_copy.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月21日 星期五 20时06分04秒
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
        this->arr = new int[100];
    }
    A(const A &obj) : x(obj.x), y(obj.y){ //修改为拷贝对应数据保存在其中
        this->arr = new int[100];
        memcpy(this->arr, obj.arr, sizeof(int) * 100);
    }
    int *arr;
    int x, y;
};


int main() {
    A a;
    a.x = 3, a.y = 6;
    a.arr[0] = 123;
    A b = a;
    b.arr[0] = 456;
    cout << a.arr[0] << " " << b.arr[0] << endl;
    cout << b.x << " " << b.y << endl;
    b.x = 6;
    cout << a.x << " " << a.y << endl;
    cout << b.x << " " << b.y << endl;
    return 0;
}

