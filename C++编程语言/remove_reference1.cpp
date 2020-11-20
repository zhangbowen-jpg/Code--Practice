/*************************************************************************
	> File Name: remove_reference1.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月14日 星期六 15时51分57秒
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
class remove_reference {
public :
    typedef T type;
};

template<typename T>
class remove_reference<T &>  {
public :
    typedef T type;
};

template<typename T> 
class remove_reference<T &&> {
public :
    typedef T type;
};

int main() {
    int a = 123, b = 456;
    
    return 0;
}

