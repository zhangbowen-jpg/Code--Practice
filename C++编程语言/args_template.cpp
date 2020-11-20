/*************************************************************************
	> File Name: args_template.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月28日 星期五 19时56分08秒
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

template<typename T>   //偏特化版本需要定义在上面
void print(const T &a) {
    cout << a << endl;
    return ;
}

template<typename T, typename ...ARGS>
void print(const T &a, ARGS ...args) {
    cout << a << " ";
    print(args...);
    return ;
}

template<int n, typename T, typename ...ARGS>
struct ARG {
    typedef typename ARG<n - 1, ARGS...>::getT getT;
    /*typedef T getT;*/  //重命名是为了确定T的类型，一定有固定的类型
    typedef ARG<n - 1, ARGS...> N;

};

template<typename T, typename ...ARGS> 
struct ARG<0, T, ARGS...> {
    typedef T getT;
   /* typedef typename ARG<0, ARGS...>::finalT finalT;*/ //固定最后一个参数，然后当传入的第二个参数不时finalT类型就会报错
};

template<typename T>
struct ARG<0, T> {
    typedef T getT;
    typedef T finalT;
};

template<typename T, typename ...ARGS> class Test;
template<typename T, typename ...ARGS>
class Test<T(ARGS...)> {
public :
    T operator()(typename ARG<0, ARGS...>::N::getT a, typename ARG<1, ARGS...>::finalT b) {
        return a + b;
    }
};

int main() {
/*
    print(123, "hello world", 'o');
    cout << sizeof(ARG<int, double, float>::getT) << endl;
    cout << sizeof(ARG<int, double, float>::rest::getT) << endl;
    cout << sizeof(ARG(int, double, float)::rest::rest::getT) << endl;
    ARG<int, double, float>::getT a =123;
    ARG<int, double, float>::rest::getT b = 12.3;
    ARG<int, double, float>::rest::rest::getT c = 123.45;
*/
    cout << a << " " << b << " " << c << endl;
    Test<int(double, float)> d;
    Test<int, double, int, int, int>::rest::rest::rest::rest::getT e;
    cout << d(2.3, 4.5) << endl;
    return 0;
}

