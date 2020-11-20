/*************************************************************************
	> File Name: bind.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月15日 星期日 20时41分21秒
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

void func(int x, int y, int z) {
    cout << x + y << "is a number" << endl;
    cout << z << "is a number" << endl;
}

struct A {
    void say() {
        cout << this << " : saying" << endl; 
    }
    void run() {
        cout << "hello world" << endl;
    }
};

void count_function_times(function<void()> p, int &cnt) {
    p();
    cnt += 1;
    return ;
} 

int main() {
    function<void(int, int)> f = bind(func, 123, std::placeholders::_1, std::placeholders::_2);  //返回完一个绑定过的函数 ,placeholders->是占位符，暂时无法给出量,其中的_1,_2对应着绑定之后参数的位置，而原来的位置是对应的。
    f(100, 456);
    f(200, 789);
    A a;
    cout << &a << endl;
    function<void()> f2 = bind(&A::say, ref(a)); //先取方法地址,绑定的时候需要绑定相应对象, 并且在绑定之前会进行拷贝构造, 使用ref()可以将其改成引用。
    f2();
    int cnt = 0;
    function<void()> f3 = bind(&A::run, ref(a));
    function<void()> f4 = bind(count_function_times, ref(f3), ref(cnt));
    for(int i = 0; i < rand() % 10; i++) {
        f4();
    }
    cout << cnt << endl;
    return 0;
}

