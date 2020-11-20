/*************************************************************************
	> File Name: template_turing.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月15日 星期日 16时34分23秒
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

template<int x>
struct IsOdd {
    constexpr static int r = x % 2; //编译期确定的值
};

template<int i, int x> 
struct getNextK {
    constexpr static int r = (i * i > x ? 0 : (x % i == 0 ? 1 : 2));
};

template<int i, int x, int k>
struct Test {
    constexpr static int r = Test<i + 1, x, getNextK<i, x>::r >::r;
};

template<int i, int x> 
struct Test<i, x, 0> {
    constexpr static int r = 1;
   
};

template<int i, int x> 
struct Test<i, x, 1> {
    constexpr static int r = 0;
};


template<int x>
struct is_prime {
    constexpr static int r = Test<2, x, 2>::r;
};

template<int i, int x>
struct getNextK2 {
    constexpr static int r = (i > x ? 0 : 1);
};

template<int i, int x, int sum, int k>
struct __calc_prime_sum {
    constexpr static int r = sum + i * is_prime<i>::r + __calc_prime_sum<i + 1, x, sum, getNextK2<i + 1, x>::r >::r;
};

template<int i, int x, int sum>
struct __calc_prime_sum<i, x, sum, 0> {
    constexpr static int r = 0;
};

template<int x> 
struct prime_sum {
    constexpr static int r = __calc_prime_sum<2, x, 0, 1>::r;
};


template<int x, int k>
struct __get_next_prime {
    constexpr static int r = __get_next_prime<x + 1, is_prime<x + 1>::r>::r;
};

template<int x>
struct __get_next_prime<x, 1> {
    constexpr static int r = x;  
};

template<int x>
struct get_next_prime {
    constexpr static int r = __get_next_prime<x + 1, is_prime<x + 1>::r>::r;  
};


template<int x>
struct print_prime {
    template<int i, int k>
    struct __output {
    static void run() {
        if(is_prime<i>::r) {
            cout << i << endl;
        }
        print_prime<x>::__output<i + 1, getNextK2<i + 1, x>::r>::run();
        }
    };
    template<int i>
    struct __output<i, 0> {
        static void run() {
        return ;
        }
    };
    static void output() { 
        print_prime<x>::__output<2, 1>::run();
        return ;
    }
};

template<int x>
struct print__triangle {
    template<int i , int m, int k>
    struct __output_line {
        static void run() {
            cout << "-";
            __output_line<i + 1, m, getNextK2<i + 1, m>::r >::run();
        }
    };
    template<int i, int m>
    struct __output_line<i, m, 0> {
        static void run() {
            cout << endl;      
        }
    };
    template<int i, int k>
    struct __output {
    static void run() {
        __output_line<1, i, 1>::run();
        __output<i + 1, getNextK2<i + 1, x>::r >::run();
        }
    };
    template<int i>
    struct __output<i, 0> {
        static void run() {
        return ;
        }
    };
    static void output() { 
        __output<1, 1>::run();
        return ;
    }
};


bool __is_prime(int i, int x) {
    if(i * i > x) return true; // k = 0;
    if(x % i == 0) return false; // k = 1;
    return __is_prime(i + 1, x); // k = 2;
}

int is_prime_2(int x) {
    return __is_prime(2, x);
}

int main() {
    cout << IsOdd<5>::r << endl;
    cout << IsOdd<6>::r << endl;
    cout << is_prime<9973>::r << endl;
    cout << prime_sum<100>::r << endl;
    //cout << five_x<100>::r << endl;
    print_prime<100>::output();
    cout << get_next_prime<5>::r << endl;
    cout << get_next_prime<12>::r << endl;
    print__triangle<4>::output();  //输出四层数字三角形，要求不能有循环  
    return 0;
}
