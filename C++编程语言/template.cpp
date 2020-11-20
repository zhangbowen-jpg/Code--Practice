/*************************************************************************
	> File Name: template.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月28日 星期五 18时33分47秒
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
T add(T a, T b) { //模板并非在对象文件中，当被调用时，模板会自动判断参数类型，并且在代码中进行相关函数的实现。
    cout << "add function : " << sizeof(T) << endl;
    static int i = 0;
    cout << "i : " << (++i) << endl;
    return a + b;
}

template<typename T> //偏特化模板
T add(T *a, T *b) {
    cout << "T * add function" << endl;
    return (*a) + (*b);
}

template<>    //特化模板
int add(int a, int b) {
    cout < "specific template and function" << endl;
    return a + b;
}

template<typename T>
class Array {
public :
    Array(int n) : n(n) {
        this->arr = new T[n];
    }
    T &operator[](int ind) { //需要给对象位置赋值，而不是给值赋值
        if(ind < 0 || ind >= n) return this->__end;
        return this->arr[ind];  
    }
    template<typename U>
    friend ostream &operator<< (ostream &, const Array<U> &); //需要说明为模板的友元函数,且不能跟之上的同样的名字。
private :
    T *arr;
    T __end;
    int n;
};

template<>
class Array<double> { //特化类模板
public :
    Array(int n) : n(n) {
        cout << "double array template" << endl;
        this->arr = new double[n];
    }
    double &operator[](int ind) { 
        if(ind < 0 || ind >= n) return this->__end;
        return this->arr[ind];  
    }
    template<typename T>
    friend ostream &operator<< <>(ostream &, const Array<T> &);
private :
    T *arr;
    T __end;
    int n;
};

template<typename T>  //在重载左移运算时，也使用模板
ostream &operator<<(ostream &out, const Array<T> &a) {
    cout << "Class Array : ";
    for(int i = 0; i < a.n; i++) {
        cout << a.arr[i] << " ";
    }
    return out;
}

int main() {
    int a_num = 123, b_num = 456;
    cout << add(2, 3) << endl;
    cout << add(2.3, 4.5) << endl;
    cout << add<double>(2.3, 5) << endl;  //显式固定模板类型,与前一个调用的同一函数
    cout << add(&a_num, &b_num) << endl;
    Array<int> a(10);
    Array<double> b(10);
    a[0] = 123;
    a[-123] = 456;
    for(int i = 0; i < 10; i++) {
        b[i] = (rand() % 100) / 100.0;
    }
    cout << a << endl;
    cout << b << endl;
    return 0;
}

