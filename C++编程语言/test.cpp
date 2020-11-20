/*************************************************************************
	> File Name: test.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月24日 星期一 16时57分50秒
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

class Test {
public : 
    Test() {};
    void say() { cout << "hello world" << endl; }
    Test(const Test &t);
};

int main() {
    Test t;
    Test b = t;
    t.say();
    return 0;
}

