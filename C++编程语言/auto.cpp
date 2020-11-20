/*************************************************************************
	> File Name: auto.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月12日 星期四 20时09分19秒
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

int main() {
    long long a = 123;
    auto b = a;   //编译阶段可以自动确定的类型,不可以为不确定的类型,即auto b
    //额外的，auto关键字只能够为简单类型的类型，不能够定义数组
    cout << sizeof(b) << endl;
    map<string, int> arr;
    arr["hello world"] = 123;
    arr["haizei"] = 567;
    arr["harbin"] = 987;
    /*for(map<string, int>::iterator iter = arr.begin(); iter != arr.end(); iter++) { //iterator为迭代器类型,实际为重载了指针的类，iter为类的对象
        cout << iter->first << " " << iter->second << endl;
    }*/
    for(auto iter = arr.begin(); iter != arr.end(); iter++) { //iterator为迭代器类型,实际为重载了指针的类，iter为类的对象, auto进行类型转换，只有在编译阶段确定。
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}

