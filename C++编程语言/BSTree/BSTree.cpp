/*************************************************************************
	> File Name: BSTree.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月15日 星期日 14时39分19秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include "BSTree.h"
#include<set>
using namespace std;

class A {
public : 
    void operator++() {
        cout << "no param" << endl;
    }
    A &operator++(int x) {
        cout << "have param" << endl;
    }
};


int main() {
    haizei::BSTree<int> root_bs;
    std::set<int> root_s;
    for(int i = 0; i < 10; i++) {
        root_bs.insert(rand() % 100);
        root_s.insert(rand() % 100);
    }
    for(std::set<int>::iterator iter = root_s.begin(); iter != root_s.end(); iter++) { 
        cout << *iter << endl;
    } //iter是一个迭代器(指针对象)
    for(haizei::BSTree<int>::iterator iter = root_bs.begin(); iter != root_bs.end(); iter++) {
       cout << *iter << endl; 
    }

    return 0;
}

