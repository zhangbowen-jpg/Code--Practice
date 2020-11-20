/*************************************************************************
	> File Name: visitor.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月24日 星期二 18时29分53秒
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

class B;
class C;
class D;
class E;
class F;

class A {
public :
    class IVisitor { //访问者模式接口类，所有函数皆为纯虚函数
    public :
        virtual void visit(A *) = 0;
        virtual void visit(B *) = 0;
        virtual void visit(C *) = 0;
        virtual void visit(D *) = 0;
        virtual void visit(E *) = 0;
        virtual void visit(F *) = 0;
    };
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }

    virtual ~A() {}
};

class B : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class C : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
    
};

class D : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class E : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class F : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class OutputVisitor : public A::IVisitor{  //每一个访问者对应一个需要映射的功能
    virtual void visit(A *object) {
        cout << "this is a father object" << endl;
    }

    virtual void visit(B *object) {
        cout << "this is a class B object" << endl;
    } 
    virtual void visit(C *object) {
        cout << "this is a class C object" << endl;
    } 
    virtual void visit(D *object) {
        cout << "this is a class D object" << endl;
    }
    virtual void visit(E *object) {
        cout << "this is a class E object" << endl;
    }
    virtual void visit(F *object) {
        cout << "this is a class F object" << endl;
    }
};

class suanshu : public A::IVisitor{
public :
    suanshu(int val = 1) : val(val) {}
    virtual void visit(A *object) {
        return ;
    }
    virtual void visit(B *object) {
        val += 5;
        return ;
    } 
    virtual void visit(C *object) {
        val *= 2;
        return ;
    } 
    virtual void visit(D *object) {
        val -= 4;
        return ;
    }
    virtual void visit(E *object) {
        val += 6;
        return ;
    }
    virtual void visit(F *object) {
        val -= 7;
        return ;
    }
    int val;
};



int main() {
    A *arr[10];
    for(int i = 0; i < 10; i++) {
        switch(rand() % 5) {
            case 0: arr[i] = new B(); break;
            case 1: arr[i] = new C(); break;
            case 2: arr[i] = new D(); break;
            case 3: arr[i] = new E(); break;
            case 4: arr[i] = new F(); break;
        }
    }

    OutputVisitor vis;
    for(int i = 0; i < 10; i++) {
        arr[i]->Accept(&vis);
    }
    
    suanshu su;

    for(int i = 0; i < 10; i++) {
        arr[i]->Accept(&su);
    }

    cout << su.val << endl;

    return 0;
}


