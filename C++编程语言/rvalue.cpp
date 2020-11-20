/*************************************************************************
	> File Name: rvalue.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月12日 星期四 20时58分00秒
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

void f2(int &x) {
    cout << " in func f2 : " << x << " is left value" << endl;
    return ;
}

void f2(int &&x) {
    cout << " int func f2 : " << x << " is right value" << endl;
    return ;
}

void f(int &x) { //判断左值
    cout << x << " is left value" << endl;
    f2(forward<int &>(x));   
    return ;
}

void f(int &&x) { //判断右值
    cout << x << " is right value" << endl;
    /*f2(x);  //这里传入的x是 左值 因为这里(函数内部)x是左值的规则，哪怕是右值引用*/
    f2(forward<int &&>(x)); // forward 转换成尖括号内的类型
    return ; 
} 

class A {
public :
    A(int n = 10) : n(n) {
        arr = new int[n];
        for(int i = 0; i < this->n; i++) arr[i] = i;
    }
    
    A(const A &obj) : n(obj.n) { //返回值优化 且默认拷贝为左值拷贝
        cout << "copy constructor" << endl;
        this->arr = new int[n];
        for(int i = 0; i < n; i++) {
            this->arr[i] = obj.arr[i];
        }
    }

    A(A &&obj) {  //直接改变指针指向对象
        cout << "move constructor" << endl;
        this->n = obj.n;
        this->arr = obj.arr;
        obj.arr = nullptr;  //记得空地址
    }

    A operator+(const A &obj) {
        A temp(this->n + obj.n);
        for(int i = 0; i < this->n; i++) temp.arr[i] = arr[i];
        for(int i = 0; i < obj.n; i++) temp.arr[i + this->n] = obj.arr[i];
        return temp;
    }

    void output() {
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return ;
    }
    ~A() {
        cout << "destructor" << endl;
        delete[] arr;
    }

private :
    int *arr;
    int n;
};

int main() {
    int n = 123; // 如果到了下面的代码还能够访问到就是左值，访问不到机就是右值
    cout << ((n++)++) << endl;;  // ----> 报错    很大程度上 左值是一个可以操控的变量，而右值不能修改
    cout << (++n)++ << endl; //不报错， ++n 为左值

    /*int &a = n;   //严格的名称叫左值引用
    int &&b = n;  //右值引用*/
    f(++n);
    f(move(n++)); // move强制转换成右值
    /*A *p = new A();   //假设p指向的之后不会再用
    A a = (*p);
    delete p;   //三步废物操作， 直接把p指向的嫁接给a更快
    */

    A *p = new int[n];
    A a = move(*p);
    delete p;
    a.output();
    return 0;
}

