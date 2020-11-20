/*************************************************************************
	> File Name: add_lvalue_reference.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月14日 星期六 16时17分15秒
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

template<typename T>
typename remove_reference<T>::type &&my_move(T &&a) { //自己实现move
    return static_cast<typename remove_reference<T>::type &&>(a);
};

template<typename T>
struct my_remove_point {
    typedef T type;
};

template<typename T> 
struct my_remove_point<T *> {
    typedef typename my_remove_point<T>::type type;
};


template<typename T> 
struct my_add_lvalue_reference {
    typedef T &type;
};

template<typename T> 
struct my_add_lvalue_reference<T &> {
    typedef T &type;
};

template<typename T> 
struct my_add_lvalue_reference<T &&> {
    typedef T &type;
};

template<typename T>
struct my_add_const {
    typedef const T type;
};   

template<typename T> 
struct my_add_const<const T> { //如果已经是const 不动类型
    typedef const T type;
};

void func(int &a) {
    cout << "left reference" << endl;
}

void func(int &&a) {
    cout << "right reference" << endl; 
}

void is(int a) {
    cout << "normal value" << endl;
}

void is(int *a) {
    cout << "point value" << endl;
}

int main() {
    int a = 123;
    func(a);
    func(my_move(a));
    typename my_add_lvalue_reference<int>::type c = a;
    func(c);
    typename my_add_lvalue_reference<int &>::type d = a;
    func(d);
    typename my_add_lvalue_reference<int &&>::type e = a;
    func(e);
    typename my_remove_point<int>::type f;
    typename my_remove_point<int *>::type g;
    typename my_remove_point<int **>::type h;
    is(f);
    is(g);
    is(h);
    typename my_add_const<int>::type o = 1;
    //o = 5;
    typename my_add_const<const int>::type p = 1;
    //p = 5;
    return 0;
}


