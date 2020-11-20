/*************************************************************************
	> File Name: template_type.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月14日 星期六 15时03分12秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<functional>
using namespace std;

template<typename T>
void my_swap(T &&a, T &&b) { //引用折叠 ，这里T在30行会被定义成int &(3个&)
    typename remove_reference<T>::type c; // remove_reference -> 去掉引用
    c = a;
    a = b;
    b = c;
    return ;
}

template<typename T> 
void add(T &&a, T &&b) { //两个&一定传引用
    a += 3;
    b += 4;
    return ;
}

void func(void (*p)(int &, int &), int &a, int &b) {//函数对象指针,传入参数为相应类型,这里在传入之后add会自动推导T的类型
    p(a, b);
    return ;
}

template<typename T>
typename remove_reference<T>::type &&my_move(T &&a) { //自己实现move
    return static_cast<typename remove_reference<T>::type &&>(a);
} 

template<typename T> 
struct my_remove_reference {
    typedef T type;
};

template<typename T>
struct my_remove_reference<T &> {
    typedef T type;
}；

template<typename T> 
struct my_remove_reference<T &&> {
    typedef T type;
};


void func(int &a) {
    cout << "left value" << endl
}

void func(int &&a) {
    cout << "right value" << endl;
}

int main() {
    int a = 123, b = 456;
    cout << a << " " << b << endl;
    my_swap(a, b);
    cout << a << " " << b << endl;
    my_swap(move(a), move(b));
    cout << a << " " << b << endl;
    func(add, a, b);
    cout << a << " " << b << endl;
    return 0;
}


