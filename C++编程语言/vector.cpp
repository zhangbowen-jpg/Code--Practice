/*************************************************************************
	> File Name: vector.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月03日 星期二 13时37分57秒
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
class Vector {
public :
    Vector() : arr(), capacity(0), size(0) {
        this->capacity = 1;   //默认容量
        this->size = 0;
        T *arr = new T[capacity];
    } //无参构造容器
    Vector(int size) {
        this->size = size;
        this->capacity = size;
        this->arr = new T[capacity];
        for(int i = 0; i < this->size; i++) {
            this->arr[i] = 0;
        }
    } //默认初值有参构造
    Vector(int size, T data) {  //有参构造
        this->capacity = size;
        this->size = size;
        this->arr = new T[capacity];
        for(int i = 0; i < this->size; i++) {
            this->arr[i] = data;
        }
    }
    ~Vector() {  //构析函数， 释放指针
        if(arr != NULL)
        {
            delete[] arr;
        }
    }
    Vector(const Vector &a) {
        this->capacity = a.capacity;
        this->size = a.size;
        this->arr = new T[this->capacity];
        memcpy(this->arr, a.arr, this->size*sizeof(T));
    }

    void print() {
        for(int i = 0; i < this->size; i++) {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }
    
    void push_back(T data) {
        if(this->arr == NULL) {
            this->capacity = 1;
            this->size = 0;
            this->arr = new T[capacity];
        }
        if(this->size == this->capacity) { //扩容
            T *temp_arr = new T[this->capacity * 2];
            memcpy(temp_arr, arr, this->size * sizeof(T));
            this->capacity *= 2;
            delete[] arr;
            arr = temp_arr;
        }
        this->arr[this->size++] = data;
    }
    
    void pop_back() {
        if(this->size > 1) {
            this->arr[this->size - 1] = 0;
            this->size--;
        }
        else error();
    }
    
    T* begin() {
        return this->arr;
    }

    T* end() {  
        return this->arr + this->size - 1;
    } 
    
    T at(int x) {
        return this->arr[x - 1];
    }

    bool empty() {
        return this->size == 0; 
    }

    void insert(int n, T data) {
        if(n >= 0 && n <= this->size) { //中间
            if(this->size == this->capacity) { //扩展
                error();
                T *temp_arr = new T[this->capacity * 2];
                memcpy(temp_arr, this->arr, this->size * sizeof(T));
                this->capacity *= 2;
                delete[] arr;
                arr = temp_arr;
            }
            for(int i = this->size; i > n; i--) {
                this->arr[i] = this->arr[i - 1];
            }
            this->arr[n] = data;
            this->size++;
        }
    }

    void erase(int n) {
        if(n > this->size) {
            error1();
            return ;
        }
        for(int i = this->size; i > n + 1; i--) {
            this->arr[i - 1] = this->arr[i];
        }
        this->size--;
    }
    
    void error() {
        cout << "error! 数组越界, 进行扩容!" << endl;
    }

    void error1() {
        cout << "error! 删除的位置没有元素。" << endl;
    }

    void clear() {
        T *temp_arr = new T[this->capacity];
        delete[] arr;
        this->arr = temp_arr;
        this->size = 0;
        return ;
    }

    T &operator[](int n) {
        if(n >= 0 && n < this->size) return this->arr[n];
        error();
    }

    T &operator=(const Vector &a) {
        if(this->arr != NULL) {
            delete[] arr;
            this->capacity = 0;
            this->size = 0;
            this->arr = NULL;
        }
        this->capacity = a.capacity;
        this->size = a.size;
        this->arr = new T[this->capacity];
        memcpy(arr, a.arr, this->size * sizeof(T));
    }

    int get_size() {
        return this->size;
    }

    int get_capacity() {
        return this->capacity;
    }

private :
    T *arr;
    int capacity;
    int size;
};

int main() {
    int *p, *q;
    Vector<int> Vector1(3, 5);
    Vector1.print();
    cout << Vector1.get_size() << " " << Vector1.get_capacity() << endl;
    for(int i = 0; i < 11; i++) {
        Vector1.push_back(i);
        Vector1.print();
    }
    Vector1.erase(14);
    p = Vector1.begin();
    cout << *p << endl;
    q = Vector1.end();
    cout << *q << endl;
    Vector1.pop_back();
    Vector1.pop_back();
    Vector1.pop_back();
    Vector1.print();
    Vector1[2] = 5438;
    Vector1.print();
    cout << Vector1.empty() << endl;
    Vector<int> Vector2(5, 1);
    Vector2.print();
    Vector2.insert(0, 5);
    Vector2.insert(1, 666);
    Vector2.insert(Vector2.get_size(), 233);
    Vector2.print();
    return 0;
}

