/*************************************************************************
	> File Name: int_arr.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月26日 星期三 20时07分57秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<ctime>
using namespace std;

struct IntArray {
    IntArray() {}
    IntArray(int x) {
        data = new int[x];
        n = x;
    }
    IntArray (const IntArray &obj) : n(obj.n){
        this->data = new int[n];
        for(int i = 0; i < n; i++) {
            this->data[i] = obj.data[i];
        }
    } 
    int &operator[](int x) {
        if(x >= 0) return this->data[x];
        if(x < 0) return this->data[x + n];
    }
     
    void operator+=(int num) {
        for(int i = 0; i < n; i++) {
            this->data[i] = this->data[i] + num;
        }
        return ;
    }    
    
    void operator<<=(int num) {
        for(int i = 0; i < n; i++) {
            this->data[i] = this->data[i] << num;
        }
        return ;
    }


    IntArray operator++(int x) {
        IntArray tmp = (*this);
        for(int i = 0; i < n; i++) {
            this->data[i] = this->data[i] + 1;
        }
        return tmp;
    }
    
    void operator=(const IntArray &a) {
        this->data = new int[a.n];
        this->n = a.n;
        for(int i = 0; i < n; i++) {
            this->data[i] = a.data[i];
        }
        return ;
    }

    void operator,(const IntArray &a) {
        if(this->n != a.n) return ;
        for(int i = 0; i < n; i++) {
            this->data[i] = this->data[i] + a.data[i]; 
        }
        return ;
    }
    
    int operator&&(const IntArray &a) {
        int cnt = 0;
        if(this->n != a.n) return 0;
        for(int i = 0; i < n; i++) {
            if(this->data[i] == a.data[i]) return i + 1;
        }
        return cnt;
    }

    IntArray &operator++() {
        for(int i = 0; i < this->n; i++) {
            this->data[i] = this->data[i] + 1;
        }
        return *this;
    }

    string operator==(const IntArray &a) {
        int cnt = 0;
        if(a.n != this->n) return "Not the same";
        for(int i = 0; i < n; i++) {
            if(this->data[i] != a.data[i]) return "Not the same";
        }
        return "Is the same";
    }
    
    ~IntArray() {
        delete[] this->data;
    }
    friend ostream &operator<<(ostream &out, const IntArray &a);
private : 
    int *data;
    int n; //个数
};

ostream &operator<<(ostream &out, const IntArray &a) {
    for(int i = 0; i < a.n; i++) {
        out << a.data[i] << " ";
    }
    return out;
}


int main() {
    IntArray a(10);
    for(int i = 0; i < 10; i++) {
        a[i] = rand() % 100;
    }
    IntArray c = a; //这里使用 = 重载来进行拷贝
    cout << c << endl;
    cout << a << endl;
    cout << (c == a) << endl;  //输出两个数组是否相同
    cout << (c&&a) << endl;  //返回第几个元素相同
    a += 5;   //给数组所有元素都+5
    cout << a << endl; // 输出整个数组中的元素
    cout << (c == a) << endl;
    cout << c << endl;
    cout << (a++) << endl; //给数组中的所有元素都加一
    cout << (++a) << endl; //给数组的所有元素+1
    a <<= 1;    //所有元素左移一位。
    c,a;    //数组对应位置相加。
    cout << a << endl;
    cout << c << endl;
    return 0;
}

