/*************************************************************************
	> File Name: virtual.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月28日 星期五 14时50分40秒
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

string rand_name(int n) {
    string name = "";
    for(int i = 0; i < n; i++) {
        name = name + (char)(rand() % 26 + 'A');
    }
    return name;
}

class Animal {
public :
    Animal(string name) : name(name) {}
    string tell_me_your_name() {
        return this->name;
    }
    virtual void run() {
        cout << "I don't know how to run" << endl;
    }
    virtual void say() = 0; //纯虚函数的性质类似接口
    virtual void func0() {};
    virtual ~Animal() {
        cout << "Animal distructor" << endl;
    }    
private :
    string name;
};

class Cat : public Animal { 
public :
    Cat() : Animal (rand_name(5) + "Cat") {}
    void run() override {
        cout << "I can run with four legs" << endl;
    }
    void func0() override {
        cout << "this is funco" << endl;
    }
    void say() override {
        cout << "miao~" << endl;
    }
    ~Cat() {
        cout << "Cat distructor" << endl;
    }
};

class Bat : public Animal {
public : 
    Bat() : Animal(rand_name(5) + "Bat") {}
    void run() override { //override会在如果覆盖错误时会返回错误
        cout << "I can fly" << endl; 
    }
    void say() override {
        cout << "zzz~" << endl; 
    }
    ~Bat() {
        cout << "Bat distructor" << endl;
    }
};

int main() {
    Cat a;
    Bat b;
    cout << a.tell_me_your_name() << endl;
    a.run();
    cout << b.tell_me_your_name() << endl;
    b.run();
    Animal ** arr = new Animal*[10];
    for(int i = 0; i < 10; i++) {
        if(rand() % 2) {
            arr[i] = new Cat();
        } else {
            arr[i] = new Bat();
        }
    }
    for(int i = 0; i < 10; i++) {
        cout << arr[i]->tell_me_your_name() << endl;
        arr[i]->run();
        arr[i]->say();
    }
    for(int i = 0; i < 10; i++) {
        delete arr[i];
    }
    delete[] arr;
    return 0;
}

