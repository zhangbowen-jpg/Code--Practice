/*************************************************************************
	> File Name: 459.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年07月15日 星期三 19时40分04秒
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

struct student {
    string name;
    string sex;
    int age;
    double weight;
};

int main() {
    student stu;
    cin >> stu.name >> stu.sex >> stu.age >> stu.weight;
    cout << stu.name << " " << stu.sex << " " << stu.age;
    printf(" %.1lf", stu.weight);
    return 0;
}



