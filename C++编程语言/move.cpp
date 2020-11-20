/*************************************************************************
	> File Name: move.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月14日 星期六 15时33分25秒
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
typename remove_reference<T>::type && my_move(T &&t) { //实现move，无论使用什么类型，传出的一定是右值, type后面&&是为了转化成右值
    return static_cast<typename remove_reference<T> &&>(t);
} 

void func(int &&a) {
    cout << "right value" << endl;
}

void func(int &a) {
    cout << "left value" << endl;
}

int main() {
    int a = 123, b = 456;
    return 0;
}

