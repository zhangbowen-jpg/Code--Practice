/*************************************************************************
	> File Name: succeed.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月24日 星期一 15时47分08秒
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

#define P_ADD(obj, a) cout << #obj "." #a " = " << &(obj.a)

class Animal {
public:
    Animal(string name) : __name(name) {
        cout << "Animal constructor " << this << endl;
    }
    string name() { return this->__name; }

/*private :   //即使子类访问不到，但时其依旧在子类中存储了,并且父类的信息存储在子类信息的头部，再存储子类自己的信息。
    int x, y;
    string __name;
*/
    int x, y;
    string __name;
    ~Animal() {
        cout << "Animal distructor " << this << endl;
    } 
};

class Cat : public Animal {
public :
    Cat() : Animal("hello kitty") {
        cout << "Cat constructor " << this << endl;
    }
    void say() {
        cout << "my name is" << this->name() << endl;
    }
    int z; 
    ~Cat() {
        cout << "Cat distructor " << this << endl;
    }
};

ostream &operator<<(ostream &out, const Cat &a) {
    out << "<class Cat> " << &a << endl;
    P_ADD(a, x) << endl;
    P_ADD(a, y) << endl;
    P_ADD(a, __name) << endl;
    P_ADD(a, z) << endl;
    return out;
}

ostream &operator<<(ostream &out, const Animal &a) {
    out << "<class Animal> " << &a << endl;
    P_ADD(a, x) << endl;
    P_ADD(a, y) << endl;
    P_ADD(a, __name) << endl;
    return out;
}

int main() {
    Animal a("any");
    Cat c;
    c.say();
    cout << sizeof(a) << " " << sizeof(c) << endl;
    cout << c << endl;
    Animal *p = new Cat();
    cout << "Animal * : " << p->name() << endl;
    delete p;
    Animal &q = c;   //隐式类型转换，把属于子类的部分忽略掉，将其看成父类指针。
    cout << q << endl;
    return 0;
}

